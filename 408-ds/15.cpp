#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
    int data;
    struct Node * link;
}Node , *List;

/**
 * 创建一个带有头节点的链表并返回
 */
List create_list(const std::vector<int> &data) {
    if (data.empty()) {
        return NULL;
    }

    auto *head = (Node *) malloc(sizeof(Node));
    head->link = NULL;

    Node *p = head;
    for (int i: data) {
        auto *cur = (Node *) malloc(sizeof(Node));
        cur->data = i;
        cur->link = NULL;
        p->link = cur;
        p = cur;
    }

    return head;
}

/**
 * 遍历链表结点值，返回如“1 -> 2 -> 3”的字符串，不接受空链表
 */
std::string to_string(List list) {
    return list->link == NULL ?
           std::to_string(list->data) :
           std::to_string(list->data) + " -> " + to_string(list->link);
}

//空间换时间
void fun(List list , int m , int n)
{
    int arr[n];
    memset(arr , 0 , sizeof(arr));
    Node *t1 = list;
    while(t1->link != NULL)
    {   
        //每次对下一个的data进行判断
        int da = abs(t1->link->data);
        if(arr[da] == 0)
        {
            arr[da] = 1;
            //下一个值data没有问题，t1往前移动
            t1 = t1->link;
        }
        else
        {  
            //不能确认link的link符合条件,t1不能往前移动,只能将link删除
            t1->link = t1->link->link;
        }
    }
}

int main()
{
    //vector<int> v = {1,2,3,4,5,6,7,3,4,5,2,1};
    //vector<int> v = {21, -15, -15, -7, 15};
    vector<int> v = {1, -1, 1, -4, -1, -9, 4, -9, 9};
    List list = create_list(v);
    cout << to_string(list) << endl;
    fun(list , 12 , 100);
    cout << to_string(list) << endl;
}