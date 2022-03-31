bool isSafe(bool graph[101][101], int colornum,int V,int i,int color[])
{
    for(int j=0;j<V;j++) // any adjecent shouldn't have same color
    {
        if((j != i) && graph[j][i] == 1 && color[j] == colornum)
        {
            return false;
        }
    }
    return true;
}
bool coloring(bool graph[101][101],int m,int V,int p,int color[])
{
    if(p == V) // if all done return true
    {
        return true;
    }
    for(int colornum = 1;colornum <= m ;colornum++) // assign all colors and see if it works
    {
        if(isSafe(graph,colornum,V,p,color)) // if its safe check for next one
        {
            color[p] = colornum;
            if(coloring(graph,m,V,p+1,color))
                return true;
             color[p] = 0;
        }
       
    }
    
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V] = {0}; // to store colors
    if(coloring(graph,m,V,0,color))
    {
        return true;
    }
    return false;
}
