#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


bool no_equal(vector<int> a)
{
  std::sort (a.begin(), a.end());
  for (vector<int>::iterator it=a.begin(); it != a.end(); ++it)
  {
    vector<int>::iterator it2 = it;
    ++it2;
    if (*it == *it2) return 0;
  }
  return 1;
}

bool expression(vector<int> a)
{
  return (100*a[0]+10*a[1]+a[2]+100*a[0]+10*a[3]+a[3] == 100*a[3]+10*a[1]+a[4]);
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
	    int b[] = {u, x, t, z, s};
	    vector<int> a(b,b + sizeof(b)/sizeof(int));
	    if (expression(a) && no_equal(a))
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
