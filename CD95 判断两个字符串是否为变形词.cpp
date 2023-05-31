#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n1,n2;
    cin >> n1 >> n2;
    string a,b;
    cin >> a;
    cin >> b;
    int hash[256] = {0};
    for(auto ch : a) {
        hash[ch] ++;
    }
    for(auto ch : b) {
        if (hash[ch] -- == 0) {
            cout << "false";
            return 0;
        }
    }
    for(int i = 0;i < 256;i++) {
        if(hash[i] != 0) {
            cout << "false";
            return 0;
        }
    }
    cout << "true" ;
    return 0;
}
