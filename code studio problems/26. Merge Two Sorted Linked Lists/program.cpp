#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* solve(Node<int>* first, Node<int>* second){
    
    // if only one element is present in list 
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    
    Node<int>* curr = first;
    Node<int>* next = curr->next;
    Node<int>* insertNode = second;
    
    
    while(next != NULL && insertNode!= NULL){
        
        if( (curr->data <= insertNode->data) &&
              (next->data >= insertNode->data)){
            
            // add Node in between first list
            curr -> next = insertNode;
            Node<int>* nextInsert = insertNode->next;
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


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // if linked list is empty
    if(first == NULL && second == NULL)
        return NULL;
    
    if(first == NULL)
        return second;
    
    if(second == NULL)
        return first;
    
    if(first->data <= second->data){
        return solve(first, second);
    } else {
        return solve(second, first);
    }
    
    
    
   
}
