#include <iostream>
using namespace std;

int X; // X번째 분수

int main() {
    cin >> X;
    int i = 1;
    while (true) {
        X -= i;
        if (X <= 0)
            break;
        i++;
    }

    int up, down;
    if (i % 2) { // odd
        up = 1 - X;
        down = i + X;
    }
    else { // even
        up = i + X;
        down = 1 - X;
    }

    cout << up << "/" << down << endl;
}