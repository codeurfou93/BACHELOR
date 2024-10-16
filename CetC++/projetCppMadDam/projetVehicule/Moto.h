#ifndef MOTO_H
#define MOTO_H

#include "Vehicule.h"

class Moto : public Vehicule {
private:
    std::string typeMoteur;

public:
    Moto(std::string marque, std::string modele, int annee, std::string typeMoteur);
    void afficherInfo() const override;
};

#endif
