#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string add(string a, string b) {
    string res;
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        res.push_back(sum % 10 + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int N;
    cin >> N;
    
    if (N == 0) {
        cout << "1" << endl;
        return 0;
    }
    if (N == 1) {
        cout << "1" << endl;
        return 0;
    }
    
    string a = "1"; // f(0) 或 f(1)
    string b = "2"; // f(2)
    
    if (N == 1) cout << a << endl;
    else if (N == 2) cout << b << endl;
    else {
        for (int i = 3; i <= N; i++) {
            string c = add(a, b);
            a = b;
            b = c;
        }
        cout << b << endl;
    }
    
    return 0;
}