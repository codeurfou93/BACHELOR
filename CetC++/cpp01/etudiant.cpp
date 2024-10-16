#include <iostream>
using namespace std;

int main() {
    
    int age = 25;                
    float taille = 1.80f;         
    char initiale = 'A';         
    bool estEtudiant = true;      
    string nom = "Alice";         

    cout << "Nom : " << nom << endl;
    cout << "Age : " << age << endl;
    cout << "Taille : " << taille << " mètres" << endl;
    cout << "Initiale : " << initiale << endl;
    cout << "Est étudiant : " << (estEtudiant ? "Oui" : "Non") << endl;  // Affichage conditionnel pour le booléen

    return 0;
}
