#ifndef MOTEUR_HPP
#define MOTEUR_HPP

#include "Peripherique.hpp"
#include <stdint.h>
#include "stm32l1xx_hal.h"
#include <cstddef> // Pour size_t
#include <cstring> // Pour strcmp


class Moteur : public Peripherique {
public:

    Moteur();
    void Power() override;
    void SetState(State state);
private:
    TIM_HandleTypeDef *htim;
};

#endif // MOTEUR_HPP
