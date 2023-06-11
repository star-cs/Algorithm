#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    char data;
    struct Node *next;
}Node , *List;

/**
 * 创建一个带有头节点的链表并返回
 */
List create_list(const std::vector<char> &data) {
    if (data.empty()) {
        return NULL;
    }

    auto *head = (Node *) malloc(sizeof(Node));
    head->next = NULL;

    Node *p = head;
    for (char c: data) {
        auto *cur = (Node *) malloc(sizeof(Node));
        cur->data = c;
        cur->next = NULL;
        p->next = cur;
        p = cur;
    }

    return head;
}
/**
 * 获取链表长度并返回
 */
int get_len(List list) {
    int len = 0;
    while(list != NULL)
    {
        list = list->next;
        len++;
    }
    return len;
}

Node* find_same_Node(List A , List B)
{
    int len1 = get_len(A);
    int len2 = get_len(B);

    while(len1 > len2)
    {
        A = A->next;
        len1--;
    }
    while(len1 < len2)
    {
        B = B->next;
        len2--;
    }

    while(A != NULL && B != NULL)
    {
        if(A->data == B->data)
        {
            return A;
        }
        A = A->next;
        B = B->next;
    }
    return  NULL;
}

int main()
{
    List list1 = create_list(vector<char>{'l' ,'o' , 'a' , 'd' , 'i' , 'n' , 'g'});
    List list2 = create_list(vector<char>{'b' , 'e' , 'a' , 'n' , 'g'});
    Node* node1 = find_same_Node(list1 , list2);
    cout  << node1->data << endl;
}