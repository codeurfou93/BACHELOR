#include "Mot.h"
#include <iostream>
#include <algorithm>

Mot::Mot(const std::string& motADeviner) : mot(motADeviner), erreurs(0) {
    lettresDevinees.resize(mot.size(), false);
}

void Mot::revelerLettre(char lettre) {
    for (size_t i = 0; i < mot.size(); ++i) {
        if (mot[i] == lettre) {
            lettresDevinees[i] = true;
        }
    }
}

bool Mot::verifierVictoire() const {
    return std::all_of(lettresDevinees.begin(), lettresDevinees.end(), [](bool devine) { return devine; });
}

void Mot::afficherMot() const {
    for (size_t i = 0; i < mot.size(); ++i) {
        if (lettresDevinees[i]) {
            std::cout << mot[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int Mot::getErreurs() const {
    return erreurs;
}

const std::string& Mot::getMot() const {
    return mot;
}

std::vector<bool>& Mot::getLettresDevinees() {
    return lettresDevinees;
}

void Mot::setMot(const std::string& motADeviner) {
    mot = motADeviner;
    lettresDevinees.resize(mot.size(), false);
}
