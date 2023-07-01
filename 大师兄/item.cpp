 #include <stdio.h>
 #include <stdlib.h>
 
//Day01
//在带头结点的单链表L中,删除所有值为x的结点,并释放其空间,假设值为x的结点不唯一
//编写算法以实现上述操作
void del_x(LinkList &L , ElemType x)
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