void solve(stack<int>& myStack, int x)
{
    // base condition
    if(myStack.empty())
    {
        myStack.push(x);
        return ;
    }
    
    // keeping top element aside
    int num = myStack.top();
    myStack.pop();
    
    solve(myStack, x);
    
    // pushing sided number
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack, x);
    
    return myStack;
    
}
