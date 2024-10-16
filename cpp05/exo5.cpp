#include <iostream>
using namespace std;

void modifierElement(int& element) {
    element += 10;
}

int main() {
    int tableau[5] = {1, 2, 3, 4, 5};

    cout << "Tableau avant modification : ";
    for (int i = 0; i < 5; ++i) {
        cout << tableau[i] << " ";
    }
    cout << endl;

    modifierElement(tableau[2]);

    cout << "Tableau après modification : ";
    for (int i = 0; i < 5; ++i) {
        cout << tableau[i] << " ";
    }
    cout << endl;

    return 0;
}
