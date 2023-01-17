/*
给定一个n个点m条边的无向图，图中可能存在重边和自环。
请你判断这个图是否是二分图。
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 100010 , M = 2*N;
int n,m;
int h[N],e[M],ne[M],idx;
int color[N];
void add(int a , int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u , int c)
{
    color[u]=c;
    for(int i = h[u] ; i!=-1 ; i=ne[i]){
        int j = e[i];
        if(!color[j]){
            //  
            if( !dfs(j,3-c) )  return 0;
        }else if(color[j]==c) return 0;
    }
    return 1;
}


int main()
{
    scanf("%d%d" , &n , &m);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    bool flag = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!color[i]){
            if(!dfs(i , 1)){
                flag = 0;
                break;
            }
        }
    }
    if(flag)  puts("Yes");
    else puts("No");
    return 0;
}  