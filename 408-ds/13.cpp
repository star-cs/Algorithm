#include<bits/stdc++.h>
using namespace std;

//找出序列中出现频率大于一半的数
//时间 nlogn    空间 1
int find_prime_node(vector<int> v , int len)
{
    sort(v.begin() , v.end());
    int t = v[0];
    int num = 0;
    for(int a : v)
    {  
        if(a == t)  
        {
            num++;
            if(num > len/2)
            {
                return t;
            }
        }
        else
        {
            num = 1;
            t = a;
        }
    }

    return -1;
}


int main()
{
    vector<int> arr = {0, 5, 5, 3, 5, 9, 3, 5 , 6 , 5 , 5};
    cout << find_prime_node(arr , 11);
    return 0;
}