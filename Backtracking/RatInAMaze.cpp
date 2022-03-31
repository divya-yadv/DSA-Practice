public:
    bool isSafe(vector<vector<int>> &m,int i,int j,int n)
    {
        if((i >= 0) && (j >= 0) && (j<n) && (i<n) && (m[i][j] == 1)) // to check if its safe to move
        {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> &m,int n,int row,int col, vector<string>&ans,string p)
    {
        if((row == n-1 )&& (col == n-1))
        {
            ans.push_back(p);
            return;
        }
        // for downward
        
        if(isSafe(m,row+1,col,n))
        {
            m[row][col] = 2; // in recursion tree its marked as visited
            solve(m,n,row+1,col,ans,p+'D');
             m[row][col] = 1;
        }
        // for left
         if(isSafe(m,row,col-1,n))
        {
            m[row][col] = 2;
            solve(m,n,row,col-1,ans,p+'L');
             m[row][col] = 1;
        }
        //for right
        if(isSafe(m,row,col+1,n))
        {
            m[row][col] = 2;
            solve(m,n,row,col+1,ans,p+'R');
            m[row][col] = 1;
        }
       // for up
        if(isSafe(m,row-1,col,n))
        {
            m[row][col] = 2;
            solve(m,n,row-1,col,ans,p+'U');
             m[row][col] = 1;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
         vector<string> ans;
         if(m[0][0] == 0 || m[n-1][n-1] == 0)
         {
             return ans;
         }
         string p = "";
         solve(m,n,0,0,ans,p);
         return ans;
    }
