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

void deleteHead(Node* &head){
    if(head->next == NULL){
        delete head;
    }else{
        Node *t = head;
        head = head->next;
        delete t;

    }
}

void deleteN(Node* &head, int position){
    if(position == 1){
        deleteHead(head);
    }
    else{
        Node *t = head;
        for(int i=1;i<position-1;i++){
            t = t->next;
            if(t==NULL){
                cout<<"list ka bahar aa gya"<<endl;
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

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, 22);
    insertAtTail(head, 233);
    insertAtTail(head, 234);
    insertAtTail(head, 444);
    insertAtHead(head, 49494);
    insertAtPosition(head, 4, 2222222);
    deleteN(head, 13);
    printList(head);

    return 0;
}