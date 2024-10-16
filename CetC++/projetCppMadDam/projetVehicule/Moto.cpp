#include "Moto.h"
#include <iostream>

Moto::Moto(std::string marque, std::string modele, int annee, std::string typeMoteur)
    : Vehicule(marque, modele, annee), typeMoteur(typeMoteur) {}

void Moto::afficherInfo() const {
    Vehicule::afficherInfo();
    std::cout << "Type de moteur: " << typeMoteur << std::endl;
}
