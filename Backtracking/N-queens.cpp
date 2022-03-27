bool isSafe(vector<int>path,int row,int col)
  {
      for(int i=row-2;i>=0;i--) // 1 for 1-indexing and second one for we will check before that row only
      {
          if(path[i] == col)
          {
              return false;
          }
          
      }
      for(int i=row-2;i>=0;i--) // 1 for 1-indexing and second one for we will check before that row only
      {
          if(path[i] == i-row + col + 1)
          {
              return false;
          }
          
      }
      for(int i=row-2;i>=0;i--) // 1 for 1-indexing and second one for we will check before that row only
      {
          if(path[i] == row + col-i-1)
          {
              return false;
          }
          
      }
      return true;
  }
  
  
   void solve(vector<vector<int>>& res,vector<int> v,int n, int row)
   {
       if(v.size() == n)
       {
           res.push_back(v);
           return;
       }
       for(int i=1;i<= n;i++)
       {
           if(isSafe(v,row,i))
           {
               v.push_back(i);
               solve(res,v,n,row+1);
               v.pop_back();
           }
       }
   }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        if(n == 1)
        {
            return {{1}};
        }
        if(n<=3)
        {
            return res;
        }
        
        vector<int> v;
        solve(res,v,n,1);
        return res;
    }
