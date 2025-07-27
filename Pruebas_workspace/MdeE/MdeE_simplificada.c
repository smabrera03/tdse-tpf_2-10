/*
 * En este archivo voy a dejar escritas 2 versiones de la máquina de estados. La primera es más larga y legible,
 * pero es muy dificil hacerle modificaciones y debuggear. Es insostenible
 *
 * La segunda es más compacta y un poco más críptica, pero es un mal necesario.
 */


#import "task_system_attribute.h"
#import "task_system_interface.h"

//>>>>>>>>>>>>>>>>>>>BEGIN PRIMERA VERSIÓN<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



static void Maquina_de_estados_M1(task_system_dta_t *p_task_system_dta){
	switch(p_task_system_dta->turno){
		case ST_SYS_TJ1:
			if(p_task_system_dta->event == EV_SYS_CARTA_NUEVA){
				//get_Carta(&p_task_system_dta->cartasJ1[0]); //ilegible
				carta_t *carta_addrs = &(p_task_system_dta->cartasJ1[0]);
				get_Carta(carta_addrs);
				//mejor? Sería mejor que crear una carta local, que la función devuelva la carta y hacer la asignación acá?
				//le estoy dando muchas vueltas. Consultar con los pibes
				p_task_system_dta->nCartas++;
				if(p_task_system_dta->nCartas == 2){
					uint8_t prioridad_cartaJ1 = p_task_system_dta->cartasJ1[0].prioridad;
					uint8_t prioridad_cartaJ2 = p_task_system_dta->cartasJ2[0].prioridad;
					if(prioridad_cartaJ1 > prioridad_cartaJ2){
						//ganó J1
						p_task_system_dta->mano = ST_SYS_M2;
						p_task_system_dta->manos_ganadasJ1++;
						p_task_system_dta->turno = ST_SYS_TJ1;
					}else if(prioridad_cartaJ1 < prioridad_cartaJ2){
						//ganó J2
						p_task_system_dta->mano = ST_SYS_M2;
						p_task_system_dta->manos_ganadasJ2++;
						p_task_system_dta->turno = ST_SYS_TJ2;
					}else{
						//empataron
						p_task_system_dta->mano = ST_SYS_M2;
						p_task_system_dta->turno = ST_SYS_TJ2;
					}
				}else{
					//Pasar a turno de J2
					p_task_system_dta->turno = ST_SYS_TJ2;
				}
			}
			break;
		case ST_SYS_TJ2:
			if(p_task_system_dta->event == EV_SYS_CARTA_NUEVA){
				carta_t *carta_addrs = &(p_task_system_dta->cartasJ2[0]);
				get_Carta(carta_addrs);
				p_task_system_dta->nCartas++;

				if(p_task_system_dta->nCartas == 2){
					//este bloque if es muy parecido al del TJ2 ¿Meterlo en una fucnión? Solo se repite 2 veces
					uint8_t prioridad_cartaJ1 = p_task_system_dta->cartasJ1[0].prioridad;
					uint8_t prioridad_cartaJ2 = p_task_system_dta->cartasJ2[0].prioridad;
					if(prioridad_cartaJ1 > prioridad_cartaJ2){
						//ganó J1
						p_task_system_dta->mano = ST_SYS_M2;
						p_task_system_dta->manos_ganadasJ1++;
						p_task_system_dta->turno = ST_SYS_TJ1;
					}else if(prioridad_cartaJ1 < prioridad_cartaJ2){
						//ganó J2
						p_task_system_dta->mano = ST_SYS_M2;
						p_task_system_dta->manos_ganadasJ2++;
						p_task_system_dta->turno = ST_SYS_TJ2;
					}else{
						//empataron
						p_task_system_dta->mano = ST_SYS_M2;
						p_task_system_dta->turno = ST_SYS_TJ1;
					}
				}else{
					p_task_system_dta->turno = ST_SYS_TJ1;
				}
			}
			break;
		default:
			break;
	}
}

