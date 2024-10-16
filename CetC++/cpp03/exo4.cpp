#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> fusionnerEtSupprimerDoublons(const vector<int>& tableau1, const vector<int>& tableau2) {
    set<int> ensemble;
    for (int val : tableau1) {
        ensemble.insert(val);
    }
    for (int val : tableau2) {
        ensemble.insert(val);
    }
    return vector<int>(ensemble.begin(), ensemble.end());
}

int main() {
    vector<int> tableau1 = {1, 2, 3, 4, 5};
    vector<int> tableau2 = {3, 4, 5, 6, 7};
    vector<int> tableauFusionne = fusionnerEtSupprimerDoublons(tableau1, tableau2);
    cout << "Tableau fusionné sans doublons : " << endl;
    for (int val : tableauFusionne) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
