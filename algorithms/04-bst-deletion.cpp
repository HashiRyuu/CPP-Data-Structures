
//The code

void BST::deleteItem(int itemToDelete)
{
	if(root == nullptr)
	{
   	cerr << "Cannot delete from an empty tree." << endl;
	}

	else
	{
   	Node* current = root;
   	Node* parent = nullptr;
   	while(current != nullptr 
         	&& current->data != itemToDelete)
   	{
      	parent = current;
      
      	if(itemToDelete < current->data)
      	{
         	current = current->llink;
      	}
      
      	else if(itemToDelete > current->data)
      	{
         	current = current->rlink;
      	}
   	}
   
   	if(current != nullptr)
   	{
      	if(current == root 
         	&& root->llink == nullptr 
         	&& root->rlink == nullptr)
      	{
         	delete root;
            root = nullptr;
         }
      
         else if(current->llink == nullptr 
                  && current->rlink == nullptr)
         {

            if(parent->llink == current)
            {
               parent->llink = nullptr;
            }
         
            else
            {
               parent->rlink = nullptr;
            }

            delete current;
            current = nullptr;
         }
         
         else if(current->llink != nullptr 
                  && current->rlink != nullptr)
         {
            deleteInternalNode(current);
         }
         
         else
         {
            if(current->llink != nullptr)
            {
               deleteNoRightSubtree(current, parent);
            }
            
            else
            {
               deleteNoLeftSubtree(current, parent);
            }
         }
         
         totalNodes--;
      }
   
      else 
      {
         cerr << "The item to delete is not in the tree." << endl;
      }
   }
}
