#include <stdio.h>

// Déclaration de la structure Heure
struct Heure {
    int heures;   // Heure (0-23)
    int minutes;  // Minutes (0-59)
    int secondes; // Secondes (0-59)
};

// Déclaration de la structure Date
struct Date {
    int jour;     // Jour (1-31)
    int mois;     // Mois (1-12)
    int annee;    // Année
    struct Heure heure; // Heure imbriquée
};

// Fonction pour vérifier si une année est bissextile
int estBissextile(int annee) {
    return (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);
}

// Fonction pour calculer le nombre de jours dans un mois
int joursDansMois(int mois, int annee) {
    if (mois == 2) { // Février
        return estBissextile(annee) ? 29 : 28;
    } else if (mois == 4 || mois == 6 || mois == 9 || mois == 11) { // Avril, Juin, Septembre, Novembre
        return 30;
    }
    return 31; // Janvier, Mars, Mai, Juillet, Août, Octobre, Décembre
}

// Fonction pour convertir une date en secondes depuis l'an 0
long long convertirEnSecondes(struct Date date) {
    long long totalSecondes = 0;

    // Ajout des années complètes
    for (int annee = 0; annee < date.annee; annee++) {
        totalSecondes += estBissextile(annee) ? 31622400 : 31536000; // 366 ou 365 jours en secondes
    }

    // Ajout des mois de l'année en cours
    for (int mois = 1; mois < date.mois; mois++) {
        totalSecondes += joursDansMois(mois, date.annee) * 86400; // 24 * 60 * 60
    }

    // Ajout des jours
    totalSecondes += (date.jour - 1) * 86400; // Jours en secondes

    // Ajout des heures, minutes et secondes
    totalSecondes += (date.heure.heures * 3600) + (date.heure.minutes * 60) + date.heure.secondes;

    return totalSecondes;
}

// Fonction principale
int main() {
    struct Date date1, date2;

    // Demande à l'utilisateur de saisir la première date
    printf("Entrez la première date (jour mois annee heures minutes secondes) : ");
    scanf("%d %d %d %d %d %d", &date1.jour, &date1.mois, &date1.annee,
          &date1.heure.heures, &date1.heure.minutes, &date1.heure.secondes);

    // Demande à l'utilisateur de saisir la deuxième date
    printf("Entrez la deuxième date (jour mois annee heures minutes secondes) : ");
    scanf("%d %d %d %d %d %d", &date2.jour, &date2.mois, &date2.annee,
          &date2.heure.heures, &date2.heure.minutes, &date2.heure.secondes);

    // Conversion des dates en secondes
    long long secondesDate1 = convertirEnSecondes(date1);
    long long secondesDate2 = convertirEnSecondes(date2);

    // Calcul de la différence en secondes
    long long difference = secondesDate2 - secondesDate1;

    // Affichage de la différence
    printf("La différence entre les deux dates est : %lld secondes\n", difference);

    return 0;
}
