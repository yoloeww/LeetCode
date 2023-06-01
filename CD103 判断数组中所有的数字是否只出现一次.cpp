#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int,int>hash;
    vector<int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        hash[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (hash[a[i] > 1]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
