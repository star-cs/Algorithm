#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int primes[N] , cnt;
bool st[N];

void get_primes(int n)
{
    for(int i = 2; i <= n; i++)
    {
        if(!st[i])
        {
            primes[cnt++] = i;
            //埃氏筛法  O(n log log n) 
            for(int j = i+1 ; j < n ; j += i)   st[j] = true;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    get_primes(n);

    cout << cnt << endl;

    return 0;
}