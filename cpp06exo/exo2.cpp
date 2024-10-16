#include <iostream>
using namespace std;

class Rectangle {
private:
    double longueur;
    double largeur;

public:
    void setLongueur(double l) {
        longueur = l;
    }

    void setLargeur(double l) {
        largeur = l;
    }

    double getLongueur() const {
        return longueur;
    }

    double getLargeur() const {
        return largeur;
    }

    double calculerSurface() const {
        return longueur * largeur;
    }

    double calculerPerimetre() const {
        return 2 * (longueur + largeur);
    }

    void afficher() const {
        cout << "Longueur : " << longueur << ", Largeur : " << largeur << endl;
        cout << "Surface : " << calculerSurface() << endl;
        cout << "Périmètre : " << calculerPerimetre() << endl;
    }
};

int main() {
    Rectangle rect;
    rect.setLongueur(5.0);
    rect.setLargeur(3.0);

    rect.afficher();

    return 0;
}
