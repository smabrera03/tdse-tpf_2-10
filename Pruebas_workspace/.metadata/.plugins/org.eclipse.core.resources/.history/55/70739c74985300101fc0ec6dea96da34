/*
 * Copyright (c) 2023 Juan Manuel Cruz <jcruz@fi.uba.ar>.
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
 * @file   : board.h
 * @date   : Set 26, 2023
 * @author : Juan Manuel Cruz <jcruz@fi.uba.ar> <jcruz@frba.utn.edu.ar>
 * @version	v1.0.0
 */

#ifndef BOARD_INC_BOARD_H_
#define BOARD_INC_BOARD_H_

/********************** CPP guard ********************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************** inclusions *******************************************/

/********************** macros ***********************************************/
#define NUCLEO_F103RC		(0)
#define NUCLEO_F401RE		(1)
#define NUCLEO_F446RE		(2)
#define NUCLEO_F429ZI		(3)
#define NUCLEO_F439ZI		(4)
#define NUCLEO_F413ZH		(5)
#define STM32F429I_DISCO1	(6)

#define BOARD (NUCLEO_F103RC)

/* STM32 Nucleo Boards - 64 Pins */
#if ((BOARD == NUCLEO_F103RC) || (BOARD == NUCLEO_F401RE) || (BOARD == NUCLEO_F446RE))

#define BTN_A_PIN		B1_Pin
#define BTN_A_PORT		B1_GPIO_Port
#define BTN_A_PRESSED	GPIO_PIN_RESET
#define BTN_A_HOVER		GPIO_PIN_SET

//BTN SUMA
#define BTN_SUMA_PIN		BTN_SUMA_Pin
#define BTN_SUMA_PORT		BTN_SUMA_GPIO_Port
#define BTN_SUMA_PRESSED	GPIO_PIN_SET
#define BTN_SUMA_HOVER		GPIO_PIN_RESET

//BTN RESTA
#define BTN_RESTA_PIN		BTN_RESTA_Pin
#define BTN_RESTA_PORT		BTN_RESTA_GPIO_Port
#define BTN_RESTA_PRESSED	GPIO_PIN_SET
#define BTN_RESTA_HOVER		GPIO_PIN_RESET

//LED_A, led integrada a la placa
#define LED_A_PIN		LD2_Pin
#define LED_A_PORT		LD2_GPIO_Port
#define LED_A_ON		GPIO_PIN_SET
#define LED_A_OFF		GPIO_PIN_RESET

//LED8
#define LED8_PIN		LED8_Pin
#define LED8_PORT		LED8_GPIO_Port
#define LED8_ON		    GPIO_PIN_SET
#define LED8_OFF		GPIO_PIN_RESET

//LED4
#define LED4_PIN		LED4_Pin
#define LED4_PORT		LED4_GPIO_Port
#define LED4_ON		    GPIO_PIN_SET
#define LED4_OFF		GPIO_PIN_RESET

//LED2
#define LED2_PIN		LED2_Pin
#define LED2_PORT		LED2_GPIO_Port
#define LED2_ON		    GPIO_PIN_SET
#define LED2_OFF		GPIO_PIN_RESET

//LED1
#define LED1_PIN		LED1_Pin
#define LED1_PORT		LED1_GPIO_Port
#define LED1_ON		    GPIO_PIN_SET
#define LED1_OFF		GPIO_PIN_RESET
#endif/* STM32 Nucleo Boards - 144 Pins */

#if ((BOARD == NUCLEO_F429ZI) || (BOARD == NUCLEO_F439ZI) || (BOARD == NUCLEO_F413ZH))

#define BTN_A_PIN		USER_Btn_Pin
#define BTN_A_PORT		USER_Btn_GPIO_Port
#define BTN_A_PRESSED	GPIO_PIN_SET
#define BTN_A_HOVER		GPIO_PIN_RESET

#define LED_A_PIN		LD1_Pin
#define LED_A_PORT		LD1_GPIO_Port
#define LED_A_ON		GPIO_PIN_SET
#define LED_A_OFF		GPIO_PIN_RESET

#endif

/* STM32 Discovery Kits */
#if (BOARD == STM32F429I_DISCO1)

#define BTN_A_PIN		B1_Pin
#define BTN_A_PORT		B1_GPIO_Port
#define BTN_A_PRESSED	GPIO_PIN_SET
#define BTN_A_HOVER		GPIO_PIN_RESET

#define LED_A_PIN		LD3_Pin
#define LED_A_PORT		LD3_GPIO_Port
#define LED_A_ON		GPIO_PIN_SET
#define LED_A_OFF		GPIO_PIN_RESET

#endif

/********************** typedef **********************************************/

/********************** external data declaration ****************************/

/********************** external functions declaration ***********************/

/********************** End of CPP guard *************************************/
#ifdef __cplusplus
}
#endif

#endif /* BOARD_INC_BOARD_H_ */

/********************** end of file ******************************************/
