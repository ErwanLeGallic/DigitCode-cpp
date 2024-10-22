/*
 * main_cpp.cpp
 *
 *  Created on: Oct 16, 2024
 *      Author: mathi
 */

#include <max7219_Yncrea2.hpp>
#include "afficheur.hpp"
#include "user.hpp"
#include "main.hpp"
#include <stdio.h>
#include "stm32l1xx_it.h"
#include "stm32l1xx_hal.h"
#include <string.h>
#include <stdint.h>

#include "Moteur.hpp"
#include "Buzzer.hpp"

extern TIM_HandleTypeDef htim3;
extern const char *buzzer_partition[];
extern const size_t buzzer_partition_size;
extern TypeDef_Note notes[];
extern const size_t notes_size;

extern int flag_btn;
extern int btn_trig;



void main_cpp(void){
	uint32_t startTick = HAL_GetTick();

    // creation objet user host et root
    int zero_code[4] = {0, 0, 0, 0};
    User root(zero_code);
    User host(zero_code);

    // creation objet buzzer, moteur
    Buzzer buzzer;
    Moteur moteur;

    // init afficheur
    Afficheur afficheur(500);
  	MAX7219_Init();
  	MAX7219_DisplayTestStart();
  	//HAL_Delay(2000);
  	while ((HAL_GetTick() - startTick) < 2000) {}

  	MAX7219_DisplayTestStop();
  	MAX7219_Clear();

  	// init buzzer et moteur
	buzzer.SetState(ON);
	moteur.SetState(ON);
	htim3.Instance->ARR = 1024;

    afficheur.ask_code(500);
    strcpy(root.final_code, root.code());
    printf("root code : %c%c%c%c \r\n", root.final_code[0], root.final_code[1], root.final_code[2], root.final_code[3]);

    afficheur.ask_code(500);
    strcpy(host.final_code, host.code());
    printf("user code : %c%c%c%c \r\n", host.final_code[0], host.final_code[1], host.final_code[2], host.final_code[3]);

  	while ((HAL_GetTick() - startTick) < 3000) {}

    if (strcmp(root.final_code, host.final_code) == 0) {
    	 afficheur.code_bon(500);
 		 buzzer.Power();

    } else {
    	 afficheur.code_faux(500);
    	 moteur.Power();

    }

    while(1) {

    }
}



