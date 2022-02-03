class Solution
{
private:
    struct Node *reverse(struct Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *temp = NULL;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void insertAtTail(struct Node *&head, struct Node *&tail, int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    struct Node *add(struct Node *first, struct Node *second)
    {
        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        while (first != NULL && second != NULL)
        {
            int sum = carry + first->data + second->data;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            first = first->next;
            second = second->next;
        }
        while (first != NULL)
        {
            int sum = carry + first->data;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            first = first->next;
        }
        while (second != NULL)
        {
            int sum = carry + second->data;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            second = second->next;
        }
        while (carry != NULL)
        {
            int sum = carry;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
        }
        return ansHead;
    }

public:
    //Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        //step1->reverse both linked list
        first = reverse(first);
        second = reverse(second);
        //step 2-> add both reversed linked list
        Node *ans = add(first, second);
        //step3->reverse ans ll
        ans = reverse(ans);

        return ans;
    }
};
// Expected Time Complexity : O(N + M)
// Expected Auxiliary Space : O(Max(N, M))
//generic code
class Solution
{
private:
    struct Node *reverse(struct Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *temp = NULL;
        while (curr != NULL)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    void insertAtTail(struct Node *&head, struct Node *&tail, int val)
    {
        Node *temp = new Node(val);
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    struct Node *add(struct Node *first, struct Node *second)
    {
        int carry = 0;
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        while (first != NULL || second != NULL || carry != 0)
        {
            int val1 = 0;
            if (first != NULL)
            {
                val1 = first->data;
            }
            int val2 = 0;
            if (second != NULL)
            {
                val2 = second->data;
            }
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum / 10;
            if (first != NULL)
            {
                first = first->next;
            }
            if (second != NULL)
            {
                second = second->next;
            }
        }

        return ansHead;
    }

public:
    //Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        //step1->reverse both linked list
        first = reverse(first);
        second = reverse(second);
        //step 2-> add both reversed linked list
        Node *ans = add(first, second);
        //step3->reverse ans ll
        ans = reverse(ans);

        return ans;
    }
};