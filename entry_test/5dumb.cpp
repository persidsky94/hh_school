#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

const int LEFT_LIMIT=310000000, RIGHT_LIMIT=320000000;

vector<int> get_primes(const int rl)
{
  vector<int> primes;
  vector<int>::iterator it=primes.end();
  primes.insert(it, 2);
  it=primes.end();
  int limit = int(sqrt(rl)+1);
  for (int i=3; i<limit+1; ++i)
  {
    bool not_prime=0;
    for (it=primes.begin(); it != primes.end(); ++it)
    {
      if ((i % (*it)) == 0)
      {
	not_prime=1;
	break;
      }
    }
    if (not_prime == 0)
    {
      it = primes.end();
      primes.insert(it, i);
    }
  }
  return primes;
}

int max_pow(int n, int divider)
{
  int cur_dividend = n;
  int pow = 0;
  while ((cur_dividend % divider) == 0)
  {
    cur_dividend = cur_dividend/divider;
    pow += 1;
  }
  return pow;
}

int find_arg(int p, int q)
{
  if (q == 0) return 0;
  int cur_arg = p;
  int sum_pow = 1;
  while (sum_pow < q)
  {
    cur_arg += p;
    sum_pow += max_pow(cur_arg, p);
  }
  return cur_arg;
}

int main()
{
  unsigned long long int total_sum=0;
  vector<int> primes = get_primes(RIGHT_LIMIT);
  int primes_size = primes.size();
  for (int i=LEFT_LIMIT; i< RIGHT_LIMIT+1; ++i)
  {
    int cur_number = i;
    vector<int> pow_primes(primes_size);
    for (std::vector<int>::iterator it=primes.begin(); it != primes.end(); ++it)
    {
      int pow=0;
      while ((cur_number % (*it)) == 0)
      {
	cur_number = cur_number/(*it);
	pow += 1;
      }
      pow_primes[it-primes.begin()] = pow;
    }
    int max_arg = cur_number;
    for (std::vector<int>::iterator it=pow_primes.begin(); it != pow_primes.end(); ++it)
    {
      int arg = find_arg(primes[it-pow_primes.begin()], (*it));
      if (max_arg < arg) max_arg=arg;
    }
    total_sum += static_cast<unsigned long long int>(max_arg);
    if ((i % 100000) == 0) cout << "Still working on it, current i is " << i << " and sum now is " << total_sum << endl;
  }
  cout << "Total summ is " << total_sum << endl;
  return 1;
}
