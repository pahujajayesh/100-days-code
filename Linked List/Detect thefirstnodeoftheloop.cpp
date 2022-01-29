/****************************************************************
Ques-https://www.codingninjas.com/codestudio/problems/detect-the-first-node-of-the-loop_1112628
You have been given a singly linked list which may or may not contain a cycle. 
You are supposed to return the node where the cycle begins (if a cycle exists).
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {

        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    slow = slow->next;
    fast = fast->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
        {
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    if (slow != fast)
    {
        return NULL;
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;

    //    Write your code here.
}