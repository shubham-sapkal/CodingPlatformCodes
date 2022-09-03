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
int getLength(Node* head)
{
    int len = 0;
    while(head!=NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}


Node *findMiddle(Node *head) {
    // Write your code here
    
    int len = getLength(head);
    int cnt = 0;
    len=len/2;
    Node *temp = head;
    
    while(cnt<len)
    {
        temp=temp->next;
        cnt++;
    }
    
    return temp;
    
}