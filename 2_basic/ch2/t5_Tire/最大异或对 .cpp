/*
在给定的 N 个整数 A1，A2……AN 中选出两个进行 xor （异或）运算，得到的结果最大是多少？

*** 如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为0。

输入格式
第一行输入一个整数 N。
第二行输入 N 个整数 A1～AN。

输出格式
输出一个整数表示答案。

数据范围
1≤N≤10^5
0≤Ai<2^31
*/

#include <iostream>
using namespace std;
const int N = 1e5 + 5 , M = 32 * N + 5;

int son[M][2] , idx ;
int a[N];

void insert(int x)
{
    int p = 0;
    for(int i = 30 ; i >= 0 ; i--)
    {
        int u = x >> i & 1;
        if(!son[p][u])  son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x)
{
    int p = 0;
    int t = 0;
    for(int i = 30 ; i >= 0 ; i--)
    {
        //u是0，那么就找1。没有1再找0。反之一样。
        int u = x >> i & 1;
        if(son[p][!u])
        {
            p = son[p][!u];
            t = t * 2 + !u;
        }else
        {
            p = son[p][u];
            t = t * 2 + u;
        }
    }
    return t;
}

int main()
{
    int n ;
    cin >> n;
    for(int i = 0 ; i < n ; i++)    cin >> a[i];
    int res = 0;
	for(int i=0;i<n;i++){
		insert(a[i]);
		int t = query(a[i]);
		res = max(res,a[i] ^ t);
	}
	cout<<res<<endl;
	return 0;
}