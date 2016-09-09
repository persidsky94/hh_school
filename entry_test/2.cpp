#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


bool no_equal(vector<int> a)
{
  a.sort
}

int main()
{
  int total_counter=0;
  for (int u=1; u<10; ++u)
  {
    for (int x=0; x<10; ++x)
    {
      for (int t=0; t<10; ++t)
      {
	for (int z=1; z<10; ++z)
	{
	  for (int s=0; s<10; ++s)
	  { 
	    if (expression(u, x, t, z, s) && no_equal(u, x, t, z, s))
	    {
	      cout << u << x << t << "+" << u << z << z << "=" << z << x << s << endl;
	      total_counter += 1;
	    }
	  }
	}
      }
    }
  }
  cout << "Equality has " << total_counter << " solutions" << endl;
  return total_counter;
}
