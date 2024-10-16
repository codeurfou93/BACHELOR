#include <iostream>
using namespace std;

class Film {
private:
    string titre;
    string realisateur;
    int duree;

public:
    Film() : titre(""), realisateur(""), duree(0) {}

    void definirFilm(string t, string r, int d) {
        titre = t;
        realisateur = r;
        duree = d;
    }

    void afficherFilm() const {
        cout << "Titre : " << titre << endl;
        cout << "Réalisateur : " << realisateur << endl;
        cout << "Durée : " << duree << " minutes" << endl;
    }
};

int main() {
    int nombreFilms = 3;
    Film* films = new Film[nombreFilms];

    films[0].definirFilm("Inception", "Christopher Nolan", 148);
    films[1].definirFilm("Le Parrain", "Francis Ford Coppola", 175);
    films[2].definirFilm("Interstellar", "Christopher Nolan", 169);

    for (int i = 0; i < nombreFilms; ++i) {
        cout << "Film " << i + 1 << " :" << endl;
        films[i].afficherFilm();
        cout << endl;
    }

    delete[] films;

    return 0;
}
