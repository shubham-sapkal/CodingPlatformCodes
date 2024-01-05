/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void solve(ListNode* &head)
    {
        // base case
        if(head == NULL)
        {
            return ;
        }

        if(head->next != NULL)
        {
            swap(head->val, head->next->val);
            // return;
            solve(head->next->next);
        
        }
            
        
        

    }

    ListNode* swapPairs(ListNode* head) {
        solve(head);

        return head;
    }
};