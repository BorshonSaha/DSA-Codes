#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void removeCycle(Node* head)
{
    Node *fastPtr = head, *slowPtr=head;

    do
    {
        fastPtr = fastPtr->next->next ;
        slowPtr = slowPtr->next ;
    }while(fastPtr != slowPtr) ;

    if(fastPtr == head)
    {
        while(slowPtr->next != head)
            slowPtr = slowPtr->next ;
        slowPtr->next = NULL ;
        return ;
    }
    fastPtr = head ;
    while(fastPtr->next != slowPtr->next){
        fastPtr = fastPtr->next ;
        slowPtr = slowPtr->next ;
    }
    slowPtr->next = NULL ;
}

bool detectCycle(Node *head)
{
    Node *slowPtr = head, *fastPtr = head;
    while(fastPtr != NULL && fastPtr->next != NULL)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr)
            return true;
    }
    return false;
}

void print(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Node n1(10);
    Node *head = &n1;

    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n2; /// making cycle

    removeCycle(head);

    detectCycle(head) ? cout<<"Has Cycle" : cout<<"No Cycle";
}

