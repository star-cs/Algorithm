#include <bits/stdc++.h>
using namespace std;

const int N = 1e7+10;

int n ;
int d[N];
int u , v;

int main()
{
    cin >> n;
        
    int p = 0;
    
    //EOF表示文件末尾
    while(scanf("%d" , &d[p++]) != EOF){}
    
    sort(d , d+p);
    
    for(int i = 0 ; i < p ; i++)
    {
        if(d[i]==d[i+1]) u=d[i];
        if(d[i]==d[i+1]-2) v=d[i];
    }
    
    cout << v+1 << " " << u << endl;
    
    return 0;
}