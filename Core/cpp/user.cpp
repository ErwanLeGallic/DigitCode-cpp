/*
 * user.cpp
 *
 *  Created on: Oct 21, 2024
 *      Author: Acer Nitro RTX
 */

#include <max7219_Yncrea2.hpp>
#include "user.hpp"
#include <stdio.h>
#include "stm32l1xx_hal.h"
#include "main.h"

// constructeur
User::User(const int user_code[4]) {
	for (int i = 0; i < 4; i++) {
		this->user_code[i] = user_code[i];
	}
	this->pos = 0;
	//this->btn_trig = 0;
	//this->flag_btn = 0;
}

void User::affiche_1(int pos) {
	MAX7219_DisplayChar(pos, '1');
}

void User::affiche_2(int pos) {
	MAX7219_DisplayChar(pos, '2');
}

void User::affiche_3(int pos) {
	MAX7219_DisplayChar(pos, '3');
}

void User::affiche_4(int pos) {
	MAX7219_DisplayChar(pos, '4');
}
/*
 void User::HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
 if (GPIO_Pin == btn1_Pin) {
 flag_btn = 1;
 btn_trig = 1;
 } else if (GPIO_Pin == btn2_Pin) {
 flag_btn = 2;
 btn_trig = 1;
 } else if (GPIO_Pin == btn3_Pin) {
 flag_btn = 3;
 btn_trig = 1;
 } else if (GPIO_Pin == btn4_Pin) {
 flag_btn = 4;
 btn_trig = 1;
 }
 }
 */
char* User::code() {
	uint32_t startTick = HAL_GetTick();
	while ((HAL_GetTick() - startTick) < 300) {
	}
	while (pos < 4) {
		startTick = HAL_GetTick();
		while ((HAL_GetTick() - startTick) < 100) {
		}
		if (btn_trig == 1) {
			if (flag_btn == 1) {
				user_code[pos] = '1';
				pos++;
				affiche_1(pos);
				btn_trig = 0;
			} else if (flag_btn == 2) {
				user_code[pos] = '2';
				pos++;
				affiche_2(pos);
				btn_trig = 0;
			} else if (flag_btn == 3) {
				user_code[pos] = '3';
				pos++;
				affiche_3(pos);
				btn_trig = 0;
			} else if (flag_btn == 4) {
				user_code[pos] = '4';
				pos++;
				affiche_4(pos);
				btn_trig = 0;
			}
			btn_trig = 0;
			startTick = HAL_GetTick();
			while ((HAL_GetTick() - startTick) < 250) {
			}
		}
	}

	// Copier le code final
	for (uint32_t a = 0; a < 4; a++)
		final_code[a] = user_code[a];
	final_code[4] = '\0';
	pos = 0; // Réinitialiser pour la prochaine utilisation
	return final_code;
}

// Callback pour interruptions

// destructeur
User::~User() {
}
