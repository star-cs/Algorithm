/*
给定一个n个点m条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出impossible。

给定一张边带权的无向图G=(V, E)，其中V表示图中点的集合，E表示图中边的集合，n=|V|，m=|E|。

由V中的全部n个顶点和E中n-1条边构成的无向连通子图被称为G的一棵生成树，其中边的权值之和最小的生成树被称为无向图G的最小生成树。
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 510 , INF = 0x3f3f3f3f;
/*
S:当前已经在联通块中的所有点的集合
1. dist[i] = inf
2. for n 次
    t<-S外离S最近的点
    利用t更新S外点到S的距离
    st[t] = true
n次迭代之后所有点都已加入到S中
联系：Dijkstra算法是更新到起始点的距离，Prim是更新到集合S的距离
*/
int n , m;
int g[N][N] , dist[N];
bool st[N];

int prim()
{
    //如果图不连通返回INF, 否则返回res
    memset(dist, INF, sizeof dist);
    int res = 0;

    for(int i = 0 ; i < n ; i++)
    {
        int t = -1;
        for(int j = 1 ; j <= n ; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;

        //保存
        if(t) res += dist[t];

        //更新
        for(int j = 1 ; j <= n ; j++)   dist[j] = min(dist[j] , g[t][j]);
    }
    return res;
}

int main()
{
    scanf("%d%d" , &n , &m);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i ==j) g[i][j] = 0;
            else g[i][j] = INF;

    while(m--) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(g[u][v], w);
    }

    int t = prim();
    //临时存储防止执行两次函数导致最后仅返回0
    if(t == INF) puts("impossible");
    else cout << t << endl;
}
