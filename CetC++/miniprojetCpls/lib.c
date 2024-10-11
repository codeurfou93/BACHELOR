#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  
#include <limits.h>  

#define BUFFER_SIZE 100


int* lire_valeurs_separees_par_virgules(const char *nom_fichier, int *taille) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return NULL;
    }

    char ligne[BUFFER_SIZE];
    if (fgets(ligne, BUFFER_SIZE, fichier) == NULL) {
        printf("Erreur: Impossible de lire le contenu du fichier\n");
        fclose(fichier);
        return NULL;
    }

    fclose(fichier);

    
    char *token = strtok(ligne, ",");
    int *valeurs = (int*) malloc(BUFFER_SIZE * sizeof(int));  
    *taille = 0;

    while (token != NULL) {
        valeurs[*taille] = atoi(token);  
        (*taille)++;
        token = strtok(NULL, ",");
    }

    return valeurs;
}


void ecrire_resultats_dans_fichier(const char *nom_fichier, double moyenne, int min, int max) {
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur: Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return;
    }

    fprintf(fichier, "Moyenne: %.2f\n", moyenne);
    fprintf(fichier, "Minimum: %d\n", min);
    fprintf(fichier, "Maximum: %d\n", max);

    fclose(fichier);
}


int strtoint(const char *str) {
    return atoi(str);
}


double moyenne(int *arr, int taille) {
    if (taille == 0) return 0.0;
    
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += arr[i];
    }
    return (double)somme / taille;
}


int minimum(int *arr, int taille) {
    if (taille == 0) return INT_MAX;  

    int min = arr[0];
    for (int i = 1; i < taille; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}


int maximum(int *arr, int taille) {
    if (taille == 0) return INT_MIN;  

    int max = arr[0];
    for (int i = 1; i < taille; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
