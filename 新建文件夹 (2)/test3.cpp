#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 判断是否是回文
bool isPalindrome(const string &s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

// 将字符转成数字
int charToInt(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

// 将数字转成字符
char intToChar(int x) {
    if (x < 10) return '0' + x;
    return 'A' + (x - 10);
}

// N进制高精度加法
string addWithBase(const string &a, const string &b, int base) {
    string res;
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += charToInt(a[i--]);
        if (j >= 0) sum += charToInt(b[j--]);
        carry = sum / base;
        res.push_back(intToChar(sum % base));
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int N;
    string M;
    cin >> N >> M;

    int step = 0;
    while (step <= 30) {
        if (isPalindrome(M)) {
            cout << "STEP=" << step << endl;
            return 0;
        }
        string revM = M;
        reverse(revM.begin(), revM.end());
        M = addWithBase(M, revM, N);
        step++;
    }
    cout << "Impossible" << endl;
    return 0;
}