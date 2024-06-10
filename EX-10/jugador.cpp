#include "jugador.h"
#include <iostream>

// Constructor
Jugador::Jugador() : velocidad(0), fuerza(0), nombre("sin nombre") {}

// Destructor
Jugador::~Jugador() {
    std::cout << "Jugador " << nombre << " eliminado" << std::endl;
}

// Setters
void Jugador::setVelocidad(int velocidad) {
    this->velocidad = velocidad;
}

void Jugador::setFuerza(int fuerza) {
    this->fuerza = fuerza;
}

void Jugador::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

// Getters
int Jugador::getVelocidad() const {
    return velocidad;
}

int Jugador::getFuerza() const {
    return fuerza;
}

std::string Jugador::getNombre() const {
    return nombre;
}
