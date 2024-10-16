#include "Camion.h"
#include <iostream>

Camion::Camion(std::string marque, std::string modele, int annee, double capaciteChargement)
    : Vehicule(marque, modele, annee), capaciteChargement(capaciteChargement) {}

void Camion::afficherInfo() const {
    Vehicule::afficherInfo();
    std::cout << "Capacité de chargement: " << capaciteChargement << " tonnes" << std::endl;
}
