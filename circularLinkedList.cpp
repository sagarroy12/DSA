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
    }
};

void insertNodeafter(Node *&tail, int afterValue, int data)
{
    Node *n = new Node(data);
    if (tail == NULL)
    {
        tail = n;
        n->next = n;
    }
    else
    {
        Node *temp = tail;
        while (temp->data != afterValue)
        {
            temp = temp->next;
            if (temp == tail)
            {
                cout << "value not found and no insertion is persormed" << endl;
                return;
            }
        }
        n->next = temp->next;
        temp->next = n;
    }
}

void printList(Node *tail)
{
    Node *t = tail;
    if (t == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    else
    {

        do
        {
            cout << t->data << " ";
            t = t->next;
        } while (t != tail);
    }
}

void deleteNode(Node *&tail, int dValue)
{
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
    }
    else if (tail->data == dValue)
    {
        Node *te = tail;
        tail = tail->next;
        delete te;
    }
    else
    {
        Node *temp = tail;
        while (temp->next->data != dValue)
        {
            temp = temp->next;
        }
        Node *x = temp->next;
        temp->next = x->next;
        delete x;
    }
}

int main()
{

    Node *tail = NULL;
    insertNodeafter(tail, 2, 1);
    insertNodeafter(tail, 1, 2);
    insertNodeafter(tail, 2, 33);
    insertNodeafter(tail, 33, 223);
    deleteNode(tail, 33);
    printList(tail);

    return 0;
}