#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    // Crear un std::vector para contener objetos de la clase std::string
    std::vector<std::string> idiomaticExpressions;

    // Cargar 5 expresiones idiomáticas
    idiomaticExpressions.push_back("pan comido");
    idiomaticExpressions.push_back("llover a cántaros");
    idiomaticExpressions.push_back("meter la pata");
    idiomaticExpressions.push_back("estar en las nubes");
    idiomaticExpressions.push_back("dormirse en los laureles");

    // Ordenar alfabéticamente las expresiones
    std::sort(idiomaticExpressions.begin(), idiomaticExpressions.end());

    // Publicar por consola las expresiones ordenadas alfabéticamente
    std::cout << "Expresiones idiomáticas ordenadas alfabéticamente:" << std::endl;
    for (const auto& expression : idiomaticExpressions) {
        std::cout << expression << std::endl;
    }

    return 0;
}
