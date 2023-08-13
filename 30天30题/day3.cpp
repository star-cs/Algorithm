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
/*
方便划分边界的二分查找法

1. 建模：划分蓝红区域，确定 IsBlue（）
2. 确定返回 L 还是 R
3. 套用算法模板
4. (后处理……)，包含只有蓝色区域/红色区域的返回值处理问题等
*/
int Bsearch(int A[] , int n , int k)
{
    int l = -1 , r = n; 
    // 左右指针分别指向，满足条件的左右边界，不断往中间移动。
    while(l + 1 != r)
    {
        int m = A[l + r >> 1];
        if(m < k) l = m;
        else r = m; 
    }
    return r;   //满足条件的右边一位，方便计算ans
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
        i = bsearch_l(A , n , B[j]);    // i为，小于B[j]，右边一个点
        z = bsearch_l(C , n , B[j]+1);  // z为，小于B[j]+1，即大于B[j]，右边一个点。
        ans += i * (n-z);
    }
    return ans;
}