/*
给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。

输入格式
第一行包含整数 N，表示数列长度。
第二行包含 N 个整数，表示整数数列。

输出格式
共一行，包含 N 个整数，其中第 i 个数表示第 i 个数的左边第一个比它小的数，如果不存在则输出 −1。

数据范围
1≤N≤10^5
1≤数列中元素≤10^9
*/

#include <iostream>

using namespace std;

const int N = 100010;

int n , stk[N] , tt;

int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        int x ;
        cin >> x;
        while(tt && stk[tt] >= x )  tt--;    //一直出栈，直到找到第一个比栈顶小的元素
        if(tt) cout << stk[tt] << " ";    
        else
        {
            cout << -1 << " ";
        }
        stk[++tt] = x;
    }
    //整体的单调栈的结构一定是单调性的。
    return 0;
}