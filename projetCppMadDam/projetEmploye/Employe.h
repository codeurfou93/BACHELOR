#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <string>

class Employe {
private:
    std::string nom;
    int id;
    double salaireBase;
    std::string departement;

public:
    Employe(std::string nom, int id, double salaireBase, std::string departement);
    void afficherInfo() const;
    double getSalaireBase() const;
    std::string getDepartement() const;
};

#endif
