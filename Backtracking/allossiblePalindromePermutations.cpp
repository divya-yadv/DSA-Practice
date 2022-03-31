bool isPalindrome(string S,int low,int high){
     while(low<high){
         if(S[low]!=S[high]){
             return false ;
         }
         high--;
         low++;
     }
     return true;
 }
  
   void solve(string S,vector<vector<string>>&res,int p,vector<string>v,int n)
   {
       if(p >= n) // if all came then push it in res
       {
           res.push_back(v);
           return;
       }
       for(int i=p;i<n;i++) // check for all 
       {
           if(isPalindrome(S,p,i))
           {
               v.push_back(S.substr(p,i-p+1)); // add it to the current one
               solve(S,res,i+1,v,n); // check for next index in same call
               v.pop_back();
           }
           
       }
   }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> res;
        if(S.length() == 0)
        {
            return res;
        }
        vector<string> v;
        int n = S.length();
        string q = "";
        solve(S,res,0,v,n);
    }
