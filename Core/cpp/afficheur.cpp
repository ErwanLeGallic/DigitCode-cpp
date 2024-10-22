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

Afficheur::Afficheur(int MyDelay) {
}

void Afficheur::code_bon(int MyDelay) {
	MAX7219_Clear();
	HAL_Delay(100);
	MAX7219_DisplayChar(4, 'C');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(3, 'C');
	MAX7219_DisplayChar(4, 'O');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(2, 'C');
	MAX7219_DisplayChar(3, 'O');
	MAX7219_DisplayChar(4, 'D');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'C');
	MAX7219_DisplayChar(2, 'O');
	MAX7219_DisplayChar(3, 'D');
	MAX7219_DisplayChar(4, 'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'O');
	MAX7219_DisplayChar(2, 'D');
	MAX7219_DisplayChar(3, 'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'D');
	MAX7219_DisplayChar(2, 'E');
	MAX7219_DisplayChar(4, 'B');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'E');
	MAX7219_DisplayChar(3, 'B');
	MAX7219_DisplayChar(4, 'O');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(2, 'B');
	MAX7219_DisplayChar(3, 'O');
	MAX7219_DisplayChar(4, 'N');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'B');
	MAX7219_DisplayChar(2, 'O');
	MAX7219_DisplayChar(3, 'N');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'O');
	MAX7219_DisplayChar(2, 'N');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'N');
	HAL_Delay(MyDelay);
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

void Afficheur::ask_code(int MyDelay) {
	MAX7219_Clear();
	HAL_Delay(100);
	MAX7219_DisplayChar(4, 'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(3, 'E');
	MAX7219_DisplayChar(4, 'N');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(2, 'E');
	MAX7219_DisplayChar(3, 'N');
	MAX7219_DisplayChar(4, 'T');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'E');
	MAX7219_DisplayChar(2, 'N');
	MAX7219_DisplayChar(3, 'T');
	MAX7219_DisplayChar(4, 'R');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'N');
	MAX7219_DisplayChar(2, 'T');
	MAX7219_DisplayChar(3, 'R');
	MAX7219_DisplayChar(4, 'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'T');
	MAX7219_DisplayChar(2, 'R');
	MAX7219_DisplayChar(3, 'E');
	MAX7219_DisplayChar(4, 'R');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'R');
	MAX7219_DisplayChar(2, 'E');
	MAX7219_DisplayChar(3, 'R');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'E');
	MAX7219_DisplayChar(2, 'R');
	MAX7219_DisplayChar(4, 'C');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'R');
	MAX7219_DisplayChar(3, 'C');
	MAX7219_DisplayChar(4, 'O');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(2, 'C');
	MAX7219_DisplayChar(3, 'O');
	MAX7219_DisplayChar(4, 'D');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'C');
	MAX7219_DisplayChar(2, 'O');
	MAX7219_DisplayChar(3, 'D');
	MAX7219_DisplayChar(4, 'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'O');
	MAX7219_DisplayChar(2, 'D');
	MAX7219_DisplayChar(3, 'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'D');
	MAX7219_DisplayChar(2, 'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	MAX7219_DisplayChar(1, 'E');
	HAL_Delay(MyDelay);

	MAX7219_Clear();
	HAL_Delay(MyDelay);

}

void Afficheur::code_faux(int MyDelay) {
	MAX7219_Clear();
	HAL_Delay(MyDelay);
	MAX7219_DisplayChar(1, 'N');
	MAX7219_DisplayChar(2, 'O');
	MAX7219_DisplayChar(3, 'N');
}

//destructeur
Afficheur::~Afficheur() {
}

