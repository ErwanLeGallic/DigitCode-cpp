/*
 * user.cpp
 *
 *  Created on: Oct 21, 2024
 *      Author: Acer Nitro RTX
 */

#include "main.h"
#include "main.hpp"
#include <stdio.h>
#include "stm32l1xx_it.h"
#include "stm32l1xx_hal.h"
#include <string.h>
#include "user.hpp"
#include "afficheur.hpp"
#include "Display/max7219_Yncrea2.hpp"

Afficheur::Afficheur(uint32_t MyDelay) {
}


void Afficheur::code_bon(uint32_t MyDelay) {

	MAX7219_Clear();
	HAL_Delay(100);
	MAX7219_DisplayChar(4, 'C');
	uint32_t startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(3, 'C');
	MAX7219_DisplayChar(4, 'O');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(2, 'C');
	MAX7219_DisplayChar(3, 'O');
	MAX7219_DisplayChar(4, 'D');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'C');
	MAX7219_DisplayChar(2, 'O');
	MAX7219_DisplayChar(3, 'D');
	MAX7219_DisplayChar(4, 'E');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'O');
	MAX7219_DisplayChar(2, 'D');
	MAX7219_DisplayChar(3, 'E');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'D');
	MAX7219_DisplayChar(2, 'E');
	MAX7219_DisplayChar(4, 'B');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'E');
	MAX7219_DisplayChar(3, 'B');
	MAX7219_DisplayChar(4, 'O');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(2, 'B');
	MAX7219_DisplayChar(3, 'O');
	MAX7219_DisplayChar(4, 'N');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'B');
	MAX7219_DisplayChar(2, 'O');
	MAX7219_DisplayChar(3, 'N');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'O');
	MAX7219_DisplayChar(2, 'N');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'N');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}
  	MAX7219_Clear();
}
/*
 void aff_message(const char* mot, uint32_t MyDelay) {
 size_t len_mot = strlen(mot);
 for (size_t i = 0; i < len_mot; i++) {
 char lettre = mot[i];
 if (lettre == ' ') {
 MAX7219_Clear();
 HAL_Delay(MyDelay);
 } else {
 MAX7219_Clear();
 MAX7219_DisplayChar(4, lettre); // Utilisation d'une position fixe ici
 HAL_Delay(MyDelay);
 }
 }
 }

 */

void Afficheur::ask_code(uint32_t MyDelay) {

	MAX7219_Clear();
	HAL_Delay(100);
	MAX7219_DisplayChar(4, 'E');
	uint32_t startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(3, 'E');
	MAX7219_DisplayChar(4, 'N');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(2, 'E');
	MAX7219_DisplayChar(3, 'N');
	MAX7219_DisplayChar(4, 'T');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'E');
	MAX7219_DisplayChar(2, 'N');
	MAX7219_DisplayChar(3, 'T');
	MAX7219_DisplayChar(4, 'R');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'N');
	MAX7219_DisplayChar(2, 'T');
	MAX7219_DisplayChar(3, 'R');
	MAX7219_DisplayChar(4, 'E');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'T');
	MAX7219_DisplayChar(2, 'R');
	MAX7219_DisplayChar(3, 'E');
	MAX7219_DisplayChar(4, 'R');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'R');
	MAX7219_DisplayChar(2, 'E');
	MAX7219_DisplayChar(3, 'R');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'E');
	MAX7219_DisplayChar(2, 'R');
	MAX7219_DisplayChar(4, 'C');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'R');
	MAX7219_DisplayChar(3, 'C');
	MAX7219_DisplayChar(4, 'O');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(2, 'C');
	MAX7219_DisplayChar(3, 'O');
	MAX7219_DisplayChar(4, 'D');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'C');
	MAX7219_DisplayChar(2, 'O');
	MAX7219_DisplayChar(3, 'D');
	MAX7219_DisplayChar(4, 'E');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'O');
	MAX7219_DisplayChar(2, 'D');
	MAX7219_DisplayChar(3, 'E');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'D');
	MAX7219_DisplayChar(2, 'E');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'E');
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}

	MAX7219_Clear();
  	startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}
}

void Afficheur::code_faux(uint32_t MyDelay) {
	MAX7219_Clear();
	uint32_t startTick = HAL_GetTick();
  	while ((HAL_GetTick() - startTick) < MyDelay) {}
	MAX7219_DisplayChar(1, 'N');
	MAX7219_DisplayChar(2, 'O');
	MAX7219_DisplayChar(3, 'N');
}

//destructeur
Afficheur::~Afficheur() {
}

