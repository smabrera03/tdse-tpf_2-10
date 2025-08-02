/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 *
 * @file   : task_system.c
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

/********************** inclusions *******************************************/
/* Project includes. */
#include "main.h"

/* Demo includes. */
#include "logger.h"
#include "dwt.h"

/* Application & Tasks includes. */
#include "board.h"
#include "app.h"
#include "task_system_attribute.h"
#include "task_system_interface.h"
#include "task_actuator_attribute.h"
#include "task_actuator_interface.h"

/********************** macros and definitions *******************************/
#define G_TASK_SYS_CNT_INI			0ul
#define G_TASK_SYS_TICK_CNT_INI		0ul

#define DEL_SYS_XX_MIN				0ul
#define DEL_SYS_XX_MED				50ul
#define DEL_SYS_XX_MAX				500ul

/********************** internal data declaration ****************************/
task_system_dta_t task_system_dta =
	{DEL_SYS_XX_MIN, false, EV_SYS_CARTA_NUEVA, ST_SYS_RONDA, ST_SYS_M1, ST_SYS_TJ1, 0, J1, 0, 0,
			{{0, ESPADA, 0}, {0, ESPADA, 0}, {0, ESPADA, 0}}, //3 cartas iniciales de J1
			{{0, ESPADA, 0},{0, ESPADA, 0}, {0, ESPADA, 0}}, //3 cartas iniciales de J2
			0, 0, NINGUNO, 1, NINGUNO, 0, 0,false};

#define SYSTEM_DTA_QTY	(sizeof(task_system_dta)/sizeof(task_system_dta_t))

/********************** internal functions declaration ***********************/
static void Maquina_de_estados_ronda(task_system_dta_t *p_task_system_dta);
static void finalizar_ronda(task_system_dta_t *p_task_system_dta);
static uint8_t calcularFE(uint8_t puntosJ1,uint8_t puntosJ2,jugador_enum_t ganador);
/********************** internal data definition *****************************/
const char *p_task_system 		= "Task System (System Statechart)";
const char *p_task_system_ 		= "Non-Blocking & Update By Time Code";

/********************** external data declaration ****************************/
uint32_t g_task_system_cnt;
volatile uint32_t g_task_system_tick_cnt;

/********************** external functions definition ************************/
void task_system_init(void *parameters)
{
	task_system_dta_t 	*p_task_system_dta;
	task_system_st_t	state;
	task_system_ev_t	event;
	bool b_event;

	/* Print out: Task Initialized */
	LOGGER_LOG("  %s is running - %s\r\n", GET_NAME(task_system_init), p_task_system);
	LOGGER_LOG("  %s is a %s\r\n", GET_NAME(task_system), p_task_system_);

	g_task_system_cnt = G_TASK_SYS_CNT_INI;

	/* Print out: Task execution counter */
	LOGGER_LOG("   %s = %lu\r\n", GET_NAME(g_task_system_cnt), g_task_system_cnt);

	init_queue_event_task_system();

	/* Update Task Actuator Configuration & Data Pointer */
	p_task_system_dta = &task_system_dta;

	/* Print out: Task execution FSM */
	state = p_task_system_dta->state;
	LOGGER_LOG("   %s = %lu", GET_NAME(state), (uint32_t)state);

	event = p_task_system_dta->event;
	LOGGER_LOG("   %s = %lu", GET_NAME(event), (uint32_t)event);

	b_event = p_task_system_dta->flag;
	LOGGER_LOG("   %s = %s\r\n", GET_NAME(b_event), (b_event ? "true" : "false"));

	g_task_system_tick_cnt = G_TASK_SYS_TICK_CNT_INI;
}


