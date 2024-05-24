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
    cout<<"NULL\n";
}

void deleteAtHead(Node* &head, int val)
{
    Node* toDelete = head;
    head = head->next;

    delete toDelete;
}

void deleteByValue(Node* &head, int val)
{
    if(head == NULL)
        return;
        
    if(head->data == val)
    {
        deleteAtHead(head, val);
        return;
    }

    Node* temp = head;
    while(temp->next->data != val)
    {
        temp = temp->next;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

int main()
{

    Node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);

    display(head);

    deleteByValue(head, 1);

    display(head);

}