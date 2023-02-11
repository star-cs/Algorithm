/*
https://www.acwing.com/problem/content/1211/

分析：
1.      n = a + b / c
      c*n = a*c + b
2.  先枚举a (a < n ) ，再枚举c ， 得出 b ， 判断b的值是否正确。
*/

#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n ;
bool st[N] , backup[N];
int ans;

bool check(int a , int c)
{
    int b =  c * ( n - a );
    if(!b) return false;
    //拷贝st到backup
    memcpy(backup , st , sizeof st);
    while(b)
    {
        int x = b % 10;
        b /= 10;
        // x 不能为 0
        if(!x || backup[x])   return false;
        backup[x] = true;
    }

    for(int i = 1 ; i <= 9 ; i++)
        if(!backup[i])
            return false;

    return true;
}

void f_c(int u , int a , int c)
{
    if(u == n)   return;
    if(a && c)  
        if(check(a , c)) 
            ans++;

    for(int i = 1 ; i <= 9 ; i++)
        if(!st[i])
        {
            st[i] = true;
            f_c(u+1 , a , c*10 + i);
            st[i] = false;
        }
}

void f_a(int u , int a)
{
    if(a >= n)  return;
    f_c(u , a , 0);

    for(int i = 1 ; i <= 9 ; i++)
        if(!st[i])
        {
            st[i] = true;
            f_a(u+1, a * 10 + i);
            st[i] = false;
        }
}

int main()
{
    cin >> n;
    f_a(0 , 0);

    cout << ans << endl;
    return 0;
}