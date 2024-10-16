#include <iostream>
using namespace std;

class Livre {
private:
    string titre;
    string auteur;
    int nombrePages;

public:
    Livre(string t, string a, int p) : titre(t), auteur(a), nombrePages(p) {}

    void afficherLivre() const {
        cout << "Titre : " << titre << endl;
        cout << "Auteur : " << auteur << endl;
        cout << "Nombre de pages : " << nombrePages << endl;
    }
};

int main() {
    Livre* livrePtr = new Livre("Les Misérables", "Victor Hugo", 1232);

    livrePtr->afficherLivre();

    delete livrePtr;

    return 0;
}
