#include <bits/stdc++.h>

using namespace std;

// 유형 : 트리

int N; // 26 under
int p[27];
int lc[27];
int rc[27];

void preorder(int num) {
    cout << char(num + 65);
    if (lc[num] != 0) preorder(lc[num]);
    if (rc[num] != 0) preorder(rc[num]);
    return;
}

void inorder(int num) {
    if (lc[num] != 0) inorder(lc[num]);
    cout << char(num + 65);
    if (rc[num] != 0) inorder(rc[num]);
    return;
}

void postorder(int num) {
    if (lc[num] != 0) postorder(lc[num]);
    if (rc[num] != 0) postorder(rc[num]);
    cout << char(num + 65);
    return;
}

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        if (left != '.')
           lc[parent - 65] = left - 65;
        if (right != '.')
            rc[parent - 65] = right - 65;
        p[parent - 65] = parent - 65; // A => 0, B => 1, ...
    }

    // cout << 'B'- 65;

    preorder(0);
    cout << "\n";

    inorder(0);
    cout << "\n";

    postorder(0);
    cout << "\n";
}