#include <iostream>
#include <vector>
#include <memory>

class Instrumento {
public:
    virtual void sonar() const = 0;
    virtual void verMarca() const {
        std::cout << "Marca: Yamaha" << std::endl;
    }
};

class Guitarra : public Instrumento {
private:
    int cuerdas;

public:
    Guitarra(int _cuerdas = 6) : cuerdas(_cuerdas) {}

    void sonar() const override {
        std::cout << "Guitarra suena..." << std::endl;
    }

    void verMarca() const override {
        Instrumento::verMarca();
    }

    int getCuerdas() const {
        return cuerdas;
    }

    void setCuerdas(int _cuerdas) {
        cuerdas = _cuerdas;
    }
};

class Bateria : public Instrumento {
private:
    int tambores;

public:
    Bateria(int _tambores = 5) : tambores(_tambores) {}

    void sonar() const override {
        std::cout << "Bateria suena..." << std::endl;
    }

    void verMarca() const override {
        Instrumento::verMarca();
    }

    int getTambores() const {
        return tambores;
    }

    void setTambores(int _tambores) {
        tambores = _tambores;
    }
};

class Teclado : public Instrumento {
private:
    int teclas;

public:
    Teclado(int _teclas = 61) : teclas(_teclas) {}

    void sonar() const override {
        std::cout << "Teclado suena..." << std::endl;
    }

    void verMarca() const override {
        Instrumento::verMarca();
    }

    int getTeclas() const {
        return teclas;
    }

    void setTeclas(int _teclas) {
        teclas = _teclas;
    }
};

class Electrico {
public:
    ~Electrico() {
        std::cout << "Desenchufado" << std::endl;
    }
};

class TecladoElectrico : public Teclado, public Electrico {
public:
    TecladoElectrico(int _teclas = 61) : Teclado(_teclas) {}
};

int main() {
    std::vector<std::unique_ptr<Instrumento>> instrumentos;
    instrumentos.push_back(std::make_unique<Guitarra>());
    instrumentos.push_back(std::make_unique<Bateria>());
    instrumentos.push_back(std::make_unique<TecladoElectrico>());

    for (const auto& inst : instrumentos) {
        inst->verMarca();
    }

    return 0;
}
