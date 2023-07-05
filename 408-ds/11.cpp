#include<bits/stdc++.h>
using namespace std;

/*
    题目说是两个等长有序序列
*/
int find_mid(int A[] , int B[] , int len)
{
    int i = 0 , j = 0;
    while(i + j < len - 1)  //判断到平均值前一个数，平均值就在A[i],B[j]中取
    {
        if(A[i] <= B[j])
            i++;
        else
            j++;
    }
    return A[i] <= B[j] ? A[i] : B[j];
}

int main()
{
    int arr1[] = {9, 13, 15, 17, 19};
    int arr2[] = {2, 4, 8, 10, 11};
    
    cout << process(arr1, arr2, 5, 5) << endl;
    cout << find_mid(arr1 , arr2 , 5) << endl;

    return 0;
}
