/*
给定一个n*m的二维整数数组，用来表示一个迷宫，数组中只包含0或1，其中0表示可以走的路，1表示不可通过的墙壁。

最初，有一个人位于左上角(1, 1)处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角(n, m)处，至少需要移动多少次。

数据保证(1, 1)处和(n, m)处的数字为0，且一定至少存在一条通路。
*/

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;  // 每个点的x,y信息
const int N = 110;
int mp[N][N];    //地图
int d[N][N];    //距离
PII q[N*N];     //模拟队列
int n , m;
int bfs()
{
    int hh = 0 , tt = 0;//hh指向队头元素，tt指向队尾元素 
    q[0] = {0 , 0};
    //初始化d[][]
    memset(d , -1 , sizeof(d));
    d[0][0] = 0;
    int dx[4] = {-1 , 0 , 0 , 1} , dy[4] = {0 , 1 , -1 , 0};
    while(hh <= tt)
    {
        auto t = q[hh++];
        for(int i = 0 ; i < 4 ; i++)
        {
            int x = t.first + dx[i] , y = t.second + dy[i];
            if(x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && mp[x][y] == 0)
            {
                d[x][y] = d[t.first][t.second]+1;
                q[++tt] = {x , y};
            }
        }
    }
    return d[n-1][m-1];
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mp[i][j];

    cout << bfs() << endl;
    return 0;
}