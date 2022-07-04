 
//O(n) O(n)
int countFriendsPairings(int n) 
    { 
        if(n<=2)
        {
            return n;
        }
        long long int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=n;i++)
        {
            dp[i] = (dp[i-1]%1000000007 + ((i-1)*dp[i-2])%1000000007)%1000000007; // two options
          //           either single         or pair with n-1 friends after pairing there are n-2 people.
        }
        return dp[n];
    }
