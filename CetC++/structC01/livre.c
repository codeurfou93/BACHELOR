#include <stdio.h>
#include <string.h>

// Déclaration de la structure Livre
struct Livre {
    char titre[100];
    int nombre_de_pages;
    float prix;
};

// Fonction pour afficher les détails du livre
void afficherLivre(struct Livre *l) {
    printf("Titre : %s\n", l->titre);
    printf("Nombre de pages : %d\n", l->nombre_de_pages);
    printf("Prix : %.2f euros\n", l->prix);
}

// Fonction principale
int main() {
    // Création d'une variable de type Livre
    struct Livre livre;

    // Initialisation des membres de la structure Livre
    strcpy(livre.titre, "Le Petit Prince");
    livre.nombre_de_pages = 96;
    livre.prix = 10.50;

    // Déclaration d'un pointeur sur une structure Livre et affectation de l'adresse de la variable livre
    struct Livre *ptr = &livre;

    // Utilisation du pointeur pour modifier les membres de la structure
    ptr->nombre_de_pages = 100; // Modification du nombre de pages
    ptr->prix = 12.00; // Modification du prix

    // Affichage des valeurs des membres pour vérifier que les modifications ont bien été prises en compte
    printf("Informations sur le livre après modification :\n");
    afficherLivre(ptr);

    // Tests unitaires pour vérifier que l'accès et la modification via le pointeur fonctionnent correctement
    if (ptr->nombre_de_pages == 100 && ptr->prix == 12.00) {
        printf("Test unitaire réussi : les valeurs correspondent aux valeurs attendues.\n");
    } else {
        printf("Échec du test unitaire : les valeurs ne correspondent pas.\n");
    }

    return 0;
}
