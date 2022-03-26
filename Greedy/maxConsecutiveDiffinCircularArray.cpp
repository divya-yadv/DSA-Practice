long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int i=0,j=n-1;
    long long int sum = 0;
   for(int i=0;i<n;i++)
   {
       sum += abs(arr[i] - arr[j--]); //  this will be something like 1 8 2 6 one min and one max
   }
   return sum;
}
