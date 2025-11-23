#include <iostream>
#include <cmath>
using namespace std;

// 判断质数
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    
    for (int x = 4; x <= N; x += 2) {
        for (int p = 2; p <= x / 2; p++) {
            if (isPrime(p) && isPrime(x - p)) {
                cout << x << "=" << p << "+" << x - p << endl;
                break;
            }
        }
    }
    
    return 0;
}
