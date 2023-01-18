#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if(n < 2)   return false; 
    //推荐写法 i <= n / i
    for(int i = 0 ; i <= n / i; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main()
{



}