void task_system_update(void *parameters)
{
	task_system_dta_t *p_task_system_dta;
	bool b_time_update_required = false;

	/* Update Task System Counter */
	g_task_system_cnt++;

	/* Protect shared resource (g_task_system_tick) */
	__asm("CPSID i");	/* disable interrupts*/
    if (G_TASK_SYS_TICK_CNT_INI < g_task_system_tick_cnt)
    {
    	g_task_system_tick_cnt--;
    	b_time_update_required = true;
    }
    __asm("CPSIE i");	/* enable interrupts*/

    while (b_time_update_required)
    {
		/* Protect shared resource (g_task_system_tick) */
		__asm("CPSID i");	/* disable interrupts*/
		if (G_TASK_SYS_TICK_CNT_INI < g_task_system_tick_cnt)
		{
			g_task_system_tick_cnt--;
			b_time_update_required = true;
		}
		else
		{
			b_time_update_required = false;
		}
		__asm("CPSIE i");	/* enable interrupts*/

    	/* Update Task System Data Pointer */
		p_task_system_dta = &task_system_dta;

		if (true == any_event_task_system())
		{
			p_task_system_dta->flag = true;
			p_task_system_dta->event = get_event_task_system();
		}
		task_system_ev_t evento = p_task_system_dta->event;
		bool flag = p_task_system_dta->flag;

		switch (p_task_system_dta->state){
			case ST_SYS_RONDA:

				if((evento == EV_SYS_CARTA_ERR) && (flag == true)){
					p_task_system_dta->flag = false;
					put_event_led(EV_LED_SET, ID_LED_ROJA);
				}

				if((evento == EV_SYS_CARTA_NUEVA) && (flag == true)){
					p_task_system_dta->flag = false;
					put_event_led(EV_LED_SET, ID_LED_VERDE);

					Maquina_de_estados_ronda(p_task_system_dta);
					return;
				}

				if((evento == EV_SYS_BTN_NQ) && (flag == true)){
					p_task_system_dta->flag = false;

					if(p_task_system_dta->turno == ST_SYS_TJ1){
						p_task_system_dta->manos_ganadasJ1 = -1; //BUG: si defino manos_ganadasJ1 como uint8_t, esta asignación hace que valga 255. Lo cambié a int8_t para que pueda ser negativo
					}else{
						p_task_system_dta->manos_ganadasJ2 = -1;
					}
					finalizar_ronda(p_task_system_dta);
					return;
				}

				if((evento == EV_SYS_BTN_TRU) && (flag == true)){
					p_task_system_dta->flag = false;

					if(p_task_system_dta->turno == ST_SYS_TJ1){
						p_task_system_dta->jugador_truco = J1;
					}else{
						p_task_system_dta->jugador_truco = J2;
					}

					//acá tengo que prender una LED para avisar que el sistema está esperando una respuesta
					p_task_system_dta->state = ST_SYS_TRUCO_PENDIENTE;
					p_task_system_dta->puntos_TRU++;
					return;
				}

				if((evento == EV_SYS_BTN_ENV) && (flag == true)){
					p_task_system_dta->flag = false;

					if(p_task_system_dta->nCartas < 2 && p_task_system_dta->puntos_ENV == 0){
						p_task_system_dta->state = ST_SYS_E;

						if(p_task_system_dta->turno == ST_SYS_TJ1){
							p_task_system_dta->jugador_envido = J1;
						}else{
							p_task_system_dta->jugador_envido = J2;
						}
						//mostrar la selección en el display. Algo del tipo "->E	RE	FE"
					}
				}
				break;
			case ST_SYS_TRUCO_PENDIENTE:
				if(p_task_system_dta->flag == false)break;
				p_task_system_dta->flag = false;
				//Misma duda que en el caso de ST_SYS_RONDA. ¿Hay alguna transición que no la dispare ningún evento?
				//¿Vale la pena poner esto acá? ¿O conviene más ponerlo afuera del switch?

				if(evento == EV_SYS_BTN_TRU){
					if(p_task_system_dta->puntos_TRU < 4){
						p_task_system_dta->puntos_TRU++;
						p_task_system_dta->jugador_truco = !p_task_system_dta->jugador_truco;
					}
				}

				if(evento == EV_SYS_BTN_Q){
					p_task_system_dta->state = ST_SYS_RONDA;
				}

				if(evento == EV_SYS_BTN_NQ){
					p_task_system_dta->puntos_TRU--;

					//al que dijo no quiero le quito las manos ganadas
					if(p_task_system_dta->jugador_truco == J1){
						p_task_system_dta->manos_ganadasJ2 = -1;
					}else{
						p_task_system_dta->manos_ganadasJ1 = -1;
					}
					finalizar_ronda(p_task_system_dta);
					return;
				}
				break;

			case ST_SYS_E:
				if(p_task_system_dta->flag == false)break;
				p_task_system_dta->flag = false;

				if(evento == EV_SYS_BTN_ENV){
					p_task_system_dta->state = ST_SYS_RE;
					//en el display "E    ->RE    FE"
				}
				if(evento == EV_SYS_BTN_Q){
					p_task_system_dta->puntos_ENV_NQ = p_task_system_dta->puntos_ENV;
					p_task_system_dta->puntos_ENV += 2;
					p_task_system_dta->state = ST_SYS_ENVIDO_PENDIENTE;
				}
				break;

			case ST_SYS_RE:
				if(p_task_system_dta->flag == false)break;
				p_task_system_dta->flag = false;

				if(evento == EV_SYS_BTN_ENV){
					p_task_system_dta->state = ST_SYS_FE;
				}

				if(evento == EV_SYS_BTN_Q){
					p_task_system_dta->puntos_ENV_NQ = p_task_system_dta->puntos_ENV;
					p_task_system_dta->puntos_ENV += 3;
					p_task_system_dta->state = ST_SYS_ENVIDO_PENDIENTE;
				}
				break;
			case ST_SYS_FE: //Tengo que poder simplificar los estados ST_SYS_E, ST_SYS_RE y ST_SYS_FE
				if(p_task_system_dta->flag == false)break;
				p_task_system_dta->flag = false;

				if(evento == EV_SYS_BTN_ENV){
					p_task_system_dta->state = ST_SYS_E;
				}

				if(evento == EV_SYS_BTN_Q){
					p_task_system_dta->puntos_ENV_NQ = p_task_system_dta->puntos_ENV;
					p_task_system_dta->fe_cantado=true;
					p_task_system_dta->state = ST_SYS_ENVIDO_PENDIENTE;

				}
				break;

			case ST_SYS_ENVIDO_PENDIENTE:
				if(p_task_system_dta->flag == false)break;
				p_task_system_dta->flag = false;

				if(evento == EV_SYS_BTN_Q){
					p_task_system_dta->state = ST_SYS_DEFINIR_GANADOR;
				}

				if(evento == EV_SYS_BTN_NQ){
					if(p_task_system_dta->puntos_ENV_NQ == 0){
						p_task_system_dta->puntos_ENV_NQ = 1;
					}
					if(p_task_system_dta->jugador_envido == J1){
						p_task_system_dta->puntosJ1 += p_task_system_dta->puntos_ENV_NQ;
					}else{
						p_task_system_dta->puntosJ2 += p_task_system_dta->puntos_ENV_NQ;
					}
					p_task_system_dta->state = ST_SYS_RONDA;
				}

				if(evento == EV_SYS_BTN_ENV){
					p_task_system_dta->jugador_envido = !p_task_system_dta->jugador_envido;
					p_task_system_dta->state = ST_SYS_E;
				}
				break;
			case ST_SYS_DEFINIR_GANADOR:
				if(p_task_system_dta->flag == false)break;
				p_task_system_dta->flag = false;

				if(evento == EV_SYS_BTN_Q){//ganó J1
					if(p_task_system_dta->fe_cantado){
						p_task_system_dta->puntos_ENV = calcularFE(p_task_system_dta->puntosJ1,p_task_system_dta->puntosJ2,J1);
					}

					p_task_system_dta->puntosJ1 += p_task_system_dta->puntos_ENV;
					p_task_system_dta->state = ST_SYS_RONDA;
					p_task_system_dta->fe_cantado=false;
				}

				if(evento == EV_SYS_BTN_NQ){//ganó J2
					if(p_task_system_dta->fe_cantado){
						p_task_system_dta->puntos_ENV = calcularFE(p_task_system_dta->puntosJ1,p_task_system_dta->puntosJ2,J2);
					}

					p_task_system_dta->puntosJ2 += p_task_system_dta->puntos_ENV;
					p_task_system_dta->state = ST_SYS_RONDA;
					p_task_system_dta->fe_cantado=false;
				}
				break;

			default:
				break;

		}
	}
}


