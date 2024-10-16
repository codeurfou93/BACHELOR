#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int& ref = x;
    
    cout << "Valeur de x avant modification : " << x << endl;
    
    ref = 20;
    
    cout << "Valeur de x après modification : " << x << endl;

    return 0;
}
