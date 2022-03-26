long long minCost(long long arr[], long long n) {
         priority_queue<long long,vector<long long>,greater<long long>> pq; // to keep track of two lowest values that we want to add
         for(long long i=0;i<n;i++)
         {
             pq.push(arr[i]);
         }
         long long res = 0;
         while(pq.size()!= 1)
         {
             long long n1 = pq.top();
             pq.pop();
             long long n2 = pq.top();
             pq.pop();
             pq.push(n1+n2);
             res += n1+n2;
         }
         return res;
    }
