 string smallestNumber(int S, int D){
        string p(D,'0'); 
        if(S>D*9)
        {
            return "-1";
        }
        int i = D-1; // start from last digit
        while(S>9) // fill all with 9 till we can
        {
            p[i] = '9';
            S = S-9;
            i--;
        }
        if(i == 0) // if filled all then last should be whatever sum left
        {
            p[0] = S+'0';
        }
        else  // if more places left
        {
            p[0] = '1'; // fill first with 1
            p[i] = S-1+'0'; // last one with sum left-1
        } // rest of them are gonna be 0 only
        return p;
    }
