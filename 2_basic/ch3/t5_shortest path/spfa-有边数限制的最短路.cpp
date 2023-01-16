#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,dis[N];
bool st[N];//代表点是否在队列中
int h[N],e[N],ne[N],w[N],idx;
void add(int a,int b,int c){
	e[idx]=b;ne[idx]=h[a];w[idx]=c;h[a]=idx++;
}
int spfa(){
	queue<int> q;
	memset(dis,0x3f,sizeof dis);
	q.push(1);
	dis[1]=0;
	st[1]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		st[u]=0;
		for(int i=h[u];i!=-1;i=ne[i]){
			int v=e[i];
			if(dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				if(!st[v]){
					q.push(v);
					st[v]=1;
				}
			}
		}
	}
	if(dis[n]==0x3f3f3f3f) return -1;
	else return dis[n];
}
int main(){
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	int t=spfa();
	if(t==-1) puts("impossible");
	else printf("%d",t);
}
