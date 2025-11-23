#include <iostream>
using namespace std;

int k;

bool check(int m) {
    int pos = 0; // 从0开始（第一个好人）
    int total = 2 * k;
    // 需要杀死k个坏人
    for (int i = 0; i < k; i++) {
        pos = (pos + m - 1) % total;
        if (pos < k) { // 杀到好人，不行
            return false;
        }
        total--; // 总人数减少
        // 后面的人位置前移
    }
    return true;
}

int main() {
    cin >> k;
    for (int m = k + 1; ; m++) {
        if (check(m)) {
            cout << m << endl;
            break;
        }
    }
    return 0;
}