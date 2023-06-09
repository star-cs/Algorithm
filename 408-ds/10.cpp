#include<bits/stdc++.h>
using namespace std;
/*
    0 1 2 3 | 4 5 6 7 8 9 
    3 2 1 0 | 9 8 7 6 5 4 
    4 5 6 7 8 9 0 1 2 3 4
*/

void reserve(int arr[] ,int l ,int r)
{
    int t = (r+l)/2;
    while(l <= t)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++ , r--;
    }
}

void fun(int arr[] ,  int k , int n)
{
    int r = 0;
    reserve(arr , 0 , k-1 );
    reserve(arr , k , n-1);
    reserve(arr , 0 , n-1);
}

/**
 * 打印数组，返回字符串
 */
string print_array(int arr[], int n) {
    stringstream ss;
    for (int i = 0; i < n; i++) {
        ss << arr[i];
        if (i != n - 1) {
            ss << " ";
        }
    }
    return ss.str();
}


int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fun(arr, 3, 10);
    cout << print_array(arr , 10);
    return 0;
}