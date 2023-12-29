#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// pushing
void push_from_front(Node **head, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void push_from_back(Node *head, int data)
{
    Node *new_node = new Node(), *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    new_node->data = data;
    new_node->next = NULL;
    temp->next = new_node;
}

void insert_after(Node *prev_node, int data)
{
    Node *new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// deletion
void delete_from_begining(Node **head)
{
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_from_end(Node *head)
{
    Node *end = head;
    Node *prev = NULL;
    while (end->next)
    {
        prev = end;
        end = end->next;
    }
    prev->next = NULL;
    free(end);
}

void deleteNth(Node **head, int position)
{
    Node *end = *head;
    Node *prev = *head;
    if (position == 1)
    {
        prev = *head;
        *head = (*head)->next;
        free(prev);
        return;
    }
    for (int i = 0; i < position; i++)
    {
        if (i == position - 1 && end)
        {
            prev->next = end->next;
            free(end);
            return;
        }
        else
        {
            prev = end;
            if (prev == NULL)
                break;
            end = end->next;
        }
    }
}

void recursive_deletion(Node **head, int val){
    if(*head==NULL){
        cout<<"No such element\n";
        return;
    }
    if((*head)->data == val){
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    recursive_deletion(&((*head)->next), val);
}

// others
void traverse(Node *head)
{
    cout << "Traverse: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    Node *head = NULL;
    push_from_front(&head, 10);
    traverse(head);
    push_from_front(&head, 40);
    push_from_front(&head, 20);
    traverse(head);
    push_from_back(head, 100);
    traverse(head);
    cout << "Inserting after 2nd position:\n";
    Node *prev_node = head;
    prev_node = prev_node->next;
    insert_after(prev_node, 3);
    traverse(head);
    cout << "Deletion:\n";
    delete_from_begining(&head);
    traverse(head);
    delete_from_end(head);
    traverse(head);
    cout << "Delete Second:\n";
    deleteNth(&head, 2);
    traverse(head);
    cout<<"Recursive Deletion:\n";
    recursive_deletion(&head, 40);
    traverse(head);
}
