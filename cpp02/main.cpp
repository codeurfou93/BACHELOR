#include <iostream>
using namespace std;

int main() {
    const int TAILLE = 5;

    int datesDeNaissance[TAILLE];
    string noms[TAILLE];

    for (int i = 0; i < TAILLE; i++) {
        cout << "Entrez le nom de l'étudiant " << (i + 1) << ": ";
        cin >> noms[i];

        cout << "Entrez la date de naissance de l'étudiant " << (i + 1) << " (JJ/MM/AAAA): ";
        cin >> datesDeNaissance[i];
    }

    cout << "\nListe des étudiants et leurs dates de naissance:\n";
    for (int i = 0; i < TAILLE; i++) {
        cout << "Étudiant " << (i + 1) << ": " << noms[i] << ", Date de naissance: " << datesDeNaissance[i] << endl;
    }

    return 0;
}
