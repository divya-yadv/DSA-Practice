unordered_set<string> sp;
    int mind(string s)
    {
        stack<int> st; // to calculate deletions
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(isalpha(s[i]))
            {
                continue;
            }
            else 
            {
                if(st.empty())
                {
                    st.push(s[i]);
                }
                else if(st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
       return st.size();
    }
    void solve(string s,int in,vector<string>&res)
    {
      if(in <0) // if crossed return
      {
          return;
      }
        if(in == 0) // if deleted all now check if this s valid 
        {
            int now = mind(s);
            if(now == 0)
            {
                res.push_back(s);

                
            }
            return;
        }
        for(int k=0;k<s.length();k++)// for all substrings
        {
            if(isalpha(s[k]))
            {
                continue;
            }
            else 
            {
                string temp = s.substr(0,k) + s.substr(k+1);
                if(sp.find(temp) == sp.end()) // if already processed leave it
                {
                    sp.insert(temp);
                     solve(temp,in-1,res);
                }
                    
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int in = mind(s); // to get minimum deletion
        solve(s,in,res);
        return res;
    }
