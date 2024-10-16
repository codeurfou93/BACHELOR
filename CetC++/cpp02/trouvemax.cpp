#include <iostream>
using namespace std;

int trouverMaximum(int valeurs[], int taille) {
    int max = valeurs[0];
    for (int i = 1; i < taille; ++i) {
        if (valeurs[i] > max) {
            max = valeurs[i];
        }
    }
    return max;
}

int main() {
    int temperatures[7] = {22, 25, 19, 21, 24, 26, 23};
    int maxTemperature = trouverMaximum(temperatures, 7);
    
    cout << "La température maximale de la semaine est : " << maxTemperature << " °C" << endl;

    return 0;
}
