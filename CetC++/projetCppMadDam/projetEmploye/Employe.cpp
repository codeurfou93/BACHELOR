#include "Employe.h"
#include <iostream>

Employe::Employe(std::string nom, int id, double salaireBase, std::string departement)
    : nom(nom), id(id), salaireBase(salaireBase), departement(departement) {}

void Employe::afficherInfo() const {
    std::cout << "Nom: " << nom << "\nID: " << id
              << "\nSalaire de base: " << salaireBase
              << "\nDepartement: " << departement << std::endl;
}

double Employe::getSalaireBase() const {
    return salaireBase;
}

std::string Employe::getDepartement() const {
    return departement;
}
