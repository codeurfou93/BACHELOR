#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<double> notes(5);

    cout << "Entrez les notes pour 5 étudiants : " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Note de l'étudiant " << (i + 1) << ": ";
        cin >> notes[i];
    }

    double somme = 0;
    double maxNote = notes[0];
    double minNote = notes[0];

    for (double note : notes) {
        somme += note;
        if (note > maxNote) {
            maxNote = note;
        }
        if (note < minNote) {
            minNote = note;
        }
    }

    double moyenne = somme / notes.size();

    cout << "Note maximale : " << maxNote << endl;
    cout << "Note minimale : " << minNote << endl;
    cout << "Moyenne des notes : " << moyenne << endl;

    return 0;
}
