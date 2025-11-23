#include <iostream>
#include <string>
using namespace std;

int main() {
    string expr;
    getline(cin, expr);
    
    int count = 0;
    for (char c : expr) {
        if (c == '(') count++;
        else if (c == ')') count--;
        
        if (count < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    if (count == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}