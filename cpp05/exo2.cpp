#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int* ptr = &a;

    cout << "Valeur de a avant modification : " << a << endl;
    
    *ptr = 10;
    cout << "Valeur de a après modification avec pointeur : " << a << endl;

    int& ref = a;
    ref = 15;
    cout << "Valeur de a après modification avec référence : " << a << endl;

    return 0;
}
