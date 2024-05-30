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

Node* reverseIterative(Node* &head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    Node* prevPtr = NULL;
    Node* currPtr = head;
    Node* nextPtr;

    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    
    return prevPtr;

}

Node* reverseRecursive(Node* &head)
{
    if(head == NULL || head->next == NULL)
        return head;
    
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
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

    printList(head);

    head = reverseIterative(head);

    printList(head);

    head = reverseRecursive(head);

    printList(head);

    return 0;

}