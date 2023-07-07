#include <iostream>
using namespace std;
int fun(string &a,string &b) {
int cnt = 0;
for (int i = 0; i < a.size(); i += b.size()) {
if (a.substr(i,b.size()) == b)
cnt ++;
}
return cnt;
}
int main() {
string a,b;
while (cin >> a >> b) {
cout << fun(a,b) << endl;
}
return 0;
}
