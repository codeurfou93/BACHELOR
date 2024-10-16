#include <stdio.h>
#include <string.h>

// Déclaration de la structure Etudiant
struct Etudiant {
    char nom[50];
    int age;
};

// Fonction pour afficher les détails de l'étudiant
void afficherEtudiant(struct Etudiant e) {
    printf("Nom : %s\n", e.nom);
    printf("Âge : %d\n", e.age);
}

// Fonction principale
int main() {
    // Création d'une variable de type Etudiant
    struct Etudiant etudiant;

    // Utilisation de strcpy pour initialiser le nom de l'étudiant
    strcpy(etudiant.nom, "Alice Martin");
    etudiant.age = 22;  // Initialisation de l'âge

    // Affichage des informations de l'étudiant
    afficherEtudiant(etudiant);

    // Tests unitaires
    if (strcmp(etudiant.nom, "Alice Martin") == 0 && etudiant.age == 22) {
        printf("Test unitaire réussi : les valeurs correspondent aux valeurs affichées.\n");
    } else {
        printf("Échec du test unitaire : les valeurs ne correspondent pas.\n");
    }

    return 0;
}
