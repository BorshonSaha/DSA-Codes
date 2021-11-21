#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

Node* reverseKnodesLL(Node *head, int k)
{
    if(head == NULL)
        return NULL;

    Node *prevPtr = NULL, *currPtr = head, *nextPtr = NULL;
    int count = 0;

    /// reverse first k nodes
    while(currPtr != NULL && count < k)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
        count++;
    }

    /// reverse rest of the k nodes
    if(nextPtr != NULL)
        head->next = reverseKnodesLL(nextPtr, k);

    return prevPtr;
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

    head = reverseKnodesLL(head, 3);

    print(head);
}

