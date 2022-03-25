         sort(candies,candies+N);
         int count = 0;
         int maxi = 0;
         int mini = 0;
         for(int i=0;i<N;i++)
         {
             if(count >= N) // if got all break
             {
                 break;
             }
             mini += candies[i]; // take the starting ones
             maxi += candies[N-1-i]; // take the last ones
             count += 1 + K;
         }
         return {mini,maxi};
