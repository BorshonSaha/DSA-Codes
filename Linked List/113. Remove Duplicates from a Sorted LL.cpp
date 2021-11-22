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

Node* removeDuplicates(Node *head)
{
    Node *temp = head;
    if(temp == NULL)
        return NULL;

    while(temp->next != NULL)
    {
        if(temp->data == temp->next->data)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
    return head;
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
    Node n3(20);
    Node n4(40);
    Node n5(50);
    Node n6(50);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    print(head);

    head = removeDuplicates(head);
    cout<<"\n";
    print(head);
}
