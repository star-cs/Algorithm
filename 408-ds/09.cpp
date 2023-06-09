#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
typedef int ElemType;

typedef struct Node
{
    /* data */
    int data;
    struct Node *link;  
} Node1 , *List;

/**
 * 创建一个带有头节点的链表并返回
 */
List create_list(const std::vector<ElemType> &data) {
    if (data.empty()) {
        return NULL;
    }

    auto *head = (Node *) malloc(sizeof(Node));
    head->link = NULL;

    Node *p = head;
    for (ElemType i: data) {
        auto *cur = (Node *) malloc(sizeof(Node));
        cur->data = i;
        cur->link = NULL;
        p->link = cur;
        p = cur;
    }

    return head;
}

int search1(List list , int k)
{
    int len = 0;
    Node *p = list->link;
    while(p != NULL)
    {
        p = p->link;
        len++;
    }
    if(len < k)
    {
        return 0;
    }
    int cnt = len - k;
    p = list->link;
    while(cnt--)
    {
        p = p->link;
    }
    printf("%d\n" , p->data);
    return 1;    
}

int search2(List list , int k)
{
    Node *p1 = list->link , *p2 = list->link;
    int cnt = 0;
    while(p1 != NULL)
    {
        if(cnt < k) {
            cnt++;
        } else {
            p2 = p2->link;
        }
        p1 = p1->link;
    }
    if(cnt  < k)
    {
        return 0;
    }
    printf("%d\n", p2->data);
    return 1;
}

int main()
{
    vector<int> data{1,2,3,4,5,6,7,8,9,10};
    List list = create_list(data);
    
    DWORD start1 = GetTickCount();
	search1(list , 3);
	DWORD end1 = GetTickCount();
	cout<<"程序运行时间为："<<(end1 - start1)<<"毫秒！"<<endl;
    
    DWORD start2 = GetTickCount();
	search2(list , 3);
	DWORD end2 = GetTickCount();
	cout<<"程序运行时间为："<<(end2 - start2)<<"毫秒！"<<endl;


	return 0;
}
