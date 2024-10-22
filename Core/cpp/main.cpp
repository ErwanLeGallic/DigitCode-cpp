/*
 * main_cpp.cpp
 *
 *  Created on: Oct 16, 2024
 *      Author: mathi
 */
/*
 * main_cpp.cpp
 *
 *  Created on: Oct 16, 2024
 *      Author: mathi
 */
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
extern int flag_btn;
extern int btn_trig;
void main_cpp(void){
    // User C++ code
    int zero_code[4] = {0, 0, 0, 0};
    User root(zero_code);
    User host(zero_code);

    Afficheur afficheur(500);
  	MAX7219_Init();
  	MAX7219_DisplayTestStart();
  	HAL_Delay(2000);
  	MAX7219_DisplayTestStop();
  	MAX7219_Clear();

    afficheur.ask_code(500);
    strcpy(root.final_code, root.code());
    printf("root code : %c%c%c%c \r\n", root.final_code[0], root.final_code[1], root.final_code[2], root.final_code[3]);

    afficheur.ask_code(500);
    strcpy(host.final_code, host.code());
    printf("user code : %c%c%c%c \r\n", host.final_code[0], host.final_code[1], host.final_code[2], host.final_code[3]);

    HAL_Delay(4000);

    if (strcmp(root.final_code, host.final_code) == 0) {
    	 afficheur.code_bon(500);
    } else {
    	 afficheur.code_faux(500);
    }

    while(1) {
    }
}
