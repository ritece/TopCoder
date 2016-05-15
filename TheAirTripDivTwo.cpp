#include <iostream>
#include <vector>
using namespace std;

class TheAirTripDivTwo
{
   public:
       int find(vector<int> flights, int fuel)
       {
           int count=0;
           int total = flights.size();
           for(int i=0; i<total; i++)
           {
               if(flights[i] >= fuel)
               {
                   count+=1;
                   fuel-=flights[i];
               }
               else
                   break;
           }
           return count;
       }
};
