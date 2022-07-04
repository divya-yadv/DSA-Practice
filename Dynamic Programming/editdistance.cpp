# Recursion

int solve(string s,string t, int i, int j)
  {
      if(i<0)
      {
          return j+1; // extra words have to insert
      }
      else if(j<0)
      {
          return i+1; // same here
      }
      else if(s[i] == t[j])
      {
          return solve(s,t,i-1,j-1); // character same go ahead
      }
      else
      {
          return min(1+solve(s,t,i-1,j),min(1+solve(s,t,i-1,j-1),1+solve(s,t,i,j-1))); // three cases //get minimum
                        //delete                      //replace          //insert
      }
  }
    int editDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        return solve(s,t,n-1,m-1);
    }


# Memoisation
int solve(string s,string t, int i, int j,vector<vector<int>>&dp)
  {
      if(i<0)
      {
          return j+1;
      }
      else if(j<0)
      {
          return i+1;
      }
      
      if(dp[i][j] != 0)
      {
          return dp[i][j];
      }
      
      else if(s[i] == t[j])
      {
          return dp[i][j] =solve(s,t,i-1,j-1,dp);
      }
      else
      {
          return dp[i][j] =  min(1+solve(s,t,i-1,j,dp),min(1+solve(s,t,i-1,j-1,dp),1+solve(s,t,i,j-1,dp)));
      }
  }
    int editDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
       vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        return solve(s,t,n-1,m-1,dp);
       
    }

# Tabulation

int editDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0] = i;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j] = j;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i-1][j],1+dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
