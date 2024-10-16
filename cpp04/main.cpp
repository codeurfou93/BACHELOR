#include <iostream>
using namespace std;

void echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int& plusPetit(int& a, int& b) {
    return (a < b) ? a : b;
}

int main() {
    int x = 10, y = 20;

    cout << "Avant échange : x = " << x << ", y = " << y << endl;
    echanger(x, y);
    cout << "Après échange : x = " << x << ", y = " << y << endl;

    int& min = plusPetit(x, y);
    cout << "Le plus petit entre x et y est : " << min << endl;

    min = 5; 
    cout << "Après modification, x = " << x << ", y = " << y << endl;

    return 0;
}
