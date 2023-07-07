
#include <iostream>
using namespace std;
long long c[80];
int main() {
int a, b;
c[0] = 1;
c[1] = 1;
for (int i = 2; i < 80; i++) {
c[i] = c[i - 1] + c[i - 2];
}
while (cin >> a >> b) {
long long num = 0;
for (int i = a - 1; i < b; i++) {
num += c[i];
}
cout << num << endl;
}
}
