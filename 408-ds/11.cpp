#include<bits/stdc++.h>
using namespace std;

/*
    时间复杂度 n
    空间复杂度 1

    ……没看到等长的条件
    
*/
int process(int arr1[] , int arr2[] , int n1 , int n2)
{
    int target = (n1 + n2 + 0.5)/2;
    int i , j= 0;
    // int num = 0;
    // while(num <= target)
    // {
    //     while(t2 < n2 && arr1[t1] >= arr2[t2] )   
    //     { 
    //         t2++; num++;
    //         //在里面，时刻判断num是否到达了平均值
    //         if(num == target)   return arr2[t2-1];
    //     }
        
    //     while(t1 < n1 && arr1[t1] < arr2[t2]) 
    //     { 
    //         t1++; num++;
    //         if(num == target)   return arr1[t1-1];
    //     }
    // }
    //精简代码
    while(i+j < target-1)
    {
        if(arr1[i] >= arr2[j])  j++;
        else i++;
    }

    return arr1[i] < arr2[j] ? arr1[i] : arr2[j];
}

/*
    题目说是两个等长有序序列

    最后的判断，很棒
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
