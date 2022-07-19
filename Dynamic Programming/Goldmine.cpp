// recursion solution
// time complexity O(3^n*m), space O(N*M)
int solve(vector<vector<int>>M,int n, int m, int i,int j)
     {
       if((j>=m) || (i<0) || (i>= n)) // check for valid indexes
       {
           return 0;
       }
        // calculate for individual 
       int right = solve(M,n,m,i,j+1);
       int rightupper = solve(M,n,m,i-1,j+1);
       int rightlower = solve(M,n,m,i+1,j+1);
  //take max
       return M[i][j]+(max(right,max(rightupper,rightlower)));
     }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
      // choose starting point and take max
        int overallmax = 0;
        for(int i=0;i<n;i++)
        {
        
         overallmax = max(overallmax,solve(M,n,m,i,0));
        }
        return overallmax;
    }


// Dp memoisation (bottom up)
// time complexity O(n*m) space O(n*m)
 int solve(vector<vector<int>>M,int n, int m, int i,int j,vector<vector<int>>&dp)
     {
   //store the stack in a vector 
       if((j>=m) || (i<0) || (i>= n))
       {
           return 0;
       }
       if(dp[i][j] != -1)
       {
          return  dp[i][j];
       }
       int right = solve(M,n,m,i,j+1,dp);
       int rightupper = solve(M,n,m,i-1,j+1,dp);
       int rightlower = solve(M,n,m,i+1,j+1,dp);
       return dp[i][j] = M[i][j]+(max(right,max(rightupper,rightlower)));
     }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int overallmax = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            overallmax = max(overallmax,solve(M,n,m,i,0,dp));
        }
        return overallmax;
    }

//DP tabulation 
int maxGold(int n, int m, vector<vector<int>> M)
    {
       
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=m-1;j>=0;j--) // start from last column
        {
            for(int i=0;i<n;i++)
            {
                if(j == m-1) // if at the last column can't go in any direction 
                {
                    dp[i][j] = M[i][j];
                }
                else
                {
                     int right = dp[i][j+1];
                     int rightupper = (i == 0) ? 0:  dp[i-1][j+1];
                    int rightlower = (i == n-1) ? 0: dp[i+1][j+1];
                    dp[i][j] = M[i][j]+(max(right,max(rightupper,rightlower)));
                }
              
            }
        }
  //overall will be collected at the firdt column itself 
        int overallmax = dp[0][0];
        for(int i=1;i<n;i++)
        {
            overallmax = max(overallmax,dp[i][0]);
        }
        return overallmax;
    }



