static bool comp(Item &item1,Item &item2)
    { 
        double a1 = (double) item1.value/item1.weight;
        double a2 = (double) item2.value/item2.weight;
       return a1>a2;  
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp); // sort according to value/weight ratio
        double ans = 0;
        for(int i=0;i<n;i++)
        {
            if(arr[i].weight <= W)
            {
                ans += (double)arr[i].value;
                W -= arr[i].weight;
            }
            else 
            {
                if(W!=0)
                {
                     ans += (double)W*(double)(arr[i].value)/(arr[i].weight);
                     break;
                }
               
            }
        }
        return ans;
    }
        
