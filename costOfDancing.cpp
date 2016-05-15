#include <iostream>
#include <algorithm>
using namespace std;

class CostOfDancing
{
        public:
                int minimum(int K, vector <int> danceCost)
                        {
                          sort(danceCost.begin(), danceCost.end());
                          int ans = 0;
                          for(int i=0; i<K; i++)
                                  ans+=danceCost[i];
                          return ans;
                        }
};
