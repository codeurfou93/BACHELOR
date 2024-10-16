#include <stdio.h>
#include <string.h>

// Déclaration de la structure Personne
struct Personne {
    char prenom[50];
    char nom[50];
    int age;
};

// Fonction pour afficher les détails de la personne
void afficherPersonne(struct Personne p) {
    printf("Prénom : %s\n", p.prenom);
    printf("Nom : %s\n", p.nom);
    printf("Âge : %d\n", p.age);
}

// Fonction principale
int main() {
    // Création d'une variable de type Personne
    struct Personne personne;

    // Affectation de valeurs aux membres
    strcpy(personne.prenom, "Alice");
    strcpy(personne.nom, "Dupont");
    personne.age = 30;

    // Affichage des valeurs des membres
    afficherPersonne(personne);

    // Tests unitaires
    if (strcmp(personne.prenom, "Alice") == 0 &&
        strcmp(personne.nom, "Dupont") == 0 &&
        personne.age == 30) {
        printf("Test unitaire réussi : les valeurs correspondent aux valeurs affichées.\n");
    } else {
        printf("Échec du test unitaire : les valeurs ne correspondent pas.\n");
    }

    return 0;
}
