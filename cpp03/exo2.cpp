#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> scores = {85, 90, 76, 88, 92};

    cout << "Scores avant insertion : " << endl;
    for (const int& score : scores) {
        cout << score << " ";
    }
    cout << endl;

    scores.insert(scores.begin() + 2, 95);

    cout << "Scores après insertion : " << endl;
    for (const int& score : scores) {
        cout << score << " ";
    }
    cout << endl;

    sort(scores.begin(), scores.end(), greater<int>());

    cout << "Scores après tri décroissant : " << endl;
    for (const int& score : scores) {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}
