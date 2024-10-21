/*
 * main_cpp.cpp
 *
 *  Created on: Oct 16, 2024
 *      Author: mathi
 */
#include "main.hpp"
#include "Moteur.hpp"
#include "Buzzer.hpp"
#include "stm32l1xx_hal.h"
Buzzer buzzer;
Moteur moteur;
extern TIM_HandleTypeDef htim3;
extern const char *buzzer_partition[];
extern const size_t buzzer_partition_size;
extern TypeDef_Note notes[];
extern const size_t notes_size;

/*void play_buzzer_partition() {
	for (size_t i = 0; i < buzzer_partition_size; ++i) {
		const char *noteName = buzzer_partition[i];

		buzzer_play_note_by_name(&htim3, notes, notes_size, noteName); // Utiliser notes_size ici
		HAL_Delay(500);
	}
}*/

void main_cpp(void) {

	buzzer.SetState(ON);
	moteur.SetState(ON);
	htim3.Instance->ARR = 1024;

	while (1) {

		buzzer.Power();

	}
}

