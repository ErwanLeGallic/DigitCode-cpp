#ifndef BUZZER_HPP
#define BUZZER_HPP

#include "Peripherique.hpp"
#include <stdint.h>
#include "stm32l1xx_hal.h"
#include <cstddef> // Pour size_t
#include <cstring> // Pour strcmp

typedef struct{
	const char* name;
	double frequency;
	uint16_t ARR;

}TypeDef_Note;
extern TypeDef_Note notes[];
extern const char* buzzer_partition[];
extern TIM_HandleTypeDef htim3;

void buzzer_play_note_by_name(TIM_HandleTypeDef *_htim, TypeDef_Note *_note, size_t _notes_sz, const char* _name);
void buzzer_mute(TIM_HandleTypeDef *_htim);
void buzzer_play_note(TIM_HandleTypeDef *_htim, TypeDef_Note *_note);

extern const size_t notes_size;
extern const size_t buzzer_partition_size;

class Buzzer : public Peripherique {
public:

    Buzzer();
    void Power() override;
    void SetState(State state);
private:
    TIM_HandleTypeDef *htim;
};

#endif // BUZZER_HPP
