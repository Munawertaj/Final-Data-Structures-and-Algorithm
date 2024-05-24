#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        Node* next;
        int data;

        Node(int val)
        {
            next = NULL;
            data = val;
        }
};

void insertAtFirst(Node* &head, int val)
{
    Node* newNode = new Node(val);

    newNode->next = head;
    head = newNode;
}

void insertAtLast(Node* &head, int val)
{
    if(head == NULL)
    {
        insertAtFirst(head, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp =  temp->next;
    }

    temp->next = newNode;
}

void deleteFromFirst(Node* &head, int position)
{
    Node* temp = head;
    Node* toDelete = NULL;

    // If First Node (head) to delete
    if(position == 0)
    {
        toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    int count = 1;

    while(temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }

    if(temp == NULL || temp ->next == NULL)
    {
        cout << "Deletion is not possible because K-th node is Out of bound!!!\n";
        return;
    }
    
    toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

void display(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int main()
{
    Node* head = NULL;

    insertAtLast(head, 1);
    insertAtLast(head, 2);
    insertAtLast(head, 3);
    // insertAtLast(head, 4);
    // insertAtLast(head, 5);
    // insertAtLast(head, 6);
    // insertAtLast(head, 7);
    // insertAtLast(head, 8);
    // insertAtFirst(head, 1);

    display(head);

    // Starting index from 0
    int deleteNode = 4; //It means it will delete 5-th node if first node is consider as 1

    deleteFromFirst(head, deleteNode);

    display(head);

}