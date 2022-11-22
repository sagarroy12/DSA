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



int main()
{

    Node *h1 = NULL;
    insertAtTail(h1, 2);
    insertAtTail(h1, 4);
    insertAtTail(h1, 6);
    insertAtTail(h1, 8);

    Node *h2 = NULL;
    insertAtTail(h2, 1);
    insertAtTail(h2, 3);
    insertAtTail(h2, 5);
    insertAtTail(h2, 7);

    sortList(h1, h2);
    printList(h1);

    return 0;
}