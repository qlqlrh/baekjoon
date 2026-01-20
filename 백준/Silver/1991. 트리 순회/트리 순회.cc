#include <bits/stdc++.h>
using namespace std;

struct Node {
    int left = -1;
    int right = -1;
};

Node tree[26];

void preorder(int cur) {
    if (cur == -1) return;
    cout << char(cur + 'A');
    preorder(tree[cur].left);
    preorder(tree[cur].right);
}

void inorder(int cur) {
    if (cur == -1) return;
    inorder(tree[cur].left);
    cout << char(cur + 'A');
    inorder(tree[cur].right);
}

void postorder(int cur) {
    if (cur == -1) return;
    postorder(tree[cur].left);
    postorder(tree[cur].right);
    cout << char(cur + 'A');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        int parent = p - 'A';
        if (l == '.') tree[parent].left = -1;
        else tree[parent].left = l - 'A';
        if (r == '.') tree[parent].right = -1;
        else tree[parent].right = r - 'A';
    }

    // 루트는 항상 'A'
    int root = 0;

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';

    return 0;
}