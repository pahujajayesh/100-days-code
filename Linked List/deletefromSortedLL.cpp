// Ques->https : www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283

              Node *
              uniqueSortedList(Node *head)
{
    // Write your code here.
    if (head == NULL)
    {
        return NULL;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *newnode = curr->next->next;
            Node *temp = curr->next;
            delete temp;
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}