#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

class RGBStreet
{
public:
    int estimateCost(vector <string> houses)
    {
        int totalHouses = houses.size();
        int ans[25][3];
        for(int i=0; i<25; i++)
            for(int j=0; j<3; j++)
               ans[i][j]=-1;
        string lastCost = houses[totalHouses-1];
        stringstream ss(lastCost);
        string temp; ss>>temp;
        ans[totalHouses-1][0] = std::atoi(temp.c_str());
        ss>>temp;
        ans[totalHouses-1][1] = std::atoi(temp.c_str());
        ss>>temp;
        ans[totalHouses-1][2] = std::atoi(temp.c_str());
        
        for(int i=totalHouses-2; i>=0; i--)
        {
        lastCost = houses[i];
        stringstream ss(lastCost);
        ss>>temp;
        int rCost = std::atoi(temp.c_str());
        ss>>temp;
        int gCost = std::atoi(temp.c_str());
        ss>>temp;
        int bCost = std::atoi(temp.c_str());
        
        ans[i][0] = min(rCost+ans[i+1][1], rCost+ans[i+1][2]);
       
        ans[i][1] = min(gCost+ans[i+1][0], gCost+ans[i+1][2]);
        
        ans[i][2] = min(bCost+ans[i+1][0], bCost+ans[i+1][1]);
        }

        return min(ans[0][0], min(ans[0][1], ans[0][2]));

    }
};
