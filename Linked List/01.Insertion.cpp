#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
};

void insertAtHead(Node* &head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node* &head, int val)
{
    Node* newNode = new Node(val);

    if(head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout<< temp->data << " -> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

int main()
{

    Node* head = NULL;

    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);

    insertAtHead(head, 4);

    display(head);

}