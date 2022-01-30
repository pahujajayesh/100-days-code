// Ques->https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331
//brute force->time O(n^2)

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data == curr->data)
            {
                if (prev == NULL)
                {
                    prev = curr;
                }
                Node *nextNode = temp->next;
                Node *deleteNode = temp;
                delete (deleteNode);
                prev->next = nextNode;
                temp = prev->next;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }

    return head;
    // Write your code here
}