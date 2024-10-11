#include <stdio.h>

// Déclaration de la structure Temps
struct Temps {
    int heures;
    int minutes;
    int secondes;
};

// Fonction pour additionner deux instants Temps
struct Temps additionnerTemps(struct Temps t1, struct Temps t2) {
    struct Temps resultat;

    // Additionner les secondes, minutes et heures
    resultat.secondes = t1.secondes + t2.secondes;
    resultat.minutes = t1.minutes + t2.minutes + (resultat.secondes / 60);
    resultat.secondes %= 60; // Gérer les dépassements de secondes

    resultat.heures = t1.heures + t2.heures + (resultat.minutes / 60);
    resultat.minutes %= 60; // Gérer les dépassements de minutes

    return resultat;
}

int main() {
    // Déclaration de deux variables de type Temps
    struct Temps t1, t2, total;

    // Saisie des informations pour le premier instant
    printf("Saisissez le premier instant:\n");
    printf("Heures : ");
    scanf("%d", &t1.heures);
    printf("Minutes : ");
    scanf("%d", &t1.minutes);
    printf("Secondes : ");
    scanf("%d", &t1.secondes);

    // Saisie des informations pour le deuxième instant
    printf("\nSaisissez le deuxième instant:\n");
    printf("Heures : ");
    scanf("%d", &t2.heures);
    printf("Minutes : ");
    scanf("%d", &t2.minutes);
    printf("Secondes : ");
    scanf("%d", &t2.secondes);

    // Addition des deux temps
    total = additionnerTemps(t1, t2);

    // Affichage de l'heure totale sous la forme HH:MM:SS
    printf("\nL'heure totale est : %02d:%02d:%02d\n", total.heures, total.minutes, total.secondes);

    return 0;
}
