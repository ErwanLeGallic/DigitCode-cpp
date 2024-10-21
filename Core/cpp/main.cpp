/*
 * main_cpp.cpp
 *
 *  Created on: Oct 16, 2024
 *      Author: mathi
 */
#include "main.hpp"
#include "Buzzer.hpp"
#include "stm32l1xx_hal.h"
Buzzer buzzer;
extern TIM_HandleTypeDef htim3;
extern const char* buzzer_partition[];
extern const size_t buzzer_partition_size;
extern TypeDef_Note notes[];
extern const size_t notes_size;

void play_buzzer_partition(Buzzer& buzzer) {
    for (size_t i = 0; i < buzzer_partition_size; ++i) {
        const char* noteName = buzzer_partition[i];

        // Appeler la fonction pour jouer la note par nom
        buzzer_play_note_by_name(&htim3, notes, notes_size, noteName); // Utiliser notes_size ici

        HAL_Delay(500); // Délai entre les notes
    }
}


void main_cpp(void) {

	buzzer.Power();

	TypeDef_Note test_note = {"G5", 1567.98, 20407}; // Valeur test
	    buzzer_play_note(&htim3, &test_note);
	    HAL_Delay(1000);


	while (1) {
		if (buzzer.GetState() == Buzzer::State::ON) {
				play_buzzer_partition(buzzer);
			} else {
				buzzer_mute(&htim3);
			}
	}
}

