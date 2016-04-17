#include <iostream>
#include <vector>
using namespace std;

class ZigZag
{
    public:
    int longestZigZag(vector<int> sequence)
    {
        int bigArray[50]={0}; int smallArray[50] = {0};
        for(int i=0; i<50; i++) bigArray[i]=1;
        for(int j=0; j<50; j++) smallArray[j]=1;
        int l = sequence.size();
        int ans=1;
        for(int i=1; i<l; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(sequence[i]>sequence[j])
                {
                    if(bigArray[i]<smallArray[j]+1)
                    {
                        bigArray[i]=smallArray[j]+1;
                        ans = max(ans, bigArray[i]);
                    }
                }
                else if(sequence[i]<sequence[j])
                {
                   if(smallArray[i]<bigArray[j]+1)
                   {
                       smallArray[i]=bigArray[j]+1;
                        ans = max(ans, smallArray[i]);
                   }
                }
            }
        }
        return ans;
    }
};
