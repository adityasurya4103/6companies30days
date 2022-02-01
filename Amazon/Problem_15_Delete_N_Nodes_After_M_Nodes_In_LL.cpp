class Solution {
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        while(head)
        {
            int m1 = M;
            while(head && --m1)
            {
                head = head->next;
            }
            int n1 = N;
            Node *prev = head;
            while(head && n1--)
            {
                head = head->next;
            }
            if(prev)
            {
                head = head ? head -> next : NULL;
                prev->next = head;
            }
        }
    }
}
