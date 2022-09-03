#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverse(LinkedListNode<int>* head, LinkedListNode<int>* curr, LinkedListNode<int>* prev)
{
    // base case 
    if(curr == NULL)
    {
        head = prev;
//         cout << "Head->data = "<< head->data << endl;
        return head;
    }
    
//     cout<<"Pointer at node : " << curr->data << endl;;
    
    LinkedListNode<int>* nextNode = curr -> next;
    head = reverse(head, nextNode, curr);
    
//     cout<<"pointer prev->data = "<< prev->data << endl;
//     cout<<"pointer curr->data = "<< curr->data << endl;
//    cout << "head->data = "<< head->data << endl; 
    
    curr->next = prev;
    
    return head;

}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *prev = NULL;
    head = reverse(head, curr, prev);
    return head;
}