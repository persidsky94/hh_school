#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//const int LENGTH=1039;


int main()
{
    int LENGTH;
    cin >> LENGTH;
    cout << endl;
    int sum=1;
    int cur_length=1;
    int cur_number=1;
    while (cur_length < LENGTH)
    {
        cur_length +=2;
        for (int i=0; i<4; ++i)
        {
            cur_number += cur_length-1;
            sum += cur_number;
        }
    }
    cout << "Summ of the numbers on the diagonals of square spiral with side length " << LENGTH << " is " << sum << endl;
    return sum;
}