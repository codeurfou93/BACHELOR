#include <iostream>
#include <string>
using namespace std;

class Voiture {
private:
    string marque;
    string modele;
    int annee;

public:
    Voiture(string m, string mo, int a) : marque(m), modele(mo), annee(a) {}

    void afficher() const {
        cout << "Marque : " << marque << ", Modèle : " << modele << ", Année : " << annee << endl;
    }
};

int main() {
    Voiture maVoiture("Toyota", "Corolla", 2020);
    
    maVoiture.afficher();

    return 0;
}
