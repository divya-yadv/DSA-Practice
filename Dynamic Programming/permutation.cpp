# recursion

int permutation(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    // Recur
    return permutation(n - 1, k - 1)
           + k* permutation(n - 1, k);
}

# dp
int permutation(int n, int k)
{
    int P[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            if (j == 0 || i==j)
                P[i][j] = 1;
            else
                P[i][j] = P[i - 1][j] +
                        (j * P[i - 1][j - 1]);
        }
    }
    return P[n][k];
}
