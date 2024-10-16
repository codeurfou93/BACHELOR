#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main() {
    
    int taille = 0;

    
    int *valeurs = lire_valeurs_separees_par_virgules("valeurs.txt", &taille);

    if (valeurs != NULL && taille > 0) {
        
        double moy = moyenne(valeurs, taille);
        int min = minimum(valeurs, taille);
        int max = maximum(valeurs, taille);

        
        ecrire_resultats_dans_fichier("result.txt", moy, min, max);

        
        printf("Les résultats ont été écrits dans 'result.txt'.\n");

        
        free(valeurs);
    } else {
        printf("Erreur: Pas de valeurs à traiter\n");
    }

    return 0;
}
