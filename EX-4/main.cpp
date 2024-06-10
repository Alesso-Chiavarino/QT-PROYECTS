#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>

// Función para generar números aleatorios en el rango [1, 15]
int generateRandomNumber() {
    return 1 + std::rand() % 15;
}

// Función para encontrar la moda de un vector de enteros
int findMode(const std::vector<int>& numbers) {
    std::map<int, int> frequencyMap;

    // Contar las frecuencias de cada número
    for (int number : numbers) {
        frequencyMap[number]++;
    }

    // Encontrar el número con la frecuencia máxima
    int mode = numbers[0];
    int maxCount = 0;

    for (const auto& pair : frequencyMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mode = pair.first;
        }
    }

    return mode;
}

int main() {
    std::srand(std::time(nullptr)); // Inicializar el generador de números aleatorios

    std::vector<int> numbers(30);

    // Cargar el vector con 30 valores pseudoaleatorios entre 1 y 15
    std::generate(numbers.begin(), numbers.end(), generateRandomNumber);

    // Mostrar los números generados
    std::cout << "Números generados: ";
    for (int number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Encontrar y mostrar la moda
    int mode = findMode(numbers);
    std::cout << "La moda es: " << mode << std::endl;

    return 0;
}
