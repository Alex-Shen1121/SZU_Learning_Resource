#include <iostream>  
#include <stdlib.h>  
using namespace std;

typedef struct tag {
    int data;
    struct tag* next;
}Node, * List;

void Print(List head);
List Reverse(List head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node* head;
        head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        head->data = -1;
        int i, n, x;
        cin >> n;
        Node* p, * q;
        p = head;
        for (int i = 1; i <= n; i++)
        {
            q = (Node*)malloc(sizeof(Node));
            cin >> x;
            q->data = x;
            q->next = NULL;
            p->next = q;
            p = q;
        }
        head = Reverse(head);
        Print(head);
    }
    return 0;
}

List Reverse(List head)
{
    if (head->next == NULL || head->next->next == NULL)
    {
        return head; 
    }
    Node* t = NULL,
        * p = head->next,
        * q = head->next->next;
    while (q != NULL)
    {
        t = q->next;
        q->next = p;
        p = q;
        q = t;
    }

    head->next->next = NULL; 
    head->next = p;           
    return head;
}

void Print(List head)
{
    Node* p = head->next;
    while (p != NULL)
    {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}
