 void dfs(int i, vector<int> adj[],vector<bool>&vis,vector<int>&topo,int &mini,vector<int> d,unordered_map<int,int> mp)
    {
        vis[i] = true;
        for(auto x: adj[i])
        {
            if(!vis[x])
            {
                mini = min(mini,d[mp[x]]);
                dfs(x,adj,vis,topo,mini,d,mp);
            }
        }
        topo.push_back(i);
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<int> adj[n+1];
        unordered_map<int,int> mp;
        for(int i=0;i<p;i++) /// to keep track of indexes and get the weight 
        {
            mp[b[i]] = i;
        }
        for(int i=0;i<p;i++)
        {
            adj[a[i]].push_back(b[i]);
        }
        vector<vector<int>> ans;
        vector<bool> visited(n+1,false);
        for(int i=0;i<n+1;i++)
        {
            if((adj[i].empty()) || (mp.find(i)!=mp.end())) // to check it its a node or not
            {
                continue;
            }
            else
            {
                if(!visited[i])
                {
                    int mini = INT_MAX; // to get minimum for that component
                    vector<int> toposort; // to get the elements
                    dfs(i,adj,visited,toposort,mini,d,mp);
                     ans.push_back({toposort.back(),toposort.front(),mini});
                }
               
            }
        }
        return ans;
    }
