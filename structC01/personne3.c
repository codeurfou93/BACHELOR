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
    // Déclaration et initialisation de la première variable de type Personne
    struct Personne personne1 = {"Alice", "Dupont", 30};

    // Déclaration de la seconde variable de type Personne
    struct Personne personne2;

    // Copier les valeurs de personne1 dans personne2
    personne2 = personne1;

    // Affichage des informations de la seconde personne
    printf("Informations de la seconde personne (après copie) :\n");
    afficherPersonne(personne2);

    // Tests unitaires pour confirmer que les deux structures ont des valeurs identiques
    if (strcmp(personne1.prenom, personne2.prenom) == 0 &&
        strcmp(personne1.nom, personne2.nom) == 0 &&
        personne1.age == personne2.age) {
        printf("Test unitaire réussi : les deux personnes ont des valeurs identiques.\n");
    } else {
        printf("Échec du test unitaire : les valeurs ne correspondent pas.\n");
    }

    return 0;
}
