/*
给定一个n个点m条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出从1号点到n号点的最多经过k条边的最短距离，如果无法从1号点走到n号点，输出impossible。

注意：图中可能 存在负权回路 。
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 505 , M = 10010;
struct Node{
    int a , b , w;
}edge[M];

//back[]数组是上一次迭代后dist[]数组的备份，由于是每个点同时向外出发
//因此需要对dist[]数组进行备份，若不进行备份会因此发生串联效应，影响到下一个点
int dis[N] , backup[N];

int main()
{
    memset(dis , 0x3f , sizeof dis);
    
    dis[1] = 0;

    int n , m , k ;
    cin >> n >> m >> k;
    for(int i = 0 ; i < m ; i++)
        cin >> edge[i].a >> edge[i].b >> edge[i].w;

    for(int i = 1 ; i <= k ; i++)
    {
        memcpy(backup , dis , sizeof dis);  //备份
        for(int j = 0 ; j < m ; j++)
        {
            int a = edge[j].a;
            int b = edge[j].b;
            int w = edge[j].w;
            dis[b] = min(dis[b] , backup[a] + w);
        }
    }
    if(dis[n] > 0x3f3f3f3f/2)   cout << "impossible" << endl;
    else cout << dis[n] << endl;

    return 0;
}
