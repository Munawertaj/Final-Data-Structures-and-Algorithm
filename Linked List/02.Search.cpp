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

// Function to search for a value in the linked list and return its index
int search(Node* &head, int key)
{
    int count = 0;
    Node* temp = head;

    // Traverse the list to find the key
    while (temp != NULL)
    {
        if (temp->data == key)
            return count;

        temp = temp->next;
        count++;
    }
    return -1; // Return -1 if the key is not found
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

    printList(head); // Print the list

    // Test search function
    int value = 1;
    int index = search(head, value);

    if (index >= 0)
        cout << "Found at index = " << index << endl;
    else
        cout << "Not Found" << endl;

    // Additional edge case: search for a value not in the list
    value = 7;
    index = search(head, value);

    if (index >= 0)
        cout << "Found at index = " << index << endl;
    else
        cout << "Not Found" << endl;

    // Additional edge case: print an empty list
    head = NULL;
    printList(head); // Should print "NULL"

    // Additional edge case: search in an empty list
    index = search(head, 1);
    if (index >= 0)
        cout << "Found at index = " << index << endl;
    else
        cout << "Not Found" << endl;

    return 0;

}