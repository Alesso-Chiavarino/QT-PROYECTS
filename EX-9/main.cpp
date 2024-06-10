#include <QCoreApplication>
#include <iostream>

// Función genérica para imprimir los valores de un array ordenados
template <typename T>
void imprimir(T *v, int cantidad, bool mayor_a_menor) {
    // Ordenamiento por inserción
    for (int i = 1; i < cantidad; ++i) {
        T valor_actual = v[i];
        int j = i - 1;
        while (j >= 0 && ((mayor_a_menor && v[j] < valor_actual) || (!mayor_a_menor && v[j] > valor_actual))) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = valor_actual;
    }

    // Imprimir los valores ordenados
    if (mayor_a_menor) {
        std::cout << "Valores ordenados de mayor a menor: ";
        for (int i = 0; i < cantidad; ++i) {
            std::cout << v[i] << " ";
        }
    } else {
        std::cout << "Valores ordenados de menor a mayor: ";
        for (int i = cantidad - 1; i >= 0; --i) {
            std::cout << v[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Array de tipo int
    int intArray[] = {5, 2, 9, 1, 7};
    int intCantidad = sizeof(intArray) / sizeof(int);

    // Array de tipo float
    float floatArray[] = {3.5f, 1.2f, 9.8f, 2.7f, 5.4f};
    int floatCantidad = sizeof(floatArray) / sizeof(float);

    // Imprimir los valores del array de tipo int ordenados de mayor a menor
    imprimir(intArray, intCantidad, true);

    // Imprimir los valores del array de tipo float ordenados de menor a mayor
    imprimir(floatArray, floatCantidad, false);

    return a.exec();
}
