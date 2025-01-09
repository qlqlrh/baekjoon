#include <iostream>
#define MULTIPLE 6
using namespace std;

/**
 * 시간 제한 : 2초
 * 시간 복잡도 :
 * 구현 : 1부터 떨어진 정도가 같은 숫자들을 같은 layer라고 하자.
 *       레이어의 범위가 6의 배수로 증가하므로 6의 배수씩 더해서 어떤 layer에 있는지 판단
 *
 */
int main() {

    int N; // 최대 1,000,000,000
    cin >> N;

    int layer = 1;
    int maxNum = 1;
    while(true) {
        if (maxNum >= N) {
            break;
        }

        maxNum += layer * MULTIPLE;
        layer++;
    }


    cout << layer << endl;

    return 0;

}