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

Node* startingPointOfCycle(Node* head)
{
    if(head == NULL || head->next == NULL)
        return NULL;

    Node *fastPtr = head, *slowPtr = head;

    while(fastPtr != NULL && fastPtr->next != NULL) /// search for loop
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(fastPtr == slowPtr)
            break;
    }

    if(slowPtr != fastPtr) /// if loop does not exist
        return NULL;

    slowPtr = head;
    while(slowPtr != fastPtr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }
    return slowPtr;
}

int main()
{
    Node n1(10);
    Node *head = &n1;

    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);
    Node n6(60);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n1; /// &n3 / making cycle

    Node *res = startingPointOfCycle(head);
    res ? cout<<"Cycle starting node is : "<<res->data : cout << "Loop does not exist";
}


