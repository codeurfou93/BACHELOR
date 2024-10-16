#include <iostream>
#include <vector>
using namespace std;

class Etudiant {
private:
    string nom;
    int age;
    vector<int> notes;

public:
    Etudiant(string n, int a) : nom(n), age(a) {}

    void ajouterNote(int note) {
        notes.push_back(note);
    }

    double calculerMoyenne() const {
        if (notes.empty()) {
            return 0.0; 
        }
        int total = 0;
        for (int note : notes) {
            total += note;
        }
        return static_cast<double>(total) / notes.size();
    }

    void afficher() const {
        cout << "Nom : " << nom << ", Age : " << age << endl;
        cout << "Notes : ";
        for (int note : notes) {
            cout << note << " ";
        }
        cout << endl;
        cout << "Moyenne : " << calculerMoyenne() << endl;
    }
};

int main() {
    Etudiant etudiant1("Alice", 20);
    Etudiant etudiant2("Bob", 22);

    etudiant1.ajouterNote(15);
    etudiant1.ajouterNote(18);
    etudiant1.ajouterNote(14);

    etudiant2.ajouterNote(12);
    etudiant2.ajouterNote(17);
    etudiant2.ajouterNote(19);

    etudiant1.afficher();
    cout << endl;
    etudiant2.afficher();

    return 0;
}
