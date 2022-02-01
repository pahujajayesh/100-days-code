//aproach 1 time-o(n) space -o(n)
#include <vector>
class Solution
{
private:
    bool checkPalindrome(vector<int> arr)
    {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            if (arr[s] != arr[e])
            {
                return 0;
            }
            s++, e--;
        }
        return 1;
    }

public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        Node *temp = head;
        while (temp != NULL)
        {
            arr.push_back(temp->data);
            temp = temp->next;
        }
        return checkPalindrome(arr);
        //Your code here
    }
};

//approach 2 time o(n) space o(1)
//first find mid and than reverse the list after mid and compare both lists
//and before returning again reverse the list
class Solution
{
private:
    Node *getMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;

            slow = slow->next;
        }
        return slow;
    }
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if (head->next == NULL)
        {
            return true;
        }
        //step 1->find mid
        Node *middle = getMid(head);
        //step 2->reverse the other half
        Node *temp = middle->next;
        middle->next = reverse(temp);

        Node *head1 = head;
        Node *head2 = middle->next;
        while (head2 != NULL)
        {
            if (head1->data != head2->data)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        // step4->repeat step 2
        temp = middle->next;
        middle->next = reverse(temp);
        return true;
    }
};
