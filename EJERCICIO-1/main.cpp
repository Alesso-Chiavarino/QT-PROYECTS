#include <QCoreApplication>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Inicializar el generador de números aleatorios
    std::srand(std::time(nullptr));

    std::cout << "10 números aleatorios en el intervalo [2, 20]:\n";
    for (int i = 0; i < 10; ++i) {
        int random_number = 2 + std::rand() % 19;
        std::cout << random_number << " ";
    }
    std::cout << std::endl;

    return a.exec();
}
