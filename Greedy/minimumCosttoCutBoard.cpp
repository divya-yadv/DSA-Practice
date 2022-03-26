int minimumCostOfBreaking(int X[], int Y[], int m, int n)
{
    int res = 0;
    sort(X,X+m,greater<int>()); // here we want to cut the edge that has maximum cost and also when we have less peices. 
    sort(Y,Y+n,greater<int>());
    int hrz = 1; // how many parts are there for each
    int ver = 1;
    int i=0,j=0;
    while(i<m && j<n)
    {
        if(X[i] > Y[j])
        {
            i++;
            res += X[i]*ver;
            hrz++;
        }
        else
        {
            j++;
            res += Y[j]*hrz;
            ver++;
        }
    }
    while(i<m)
    {
        res += X[i]*ver;
        i++;
    }
    while(j<n)
    {
        res += Y[j]*hrz;
        j++;
    }
    return res;
}
