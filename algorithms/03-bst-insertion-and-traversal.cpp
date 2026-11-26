
//Part 1
void BST::nonRecursiveInsert(int elemToInsert)
{
   if(root == nullptr)
   {
      Node* aNode = new Node;
      aNode->data = elemToInsert;
      aNode->llink = nullptr;
      aNode->rlink = nullptr;
   
      root = aNode;
      count++;
   }

   else 
   {
      Node* current = root;
      Node* parent = nullptr;
      bool same = false;
      while(current != nullptr)
      {
         parent = current;
      
         if(elemToInsert < current->data)
         {
            current = current->llink;
         }
         else if(elemToInsert > current->data)
         {
            current = current->rlink;
         }
      
         else if(elemToInsert == current->data)
         {
            cerr << "Element " << elemToInsert 
               << " is already in the list." 
               << " Duplicates are not allowed." << endl;
            
            current = nullptr;
            same = true;
         }
      }
   
      if(!same)
      {
         Node* aNode = new Node;
         aNode->data = elemToInsert;
         aNode->llink = nullptr;
         aNode->rlink = nullptr;
      
         if (elemToInsert < parent->data)
         {
            parent->llink = aNode;
         }
        
         else
         {
            parent->rlink = aNode;
         }
      
         count++;   
      }
   
   }

}

//part 2
void BST::nonRecursiveInorder() const
{
    stack<Node*> aStack;
    
    Node* current = root;
    //go to the left as far as possible
    while (current != nullptr || !aStack.empty()) 
    {
        while (current != nullptr) 
        {
            aStack.push(current);
            current = current->llink; //eventually this is nullptr
        }
        
        //use stack to backtrack to set current to be nullptr
        current = aStack.top();
        aStack.pop();//visited so need to remove from the stack
        cout << current->data << " ";
        current = current->rlink;//move to the right of that node to see if there any node
        
    }
    
    cout << endl;
   
}
