#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>

class Jugador {
public:
    // Constructor
    Jugador();

    // Destructor
    ~Jugador();

    // Setters
    void setVelocidad(int velocidad);
    void setFuerza(int fuerza);
    void setNombre(const std::string& nombre);

    // Getters
    int getVelocidad() const;
    int getFuerza() const;
    std::string getNombre() const;

private:
    int velocidad;
    int fuerza;
    std::string nombre;
};

#endif // JUGADOR_H
