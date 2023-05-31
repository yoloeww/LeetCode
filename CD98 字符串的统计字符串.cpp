#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int num = 1;
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == s[i-1])
            num ++;
        else
        {
            cout << s[i - 1] << "_" << num << "_" ;
            num = 1;
        }
    }
    cout << s[s.size()-1] << "_" << num << endl; //  //因为每次是遇到不同字符才会打印所以最后一个字符会漏掉
    return 0;
}
// 64 位输出请用 printf("%lld")
