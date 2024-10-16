#include <stdio.h>
#include <math.h>

// Déclaration de la structure Point
struct Point {
    float x; // Coordonnée x
    float y; // Coordonnée y
};

// Fonction pour calculer la distance entre deux points
float calculerDistance(struct Point p1, struct Point p2) {
    float distance;
    distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); // Formule de la distance
    return distance;
}

// Fonction principale
int main() {
    struct Point point1, point2;

    // Demande à l'utilisateur de saisir les coordonnées du premier point
    printf("Saisissez les coordonnées du premier point (x y) : ");
    scanf("%f %f", &point1.x, &point1.y);

    // Demande à l'utilisateur de saisir les coordonnées du deuxième point
    printf("Saisissez les coordonnées du deuxième point (x y) : ");
    scanf("%f %f", &point2.x, &point2.y);

    // Calcule la distance entre les deux points
    float distance = calculerDistance(point1, point2);

    // Affiche la distance calculée
    printf("La distance entre les points (%.2f, %.2f) et (%.2f, %.2f) est : %.2f\n",
           point1.x, point1.y, point2.x, point2.y, distance);

    return 0;
}
