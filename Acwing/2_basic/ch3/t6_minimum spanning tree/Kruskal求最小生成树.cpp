#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n , m;
int p[N];   

struct Edge
{
    int u , v , w;
    bool operator< (const Edge* e) const
    {
        return w < e.w;
    }
}edge[N];

int find(int x)
{
    if(p[x] != x)   p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d" , &n , &m);
    
    for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[i]={u,v,w};
	}
	sort(edge,edge+m);

	for(int i=1 ; i<=n ; i++) p[i]=i;

    int res , cnt;
    
    for(int i = 0 ; i < w ; i++)
    {
        int u = edge[i].u , v = edge[i].v , w = edge[i].w;
        u = find(u);
        v = find(v);
        if(u != v)
        {
            res += w;
            p[u] = v;
            cnt++;
        }
    }
    if(cnt < n-1) puts("impossible");
	else printf("%d",res);
}