void Maquina_de_estados_ronda(task_system_dta_t *p_task_system_dta){
	turno_t turno = p_task_system_dta->turno; //¿es el turno de quién?
	mano_t mano = p_task_system_dta->mano;//¿Por qué mano vamos?


	//dentro de este bloque hay 3 etapas: 1) cargar la carta. 2) definir quién ganó (si hiciera falta). 3) pasar al siguiente estado

	//1)cargo la carta. ¿A quién? ¿Qué carta?
	carta_t *carta_addrs;
	//elijo la dirección de la carta

	if(turno == ST_SYS_TJ1){
		carta_addrs = &(p_task_system_dta->cartasJ1[mano]);
	}else{
		carta_addrs = &(p_task_system_dta->cartasJ2[mano]);
	}
	//esto tal vez sería más fácil con una matriz de carta???? Primera fila J1 y segunda fila J2
	get_Carta(carta_addrs);
	p_task_system_dta->nCartas++;

	//2)Defino el ganador si nCartas es par
	if(p_task_system_dta->nCartas%2 == 0){
		uint8_t prioridad_J1 = p_task_system_dta->cartasJ1[mano].prioridad;
		uint8_t prioridad_J2 = p_task_system_dta->cartasJ2[mano].prioridad;

		if(prioridad_J1 > prioridad_J2){
			//ganó J1
			p_task_system_dta->manos_ganadasJ1++;
			p_task_system_dta->turno = ST_SYS_TJ1; //si pasara a la siguiente mano, ya se de quién es el siguiente turno (aunque tal vez no avance de mano
		}else if(prioridad_J1 < prioridad_J2){
			//ganó J2
			p_task_system_dta->manos_ganadasJ2++;
			p_task_system_dta->turno = ST_SYS_TJ2;
		}else{
			//empataron
			p_task_system_dta->turno = !p_task_system_dta->turno;
		}
		//3)ya definida la mano, tengo que avanzar de estado
		if(mano == ST_SYS_M1){

			p_task_system_dta->mano = ST_SYS_M2;
			return; //no hace falta, pero me ayuda a ver dónde termina la función

		}else if(mano == ST_SYS_M2){

			if(p_task_system_dta->manos_ganadasJ1 == p_task_system_dta->manos_ganadasJ2){
				p_task_system_dta->mano = ST_SYS_M3;
				return;

			}else{

				finalizar_ronda(p_task_system_dta);
				return;
			}

		}else{

			finalizar_ronda(p_task_system_dta);
			return;

		}
	}else{

		//avanzo al turno del otro jugador
		p_task_system_dta->turno = !p_task_system_dta->turno;
		return;
	}


}


