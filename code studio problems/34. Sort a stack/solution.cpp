void sortedInsert(stack<int>& stack, int ele)
{
    if(stack.empty() || (!stack.empty() && stack.top() < ele) ){
        stack.push(ele);
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    // recursive call
    sortedInsert(stack, ele);
    
    stack.push(num);
}


void sortStack(stack<int> &stack)
{
	// base case
    if(stack.empty()) {
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    // recursive call
    sortStack(stack);
    
    sortedInsert(stack, num);
}