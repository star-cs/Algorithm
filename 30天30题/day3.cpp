#include<bits/stdc++.h>

int Qsort(int A , int l , int r)
{
    if(l >= r)  return l;
    int i = l-1 , j = r+1 , x = A[l + r >>1];
    if(l < r)
    {
        while(A[++i] < x);
        while(A[--j] > x);
        if(i < j) swap(A[i] , A[j]);
    }
    Qsort(A , l , j);
    Qsort(A , j+1 , r);
}

int bsearch_l(int A[] , int n , int k)
{
    int l = 0 , r = n-1;
    while(l <= r)
    {
        int mid = l + r >> 1;
        if(A[mid] < k)  l = mid + 1;
        else r = mid;
    }
    return l;
}

int Function(int A[] , int B[] , int C[] , int n)
{
    int ans = 0;
    Qsort(A , 0 , n-1);
    Qsort(B , 0 , n-1);
    Qsort(C , 0 , n-1);
    int i = 0 , z = 0;
    for(int j = 0 ; j < n ; j++)
    {
        i = bsearch_l(A , B[j]);    //小于B[j]的边界
        z = bsearch_l(C , B[j]+1);  //小于B[j]+1的边界
        //每次折半查找可以利用上次的边界缩小范围
        ans += (i+1) * (n-z-1);
    }
    return ans;
}