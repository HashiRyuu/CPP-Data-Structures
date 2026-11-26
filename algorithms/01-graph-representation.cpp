
//Part 1
map<string, set<std::string>> neighbors = 
{
   {"Illinois", {"Indiana", "Iowa", "Michigan", 
                  "Missouri", "Wisconsin"}},
   
   {"Ohio", {"Indiana", "Michigan"}},
   
   {"Kansas", {"Missouri", "Nebraska"}},
   
   {"Nebraska", {"Kansas", "Iowa", "South Dakota", "Missouri"}},
   
   {"Indiana", {"Illinois", "Ohio", "Michigan"}},
   
   {"Iowa", {"Illinois", "Minnesota", "Missouri", "Nebraska", 
               "South Dakota", "Wisconsin"}},
               
   {"Michigan", {"Illinois", "Indiana", "Minnesota", 
                  "Ohio", "Wisconsin"}},
   
   {"Missouri", {"Illinois", "Iowa", "Kansas", "Nebraska"}},
                  
   {"Wisconsin", {"Illinois", "Iowa", "Michigan", "Minnesota"}},
   
   {"Minnesota", {"Iowa", "Michigan", "North Dakota", 
                  "South Dakota", "Wisconsin"}},
   
   {"North Dakota", {"Minnesota", "South Dakota"}},
   
   {"South Dakota", {"Iowa", "Minnesota", "Nebraska", "North Dakota"}}
};


//Part 2
void printNeighbors(const map<string, set<string>>& neighbors)
{
   for(const auto& pair: neighbors)
   {
      cout << pair.first << " borders with: ";
      for(const auto& states: pair.second)
      {
         cout << states << " ";
      }
      
      cout << endl;
   }
}

//Part 3
vector<vector<int>> neighbors
{
   {0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
   {1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1},
   {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
   {1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
   {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
   {1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0},
   {0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0},
   {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
   {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0},
   {1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
};


//Part 4
bool areNeighbors(const vector<string>& states,
                  const vector<vector<int>>& neighbors,
                  const string& stateOne,
                  const string& stateTwo)
{
   if(stateOne == stateTwo) return false;
   
    int positionOfState1 = 0;
    int positionOfState2 = 0;
    
    while(states[positionOfState1] != stateOne)
    {
       ++positionOfState1;
    }
    
    while(states[positionOfState2] != stateTwo)
    {
       ++positionOfState2;
    }
    

    return neighbors[positionOfState1][positionOfState2] == 1;
}
