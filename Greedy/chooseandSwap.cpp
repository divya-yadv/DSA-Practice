string chooseandswap(string a){
        vector<int> m (26,-1); // to see which elements are present 
        for(int i=0;i<a.length();i++)
        {
            if(m[a[i]-'a'] == -1)
            {
                m[a[i]-'a'] = i;
            }
        }
        char first;
        char second;
        for(int i=0;i<a.length();i++)
        {
            for(int j=0;j<a[i]-'a';j++) // we need to see if there is any element which is smaller than this and coming after this 
            {
                if(m[j] > m[a[i]-'a'])
                {
                  
                    first = a[i];
                    second = j+'a';
                    break;
                }
            }
            if(first == a[i])
            {
                break;
            }
        }
        for(int i=0;i<a.length();i++)
        {
            if(a[i] == first)
            {
                a[i] = second;
            }
            else if(a[i] == second)
            {
                a[i] = first;
            }
        }
        return a;
    }
};
