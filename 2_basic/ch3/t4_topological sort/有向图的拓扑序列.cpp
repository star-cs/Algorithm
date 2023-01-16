/*
给定一个n个点m条边的有向图，点的编号是1到n，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出-1。

若一个由图中所有点构成的序列A满足：对于图中的每条边(x, y)，x在A中都出现在y之前，则称A是该图的一个拓扑序列。
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int h[N] , e[N] , ne[N] , idx;
int q[N] , hh , tt , n , m;
int d[N];   //每个节点的入度，每次将入度为1的点添加进队列。更新队列时，更新其子节点的入度-1。
void add(int a , int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool dfs()
{
    for(int i = 1 ; i <= n ; i ++)
    {
        if(!d[i])   q[++tt] = i;    //将入度为0的添加到队列中去。
    }
    while(hh <= tt)
    {
        int t = q[hh++];
        for(int i = h[t] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if(d[j] == 0)   q[++tt] = j; 
        }
    }
    return tt == n-1;
}
int main()
{
    cin >> n >> m;
    memset(h , -1 , sizeof(h));
    while(m--)
    {
        int x , y;
        cin >> x >> y;
        d[y]++;
        add(x , y);
    }
    if(bfs())
    {
        for(int i = 0 ; i < n ; i++)
            cout << q[i] << " ";
    }
    else 
    {
        cout << -1;
    }
    cout << endls;
    return 0;
}