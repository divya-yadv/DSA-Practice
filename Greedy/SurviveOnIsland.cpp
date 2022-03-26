void survival(int days,int onedaybuy,int onedayconsume)
{
    if((onedaybuy < onedayconsume) || ((onedaybuy*6 < onedayconsume*7) && days>6 ))
    {
      ans = 'No';
    }
    else 
    {
        ans = 'Yes';
        totalrequired = onedayconsume*days;
        count = totalrequired/onedaybuy;
      if(totalrequired%onedaybuy != 0)
      {
          count++; // one more day extra bcz we need a bit more.
      }
    }
}
