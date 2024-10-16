#include <iostream>
using namespace std;

void echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5;
    int y = 10;

    cout << "Avant échange : x = " << x << ", y = " << y << endl;

    echanger(x, y);

    cout << "Après échange : x = " << x << ", y = " << y << endl;

    return 0;
}
