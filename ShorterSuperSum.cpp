#include <iostream>
using namespace std;

class ShorterSuperSum
{
    public:
    int calculate(int k, int n)
    {
        int first[30] = {0};
        int second[30] = {0};
        for(int i=0; i<n; i++)
        {
            first[i] = i+1;
        }
        for(int i=1; i<=k;i++)
        {
            second[0] = first[0];
            for(int j=1; j<n; j++)
                second[j]=first[j]+second[j-1];
            for(int j=0; j<n; j++)
                first[j]=second[j];
        }
        return first[n-1];
    }
};
