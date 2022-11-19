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
    if (head == NULL)
    {
        return head;
    }
    else
    {
        Node *j = head;
        Node *j2 = head;
        while (j2->next != NULL)
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

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);

    printList(head);
    cout << endl;
    // reverseList(head);
    // Node *prev = NULL;
    // Node *forward = head;
    // reverseListR(head, prev, forward);
    // printList(head);
    // cout<<endl;
    // Node *middleNode = findMiddle(head);
    // cout<<middleNode->data;

    head = reverseKNodes(head, 3);
    printList(head);

    return 0;
}
