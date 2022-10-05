class NStack
{
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;
public:
    // Initialize your data structure.
    
    NStack(int N, int S)
    {
        // initialize
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        // top initialise
        for(int i=0; i<n; i++)
        {
            top[i] = -1;
        }
        
        // next initalise
        for(int i=0; i<s; i++)
        {
            next[i] = i+1;
        }
        next[s-1] = -1;   // Update last index to -1
        freespot = 0;   // initilise freespot
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if(freespot == -1)
        {
            return false;
        }
        
        // step 1: find index
        int index = freespot;
        
        // step 2: update freespot
        freespot = next[index];
        
        // step 3: insert element
        arr[index] = x;
        
        // step4: update next
        next[index] = top[m-1];
        
        // step 5: update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }
        
        int index= top[m-1];
        
        top[m-1] = next[index];
        
        next[index] = freespot;
        
        freespot = index;
        
        return arr[index];
    }
};