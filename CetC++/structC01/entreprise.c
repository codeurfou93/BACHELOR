#include <stdio.h>
#include <string.h>

// Déclaration de la structure Entreprise
struct Entreprise {
    char nom[50];
    int chiffre_affaires; // En milliers d'euros
    int nombre_employes;
};

// Déclaration de la structure Produit
struct Produit {
    char nom[50];
    float prix; // Prix en euros
    int stock;  // Quantité en stock
    struct Entreprise fabricant; // Structure imbriquée
};

// Fonction pour afficher les détails du produit
void afficherProduit(struct Produit p) {
    printf("Nom du produit : %s\n", p.nom);
    printf("Prix : %.2f euros\n", p.prix);
    printf("Stock : %d unités\n", p.stock);
    printf("Fabricant : %s\n", p.fabricant.nom);
    printf("Chiffre d'affaires : %d milliers d'euros\n", p.fabricant.chiffre_affaires);
    printf("Nombre d'employés : %d\n", p.fabricant.nombre_employes);
}

// Fonction principale
int main() {
    // Création d'une variable de type Produit
    struct Produit produit;

    // Initialisation des membres du produit
    strcpy(produit.nom, "Ordinateur Portable");
    produit.prix = 999.99;
    produit.stock = 50;

    // Initialisation des membres de la structure imbriquée Entreprise
    strcpy(produit.fabricant.nom, "Tech Corp");
    produit.fabricant.chiffre_affaires = 5000; // 5 millions d'euros
    produit.fabricant.nombre_employes = 200;

    // Affichage des informations complètes du produit
    printf("Informations sur le produit :\n");
    afficherProduit(produit);

    // Tests unitaires pour vérifier la correcte initialisation
    if (strcmp(produit.nom, "Ordinateur Portable") == 0 &&
        produit.prix == 999.99f &&  // Notez 'f' pour assurer que la comparaison est avec float
        produit.stock == 50 &&
        strcmp(produit.fabricant.nom, "Tech Corp") == 0 &&
        produit.fabricant.chiffre_affaires == 5000 &&
        produit.fabricant.nombre_employes == 200) {
        printf("Test unitaire réussi : les valeurs correspondent aux valeurs affichées.\n");
    } else {
        printf("Échec du test unitaire : les valeurs ne correspondent pas.\n");
    }

    return 0;
}
