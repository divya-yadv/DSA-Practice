long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            if(k == 0)
            {
                break;
            }
            else if(a[i] < 0)
            {
                a[i] = -a[i];
                k--;
            }
        }
        long long int sum = 0;
        if(k!=0)
        {
            sort(a,a+n); /// or you can just get the min also and change is sign accordingly
            if(k%2 != 0)
            {
                a[0] = -a[0];
            }
        }
        for(int i=0;i<n;i++)
        {
            sum += a[i];
        }
        return sum;
    }
