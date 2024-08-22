#include <bits/stdc++.h>
using namespace std;

//! Structure for double linked list

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

Node *constructDLL(vector<int> &arr)
{
    // code here
    Node *head = new Node(arr[0]);
    Node *temp = head;
    Node *prevs = NULL;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }
    return head;
}

//! add Node at a position
void addNode(Node *head, int pos, int data)
{
    Node *newNode = new Node(data);
    Node *cur = head;

    for (int i = 0; i < pos; i++)
    {
        cur = cur->next;
    }
    if (cur->next == NULL)
    {
        cur->next = newNode;
        newNode->prev = cur;
    }
    else
    {
        newNode->next = cur->next;
        cur->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = cur;
    }
}

//! delete a node from a specific position

Node *deleteNode(Node *head, int x)
{
    // Your code here
    Node *temp = head;
    int i = 1;
    while (i < x)
    {
        i++;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        temp->prev->next = NULL;
        temp->prev = NULL;
    }
    else if (temp->prev == NULL)
    {
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = NULL;
        temp->prev = NULL;
    }
    return head;
}

//! Reverse the doubly linked list

Node* reverseDLL(Node* head){
    if(head == NULL || head -> next == NULL) return head;
    Node *prevs = NULL;
    Node *current = head;
    while(current!=NULL){
        prevs = current -> next;
        current->prev = current -> next;
        current->next = prevs;
        current = current -> prev;
    }
    return prevs -> prev;
}

int main()
{
}