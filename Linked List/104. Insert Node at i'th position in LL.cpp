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

Node* insertNode(Node *head,int i,int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if(i == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    while(temp != NULL && count < i-1)
    {
        temp = temp->next;
        count++;
    }
    if(temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
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

Node* takeInput()
{
    int data;
    cin>>data;
    Node *head = NULL,*tail = NULL;
    while(data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    int data,i;
    cout<<"\n";
    cin>>data>>i;
    head=insertNode(head,i,data);
    print(head);
}


