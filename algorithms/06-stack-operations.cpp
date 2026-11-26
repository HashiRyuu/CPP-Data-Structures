
//Part 1
void iterSwapStacks(stack<int>& copyStack, stack<int>& pasteStack) 
{
    int size = copyStack.size();  

    for (int i = 0; i < size; ++i) 
    {  
        int temp = copyStack.top();
        copyStack.pop();

        //does not transfer the value that temp put in (does not transfer all value)
        // This loop transfers only the top (size - i - 1) elements from copyStack to pasteStack.
        // It does NOT transfer all elements—only those above the current 'temp' value.
        // As a result, 'temp' stays in copyStack for now, and will be restored in the next steps.
        //example [8,6,5,3,2,1] the 8 and 6 will not transfer because those all from temp input in
        //and they will stay there prevent to keep the order and if transfer those too it will
        //like a repeat will the order we want is destroy
        for (int j = i + 1; j < size; ++j) 
        {  
            pasteStack.push(copyStack.top());
            copyStack.pop();
        }

       // Push temp into bottom of copyStack
        copyStack.push(temp);

       // Move everything back to copyStack
        while (!pasteStack.empty()) 
        {
            copyStack.push(pasteStack.top());
            pasteStack.pop();
        }
    }

    // Finally move all into pasteStack
    while (!copyStack.empty()) 
    {
        pasteStack.push(copyStack.top());
        copyStack.pop();
    }
}

//Part 2
void recurSwapStacks(stack<int>& copyStack, stack<int>& pasteStack)
{
   if (!copyStack.empty())
   {
      int temp = copyStack.top();
      copyStack.pop();
      
      recurSwapStacks(copyStack, pasteStack);
      
      pasteStack.push(temp);
   }
}

//Part 3
void stlSwapStacks(stack<int>& copyStack, stack<int>& pasteStack)
{
   swap(copyStack, pasteStack);
}


//Part 4
void moveStacks(stack<int>& copyStack, stack<int>& pasteStack) 
{
    pasteStack = copyStack;
    
    while(!copyStack.empty())
    {
       copyStack.pop();
    }
}


