#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int j = str.size() - 1;
    for (int i = str.size() - 1; i > -1;i --) {
        if (str[i] != '*') {
            str[j --] = str[i];
        }
    }
    for (; j > -1;) {
        str[j --] = '*';
    }
    cout << str;
    return 0;
}
