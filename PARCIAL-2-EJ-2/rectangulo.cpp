#include "rectangulo.h"

Rectangulo::Rectangulo(int x, int y, int ancho, int alto)
    : x(x), y(y), ancho(ancho), alto(alto) {}

int Rectangulo::getX() const { return x; }
int Rectangulo::getY() const { return y; }
int Rectangulo::getAncho() const { return ancho; }
int Rectangulo::getAlto() const { return alto; }
