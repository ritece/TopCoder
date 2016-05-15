#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CarolsSinging
{
    public:

        int countCarols(int currentCombination)
        {
            int count = 0;

            while(currentCombination>0)
            {
                if(currentCombination & 1)
                {
                    count+=1;
                    currentCombination = currentCombination >> 1;
                }
            }
            return count;
        }

        int choose(vector <string> lyrics)
        {
            int total = lyrics.size();
            int carolsCount = lyrics[0].size();
            int minimumCount = 100;

            //iterate over all subsets of the possible carols combination
            for(int combination = 0; combination < (1<<carolsCount); combination++)
            {
                //from this combination of the songs, check if it possible for everyone to sing any one of them
                bool isCurrentCombinationPlayable = true;

                for(int i = 0; i<total; i++)
                {
                    bool isPossible = false;
                    //for current person check if they are able to sing any of the carol from the combination
                    for(int j = 0; j<carolsCount; j++)
                    {
                        if( lyrics[i][j] == 'Y' && ( combination & (1<<j) ) )
                            isPossible = true;
                    }
                    
                    // if current person cannot sing any of the song from the combination of the carols we chose, then we should try the next combination
                    if(!isPossible)
                    {
                        isCurrentCombinationPlayable = false;
                    }
                }

                if(isCurrentCombinationPlayable)
                {
                   minimumCount = min(minimumCount, __builtin_popcount(combination) );
                }
            }

            return minimumCount;
        }
};

