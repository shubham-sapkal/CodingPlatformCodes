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
    
    ListNode* solve(ListNode* first, ListNode* second){
    
        // if only one element is present in list 
        if(first->next == NULL){
            first->next = second;
            return first;
        }

        ListNode* curr = first;
        ListNode* next = curr->next;
        ListNode* insertNode = second;


        while(next != NULL && insertNode!= NULL){

            if( (curr->val <= insertNode->val) &&
                  (next->val >= insertNode->val)){

                // add Node in between first list
                curr -> next = insertNode;
                ListNode* nextInsert = insertNode->next;
                insertNode->next = next;

                // Update Pointer
                curr = insertNode;
                insertNode = nextInsert;

            }
            else{
                curr = curr->next;
                next = next->next;

                if(next == NULL){
                    curr->next = insertNode;
                }
            }

        }

        return first;
    
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL)
            return list2;
        
        if(list2 == NULL)
            return list1;
        
        if(list1->val < list2->val){
            return solve(list1, list2);
        } else {
            return solve(list2, list1);
        }
        
        // return list1;
    }
};