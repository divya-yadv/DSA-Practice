# recursion solution
int solve(int W, int wt[], int val[], int n, int i )
    {
        if(i<0)
        {
            return 0;
        }
        else if(W>=wt[i]){
        return max(val[i]+solve(W-wt[i],wt,val,n,i-1),solve(W,wt,val,n,i-1));
            
        }
        else
        {
            return solve(W,wt,val,n,i-1);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        return solve(W,wt,val,n,n-1);
    }

#dp solution

int knapSack(int W, int wt[], int val[], int n) 
    { 
       int dp[n+1][W+1];
       for(int i=0;i<=n;i++){
           for(int j=0;j<=W;j++){
               if(i==0||j==0)
               {
                   dp[i][j] = 0;
               }
               else if(j>=wt[i-1])
               {
                   dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
               }
               else
               {
                   dp[i][j] = dp[i-1][j];
               }
           }
       }
       return dp[n][W];
    }
