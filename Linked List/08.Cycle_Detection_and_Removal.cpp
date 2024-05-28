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

    display(head);

    makeCycle(head, 5);

    cout << detectCycle(head) << endl;
    cout << findCyclePosition(head) << endl;

    removeCycle(head);

    cout << detectCycle(head) << endl;
    
    return 0;

}