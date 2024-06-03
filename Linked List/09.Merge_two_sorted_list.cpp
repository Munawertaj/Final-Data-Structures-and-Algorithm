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

// Function to merge two sorted linked lists
Node* mergeTwoLists(Node* &list1, Node* &list2)
{
    // Create a dummy node to form the base of the merged list
    Node* dummyNode = new Node(-1);
    Node* ptr = dummyNode;

    Node* ptr1 = list1;
    Node* ptr2 = list2;

    // Traverse both lists and append the smaller value to the merged list
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->data < ptr2->data)
        {
            ptr->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr->next = ptr2;
            ptr2 = ptr2->next;
        }

        // Move the pointer to the next node in the merged list
        ptr = ptr->next;
    }

    // If there are remaining nodes in list1, append them to the merged list
    while(ptr1 != NULL)
    {
        ptr->next = ptr1;
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }

    // If there are remaining nodes in list2, append them to the merged list
    while(ptr2 != NULL)
    {
        ptr->next = ptr2;
        ptr = ptr->next;
        ptr2 = ptr2->next;
    }

    // Return the next of dummy node as the head of the merged list
    return dummyNode->next;
}

int main()
{
    // Create the first linked list and insert values
    Node* head1 = NULL;

    insertAtTail(head1, 2);
    insertAtTail(head1, 3);
    insertAtTail(head1, 6);
    insertAtTail(head1, 8);
    insertAtTail(head1, 9);
    insertAtTail(head1, 10);

    // Print the first linked list
    printList(head1);

    // Create the second linked list and insert values
    Node* head2 = NULL;

    insertAtTail(head2, 1);
    insertAtTail(head2, 2);
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    insertAtTail(head2, 7);
    insertAtTail(head2, 11);

    // Print the second linked list
    printList(head2);

    // Merge the two linked lists
    Node* newHead = mergeTwoLists(head1, head2);

    // Print the merged linked list
    printList(newHead);

    return 0;
}
