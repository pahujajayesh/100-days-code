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


//Approch 2: hashmap
#include <unordered_map>

Node *removeDuplicates(Node *head)
{

    Node *curr = head;

    // Keep track of previous node.
    Node *prev = NULL;

    unordered_map<int, bool> seen;

    // Iterate over the given linked list.
    while (curr != NULL)
    {
        int val = curr->data;

        if (seen[val])
        {
            // Node has been encountered before, so its a duplicate.
            // Firstly update the next pointer of the previous node.
            prev->next = curr->next;

            // Delete the duplicate node.
            delete curr;

            // Move on to the next node.
            curr = prev->next;
        }
        else
        {
            // Node is seen for the first time, so add it to hash table.
            seen[val] = true;

            // Move on to the next node.
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}