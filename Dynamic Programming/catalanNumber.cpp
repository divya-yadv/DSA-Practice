#recursion
cpp_int findCatalan(int n) 
{
     if(n<=1)
     {
        return 0;
     }
     cpp_int res=0;
     for (int i = 0; i < n; i++)
       {
           res += findCatalen(i)*findCatalen(n-1-i);
       }
        return res;
    }

#dp
cpp_int findCatalan(int n) 
    {
      vector<cpp_int> dp(n+1,0);
       dp[0] = 1;
       dp[1] = 1;
       for (int i = 2; i <= n; i++)
       {
           for(int j=0;j<i;j++)
           {
               dp[i] += dp[j]*dp[i - j - 1];
           }
       }
        return dp[n];
    }
