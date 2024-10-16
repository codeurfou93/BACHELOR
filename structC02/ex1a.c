#include <stdio.h>
#include <string.h>

// Déclaration de la structure Voiture
struct Voiture {
    char marque[50];
    char modele[50];
    int annee;
};

// Fonction pour afficher les informations d'une voiture
void afficherVoiture(struct Voiture *v) {
    printf("Marque : %s\n", v->marque);
    printf("Modèle : %s\n", v->modele);
    printf("Année : %d\n", v->annee);
}

// Fonction pour modifier l'année de la voiture
void modifierAnnee(struct Voiture *v, int nouvelleAnnee) {
    v->annee = nouvelleAnnee;
}

// Fonction principale
int main() {
    // Création et initialisation de la variable voiture1
    struct Voiture voiture1;
    strcpy(voiture1.marque, "Tesla");
    strcpy(voiture1.modele, "Model S");
    voiture1.annee = 2020;

    // Affichage des informations avant modification
    printf("Informations de la voiture avant modification :\n");
    afficherVoiture(&voiture1);

    // Modification de l'année via la fonction
    modifierAnnee(&voiture1, 2023);

    // Affichage des informations après modification
    printf("\nInformations de la voiture après modification :\n");
    afficherVoiture(&voiture1);

    return 0;
}
