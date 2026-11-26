
//The code

void bfs(const vector<vector<int>>& adjMatrix, 
         list<int>& sequence, int startVertex)
{
   int size = static_cast<int>(adjMatrix.size());
   bool* visited = new bool[size]();
   queue<int> aQueue;
   
   sequence.push_back(startVertex);
   visited[startVertex] = true;
   
   int count = 1;
   int vertex = startVertex;
   while(count != size)
   {
      for(int neighbor = 0; neighbor < size; ++neighbor)
      {
         if(adjMatrix[vertex][neighbor] == 1 && !visited[neighbor])
         {
            aQueue.push(neighbor);
            visited[neighbor] = true;
            count++;
         }
      }
      
      vertex = aQueue.front();
      sequence.push_back(vertex);
      aQueue.pop();
      
   }
   
   while(!aQueue.empty()) 
   {
      sequence.push_back(aQueue.front());
      aQueue.pop();
   }  
   
   delete[] visited;
   visited = nullptr;
}




