#include <iostream>
#include <cstring>
using namespace std;
// 一般N取 2~3 倍，发生冲突的概率小。
// 并且N位质数最佳。
const int N = 2000003 , null = 0x3f3f3f3f;

int h[N];

int find(int x)
{
    int k = (x % N + N)%N;
    while(h[k] != null && h[k] != x)
    {
        k ++;
        if(k == N)  k == 0;
    }
    return k;
}

int main()
{
    int n;
    scanf("%d" , &n);

    memset(h , 0x3f , sizeof h);

    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d" , op , &x);
        int t = find(x);
        if(*op == 'I')  h[t] = x;
        else
        {
            if(h[t]==null) puts("No");
			else puts("Yes");;
        }
    }
    return 0;
}