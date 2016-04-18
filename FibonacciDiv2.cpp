#include <iostream>

using namespace std;

class FibonacciDiv2
{
public:
    int find(int n)
    {
        int fibArray[32] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,
        377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,
        1346269};
        int i;
        for(i=0;fibArray[i]<n;i++)
            {
            }
        int diff1 = fibArray[i]-n;
        int diff2 = n-fibArray[i-1];

        return min(diff1, diff2);
    }
};
