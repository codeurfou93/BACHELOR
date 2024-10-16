#include <iostream>
using namespace std;

void afficherInfos(const string& prenom, int age) {
    cout << "Bonjour " << prenom << "! Tu as " << age << " ans." << endl;
}

void afficherInfos(const string& prenom, int age, float taille) {
    cout << "Bonjour " << prenom << "! Tu as " << age << " ans et tu mesures " << taille << " mètres." << endl;
}

void afficherInfos(const string& prenom, float taille) {
    cout << "Bonjour " << prenom << "! Tu mesures " << taille << " mètres." << endl;
}

int main() {
    string prenom;
    int age;
    float taille;

    cout << "Entrez votre prénom : ";
    cin >> prenom;
    cout << "Entrez votre âge : ";
    cin >> age;
    cout << "Entrez votre taille (en mètres) : ";
    cin >> taille;

    afficherInfos(prenom, age);
    afficherInfos(prenom, age, taille);
    afficherInfos(prenom, taille);

    return 0;
}
