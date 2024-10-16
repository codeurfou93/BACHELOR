#ifndef LIB_H
#define LIB_H

int* lire_valeurs_separees_par_virgules(const char *nom_fichier, int *taille);
void ecrire_resultats_dans_fichier(const char *nom_fichier, double moyenne, int min, int max);
double moyenne(int *arr, int taille);
int minimum(int *arr, int taille);
int maximum(int *arr, int taille);

#endif
