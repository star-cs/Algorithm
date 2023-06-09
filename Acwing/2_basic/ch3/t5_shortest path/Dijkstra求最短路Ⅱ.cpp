/*
给定一个n个点m条边的有向图，图中可能存在重边和自环，所有边权均为非负值。

请你求出1号点到n号点的最短距离，如果无法从1号点走到n号点，则输出-1。

针对稀疏图，我们采用邻接表法
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10 , M = 2*N;
typedef pair<int , int> PII;    //以及当前点到1号点的距离，存放点的实际数值。

int h[N] , e[M] , ne[M] , w[N] , idx;   //w[]每条边的权重
int n , m;
int dist[N];
bool st[N];

void add(int a , int b , int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int dijkstra()
{

    priority_queue<PII , vector<PII> , greater<PII>>  heap;   //小根堆
    heap.push({0,1});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second , distance = t.first;
        if(st[ver]) continue;
        st[ver] = 1;
        for(int i = h[ver] ; i != -1 ; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j] , j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    cin >> n >> m;
    memset(h , -1 , sizeof h);
    memset(dist , 0x3f , sizeof dist);
    dist[1] = 0;

    while(m--)
    {
        int x , y , z;
        cin >> x >> y >> z;
        add(x , y , z);
    }
    cout << dijkstra() << endl;
    return 0;
}