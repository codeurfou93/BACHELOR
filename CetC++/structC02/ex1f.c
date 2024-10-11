#include <stdio.h>
#include <string.h>

// Déclaration de la structure Etudiant
struct Etudiant {
    char nom[50];
    int age;
    float note;
};

int main() {
    // Création d'un tableau de deux étudiants
    struct Etudiant etudiants[2];

    // Saisie des informations pour les deux étudiants
    for (int i = 0; i < 2; i++) {
        printf("Saisissez les informations pour l'étudiant %d:\n", i + 1);
        
        printf("Nom : ");
        fgets(etudiants[i].nom, sizeof(etudiants[i].nom), stdin);
        etudiants[i].nom[strcspn(etudiants[i].nom, "\n")] = '\0'; // Suppression du saut de ligne
        
        printf("Âge : ");
        scanf("%d", &etudiants[i].age);
        
        printf("Note : ");
        scanf("%f", &etudiants[i].note);
        
        // Vider le tampon pour éviter des problèmes avec fgets après scanf
        getchar();
    }

    // Affichage des informations des deux étudiants
    printf("\nInformations des étudiants :\n");
    for (int i = 0; i < 2; i++) {
        printf("Étudiant %d:\n", i + 1);
        printf("Nom : %s\n", etudiants[i].nom);
        printf("Âge : %d\n", etudiants[i].age);
        printf("Note : %.2f\n", etudiants[i].note);
    }

    // Calcul de la moyenne des notes
    float moyenne = (etudiants[0].note + etudiants[1].note) / 2.0;
    printf("Moyenne des notes : %.2f\n", moyenne);

    return 0;
}
