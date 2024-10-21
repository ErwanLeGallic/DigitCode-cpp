#include "Peripherique.hpp"
#include "main.hpp"


Peripherique::Peripherique() : state(State::OFF) {}

void Peripherique::Power() {
    if (this->state == State::OFF) {
        this->state = State::ON;
        std::cout << "Périphérique allumé." << std::endl;
    } else {
        this->state = State::OFF;
        std::cout << "Périphérique éteint." << std::endl;
    }
}

void Peripherique::SetState(State newState) {
    this->state = newState;
}

State Peripherique::Peripherique::GetState() {
    return this->state;
}
