#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<double>> notes(3, vector<double>(4, 0.0));

    for (int i = 0; i < 3; i++) {
        cout << "Entrez les notes de l'étudiant " << (i + 1) << " : " << endl;
        for (int j = 0; j < 4; j++) {
            cout << "Note matière " << (j + 1) << ": ";
            cin >> notes[i][j];
        }
    }

    cout << "Notes des étudiants : " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Étudiant " << (i + 1) << ": ";
        for (int j = 0; j < 4; j++) {
            cout << notes[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
