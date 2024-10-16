#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<double> temperatures;

    temperatures.push_back(22.5);
    temperatures.push_back(24.0);
    temperatures.push_back(19.5);
    temperatures.push_back(21.0);
    temperatures.push_back(26.5);
    temperatures.push_back(23.0);
    temperatures.push_back(20.0);

    double moyenne = 0;
    for (int i = 0; i < temperatures.size(); i++) {
        moyenne += temperatures[i];
    }
    moyenne /= temperatures.size();

    cout << "La température moyenne de la semaine est : " << moyenne << " °C" << endl;

    return 0;
}
