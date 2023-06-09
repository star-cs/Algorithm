/*
    求 1 ~ n 中的每一个数的欧拉函数
*/
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 100010;
int prime[N] , cnt;
int phi[N];
bool st[N];

ll get_eulers(int n)
{
    phi[1] = 1;
    //线性筛
    for(int i = 2 ; i <= n ; i++)
    {
        if(!st[i])
        {
            prime[cnt ++] = i;
            phi[i] = i-1;
        }
        for(int j = 0 ; prime[j] <= n / i ; j++)
        {
            st[prime[j] * i] = true;
            if(i % prime[j] == 0)
            {
                /*
                    phi[i] 和 phi[i * prime[j] ]
                    都存在prime[j]这个质因数，所以两者的后半部分相同。
                    前半部分差距在与 phi[i * prime[j] ] = prime[j] * phi[i];
                */
                phi[i * prime[j] ] = prime[j] * phi[i];
                break;
            }
            /*
                如果phi[i]不存在prime[j]这个质因数
                那么，phi[i * prime[j] ] = prime[j] * i * .... * (1 - 1 / prime[j]);
            */
           phi[ i * prime[j] ] = phi[i] * (prime[j] - 1);
        }
    }
    ll res = 0;
    for(int i = 0 ; i <= n ; i++)   res += phi[i];
    return res;
}

int main()
{
    int n;
    cin >> n; 

    cout << get_eulers(n) << endl;

    return 0;
}