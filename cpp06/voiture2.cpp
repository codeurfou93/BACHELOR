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
    
    Voiture voiture1("Toyota", "Corolla", 2020);
    Voiture voiture2("Ford", "Mustang", 2018);
    Voiture voiture3("Tesla", "Model S", 2021);
    Voiture voiture4("Honda", "Civic", 2019);
    Voiture voiture5("Chevrolet", "Camaro", 2022);

   
    cout << "Informations sur les voitures :" << endl;
    voiture1.afficher();
    voiture2.afficher();
    voiture3.afficher();
    voiture4.afficher();
    voiture5.afficher();

    return 0;
}
