#include <stdio.h>
#include <string.h>

// Déclaration de la structure Employe
struct Employe {
    int id;
    char nom[50];
    float salaire;
};

// Fonction pour trouver l'employé avec le salaire le plus élevé
struct Employe trouverEmployeAvecSalaireMax(struct Employe employes[], int taille) {
    struct Employe employeMax = employes[0]; // Initialiser avec le premier employé

    // Parcours des employés pour trouver celui avec le salaire le plus élevé
    for (int i = 1; i < taille; i++) {
        if (employes[i].salaire > employeMax.salaire) {
            employeMax = employes[i];
        }
    }

    return employeMax; // Retourner l'employé avec le salaire le plus élevé
}

// Fonction principale
int main() {
    // Déclaration d'un tableau de trois employés
    struct Employe employes[3];
    
    // Saisie des informations pour chaque employé
    for (int i = 0; i < 3; i++) {
        printf("Saisissez les informations de l'employé %d:\n", i + 1);
        
        printf("ID : ");
        scanf("%d", &employes[i].id);
        
        printf("Nom : ");
        getchar(); // Pour consommer le caractère de nouvelle ligne précédent
        fgets(employes[i].nom, sizeof(employes[i].nom), stdin);
        employes[i].nom[strcspn(employes[i].nom, "\n")] = '\0'; // Enlève le saut de ligne
        
        printf("Salaire : ");
        scanf("%f", &employes[i].salaire);
    }

    // Trouver l'employé avec le salaire le plus élevé
    struct Employe employeAvecSalaireMax = trouverEmployeAvecSalaireMax(employes, 3);

    // Affichage des informations de l'employé avec le salaire le plus élevé
    printf("\nEmployé avec le salaire le plus élevé:\n");
    printf("ID : %d\n", employeAvecSalaireMax.id);
    printf("Nom : %s\n", employeAvecSalaireMax.nom);
    printf("Salaire : %.2f\n", employeAvecSalaireMax.salaire);

    return 0;
}
