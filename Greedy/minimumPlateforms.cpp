      sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i=0,j=0,k=0;
    	int ans =0;
    	while(i<n&&j<n)
    	 {   if(arr[i]<=dep[j])
    	    {
    	        i++;
    	        k++; // total trains at same time at plateform
    	    }
    	    else
    	    {
    	        j++;
    	        k--;
    	    }
    	    ans = max(ans,k);
    	}
    	return ans;
