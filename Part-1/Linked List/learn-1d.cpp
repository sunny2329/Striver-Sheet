#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//! Array to linked list
Node *constructLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

//! Linked list insertion at end
Node *insertAtEnd(Node *head, int x)
{
    if (head == NULL)
    {
        head = new Node(x);
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new Node(x);
    return head;
}

//! Count linked list nodes
int getCount(Node *head)
{
    if (head == NULL)
        return 0;
    return 1 + getCount(head->next);
}

//! Search in linked list
bool searchKey(int n, Node *head, int key)
{
    if (head->data == key)
        return true;
    if (head == NULL || head->next == NULL)
        return false;
    return searchKey(n, head->next, key);
}

//! Delete Node in Linked list
void deleteNode(Node * node){
    Node *nxt = node -> next;
    Node * prev = NULL;
    while(nxt!=NULL){
        node -> data = nxt -> data;
        prev = node;
        node = nxt;
        nxt = nxt -> next;
    }
    prev -> next = NULL;
}



int main()
{
}