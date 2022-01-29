/*************************************************
   Ques-https://www.codingninjas.com/codestudio/problems/interview-shuriken-42-detect-and-remove-loop_241049?leftPanelTab=0?
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node *floydCycle(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (fast == slow)
        {
            return slow;
        }
    }
    return NULL;
}
Node *startLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *fast = floydCycle(head);
    if (fast == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
Node *removeLoop(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *start = startLoop(head);
    if (start == NULL)
    {
        return head;
    }
    Node *temp = start;
    while (temp->next != start)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
    // Write your code here.
}