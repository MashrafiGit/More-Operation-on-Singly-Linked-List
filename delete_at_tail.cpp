#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void linked_list_insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void linked_list_print(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }
}

void delete_at_tail(Node *&head, Node *&tail)
{

    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node *tmp = head;
    while (tmp->next != tail)
    {
        tmp = tmp->next;
    }
    delete tail;
    tail = tmp;
    tail->next = NULL;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        linked_list_insert_at_tail(head, tail, val);
    }
    cout << "Tail Before delete: " << tail->val << endl;
    delete_at_tail(head, tail);
    delete_at_tail(head, tail);
    cout << "Tail After delete: " << tail->val << endl;
    linked_list_print(head);

    return 0;
}