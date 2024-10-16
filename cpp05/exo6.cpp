#include <iostream>
using namespace std;

void afficherConst(const int& valeur) {
    cout << "Valeur : " << valeur << endl;
}

int main() {
    int x = 10;
    cout << "Avant appel : " << x << endl;

    afficherConst(x);

    cout << "Après appel : " << x << endl;

    return 0;
}
