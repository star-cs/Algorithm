#include<bits/stdc++.h>
using namespace std;

const int MAXV = 500;

typedef struct{
    int numVertices , numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
}MGraph;

int IsExistEL(MGraph G)
{
    int t = 0;
    for(int i = 0 ; i < G.numVertices ; i++)
    {
        int a = 0;
        for(int j = 0 ; j < G.numVertices ; j++)
        {
            a += G.Edge[i][j];
        }
        if(a % 2 == 1)  t++;
    }
    if(t == 2 || t == 0)  return 1;   
    else return 0;    
}

int main()
{
    MGraph G;
    G.numVertices = 3;
    G.numEdges = 3;
    G.VerticesList[0] = 'a';
    G.VerticesList[1] = 'b';
    G.VerticesList[2] = 'c';
    G.Edge[0][1] = 1;   // a-b
    G.Edge[1][0] = 1;
    G.Edge[1][2] = 1;   // b-c
    G.Edge[2][1] = 1;
    G.Edge[0][2] = 1;   // a-c
    G.Edge[2][0] = 1;

    // 图中顶点的度均为2，即有0个度为奇数的顶点，故EL路径存在
    cout << IsExistEL(G);
    return 0;
}