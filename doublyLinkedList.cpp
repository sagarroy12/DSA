#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev = NULL;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void insertAtEnd(Node *&head, int data)
{

    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }
    else
    {
        Node *h = head;

        while (h->next != NULL)
        {
            h = h->next;
        }
        Node *n = new Node(data);
        n->prev = h;
        h->next = n;
    }
}

void insertAtPosition(Node *&head, int position, int data)
{
    if (position == 1)
    {
        insertAtHead(head, data);
    }
    else
    {
        Node *t = head;
        for (int i = 1; i < position - 1; i++)
        {
            t = t->next;
            if (t == NULL)
            {
                cout << "invalid position" << endl;
                return;
            }
        }
        Node *n = new Node(data);
        n->next = t->next;
        n->prev = t;
        t->next->prev = n;
        t->next = n;
    }
}

void deleteNode(Node *&head, int position)
{
    Node *temp;
    if (position == 1)
    {

        temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    else
    {
        Node *t = head;
        for (int i = 1; i < position - 1; i++)
        {
            t = t->next;
        }
        temp = t->next;
        t->next = temp->next;
        temp->next->prev = t;
        delete temp;
    }
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{

    Node *head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtPosition(head, 3, 33);
    insertAtEnd(head, 8);
    deleteNode(head, 4);

    printList(head);

    return 0;
}