#include<bits/stdc++.h>
using namespace std;

//时间复杂度O(n)
int find_min(int arr[] , int len)
{
    int tar[10010];
    memset(tar , 0 , sizeof(tar));
    for(int i = 0 ; i < len ; i++)
    {
        if(arr[i] > 0)  tar[arr[i]] = 1;
    }

    for(int i = 1 ; i < 10010 ; i++)
    {
        if(tar[i] == 0) return i;
    }

    return 0;
}

int main()
{
    int arr[] = {-5, 3, 2, 3};
    cout << find_min(arr , 4);
    return 0;
}