#include <iostream>
#include <vector>
using namespace std;

void rotationCirculaire(vector<int>& tableau) {
    if (tableau.empty()) return;
    
    int dernier = tableau.back();
    for (int i = tableau.size() - 1; i > 0; i--) {
        tableau[i] = tableau[i - 1];
    }
    tableau[0] = dernier;
}

int main() {
    vector<int> tableau = {1, 2, 3, 4, 5};

    cout << "Tableau original : ";
    for (int val : tableau) {
        cout << val << " ";
    }
    cout << endl;

    for (int i = 0; i < 3; i++) {
        rotationCirculaire(tableau);
        cout << "Tableau après rotation " << (i + 1) << ": ";
        for (int val : tableau) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
