#include "Peripherique.hpp"
#include "main.hpp"


Peripherique::Peripherique() : state(State::OFF) {}

void Peripherique::Power() {
    if (state == State::OFF) {
        state = State::ON;
        std::cout << "Périphérique allumé." << std::endl;
    } else {
        state = State::OFF;
        std::cout << "Périphérique éteint." << std::endl;
    }
}

void Peripherique::SetState(State newState) {
    state = newState;
    std::cout << "État du périphérique défini sur : "
              << (state == State::ON ? "ON" : "OFF")
              << std::endl;
}

Peripherique::State Peripherique::GetState() const {
    return state;
}
