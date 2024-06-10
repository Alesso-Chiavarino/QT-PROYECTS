#include <QCoreApplication>
#include <iostream>
#include <string>
#include <sstream>

// Clase Persona
class Persona {
public:
    Persona(const std::string& nombre) : nombre(nombre) {}

    std::string getDescription() const {
        std::ostringstream oss;
        oss << "Persona con nombre " << nombre;
        return oss.str();
    }

private:
    std::string nombre;
};

// Clase Poste
class Poste {
public:
    Poste(double altura, double diametro) : altura(altura), diametro(diametro) {}

    std::string getDescription() const {
        std::ostringstream oss;
        oss << "Poste con altura de " << altura << " metros y " << diametro << " cm de diámetro";
        return oss.str();
    }

private:
    double altura;
    double diametro;
};

// Función genérica para imprimir la descripción
template <typename T>
void imprimirDescripcion(const T& objeto) {
    std::cout << objeto.getDescription() << std::endl;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear objetos de la clase Persona
    Persona persona1("Lucrecia");
    Persona persona2("Miguel");

    // Crear objetos de la clase Poste
    Poste poste1(8.0, 15.0);
    Poste poste2(10.0, 20.0);

    // Imprimir las descripciones
    imprimirDescripcion(persona1);
    imprimirDescripcion(persona2);
    imprimirDescripcion(poste1);
    imprimirDescripcion(poste2);

    return a.exec();
}
