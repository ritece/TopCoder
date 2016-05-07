#include <iostream>
#include <vector>

using namespace std;


class NumbersChallenge
{
public:
    int MinNumber(vector <int> S)
    {
        int arr[2000001]={0};
        int total = S.size();
        for(int i=0; i<=((1<<total)-1); i++)
           {
             int sum = 0;
             for(int j=0; j<total; j++)
                   if(i&(1<<j))
                        {
                          sum+=S[j];
                        }
          
           }
          arr[sum] = 1;
        }

        int ans = 0;

        for(int i=0; i<2000001; i++)
        {
            if(arr[i]==0)
            {
                ans = i;
                break;
            }

        }

        return ans;
    }

};
