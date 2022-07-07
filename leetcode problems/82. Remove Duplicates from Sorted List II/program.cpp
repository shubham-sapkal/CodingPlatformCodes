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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            
            int condition = 0;
            
            if(curr->next != NULL && curr->val == curr->next->val){
                
                ListNode* temp = curr->next;
                while(temp->val == curr->val){
                    if(temp->next == NULL){
                        condition = 1;
                        break;
                    }
                    temp=temp->next;
                    
                }
                    
                if(temp->next == NULL && prev != NULL && condition == 1){
                    prev->next = NULL;
                }
                else if ( temp->next == NULL && temp->val != curr->val && prev == NULL ){
                    head = temp;
                }
                else if(temp->next == NULL && prev != NULL || prev != NULL){
                    prev->next = temp;
                }
                else if(temp->next == NULL && prev == NULL ){
                    head = NULL;
                }
                else{
                    head = temp;
                }
                
                curr = temp;
                
            }else{
                prev = curr;
                curr = curr -> next;
            }
            
        }
        
        return head;
        
    }
};