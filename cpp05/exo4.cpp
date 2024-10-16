#include <iostream>
using namespace std;

void multiplier(int& a, int& b, int facteur) {
    a *= facteur;
    b *= facteur;
}

int main() {
    int a = 3;
    int b = 4;
    int facteur = 2;

    cout << "Avant multiplication : a = " << a << ", b = " << b << endl;

    multiplier(a, b, facteur);

    cout << "Après multiplication : a = " << a << ", b = " << b << endl;

    return 0;
}
