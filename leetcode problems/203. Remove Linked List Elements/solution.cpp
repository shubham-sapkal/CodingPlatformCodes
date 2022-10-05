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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL )
        {
            return head;
        }
        
        // if(head->val != val && head->next == NULL)
        // {
        //     return head;
        // }
        
        
        if(head->val == val)
        {
            head = head->next;
            return removeElements(head, val);
        }
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        while(curr!=NULL && curr->next != NULL)
        {
            
            // cout<<"Current visited : " << curr->val << endl;
            
            if(curr->val == val)
            {
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                
                delete temp;
            }else{
                prev = curr;
                curr = curr->next;
            }
               
        }
        
        // cout<<"Current visited : " << curr->val << endl;
        // cout<<"prev visited : " << prev->val << endl;
        
        if(curr != NULL && curr->val == val)
        {
            prev->next = NULL;
        }
        
        return head;
        
        
    }
};