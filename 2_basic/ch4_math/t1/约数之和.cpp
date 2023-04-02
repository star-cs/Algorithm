#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

int main()
{
    int n;
    scanf("%d" , &n);
    ll ans = 1;
    unordered_map<int , int> hash;
    while(n--)
    {
        int x;
        cin >> x;
        for(int i = 2 ; i <= x / i ; i++)
        {
            while(x % i == 0)
            {
                x /= i;
                hash[i]++;
            }
        }
        if(x > 1)   hash[x]++;
    }
    for(auto i : hash)
    {
        ll p = i.first , a = i.second;
        ll tmp=1;
        //每次乘上 p+1
		while(a--) tmp = (tmp*p + 1) % mod;
		ans = ans *tmp % mod;
    }
    cout << ans << endl;
    return 0;
}