void solve(vector<string>&dict,vector<string>&res,string s,string p,int i)
    {
        if(i >= s.length())
        {
            p.pop_back();
            res.push_back(p);
            return;
        }
        string str="";
        for(int k=i;k<s.length();k++) // loop will run to get all different combinations with the same index if possible thats how we get all answers
        {
            str += s[k];
            if(find(dict.begin(),dict.end(),str) !=  dict.end()) // to check if current word is present
            {
                solve(dict,res,s,p+str+' ',k+1);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> res;
        int i=0;
        solve(dict,res,s,"",0);
        return res;
    }
