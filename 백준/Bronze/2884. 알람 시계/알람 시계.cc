#include <iostream>
using namespace std;

int main() {
    int h, m;
    int time = 45;
    cin >> h >> m;

    m -= time;
    while (m < 0) {
        m += 60;
        h -= 1;
        if (h < 0)
            h = 23;
    }

    cout << h << " " << m << endl;
}