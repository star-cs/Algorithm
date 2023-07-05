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
void Merge(SqList A , SqList B , SqList &C)
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
void Reverse(SqList &A)
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
void R2(SqList &A, int left , int right)
{
    if(left < right)
    {
        swap(A.data[left] , A.data[right]);
        R2(A , left+1 , right-1);
    }
}

//Day04
//对长度为n的顺序表L,编写一个时间复杂度为O(n),空间复杂度为O(1)的算法,
//该算法删除线性表中所有值为x的数据元素

//双指针
//如果 k != i，那么k指向的一定是x
//知道i找到下一个非x的数值，可以直接替换k下标的数值
void Del_x(SqList &L , ElemType x)
{
    int i = 0 , k = 0;  //k下标左边均无x的值
    while(i < L.length)
    {
        if(L.data[i] == x)  i++;    //等于x，i下标右移
        else    //不等于x，将i指针的值复制到k下标
        {
            L.data[k] = L.data[i];
            k++; i++;
        }
    }
    L.length = k;
}

//精简版本
void Del_x(SqList &L , ElemType x)
{
    int i = 0 , k = 0;  //k下标指向，新顺序表的最右端节点+1的位置。
    while(i++ < L.length)
    {
        if(L.data[i] != x)
            L.data[k++] = L.data[i];
        }
    }
    L.length = k;
}


//Day05
//从顺序表中删除其值在给定值s与t之间(包含s和t,要求s < t）的所有元素
//如果s或t不合理或顺序表为空,则显示出错信息并退出运行
bool Del_form_s_to_t(SqList &L , ElemType s , ElemType t)
{
    if(s >= t || L.length == 0)  
    {
        return fasle;
    }
    int i = 0 , k = -1;     //k指向新顺序表的最右端节点
    while(i++ < L.length)
    {
        if( !(L.data[i] >= s && L.data[i] <= t) )  
        {   
            L.data[++k] = L.data[i];        //k下标先右移，再赋值。
        }
    }
    L.length = k+1;         //这里是和上一题k值设置的区别
    return true;
}