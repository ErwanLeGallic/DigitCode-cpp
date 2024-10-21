#include "Peripherique.hpp"
#include "main.hpp"


Peripherique::Peripherique() : state(State::OFF) {}

void Peripherique::Power() {

        std::cout << "A override" << std::endl;

}

void Peripherique::SetState(State newState) {
    this->state = newState;
}

State Peripherique::Peripherique::GetState() {
    return this->state;
}
