#include "Buzzer.hpp"
#include "main.hpp"
#include <cstring>

#define MUTE "-"
Buzzer::Buzzer() :
		Peripherique() {
}

TypeDef_Note notes[] = { { "C5", 1046.50, 30578 }, { "C#5", 1108.73, 28860 }, {
		"D5", 1174.66, 27240 }, { "Eb5", 1244.51, 25711 }, { "E5", 1318.51,
		24268 }, { "F5", 1396.91, 22906 }, { "F#5", 1479.98, 21620 }, { "G5",
		1567.98, 20407 }, { "G#5", 1661.22, 19261 }, { "A5", 1760.00, 18180 }, {
		"A#5", 1864.66, 17160 }, { "B5", 1975.53, 16221 } };

const char *buzzer_partition[] = { "G5", MUTE, "G5", MUTE, "G5", MUTE, "A5",
		MUTE, "B5", "B5", "B5", "B5", "A5", "A5", "A5", "A5", "G5", MUTE, "B5",
		MUTE, "A5", MUTE, "A5", MUTE, "G5", "G5", "G5", "G5", MUTE };
const size_t notes_size = sizeof(notes) / sizeof(notes[0]);
extern TIM_HandleTypeDef htim3;
const size_t buzzer_partition_size = sizeof(buzzer_partition)
		/ sizeof(buzzer_partition[0]);

void Buzzer::Power() {
	if (this->state == ON) {

		play_buzzer_partition();

	} else {

		buzzer_mute(&htim3);
	}
}

void Buzzer::SetState(State newState) {
	this->state = newState;

}

void buzzer_mute(TIM_HandleTypeDef *_htim) {
	if (_htim == NULL) {
		return;
	}
	_htim->Instance->CCR2 = 0;
	_htim->Instance->ARR = 0;

}

void buzzer_play_note(TIM_HandleTypeDef *_htim, TypeDef_Note *_note) {
	if (_htim == NULL || _note == NULL) {
		return;
	}
	_htim->Instance->CCR2 = 6400;
	_htim->Instance->ARR = _note->ARR;
}

void buzzer_play_note_by_name(TIM_HandleTypeDef *_htim, TypeDef_Note *_notes,
		size_t _notes_sz, const char *_name) {
	for (int j = 0; j < sizeof(buzzer_partition) / sizeof(buzzer_partition[0]);
			j++) {
		if (strcmp(_name, buzzer_partition[j]) == 0) {
			if (strcmp(_name, MUTE) != 0) {
				// Trouver la correspondance avec la note et la jouer
				for (int k = 0; k < _notes_sz; k++) {
					if (strcmp(_notes[k].name, _name) == 0) {
						buzzer_play_note(_htim, &_notes[k]);
						break; // Sortir après avoir joué la note
					}
				}
			} else {
				buzzer_mute(_htim);
			}
		}
	}
}

void play_buzzer_partition() {
	for (size_t i = 0; i < buzzer_partition_size; ++i) {
		const char *noteName = buzzer_partition[i];

		buzzer_play_note_by_name(&htim3, notes, notes_size, noteName); // Utiliser notes_size ici
		HAL_Delay(500);
	}
}

