#include <stdio.h>
#include <string.h>

// Déclaration de la structure Personne
struct Personne {
    char prenom[50];
    char nom[50];
    int anneeNaissance;
};

// Fonction pour afficher les détails de la personne
void afficherPersonne(struct Personne p) {
    printf("Prénom : %s\n", p.prenom);
    printf("Nom : %s\n", p.nom);
    printf("Année de naissance : %d\n", p.anneeNaissance);
}

// Fonction principale
int main() {
    
    struct Personne personne = {"Alice", "Dupont", 1990};

   
    personne.anneeNaissance = 1995;

    
    strcpy(personne.prenom, "Alicia"); 

   
    afficherPersonne(personne);

    
    if (personne.anneeNaissance == 1995) {
        printf("Test unitaire réussi : l'année de naissance a été correctement modifiée.\n");
    } else {
        printf("Échec du test unitaire : l'année de naissance n'a pas été modifiée correctement.\n");
    }

    return 0;
}
