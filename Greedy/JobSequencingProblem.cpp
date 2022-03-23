  struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
  bool comp(Job n1,Job n2)
    {
       return n1.profit>n2.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr,arr+n,comp);
        int maxdead = 0;
        for(int i=0;i<n;i++)
        {
            maxdead = max(maxdead,arr[i].dead);
        }
        vector<int>jobdone(maxdead+1,-1); // to get the maxtime you got to finish all possible job
        int tprofit = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j = arr[i].dead;j>=1;j--) // this is to check if it can be fitted before its time deadline
            {
                if(jobdone[j] == -1)
                {
                    jobdone[j] = arr[i].id;
                    tprofit += arr[i].profit;
                    count++;
                    break;
                }
            }
        }
        return {count,tprofit};
    } 
    
