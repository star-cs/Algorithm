/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为正值。

请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出-1。

朴素dijkstra（解决稠密图）
1. 初始化 dist[1] = 0 , dist[i] = 无穷大。
    s：当前已确认最短距离的点
2. for i 1...n
    找到当前未再s中标记过且离圆点最近的点 -> t
    将该点进行标记                      -> s
    用t更新其他店的距离                 

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n , m;
int g[N][N];//邻接矩阵
int dist[N];
bool st[N];
int dijkstra()
{
    memset(dist , 0x3f , sizeof(dist));
    dist[1] = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int t = -1;
        //找到当前最短距离的点
        for(int j = 1 ; j <= n ; j++)
        {
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        }

        st[t] = 1;

        for(int j = 1; j <= n ; j++)
        {
            dist[j] = min(dist[j] , dist[t] + g[t][j]);
        }
    }
    //
    if(dist[n] == 0x3f3f3f3f)   return -1;
    else return dist[n];
}

int main()
{
    cin >> n >> m;
    //初始化邻接矩阵map
    memset(g , 0x3f , sizeof(g));
    while(m--)
    {
        int x , y , z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y] , z);
    }
    int t = dijkstra();
    cout << t << endl;
    return 0;
}