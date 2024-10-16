#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> noms(3);

    noms[0] = "Alice";
    noms[1] = "Bob";
    noms[2] = "Charlie";

    noms[0] = "Alicia";
    noms[1] = "Robert";

    for (int i = 0; i < noms.size(); i++) {
        cout << "Nom " << i + 1 << ": " << noms[i] << endl;
    }

    return 0;
}
