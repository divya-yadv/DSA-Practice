# recursion

int binomialCoeff(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    // Recur
    return binomialCoeff(n - 1, k - 1)
           + binomialCoeff(n - 1, k);
}

#dp
O(n*r) O(r)
int nCr(int n, int r){
        int dp[n+1][n+1];
        if(n<r){
           return 0;
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<i+1; j++){ //takes care of r>n
                if(j == 0 || i == j){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = ((dp[i-1][j-1])%1000000007+(dp[i-1][j])%1000000007)%1000000007;
                }
            }
        }
        return dp[n][r];
    }
