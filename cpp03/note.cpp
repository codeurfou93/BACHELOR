#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<float> notes;

    notes.push_back(15.5);
    notes.push_back(17.0);
    notes.push_back(14.0);
    notes.push_back(19.5);

    cout << "Notes après ajout : " << endl;
    for (int i = 0; i < notes.size(); i++) {
        cout << notes[i] << " ";
    }
    cout << endl;

    notes.pop_back();

    cout << "Notes après suppression : " << endl;
    for (int i = 0; i < notes.size(); i++) {
        cout << notes[i] << " ";
    }
    cout << endl;

    return 0;
}
