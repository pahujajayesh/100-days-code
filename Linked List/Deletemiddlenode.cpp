//Ques->https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118786/offering/1381207

Node<int> *deleteMiddle(Node<int> *head)
{
    // Write your code here.
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return NULL;
    }
    if (head->next->next == NULL)
    {
        Node<int> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    Node<int> *fast = head->next;
    Node<int> *slow = head;
    Node<int> *prev = NULL;
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    slow->next = NULL;
    delete slow;
    return head;
}