static void Maquina_de_estados_M2(task_system_dta_t *p_task_system_dta){
	switch(p_task_system_dta->turno){
		case ST_SYS_TJ1:
			if(p_task_system_dta->event == EV_SYS_CARTA_NUEVA){
				carta_t *carta_addrs = &(p_task_system_dta->cartasJ1[1]);
				get_Carta(carta_addrs);
				p_task_system_dta->nCartas++;

				if(p_task_system_dta->nCartas == 4){
					uint8_t prioridad_cartaJ1 = p_task_system_dta->cartasJ1[1].prioridad;
					uint8_t prioridad_cartaJ2 = p_task_system_dta->cartasJ2[1].prioridad;
					if(prioridad_cartaJ1 > prioridad_cartaJ2){
						//ganó J1
						p_task_system_dta->manos_ganadasJ1++;
						p_task_system_dta->turno = ST_SYS_TJ1;
					}else if(prioridad_cartaJ1 < prioridad_cartaJ2){
						//ganó J2
						p_task_system_dta->manos_ganadasJ2++;
						p_task_system_dta->turno = ST_SYS_TJ2;
					}else{
						//empataron
						p_task_system_dta->turno = ST_SYS_TJ2;
					}
					if(p_task_system_dta->manos_ganadasJ1 == p_task_system_dta->manos_ganadasJ2){//Si en las 2 primeras manos hay empate, se define en la tercera
						p_task_system_dta->mano = ST_SYS_M3;
					}else{ //hay un ganador
						finalizar_ronda(p_task_system_dta);
					}
				}else{
					p_task_system_dta->turno = ST_SYS_TJ2;
				}
			}
			break;
		case ST_SYS_TJ2:
			if(p_task_system_dta->event == EV_SYS_CARTA_NUEVA){
				carta_t *carta_addrs = &(p_task_system_dta->cartasJ2[1]);
				get_Carta(carta_addrs);
				p_task_system_dta->nCartas++;

				if(p_task_system_dta->nCartas == 4){
					uint8_t prioridad_cartaJ1 = p_task_system_dta->cartasJ1[1].prioridad;
					uint8_t prioridad_cartaJ2 = p_task_system_dta->cartasJ2[1].prioridad;
					if(prioridad_cartaJ1 > prioridad_cartaJ2){
						//ganó J1
						p_task_system_dta->manos_ganadasJ1++;
						p_task_system_dta->turno = ST_SYS_TJ1;
					}else if(prioridad_cartaJ1 < prioridad_cartaJ2){
						//ganó J2
						p_task_system_dta->manos_ganadasJ2++;
						p_task_system_dta->turno = ST_SYS_TJ2;
					}else{
						//empataron
						p_task_system_dta->turno = ST_SYS_TJ1;
					}
					if(p_task_system_dta->manos_ganadasJ1 == p_task_system_dta->manos_ganadasJ2){//Si en las 2 primeras manos hay empate, se define en la tercera
						p_task_system_dta->mano = ST_SYS_M3;
					}else{ //hay un ganador
						finalizar_ronda(p_task_system_dta);
					}
				}else{
					p_task_system_dta->turno = ST_SYS_TJ1;
				}
			}
			break;
		default:
			break;
	}
}

static void Maquina_de_estados_M3(task_system_dta_t *p_task_system_dta){
	switch(p_task_system_dta->turno){
		case ST_SYS_TJ1:
			if(p_task_system_dta->event == EV_SYS_CARTA_NUEVA){
				carta_t *carta_addrs = &(p_task_system_dta->cartasJ1[2]);
				get_Carta(carta_addrs);
				p_task_system_dta->nCartas++;

				if(p_task_system_dta->nCartas == 6){
					uint8_t prioridad_cartaJ1 = p_task_system_dta->cartasJ1[2].prioridad;
					uint8_t prioridad_cartaJ2 = p_task_system_dta->cartasJ2[2].prioridad;
					if(prioridad_cartaJ1 > prioridad_cartaJ2){
						//ganó J1
						p_task_system_dta->manos_ganadasJ1++;
					}else if(prioridad_cartaJ1 < prioridad_cartaJ2){
						//ganó J2
						p_task_system_dta->manos_ganadasJ2++;
					}else{
						//empataron
						//parda tercera gana primera ¿Qué hago acá???? Fijate en las cartas que guardaste
						uint8_t primer_cartaJ1 = p_task_system_dta->cartasJ1[0].prioridad;
						uint8_t primer_cartaJ2 = p_task_system_dta->cartasJ2[0].prioridad;
						if(primer_cartaJ1 > primer_cartaJ2){
							p_task_system_dta->manos_ganadasJ1++;
						}else{
							//empataron las 3 veces. Se resuelve en finalizar_ronda();
						}
					}
					finalizar_ronda(p_task_system_dta);
				}else{
					p_task_system_dta->turno = ST_SYS_TJ2;
				}
			}
			break;
		case ST_SYS_TJ2:
			if(p_task_system_dta->event == EV_SYS_CARTA_NUEVA){
				carta_t *carta_addrs = &(p_task_system_dta->cartasJ2[2]);
				get_Carta(carta_addrs);
				p_task_system_dta->nCartas++;

				if(p_task_system_dta->nCartas == 6){
					uint8_t prioridad_cartaJ1 = p_task_system_dta->cartasJ1[2].prioridad;
					uint8_t prioridad_cartaJ2 = p_task_system_dta->cartasJ2[2].prioridad;
					if(prioridad_cartaJ1 > prioridad_cartaJ2){
						//ganó J1
						p_task_system_dta->manos_ganadasJ1++;
					}else if(prioridad_cartaJ1 < prioridad_cartaJ2){
						//ganó J2
						p_task_system_dta->manos_ganadasJ2++;
					}else{
						uint8_t primer_cartaJ1 = p_task_system_dta->cartasJ1[0].prioridad;
						uint8_t primer_cartaJ2 = p_task_system_dta->cartasJ2[0].prioridad;
						if(primer_cartaJ1 > primer_cartaJ2){
							p_task_system_dta->manos_ganadasJ1++;
						}else{
							//empataron las 3 veces. Se resuelve en finalizar_ronda();
						}
					}
					finalizar_ronda(p_task_system_dta);
				}else{
					p_task_system_dta->turno = ST_SYS_TJ1;
				}
			}
			break;
		default:
			break;
	}
}

