#include <stdio.h>
#include <stdbool.h>

#define TAILLE_MAX 5 // Taille fixe de la file d'attente

// Déclaration de la structure File
struct File {
    int elements[TAILLE_MAX]; // Tableau d'entiers pour stocker les éléments
    int front;                // Indice du premier élément
    int rear;                 // Indice du dernier élément
};

// Fonction pour initialiser la file
void initFile(struct File *f) {
    f->front = -1;
    f->rear = -1;
}

// Vérifie si la file est vide
bool estVide(struct File *f) {
    return (f->front == -1);
}

// Vérifie si la file est pleine
bool estPleine(struct File *f) {
    return ((f->rear + 1) % TAILLE_MAX == f->front);
}

// Fonction d'enfilement (enqueue)
void enfile(struct File *f, int valeur) {
    if (estPleine(f)) {
        printf("Erreur : La file est pleine. Impossible d'ajouter %d.\n", valeur);
        return;
    }
    if (estVide(f)) {
        f->front = 0; // Premier élément ajouté
    }
    f->rear = (f->rear + 1) % TAILLE_MAX; // Mise à jour de l'indice rear
    f->elements[f->rear] = valeur; // Ajout de la valeur
    printf("Ajouté : %d\n", valeur);
}

// Fonction de défilement (dequeue)
int defile(struct File *f) {
    if (estVide(f)) {
        printf("Erreur : La file est vide. Impossible de retirer un élément.\n");
        return -1; // Valeur d'erreur
    }
    int valeur = f->elements[f->front]; // Récupération de la valeur
    if (f->front == f->rear) {
        // La file devient vide
        f->front = -1;
        f->rear = -1;
    } else {
        f->front = (f->front + 1) % TAILLE_MAX; // Mise à jour de l'indice front
    }
    return valeur;
}

// Fonction pour afficher l'état actuel de la file
void afficherFile(struct File *f) {
    if (estVide(f)) {
        printf("La file est vide.\n");
        return;
    }
    printf("État actuel de la file : ");
    for (int i = f->front; i != f->rear; i = (i + 1) % TAILLE_MAX) {
        printf("%d ", f->elements[i]);
    }
    printf("%d\n", f->elements[f->rear]); // Afficher le dernier élément
}

// Fonction principale
int main() {
    struct File maFile;
    initFile(&maFile);

    int choix, valeur;

    do {
        printf("\nMenu :\n");
        printf("1. Enfiler (Ajouter un élément)\n");
        printf("2. Défiler (Retirer un élément)\n");
        printf("3. Afficher l'état de la file\n");
        printf("4. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à ajouter : ");
                scanf("%d", &valeur);
                enfile(&maFile, valeur);
                break;
            case 2:
                valeur = defile(&maFile);
                if (valeur != -1) {
                    printf("Retiré : %d\n", valeur);
                }
                break;
            case 3:
                afficherFile(&maFile);
                break;
            case 4:
                printf("Quitter le programme.\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 4);

    return 0;
}
