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

//! Middle of list
Node *middleNode(Node *head)
{
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

//! Reverse a LL

Node *reverseLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *curr = head;
    Node *frwd = NULL;
    Node *prev = NULL;
    while (curr != NULL)
    {
        frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
    }
    return prev;
}

//! Has cycle

bool hasCycle(Node *head)
{
    if (head == NULL)
        return false;
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        if (fast == slow)
            return true;
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    return false;
}

//! Cycle 2

Node *detectCycle(Node *head)
{
    unordered_map<Node *, bool> maps;
    Node *temp = head;
    while (temp != NULL)
    {
        if (maps[temp])
        {
            return temp;
        }
        maps[temp] = true;
        temp = temp->next;
    }
    return NULL;
}

//! Length of loop cycle

int countNodesinLoop(Node *head)
{
    // Code here
    Node *slow = head, *fast = head;

    // Detect if a loop exists using Floyd's Cycle Detection Algorithm
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // Loop detected
        if (slow == fast)
        {
            int count = 1;
            Node *temp = slow;

            // Count the number of nodes in the loop
            while (temp->next != slow)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    // If no loop exists 
    return 0;
}

int main()
{
}