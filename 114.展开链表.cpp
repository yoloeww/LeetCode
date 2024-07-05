#include<iostream> 
#include<cstring>
#include<cstdio>
using namespace std
int stoii(char a[])//转换函数
{
    int len=strlen(a);//字符串长度
    int num=0,first;
    if(a[0]=='-') first=1;//如果是负数则从下一位开始转换
    else first=0;
    for(int i=first;i<len;i++)
    {
        num*=10;
        num+=int(a[i]-'0');
    }
    if(first) num*=-1;
    return num;
}
int main()
{
    char a[1000];
    gets(a);
    cout<<stoii(a);//a是需要转换的字符串
    return 0;
}
