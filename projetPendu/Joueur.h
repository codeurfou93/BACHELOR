#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>

class Joueur {
private:
    int tentativesRestantes;           // Nombre de tentatives restantes
    std::vector<char> lettresRatees;   // Lettres essayées

public:
    Joueur(int tentatives);
    void proposerLettre(char lettre);
    void afficherErreurs() const;
    bool aDejaEssayé(char lettre) const;
    void decrementerTentatives();
    int getTentativesRestantes() const;
    void setTentatives(int tentatives); // Permet de modifier les tentatives restantes
};

#endif
