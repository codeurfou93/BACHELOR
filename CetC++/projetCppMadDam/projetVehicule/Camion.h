#ifndef CAMION_H
#define CAMION_H

#include "Vehicule.h"

class Camion : public Vehicule {
private:
    double capaciteChargement;

public:
    Camion(std::string marque, std::string modele, int annee, double capaciteChargement);
    void afficherInfo() const override;
};

#endif
