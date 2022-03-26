int pageFaults(int N, int C, int pages[]){
        list<int> v; // easy to push in front inbuilt function
        int count = 0;
        for(int i=0;i<N;i++)
        {
            bool found = false;
             for (auto it = v.begin(); it != v.end(); it++) // see if its already there
            {
                if(*it == pages[i]) // if found drag it to the front position coz its most recent now
                {
                    v.erase(it);
                    v.push_front(pages[i]);
                    found = true;
                    break;
                }
            }
            if(found == false)
            {
                if(v.size() == C)
                {
                    v.pop_back();
                }
                v.push_front(pages[i]);
                count++; // if its not there then only it is page fault
            }
            
        }
        return count;
    }
