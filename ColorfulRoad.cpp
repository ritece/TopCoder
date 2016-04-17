#include <iostream>
#include <string>

using namespace std;

class ColorfulRoad
{
public:
    int getMin(string road)
    {
        string current = "R";
        int roadSize = road.length();
        int reachCost[30];
        reachCost[0]=1;
        for(int i=1; i<30; i++)
            reachCost[i]=-1;
        for(int i=1; i<roadSize; i++)
        {
            int currentIndex = i;
            char preColor = 'a';
           char currentColor = road[currentIndex];
            if(currentColor=='R')
                preColor = 'B';
            else if(currentColor=='B')
                preColor = 'G';
            else if(currentColor=='G')
                preColor = 'R';

            for(int j=currentIndex-1; j>=0; j--)
            {
                if(road[j]==preColor && reachCost[j]!=-1)
                {
                    int newCost = (currentIndex-j)*(currentIndex-j);
                    if(reachCost[currentIndex]==-1)
                        reachCost[currentIndex] = reachCost[j]+newCost;
                    else
                        reachCost[currentIndex] = min(reachCost[currentIndex],reachCost[j]+newCost);
                }
            }
        }
        if(reachCost[roadSize-1]!=-1)
            reachCost[roadSize-1]-=1;
        return reachCost[roadSize-1];
    }
};
