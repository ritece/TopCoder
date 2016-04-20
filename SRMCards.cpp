#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SRMCards
{
public:
    int maxTurns(vector<int> cards )
    {
        int len = cards.size();
        sort(cards.begin(), cards.begin()+len);
        int i=0, ans =0;
        while(i<len)
        {
            if( (i+1 < len) && (cards[i]+1 == cards[i+1]) )
            {
                //found successive cards
                ans+=1;
                i+=2;
            }
            else
            {
                ans+=1;
                i+=1;
            }
        }
        return ans;
    }
};
