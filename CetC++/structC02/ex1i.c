#include <stdio.h>
#include <string.h>

// Déclaration de la structure Livre
struct Livre {
    char titre[100];
    char auteur[50];
    float prix;
};

// Fonction principale
int main() {
    // Déclaration d'un tableau de trois livres
    struct Livre livres[3];
    
    // Saisie des informations pour chaque livre
    for (int i = 0; i < 3; i++) {
        printf("Saisissez les informations du livre %d:\n", i + 1);
        
        printf("Titre : ");
        getchar(); // Pour consommer le caractère de nouvelle ligne précédent
        fgets(livres[i].titre, sizeof(livres[i].titre), stdin);
        livres[i].titre[strcspn(livres[i].titre, "\n")] = '\0'; // Enlève le saut de ligne
        
        printf("Auteur : ");
        fgets(livres[i].auteur, sizeof(livres[i].auteur), stdin);
        livres[i].auteur[strcspn(livres[i].auteur, "\n")] = '\0'; // Enlève le saut de ligne
        
        printf("Prix : ");
        scanf("%f", &livres[i].prix);
    }

    // Initialisation des pointeurs pour le livre le plus cher et le moins cher
    struct Livre *plusCher = &livres[0];
    struct Livre *moinsCher = &livres[0];

    // Parcours des livres pour trouver le plus cher et le moins cher
    for (int i = 1; i < 3; i++) {
        if (livres[i].prix > plusCher->prix) {
            plusCher = &livres[i];
        }
        if (livres[i].prix < moinsCher->prix) {
            moinsCher = &livres[i];
        }
    }

    // Affichage des résultats
    printf("\nLivre le plus cher:\n");
    printf("Titre : %s\n", plusCher->titre);
    printf("Auteur : %s\n", plusCher->auteur);
    printf("Prix : %.2f\n", plusCher->prix);

    printf("\nLivre le moins cher:\n");
    printf("Titre : %s\n", moinsCher->titre);
    printf("Auteur : %s\n", moinsCher->auteur);
    printf("Prix : %.2f\n", moinsCher->prix);

    return 0;
}
