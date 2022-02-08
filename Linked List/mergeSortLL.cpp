//time-o(nlogn) space-o(logn)
node *merge(node *left, node *right)
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }
    node *ans = new node(-1);
    node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data <= right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    //if right == NULL && left!=NULL
    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
//function to find mid
node *findMid(node *head)
{
    node *slow = head;
    node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *mid = findMid(head);
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // now soritng left and right part by recursion
    left = mergeSort(left);
    right = mergeSort(right);
    //merge left and right part
    node *result = merge(left, right);

    return result;
}