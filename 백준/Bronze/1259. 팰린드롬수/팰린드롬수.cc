#include <iostream>
#include <string>
using namespace std;

int main() {
    while ( true ) {
        string num;
        cin >> num;
        
        if (num == "0")
            break;
        
        int len = num.length();
        bool isPelin = true;
        for (int i = 0; i < len / 2; i++) {
            if (num[i] != num[len -1 - i]) {
                cout << "no" << endl;
                isPelin = false;
                break;
            }
        }
        if (isPelin)
            cout << "yes" << endl;

    }
}