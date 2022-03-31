void solve(vector<int>&A,int i,int sum,vector<vector<int>> &res,vector<int>&curr)
    {
        if(sum == 0) // if sum 0 then found
        {
            res.push_back(curr);
            return;
        }
        if(sum<0)
            return;
        
        for(int j=i;j<A.size();j++)
        {
            if(sum >= A[j]) // if can be included
            {
                curr.push_back(A[j]); // push it into curr
                solve(A,j,sum-A[j],res,curr); then solve for same 
                curr.pop_back(); // backtrack
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(A.begin(),A.end()); // to get in sorted order
        A.erase(unique(A.begin(), A.end()), A.end()); // to remove dupliactes as infinite supply available
        
        solve(A,0,B,res,curr);
        return res;
    }
