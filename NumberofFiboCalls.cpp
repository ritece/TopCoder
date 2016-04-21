//simple memoisation

#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;

class NumberofFiboCalls
{
public:
    vector<int> ans;
    vector <int> fiboCallsMade(int n)
    {
        int zero[50]={0};
        int one[50] = {0};
        zero[0]=1;
        zero[1]=0;
        one[0] = 0;
        one[1] = 1;
        for(int i=2; i<=n; i++)
        {
            zero[i]=zero[i-1]+zero[i-2];
            one[i]=one[i-1]+one[i-2];
        }
         ans = {zero[n], one[n]};
        return ans;
    }
};
