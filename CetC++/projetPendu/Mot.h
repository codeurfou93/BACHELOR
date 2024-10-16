#ifndef MOT_H
#define MOT_H

#include <string>
#include <vector>

class Mot {
private:
    std::string mot;                    // Mot à deviner
    std::vector<bool> lettresDevinees;  // Lettres devinées
    int erreurs;                        // Nombre d'erreurs

public:
    Mot(const std::string& motADeviner);
    void revelerLettre(char lettre);
    bool verifierVictoire() const;
    void afficherMot() const;
    int getErreurs() const;
    const std::string& getMot() const;
    std::vector<bool>& getLettresDevinees(); // Accès aux lettres devinées
    void setMot(const std::string& motADeviner); // Permet de modifier le mot
};

#endif
