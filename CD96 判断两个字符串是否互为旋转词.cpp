#include <iostream>
using namespace std;

int main() {
    int n1,n2;
    cin >> n1 >> n2;
    string a,b;
    cin >> a;
    cin >> b;

    if (n1 != n2) {
        cout << "NO";
        return 0;
    }
    string c = a + a;
    if (c.find(b) != -1) {
        cout << "YES";
        return 0;
    }
    else {
        cout << "NO";
        return 0;
    }
    return 0;
}
