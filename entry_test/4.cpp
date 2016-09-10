#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include "decimal.h"
using namespace std;

const int /*LEFT_LIMIT, RIGHT_LIMIT,*/ FIXED_SUM=10;

bool check_number(int n)
{
    int length=decimal_length(n);
    vector<int> n_decimal(length);
    vector<bool> checker(length);
    vector<bool> sample_checker(length, 1);
    for (int j=0; j<length; ++j)
    {
        n_decimal[j]=get_numeral(n, j+1);
    }
    for (int k=0; k< length; ++k)
    {
        int sum=0;
        for (int h=k; h<length; ++h)
        {
            sum+=n_decimal[h];
            if (sum>FIXED_SUM) break;
            else if (sum == FIXED_SUM)
            {
		cout << "Current number is " << n << ", summ of numerals from " << k << " to " << h << " equals " << sum << endl;
                for (int p=k; p<h+1; ++p)
                {
                    checker[p]=(checker[p]||1);
                }
            }
        }
    }
    if (checker == sample_checker) return 1;
    else return 0;
}

int main()
{
    int LEFT_LIMIT, RIGHT_LIMIT;
    cin >> LEFT_LIMIT;
    cout << endl;
    cin >> RIGHT_LIMIT;
    cout << endl;
    int total_counter=0;
    for (int i=LEFT_LIMIT; i<=RIGHT_LIMIT; ++i)
    {
        if (check_number(i)) total_counter+=1;      
    }
    cout << "Number of 'special' numbers in range from " << LEFT_LIMIT << " to " << RIGHT_LIMIT << " is " << total_counter << endl;
    return total_counter;
}
