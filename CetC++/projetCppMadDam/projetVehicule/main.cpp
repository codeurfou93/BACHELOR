#include "Voiture.h"
#include "Camion.h"
#include "Moto.h"
#include <iostream>

int main() {
    Voiture v1("Toyota", "Corolla", 2020, 4);
    Camion c1("Mercedes", "Actros", 2018, 18.5);
    Moto m1("Harley-Davidson", "Iron 883", 2021, "V-Twin");

    v1.afficherInfo();
    std::cout << "-------------------" << std::endl;

    c1.afficherInfo();
    std::cout << "-------------------" << std::endl;

    m1.afficherInfo();

    return 0;
}
