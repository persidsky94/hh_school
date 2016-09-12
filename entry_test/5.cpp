#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int LEFT_LIMIT=2, RIGHT_LIMIT=10;

int min_factorial(int n)
{
  int compared_value=0;
  
}

int main()
{
  int total_sum=0;
  for (int i=LEFT_LIMIT; i< RIGHT_LIMIT+1; ++i)
  {
    total_sum += min_factorial(i);
  }
  cout << "Total summ is " << total_sum << endl;
  return total_sum;
}
