/*
    |n1-n2|最小，两个集合尽量相等
    |S1-S2|最大，A集合最大值和最小值分开
*/

#include<bits/stdc++.h>
using namespace std;

void _sort(int arr[] , int left , int right)
{
    if(left >= right)
        return;
    int x = arr[left] , i = left - 1 , j = right + 1;
    while(i < j)
    {
        while(arr[++i] < x);
        while(arr[--j] > x);
        if(i < j)
            swap(arr[i] , arr[j]);
    }
    _sort(arr , left , i);
    _sort(arr , i+1 , right);
}

int fun(int arr[] , int len)
{
    //排序 快排
    _sort(arr , 0 , len-1);

    int mid = len / 2;

    int i = 0 , s1 = 0 , s2 = 0 ;
    while (i <= mid) {
        s1 += arr[i++];
    }
    while (i < len) {
        s2 += arr[i++];
    }

    return s2 - s1;
}

int main()
{
    int A[10] = {1,2,3,4,5,657,7676,75,8,876};
    _sort(A , 0 , 9);
    for(int a : A)
        cout << a << " ";
    cout << endl;
    cout << fun(A , 10);
}