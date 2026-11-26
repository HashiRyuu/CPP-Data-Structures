
//Part 1
int hashValue(int key, int j, int capacity)
{
   return (((3 * key) + 3) + j * j) % capacity;
}

//Part 2
void insertKey(int * arr, int capacity, 
               int& numElements, int keyInsert)
{
   int j = 0;
   bool inserted = false;
   
   while(j < LIMIT && !inserted)
   {
      int key = hashValue(keyInsert, j, capacity);
      
      if(arr[key] == 0 || arr[key] == -2)
      {
         arr[key] = keyInsert;
         inserted = true;
         ++numElements;
      }
      
      else if(arr[key] == keyInsert)
      {
         cerr << "Key " << keyInsert 
            << " is a duplicate." << endl;
            
         inserted = true;
      }
      
      else 
      {
         ++j;
      }
      
   }
   
   if(!inserted && j == LIMIT)
   {
      cerr << "Key " << keyInsert 
         << " not inserted. Need to rehash." << endl;
   }
}

//Part 3
bool searchKey(int const * arr, 
               int capacity, int keySearch)
{
   bool check = false;
   int key = hashValue(keySearch, 0, capacity);
   int j = 1;
   
   while(j < LIMIT && !check && arr[key] != 0)
   {
      
      if(arr[key] == keySearch)
      {
        check = true;
      }
      
      key = hashValue(keySearch, j, capacity);
      ++j;
      
   }
   
   return check;
}

//Part 4
void deleteKey(int * arr, int capacity, 
               int& numElements, int keyDelete)
{
   bool deleteCheck = false;
   int key = hashValue(keyDelete, 0, capacity);
   int j = 1;
   
   while(j < LIMIT && !deleteCheck && arr[key] != 0)
   {
      if(arr[key] == keyDelete)
      {
         arr[key] = -2;
         --numElements;
         deleteCheck = true;
      }
      
      key = hashValue(keyDelete, j, capacity);
      ++j;
   }
   
   if(!deleteCheck && j == LIMIT)
   {
      cerr << "Key " << keyDelete 
         << " is not in the table." << endl;
   }
}
