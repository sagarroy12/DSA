#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
        // this->next = NULL;
    }
};

void deleteHead(Node *&head)
{
    if (head->next == NULL)
    {
        delete head;
    }
    else
    {
        Node *t = head;
        head = head->next;
        delete t;
    }
}

void deleteN(Node *&head, int position)
{
    if (position == 1)
    {
        deleteHead(head);
    }
    else
    {
        Node *t = head;
        for (int i = 1; i < position - 1; i++)
        {
            t = t->next;
            if (t == NULL)
            {
                cout << "list ka bahar aa gya" << endl;
                return;
            }
        }
        Node *bakra = t->next;
        t->next = bakra->next;
        delete bakra;
    }
}

void insertAtHead(Node *&head, int x)
{
    Node *t = new Node(x);
    t->next = head;
    head = t;
}

void insertAtTail(Node *&head, int x)
{
    Node *temp = head;
    Node *t = new Node(x);

    if (head == NULL)
    {
        head = t;
    }
    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = t;
    }
}

void insertAtPosition(Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
    }
    Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "position not valid" << endl;
            return;
        }
    }
    Node *t = new Node(data);
    t->next = temp->next;
    temp->next = t;
}

void printList(Node *h)
{
    if (h == NULL)
    {
        cout << "list is empty" << endl;
    }
    else
    {
        do
        {
            cout << h->data << " ";
            h = h->next;
        } while (h != NULL);
    }
    cout << endl;
}

void reverseList(Node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *prev = NULL;
    Node *n = NULL;
    while (head->next != NULL)
    {
        n = head->next;
        head->next = prev;
        prev = head;
        head = n;
    }
    head->next = prev;
}

void reverseListR(Node *&head, Node *prev, Node *forward)
{

    if (forward->next == NULL)
    {
        head->next = prev;
        return;
    }

    forward = head->next;
    head->next = prev;
    prev = head;
    head = forward;
    reverseListR(head, prev, forward);
}

Node *findMiddle(Node *head)
{
    Node *j = head;
    Node *j2 = head->next;
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    else
    {

        while (j2 != NULL && j2->next != NULL)
        {
            j = j->next;
            j2 = j2->next->next;
        }

        return j;
    }
}

Node *reverseKNodes(Node *head, int k)
{

    if (head == NULL)
    {
        return NULL;
    }

    Node *currentN = head;
    Node *frontN = NULL;
    Node *prevN = NULL;
    int count = 0;

    while (currentN != NULL && count < k)
    {
        frontN = currentN->next;
        currentN->next = prevN;
        prevN = currentN;
        currentN = frontN;
        count++;
    }
    if (frontN != NULL)
    {
        head->next = reverseKNodes(frontN, k);
    }
    return prevN;
}

// return the node where the loop starts
// assuming that the loop is  present;
// can also make a function that check for the loop and return bool.
Node *detectStartingNodeofL(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != fast)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow = head;
    while (slow != head)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void removeLoop(Node *head)
{
    Node *loopAt = detectStartingNodeofL(head);
    Node *t = loopAt;
    while (t->next != loopAt)
    {
        t = t->next;
    }
    t->next = NULL;
}

// remove dublicate when list is sorted
void removeDublicateS(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    while (head->next != NULL)
    {
        Node *t = head->next;
        if (t->data == head->data)
        {
            head->next = t->next;
            delete t;
        }
        if (head->data != head->next->data)
        {
            head = head->next;
        }
    }
}

// remove dublicate when list is unsorted
void removeDublicateUS(Node *head)
{
    Node *temp = NULL;

    for (Node *i = head; i->next != NULL; i = i->next)
    {
        for (Node *j = i; j->next != NULL; j = j->next)
        {
            if (i->data == j->next->data)
            {
                temp = j->next;
                j->next = temp->next;
                delete temp;
            }
        }
    }
}
// take two sorted linked list and merge them in sorted order.
Node *sortList(Node *h1, Node *h2)
{
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }

    Node *n = new Node(-1);
    Node *temp = n;
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            temp->next = h1;
            temp = h1;
            h1= h1->next;
        }
        else
        {
            temp->next = h2;
            temp = h2;
            h2 = h2->next;
        }
    }
    if (h1 != NULL)
    {
        temp->next = h1;
    }
    if (h2 != NULL)
    {
        temp->next = h2;
    }
    n = n->next;
    return n;
}

bool palindrome(Node *head)
{
    Node *mid = findMiddle(head);

    reverseList(mid);
    while (head != NULL && mid != NULL)
    {
        if (head->data != mid->data)
        {
            return false;
        }
        else
        {
            head = head->next;
            mid = mid->next;
        }
    }
    return true;
}

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *mid = findMiddle(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = sortList(left);
    right = sortList(right);
    Node *result = sortList(left, right);
    return result;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtTail(head, 1);
    insertAtTail(head, 33);
    insertAtTail(head, 75);
    insertAtTail(head, 27);
    insertAtTail(head, 74);
    insertAtTail(head, 15);
    insertAtTail(head, 125);
    insertAtTail(head, 145);
    printList(head);

    head = sortList(head);

    printList(head);

    return 0;
}