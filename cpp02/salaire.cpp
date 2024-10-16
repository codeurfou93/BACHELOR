#include <iostream>
using namespace std;

int main() {
    float salaires[5] = {2500.0, 2700.5, 2300.75, 2600.0, 2800.25};
    float somme = 0.0;

    for (int i = 0; i < 5; ++i) {
        somme += salaires[i];
    }

    float moyenne = somme / 5;
    cout << "La moyenne des salaires est: " << moyenne << " €" << endl;

    return 0;
}
