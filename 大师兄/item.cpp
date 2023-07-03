 #include <stdio.h>
 #include <stdlib.h>
 
 typedef int ElemType;

//Day01
//在带头结点的单链表L中,删除所有值为x的结点,并释放其空间,假设值为x的结点不唯一
//编写算法以实现上述操作
void Del_x(LinkList &L , ElemType x)
{
    LNode *pre = L , *cnt = L->next;
    while(cnt != NULL)  
    {
        if(cnt->data == x) 
        {   
            LNode tem = cnt;        //待删除的节点
            pre->next = cnt->next;    
            cnt = cnt.next;         //pre保持不变，cnt移动
            free(tem);  
        }
        else
        {
            pre = cnt;
            cnt = cnt->next;
        }
    }
}

//Day02
//将两个有序顺序表合并为一个新的有序顺序表,并由函数返回结果顺序表
void Merge(SqlList A , SqlList B , SqlList &C)
{
    if(A.length + B.length > C.length)  
        return false;
    int i = 0 , j = 0 , z = 0;
    while(i < A.length && j < B.length)
    {
        if(A.data[i] <= B.data[j])
            C.data[z++] = A.data[i++];
        else
            C.data[z++] = B.data[j++];
    }
    while(i < A.length) C.data[z++] = A.data[i++];
    while(j < B.length) C.data[z++] = B.data[j++];
    C.length = z + 1;
    return true;
}


//Day03
//设计一个高效算法,将顺序表L的所有元素逆置,要求算法的空间复杂度为O(1)
// 1 2 3 4 5 6
// 5 4 3 2 1
void Reverse(SqlList &A)
{
    int i = 0 ,  j = A.length - 1; 
    while(i < j)
    {
        ElemType t = A.data[i];
        A.data[i] = A.data[j];
        A.data[j] = t;
        i++ , j--;
    }
}
//递归法
void R2(SqlList &A, int left , int right)
{
    if(left < right)
    {
        swap(A.data[left] , A.data[right]);
        R2(A , left+1 , right-1);
    }
}