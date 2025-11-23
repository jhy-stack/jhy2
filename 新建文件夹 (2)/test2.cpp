#include <iostream>
using namespace std;

void convert(int n, int m) {
    if (n < m) {
        if (n < 10)
            cout << n;
        else
            cout << char('A' + n - 10);
        return;
    }
    convert(n / m, m);
    int r = n % m;
    if (r < 10)
        cout << r;
    else
        cout << char('A' + r - 10);
}

int main() {
    int X, M;
    cin >> X >> M;
    convert(X, M);
    return 0;
}