static void finalizar_ronda(task_system_dta_t *p_task_system_dta){
	uint8_t manos_ganadasJ1 = p_task_system_dta->manos_ganadasJ1;
	uint8_t manos_ganadasJ2 = p_task_system_dta->manos_ganadasJ2;
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
	p_task_system_dta->jugador_mano = (p_task_system_dta->jugador_mano)%2 + 1; //con esto, si J1 era la mano de la ronda, ahora pasa a ser J2 y viceversa
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



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>END PRIMERA VERSIÓN<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>BEGIN SEGUNDA VERSIÓN<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<



void Maquina_de_estados_ronda(task_system_dta_t *p_task_system_dta){
	task_system_st_t turno = p_task_system_dta->turno; //¿es el turno de quién?
	mano_t mano = p_task_system_dta->mano;//¿Por qué mano vamos?
	task_system_ev_t evento = p_task_system_dta->event; //¿Qué evento se registró?
	if(evento == EV_SYS_CARTA_NUEVA){
		//cargo la carta. ¿A quién? ¿Qué carta?
		carta_t *carta_addrs;
		//elijo la dirección de la carta
		int indice = (int)(p_task_system_dta->nCartas/2); // Si nCartas es 0 ó 1, devuelve 0, tengo que cargar la primer
		//carta. Si es 2 ó 3 devuelve 1, la segunda carta. Si es 4 ó 5 devuelve 2, la tercer carta
		//¿Ilegible?
		if(turno == ST_SYS_TJ1){
			carta_addrs = &(p_task_system_dta->cartasJ1[indice]);
		}else{
			carta_addrs = &(p_task_system_dta->cartasJ2[indice]);
		}
		//esto tal vez sería más fácil con una matriz de carta???? Primera fila J1 y segunda fila J2
		get_Carta(carta_addrs);
		p_task_system_dta->nCartas++;

		//Una vez cargada la carta, avanzo por el statechart
		if(p_task_system_dta->nCartas%2 == 0){
			//cantidad par de cartas, tengo que definir la mano
			uint8_t prioridad_J1 = p_task_system_dta->cartasJ1[indice].prioridad;
			uint8_t prioridad_J2 = p_task_system_dta->cartasJ2[indice].prioridad;

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
				//este bloque ya lo escribí varias veces
				if(turno == ST_SYS_TJ1){
					p_task_system_dta->turno = ST_SYS_TJ2;
				}else{
					p_task_system_dta->turno = ST_SYS_TJ1;
				}
			}
			//ya definida la mano, tengo que avanzar la mano
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
			if(turno == ST_SYS_TJ1){
				p_task_system_dta->turno = ST_SYS_TJ2;
			}else{
				p_task_system_dta->turno = ST_SYS_TJ1;
			}//p_task_system_dta->turno != }//p_task_system_dta->turno si 0 fuera el turno de J1 y 1 fuera el turno de J2
			//si bien no cambia tanto acá, este bloque aparece muchas veces
		}
	}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>END SEGUNDA VERSIÓN<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
