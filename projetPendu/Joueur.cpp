#include "Joueur.h"
#include <iostream>
#include <algorithm>

Joueur::Joueur(int tentatives) : tentativesRestantes(tentatives) {}

void Joueur::proposerLettre(char lettre) {
    lettresRatees.push_back(lettre);
}

void Joueur::afficherErreurs() const {
    std::cout << "Lettres erronées : ";
    for (char lettre : lettresRatees) {
        std::cout << lettre << " ";
    }
    std::cout << std::endl;
}

bool Joueur::aDejaEssayé(char lettre) const {
    return std::find(lettresRatees.begin(), lettresRatees.end(), lettre) != lettresRatees.end();
}

void Joueur::decrementerTentatives() {
    --tentativesRestantes;
}

int Joueur::getTentativesRestantes() const {
    return tentativesRestantes;
}

void Joueur::setTentatives(int tentatives) {
    tentativesRestantes = tentatives;
}
