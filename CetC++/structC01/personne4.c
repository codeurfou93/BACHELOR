#include <stdio.h>
#include <string.h>

// Déclaration de la structure Personne
struct Personne {
    char nom[50];
    int age;
};

// Fonction pour afficher les informations d'une personne
void afficherPersonne(struct Personne *p) {
    printf("Nom : %s\n", p->nom);
    printf("Âge : %d ans\n", p->age);
}

// Fonction pour incrémenter l'âge d'une personne
void vieillir(struct Personne *p) {
    p->age += 1; // Incrémente l'âge de 1
}

// Fonction principale
int main() {
    // Création et initialisation de la variable personne
    struct Personne personne;
    strcpy(personne.nom, "Alice");
    personne.age = 30;

    // Affichage des informations avant vieillissement
    printf("Avant vieillissement :\n");
    afficherPersonne(&personne);

    // Vieillir la personne
    vieillir(&personne);

    // Affichage des informations après vieillissement
    printf("\nAprès vieillissement :\n");
    afficherPersonne(&personne);

    // Tests unitaires pour vérifier la correcte modification
    if (personne.age == 31) {
        printf("\nTest unitaire réussi : l'âge a été correctement incrémenté.\n");
    } else {
        printf("\nÉchec du test unitaire : l'âge n'a pas été correctement incrémenté.\n");
    }

    return 0;
}
