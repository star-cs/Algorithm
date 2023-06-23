#include<bits/stdc++.h>
#include"ds.h"
using namespace std;

typedef struct node
{
    int data;
    struct node*next;
}NODE;
// //暴力，空间复杂度O(n)，不符合条件
// NODE find_NODE_by_idx(NODE head , int idx)
// {
//     NODE t = head;
//     while(idx--)
//     {
//         t = t->next;
//     }
//     return t;
// }

// NODE function(NODE head , int n)
// {
//     NODE temp = head;
//     NODE t1 = temp.next;
//     int i = 1 , mid = n/2 + 1;
//     while(i < mid)
//     {
//         t1.next = find_NODE_by_idx(n+i-1);
//         t1 = t1.next;
//         i++;
//     }
//     return head;
// }

//最优解
//快慢指针
NODE * function2(NODE *list , int n)
{
    NODE * t1 = list->next;
    NODE * t2 = list->next;

    int mid = n/2 + 1;
    while(mid --)   t2 = t2->next;

    NODE * next1 = t2->next;
    NODE * next2 = t2->next->next;

    //把后半段链表取反
    while(next2->next != NULL)   
    {
        next1->next = t2;
        t2 = next1;
        next1 = next2;
        next2 = next2->next;
    }

    while(t1 != t2)
    {
        t1->next = t2;
        t2->next = t1->next;
        
        t1 = t1->next;
        t2 = t2->next;
    }

    return list;
}

/**
 * 创建一个带有头节点的链表并返回
 */
NODE *create_list(const std::vector<int> &data) {
    if (data.empty()) {
        return NULL;
    }

    auto *head = (NODE *) malloc(sizeof(NODE));
    head->next = NULL;

    NODE *p = head;
    for (int i: data) {
        auto *cur = (NODE *) malloc(sizeof(NODE));
        cur->data = i;
        cur->next = NULL;
        p->next = cur;
        p = cur;
    }

    return head;
}
/**
 * 遍历链表结点值，返回如“1 -> 2 -> 3”的字符串，不接受空链表
 */
std::string to_string(NODE *list) {
    return list->next == NULL ?
           std::to_string(list->data) :
           std::to_string(list->data) + " -> " + to_string(list->next);
}


int mian()
{
    std::vector<int> data{1, 2, 3, 4, 5};
    NODE *list = create_list(data);
    function2(list , 5);
    string res = to_string(list->next);
    cout << res;
    //"1 -> 5 -> 2 -> 4 -> 3"
    return 0;
}