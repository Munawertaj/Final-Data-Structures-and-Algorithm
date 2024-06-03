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

void makeCycle(Node* &head, int position)
{
    Node* temp = head;
    Node* cycleNode;

    int count = 1;
    while(temp->next != NULL)
    {
        if(count == position)
            cycleNode = temp;
        
        temp = temp->next;
        count++;
    }

    temp->next = cycleNode;
}

void removeCycle(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast);

    if(fast == head)
    {
        while(slow->next != head)
        {
            slow = slow->next;
        }
        
        slow->next = NULL;
        return;
    }

    fast = head;
    while(slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

int findCyclePosition(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast);

    fast = head;
    int count = 1;
    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        count++;
    }

    return count;
}

bool detectCycle(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }

    return false;
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

    makeCycle(head, 1);

    cout << detectCycle(head) << endl;
    cout << findCyclePosition(head) << endl;

    removeCycle(head);

    cout << detectCycle(head) << endl;
    
    return 0;

}