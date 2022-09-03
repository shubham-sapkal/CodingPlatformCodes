#include <bits/stdc++.h> 
/****************************************************************

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
Node *solve(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    // IF linked list has 2 nodes
//     if(head->next->next == NULL)
//     {
//         return head->next;
//     }
    
    Node* fast = head->next;
    Node* slow = head;
    
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
    
}


Node *findMiddle(Node *head) {
   
   return solve(head);
    
}