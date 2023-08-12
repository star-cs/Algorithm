#include<bits/stdc++.h>



int qsort(int A , int l , int r)
{
    if(l >= r)  return l;
    int i = l-1 , j = r+1 , x = A[l + r >>1];
    if(l < r)
    {
        while(A[++i] < x);
        while(A[--j] > x);
        if(i < j) swap(A[i] , A[j]);
    }
    qsort(A , l , j);
    qsort(A , j+1 , r);
}

int bsearch_l(int A[] , int l , int r , int k)
{
    while(l < r)
    {
        int x = A[l + r >> 1];
        if(x < k)   r = mid;
        else l = mid+1;
    }
    return l;
}

int function(int A[] , int B[] , int C[] , int n)
{
    int ans = 0;
    qsort(A , 0 , n-1);
    qsort(B , 0 , n-1);
    qsort(C , 0 , n-1);
    int i = 0 , z = 0;
    for(int j = 0 ; j < n ; j++)
    {
        i = bsearch_l(A , i , n-1 , B[j]);//查找小于B[j]的右边界
        z = bsearch_l(C , z , n-1 , B[j]+1);//查找小于B[j]+1的右边界，z右侧的数大于B[j]
        //每次折半查找可以利用上次的边界缩小范围
        ans += (i+1) * (n-z+1);
    }
    return ans;
}
