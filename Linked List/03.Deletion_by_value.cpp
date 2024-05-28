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

// Function to delete the head node
void deleteAtHead(Node* &head)
{
    if (head == NULL)
        return; // If the list is empty, do nothing

    Node* toDelete = head;
    head = head->next;
    delete toDelete;
}

// Function to delete a node by value
void deleteByValue(Node* &head, int val)
{
    if (head == NULL)
        return; // If the list is empty, do nothing

    // If the head node holds the value to be deleted
    if (head->data == val)
    {
        deleteAtHead(head);
        return;
    }

    Node* temp = head;

    // Traverse the list to find the node to delete
    while (temp->next != NULL && temp->next->data != val)
    {
        temp = temp->next;
    }

    // If the node with the value is not found
    if (temp->next == NULL)
        return;

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

int main()
{

    Node* head = NULL; // Initialize an empty list

    // Test insertions at the tail
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);

    printList(head); // Print the list
    cout << endl;

    // Test deleteByValue function
    deleteByValue(head, 1); // Delete the head node
    printList(head); // Print the list after deletion
    cout << endl;

    deleteByValue(head, 6); // Delete the tail node
    printList(head); // Print the list after deletion
    cout << endl;
    
    deleteByValue(head, 4); // Delete a middle node
    printList(head); // Print the list after deletion
    cout << endl;
    
    deleteByValue(head, 10); // Try to delete a non-existent value
    printList(head); // Print the list to confirm no change
    cout << endl;
    
    // Additional edge case: deleting from an empty list
    head = NULL;
    deleteByValue(head, 1); // Should handle gracefully
    printList(head); // Should print "NULL"

    return 0;

}