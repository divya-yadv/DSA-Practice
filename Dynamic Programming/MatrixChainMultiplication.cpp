  int solve(int i,int j,int arr[], vector<vector<int>> &dp)
    {
        if(i >= j)
        {
            return 0;
        }
        if(dp[i][j] != -1) // to check if exists
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for(int k=i;k<j;k++) 
        {
            int temp = solve(i,k,arr,dp) + solve(k+1,j,arr,dp) + arr[i-1]*arr[j]*arr[k]; //else solve it by partitioning
            ans = min(ans,temp);
        }
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        if(N <= 2)
        {
            return 0;
        }
        vector<vector<int>> vec( N+1 , vector<int> (N+1, -1));
        return solve(1,N-1,arr,vec);
       
    }
