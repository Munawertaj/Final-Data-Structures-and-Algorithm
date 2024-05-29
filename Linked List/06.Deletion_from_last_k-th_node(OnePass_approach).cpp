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

void deleteFromLast(Node* &head, int index)
{
    if (head == NULL || index == 0)
        return;
    
    // A dummy node is created with the purpose of simply handle the edge cases
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* forward = dummy;
    Node* backward = dummy;

    int count = 0;

    // Traverse the forward node to the index
    while(forward != NULL && count <= index)
    {
        forward = forward->next;
        count++;
    }

    // If forward pointer Traverse to the end (If index is larger than the list size)
    if(count <= index)
    {
        cout << "Deletion is not possible!!!\n";
        head = dummy->next;
        return;
    }

    
    while(forward != NULL)
    {
        forward = forward->next;
        backward = backward->next;
    }

    Node* toDelete = backward->next;
    backward->next = backward->next->next;
    delete toDelete;
    
    head = dummy->next;
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
    insertAtTail(head, 7);
    insertAtTail(head, 8);

    printList(head);

    
    int deleteNodeIndex = 6; 


    deleteFromLast(head, deleteNodeIndex);

    printList(head);

}