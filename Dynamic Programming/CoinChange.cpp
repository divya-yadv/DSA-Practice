# recursion solution
void solve(int S[],int m,int sum,int i, vector<vector<int>> &res,vector<int>v)
    {
        if(sum == 0) // found one solution push it to res array
        {
            res.push_back(v);
            return;
        }
        for(int k=i;k<m;k++) // we can take one coin until sum is greater from the value of coin
        {
            if(sum >= S[k])
            {
                v.push_back(S[k]);
                solve(S,m,sum-S[k],k,res,v);
                v.pop_back(); // back way to find more solutions
            }
            else
            {
                solve(S,m,sum,k+1,res,v); // incase we can't take that coin anymore
            }
        }
    }
    long long int count(int S[], int m, int n) {
         vector<vector<int>> res; // all solutions
         vector<int>v;
         sort(S,S+m);
         if(n == 0)
         {
             return 1;
         }
        if(m == 0)
        {
             return 0;
        }
         solve(S,m,n,0,res,v);
         return res.size(); // no of solutions
    }


#Recursion solution just to find number 
void solve(int S[],int m,int sum,int i, int &ways)
    {
        if(sum == 0)
        {
            ways++;
            return;
        }
        for(int k=i;k<m;k++)
        {
            if(sum >= S[k])
            {
                sum = sum-S[k];
                solve(S,m,sum,k,ways);
                sum = sum+S[k];
            }
            else
            {
                solve(S,m,sum,k+1,ways);
            }
        }
    }
    long long int count(int S[], int m, int n) {
         int ways=0;
         if(n == 0)
         {
             return 1;
         }
        if(m == 0)
        {
             return 0;
        }
         solve(S,m,n,0,ways);
         return ways;
    }
# DP solution

long long int count(int S[], int m, int n) {
         long long int dp[m+1][n+1];
         for(int i=0;i<=m;i++)
         {
             for(int j=0;j<=n;j++)
             {
                 if(i == 0)
                 {
                     dp[i][j] = 0;
                 }
                 else if(j == 0)
                 {
                     dp[i][j] = 1;
                 }
                 else if(S[i-1] <= j)
                 {
                     dp[i][j] = dp[i][j-S[i-1]] + dp[i-1][j]; // coin select or not select
                 }
                 else
                 {
                     dp[i][j] = dp[i-1][j]; // no option to select
                 }
             }
         }
         return dp[m][n];
    }
