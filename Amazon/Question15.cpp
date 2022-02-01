#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
/* A linked list node */

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void insert(int n1)
{
    int n, value;
    n = n1;
    struct Node *temp;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

void linkdelete(struct Node *head, int M, int N)
{
    //Add code here
    Node *link = head;
    while (link)
    {

        for (int i = 1; i < M && link; i++)
        {
            link = link->next;
        }
        if (!link)
            return;
        Node *temp = link;
        for (int j = 0; j <= N && temp; j++)
        {
            temp = temp->next;
        }
        link->next = temp;
        link = temp;
    }
}

int main()
{
    int t, n1;
    cin >> t;
    while (t--)
    {
        cin >> n1;
        int m, n;
        cin >> m;
        cin >> n;
        insert(n1);
        linkdelete(start, m, n);
        printList(start);
    }

    return 0;
}
