List *foldAndMerge(List *head)
{
    List *fast = head, *prev = NULL, *next;
    while (fast->next != NULL)
    {
        fast = fast->next->next;
        // reversing the list
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    List *ans = head;
    while (prev != NULL)
    {
        head->data = head->data * prev->data;
        head = head->next;
        prev = prev->next;
    }
    return ans;
    // Write your code here.
}