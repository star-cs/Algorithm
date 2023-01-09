/*
给定一个模式串 S，以及一个模板串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。
模板串 P 在模式串 S 中多次作为子串出现。
求出模板串 P 在模式串 S 中所有出现的位置的起始下标。

输入格式
第一行输入整数 N，表示字符串 P 的长度。
第二行输入字符串 P。
第三行输入整数 M，表示字符串 S 的长度。
第四行输入字符串 S。

输出格式
共一行，输出所有出现位置的起始下标（下标从 0 开始计数），整数之间用空格隔开。

数据范围
1≤N≤10^5
1≤M≤10^6
*/
#include <iostream>


using namespace std;

const int N = 10010 , M = 100010;

int n , m;
char p[N] , s[M];
int ne[N];

int main()
{
    // p , s 从下标 1 开始输入
    cin >> n >> p + 1 >> m >> s + 1;

    //求ne[]，ne[1] = 0 ， 所以 i 从 2 开始，j从0开始
    for(int i = 2 , j = 0 ; i <= n ; i++)
    {
        while(j && p[i] != p[j+1])  j = ne[j];
        if(p[i] == p[j+1]) j++;
        ne[i] = j;  
    }

    //kmp匹配过程
    for(int i = 1 , j = 0 ; i <= m ; i++)
    {
        while( j && s[i] != p[j+1])  j = ne[j];
        if(s[i] == p[j+1])  j++;
        if(j == n)
        {
            //匹配成功
            printf("%d " , i - n);
            j = ne[j];
        }
    }
    return 0;
}