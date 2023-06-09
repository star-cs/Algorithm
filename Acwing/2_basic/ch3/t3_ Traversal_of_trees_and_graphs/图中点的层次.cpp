/*
给定一个n个点m条边的有向图，图中可能存在重边和自环。

所有边的长度都是1，点的编号为1~n。

请你求出1号点到n号点的最短距离，如果从1号点无法走到n号点，输出-1。
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5 , M = N * 2;
int n , m;
int h[N] , e[M] , ne[M] , idx;
int d[N];

void add(int a , int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void bfs()
{
    memset(d , -1 , sizeof(d));
    d[1] = 0;

    int q[N] , hh = 0 , tt = 0;     //队列存储的是
    q[hh] = 1;
   
    while(hh <= tt)
    {
        int u = q[hh++];
        for(int i = h[u] ; i != -1 ; i = ne[i])
        {
            int v = e[i];
            if(d[v] == -1)
            {
                d[v] = d[u] + 1;
                q[++tt] = v;
            }
        }
    }
    return d[n];
}

int main()
{
    cin >> n >> m;
    memset(h , -1 , sizeof(h));
    while(m--)
    {
        int a , b;
        cin >> a >> b;
        add(a , b);
    }
    cout << bfs() << endls;
    return 0;
}