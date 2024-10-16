#include <stdio.h>
#include <string.h>

// Déclaration de la structure Voiture
struct Voiture {
    char marque[50];
    int annee;
    char modele[50];
};

// Fonction pour afficher les détails de la voiture
void afficherVoiture(struct Voiture v) {
    printf("Marque: %s\n", v.marque);
    printf("Année: %d\n", v.annee);
    printf("Modèle: %s\n", v.modele);
}

// Fonction principale
int main() {
   
    struct Voiture maVoiture;

    
    strcpy(maVoiture.marque, "Toyota");
    maVoiture.annee = 2020;
    strcpy(maVoiture.modele, "Corolla");

    
    afficherVoiture(maVoiture);

    // Tests unitaires
    if (strcmp(maVoiture.marque, "Toyota") == 0 &&
        maVoiture.annee == 2020 &&
        strcmp(maVoiture.modele, "Corolla") == 0) {
        printf("Test unitaire réussi : la voiture est correctement initialisée.\n");
    } else {
        printf("Échec du test unitaire : la voiture n'est pas correctement initialisée.\n");
    }

    return 0;
}
