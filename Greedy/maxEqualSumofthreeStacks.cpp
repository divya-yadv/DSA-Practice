int maxSum(int stack1[], int stack2[], int stack3[], int n1,
           int n2, int n3)
{
    int sum1 = 0;
  int sum2 = 0;
  int sum3 = 0;
  for(int i=0;i<n1;i++)
  {
      sum1 += stack1[i];
  }
  for(int i=0;i<n2;i++)
  {
      sum2 += stack2[i];
  }
  for(int i=0;i<n3;i++)
  {
      sum3 += stack3[i];
  }
  int i=0,j=0,k=0;
  while(i<n1 && j<n2 && k<n3)
  {
      if(sum1 == sum2 && sum2 == sum3)
      {
        return sum1;
      }
    else
    {
        if(sum1 >= sum2 && sum1 >= sum3)
        {
           sum1 -= stack1[i++];
        }
        else if(sum2 >= sum1 && sum2 >= sum3)
        {
            sum2 -= stack2[j++];
        }
        else if(sum3 >= sum1 && sum3 >= sum2) // if equal or greater reduce it
        {
            sum3 -= stack3[k++];
        }
    }
  }
  return 0;
}
