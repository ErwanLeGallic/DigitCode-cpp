#include "Buzzer.hpp"
#include "Moteur.hpp"
#include "main.hpp"
#include <cstring>

#define MUTE "-"
Moteur::Moteur() :
		Peripherique() {
}

extern TIM_HandleTypeDef htim3;

void Moteur::Power() {
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	TIM3->CCR1 = 100 * (TIM3->ARR + 1) / 100;

}

void Moteur::SetState(State newState) {
	this->state = newState;
}

