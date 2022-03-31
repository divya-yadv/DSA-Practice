bool isSafe(int grid[N][N],int row,int col,int p)
    {
        for(int i=0;i<N;i++)
        {
            if((grid[i][col] == p) || (grid[row][i] == p)) // same row or same column
            {
                return false;
            }
        }
        int rs = row - (row%3); // get the factors which inner grid it is
        int cs = col - (col%3);
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(grid[rs+i][col+j] == p) // check in inner grid
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        int col,row;
        bool flag = false;
        for(int i=0;i<N;i++) // to check if we need to fill this
        {
            for(int j=0;j<N;j++)
            {
                if(grid[i][j] == 0)
                {
                    row = i;
                    col = j;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) // if not then return true
        {
            return true;
        }
        for(int i=1;i<=N;i++)
        {
            if(isSafe(grid,row,col,i)) // first check if we can fill this
            {
                grid[row][col] = i; // filled this
                if(SolveSudoku(grid)) // worked
                {
                    return true;
                }
                grid[row][col] = 0; // need to backtrack
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
