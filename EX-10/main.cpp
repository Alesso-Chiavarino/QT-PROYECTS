#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "jugador.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear un vector de Jugadores
    std::vector<Jugador> jugadores;

    // Insertar 10 jugadores distintos
    for (int i = 1; i <= 10; ++i) {
        Jugador jugador;
        jugador.setNombre("Jugador" + std::to_string(i));
        jugador.setVelocidad(i * 2);
        jugador.setFuerza(i * 3);
        jugadores.push_back(jugador);
    }

    // Publicar los datos de cada jugador
    for (const auto& jugador : jugadores) {
        std::cout << "Nombre: " << jugador.getNombre() << ", Velocidad: " << jugador.getVelocidad() << ", Fuerza: " << jugador.getFuerza() << std::endl;
    }

    return a.exec();
}
