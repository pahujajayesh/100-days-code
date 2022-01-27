//approach 1
Node *findMiddle(Node *head)
{
    // Write your code here
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }

    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    int ans = len / 2;
    int count = 0;
    temp = head;
    while (count < ans)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}

//Approach 2 fast and slow pointer

Node *getMid(Node *&head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return head;
    }
    if (head->next->next == NULL)
    {
        return head->next;
    }
    Node *fast = head->next;
    Node *slow = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}
Node *findMiddle(Node *head)
{
    // Write your code here
    return getMid(head);
}