static void finalizar_ronda(task_system_dta_t *p_task_system_dta){
	int8_t manos_ganadasJ1 = p_task_system_dta->manos_ganadasJ1;
	int8_t manos_ganadasJ2 = p_task_system_dta->manos_ganadasJ2;

	if(manos_ganadasJ1 > manos_ganadasJ2){ //ganó J1

		p_task_system_dta->puntosJ1 += p_task_system_dta->puntos_TRU; //sumo puntos

	}else if(manos_ganadasJ1 < manos_ganadasJ2){ //ganó 2

		p_task_system_dta->puntosJ2 += p_task_system_dta->puntos_TRU; //sumo puntos

	}else{ //empate

		if(p_task_system_dta->jugador_mano == J1){
			p_task_system_dta->puntosJ1 += p_task_system_dta->puntos_TRU; //sumo puntos
		}else{
			p_task_system_dta->puntosJ2 += p_task_system_dta->puntos_TRU; //sumo puntos
		}
	}

	//reseteo los parámetros
	p_task_system_dta->state = ST_SYS_RONDA;
	p_task_system_dta->mano = ST_SYS_M1;
	p_task_system_dta->jugador_mano = !p_task_system_dta->jugador_mano; //con esto, si J1 era la mano de la ronda, ahora pasa a ser J2 y viceversa
	if(p_task_system_dta->jugador_mano == J1){
		p_task_system_dta->turno = ST_SYS_TJ1;
	}else{
		p_task_system_dta->turno = ST_SYS_TJ2;
	}

	p_task_system_dta->nCartas = 0;

	p_task_system_dta->manos_ganadasJ1 = 0;
	p_task_system_dta->manos_ganadasJ2 = 0;

	p_task_system_dta->jugador_truco = NINGUNO;
	p_task_system_dta->puntos_TRU = 1;

	p_task_system_dta->jugador_envido = NINGUNO;
	p_task_system_dta->puntos_ENV = 0;
	p_task_system_dta->puntos_ENV_NQ = 0;
}
static uint8_t calcularFE(uint8_t puntosJ1,uint8_t puntosJ2,jugador_enum_t ganador){

	if(ganador == J1){
		if(puntosJ2<15){
			return 15-puntosJ2;
		}
		else{
			return 30-puntosJ2;
		}
	}
	else{
		if(puntosJ1<15){
			return 15-puntosJ1;
		}
		else{
			return 30-puntosJ1;
		}
	}
}
/********************** end of file ******************************************/
