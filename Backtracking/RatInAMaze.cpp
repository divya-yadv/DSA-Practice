bool isValid(vector<vector<int>> m,int row, int col,int n) {
        if (row >= 0 && row < n && col >= 0 && col < n && m[row][col] == 1) {
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>> m, int n,int i,int j,vector<string>&S,string p)
    {
         if(i == n-1 && j == n-1)
         {
             S.push_back(p);
             return;
         }
       // downward
    if (isValid(m,i+1,j,n)) {
      m[i][j] = 2; // to keep track it its visited or not
      solve(m,n,i + 1, j,S, p + 'D');
       m[i][j] = 1;
    }

    // left
    if (isValid(m,i,j-1,n)) {
       m[i][j] = 2;
       solve(m,n,i, j-1,S, p + 'L');
      m[i][j] = 1;
    }

    // right 
    if (isValid(m,i,j+1,n)) {
       m[i][j] = 2;
       solve(m,n,i, j+1,S, p + 'R');
       m[i][j] = 1;
    }

    // upward
    if (isValid(m,i-1,j,n)) {
       m[i][j] = 2;
       solve(m,n,i - 1, j,S, p + 'U');
       m[i][j] = 1;
    }

    }    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> v;
        vector < vector < int >> vis(n, vector < int > (n, 0));
        if(m[n-1][n-1] == 0 || m[0][0] == 0)
        {
            return v;
        }
        string p = "";
        solve(m,n,0,0,v,p);
        return v;
    }
