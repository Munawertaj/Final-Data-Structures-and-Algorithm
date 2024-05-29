#include<bits/stdc++.h>
using namespace std;

// Defining the Node structure
struct Node {
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node in the list

    // Constructor to initialize the node with a value
    Node(int x) : data(x), next(NULL) {}
};

// Function to insert a node at the head of the list
void insertAtHead(Node* &head, int val)
{
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Function to insert a node at the tail of the list
void insertAtTail(Node* &head, int val)
{
    Node* newNode = new Node(val);

     // If the list is empty, insert the node at the head
    if(head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    Node* temp = head;

    // Traverse to the end of the list
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head)
{
    Node* temp = head;

    // Traverse to the end of the list
    while(temp != NULL)
    {
        cout<< temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n" ;
}

// Function to delete a node from the first (head)
Node* deleteFromFirst(Node* &head, int index)
{
    if (head == NULL || index == 0)
        return head;
    
    // A dummy node is created with the purpose of simply handle the edge cases
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* temp = dummy;
    Node* toDelete;
    int count = 1;

    // Traverse to the node just before the index to delete
    while(temp != NULL && count < index)
    {
        temp = temp->next;
        count++;
    }

    // If the index is out of bounds or the next node is NULL
    if(temp == NULL || temp->next == NULL)
    {
        cout << "K-th node is Out of bound!!!\n";
        return dummy->next;
    }
    
    toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;

    return dummy->next;
}

int main()
{
    Node* head = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    // insertAtTail(head, 4);
    // insertAtTail(head, 5);
    // insertAtTail(head, 6);
    // insertAtTail(head, 7);
    // insertAtTail(head, 8);

    printList(head);

    // Delete the node at index (indexing starts from 1)
    int deleteNode = 4;

    head = deleteFromFirst(head, deleteNode);

    printList(head);

}