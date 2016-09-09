#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const int LEFT_LIMIT=310000000, RIGHT_LIMIT=320000000;

int min_fact(int n)
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
    cout << "Total summ is " << total_sum
    ;
    return total_sum;
}