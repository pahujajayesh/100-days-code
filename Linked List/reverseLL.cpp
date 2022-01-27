//Approach-1(iterative)

//Linked list node class
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *temp = NULL;
    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;

    // Write your code here
}

//Approach 2-recursive
void solve(LinkedListNode<int> *&head, LinkedListNode<int> *curr, LinkedListNode<int> *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    LinkedListNode<int> *temp = curr->next;
    solve(head, temp, curr);
    curr->next = prev;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    solve(head, curr, prev);
    return head;
}

//approach-3 recursive
LinkedListNode<int> *reverse(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    LinkedListNode<int> *smallHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{

    return reverse(head);
}