#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int TOP_LIMIT = 1000000;
const int FIRST_FACTOR = 3;
const int SECOND_FACTOR = 4;


int get_numeral(int r, int k) //returns k-th numeral from the end of the number r in decimal number system
{
  return ((r%int(pow(10,k))) - (r%int(pow(10,k-1))))/int(pow(10,k-1)); 
}

int decimal_length(int d)
{
  if (d <= 0) 
  {
    cout << "Can't get length; " << d << " is not positive";
    return -1;
  }
  int w = 1;
  while (d >= int(pow(10,w)))
  {
    w += 1;
  }
  return w;
}

bool check(int n)  //checks if n*FIRST_FACTOR and n*SECOND_FACTOR consist of the same asset of numerals in decimal number system
{
  if (n <= 0)
  {
    cout << n << " is not positive natural number" << endl;
    return 0;
  }
  int j=1;
  std::vector<int> a(10);
  std::vector<int> b(10);
  int p = n*max(FIRST_FACTOR, SECOND_FACTOR);
  int q = n*min(FIRST_FACTOR, SECOND_FACTOR);
  if (decimal_length(p) != decimal_length(q))
    return 0;
  while (p/pow(10,j-1) >= 1)
  {
    a[get_numeral(p, j)] += 1; 
    b[get_numeral(q, j)] += 1;
    j += 1; 
  }
  return (a==b);
}


int main()
{
  int i=1;
  while (i < TOP_LIMIT)
  {
    if (check(i))
    {
      cout << "The first number for which 3x and 4x consist of the same asset of arabic numerals is " << i << endl;
      return i;
    }
    else
      ++i;
  }
  cout << "It seems that there is no number for which 3x and 4x consist of the same asset of arabic numerals under " << TOP_LIMIT << endl;
  return -1;
} 
