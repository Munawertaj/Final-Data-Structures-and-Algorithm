#include<bits/stdc++.h>
using namespace std;

// Defining a Class for the Node structure
// class Node {
//     public:
//         int data;   // Data stored in the node
//         Node* next; // Pointer to the next node in the list

//         // Constructor to initialize the node with a value
//         Node(int val)
//         {
//             data = val;
//             next = NULL;
//         }
// };

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
    cout<<"NULL";
}

int main()
{

    Node* head = NULL; // Initialize an empty list

    insertAtHead(head, 1); // Insert 1 at the head
    insertAtTail(head, 2); // Insert 2 at the tail
    insertAtTail(head, 3); // Insert 3 at the tail

    insertAtHead(head, 0); // Insert 4 at the head

    printList(head);

}