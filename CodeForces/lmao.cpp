#include <iostream>
using   namespace  std;

int  Search( int  n)
{
  int i,j,x;
  for(i=10;i>1;i--)
    {
      x=n;j=i;
      while(j)
        {
	  if((x-1)%i!=0)break;
	  x-=(x-1)/i+1;j--;
        }
      if(j==0&&x%i==0)
	return i;
    }
  return 0;
}

int  main()
{
  int c,p;
  while(cin>>c)
    {
      if(c==-1)
	break;
      cout<<c<<" coconuts, ";
      p=Search(c);
      if(p>0)
	cout<<p<<" people and 1 monkey"<<endl;
      else
	cout<<"no solution"<<endl;
    }
  return 0;
}
