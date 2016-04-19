#include <iostream>

using namespace std;

class UnsealTheSafe
{
public:
    long countPasswords(int n)
    {
        long preCombinations[12]={0};
        long newCombinations[12]={0};
        for(int i=0; i<12; i++)
            preCombinations[i]=1;
            
        for(int i=1; i<n; i++)   //index at which new password digit is to be placed
         {
                //for 1
            newCombinations[2]+=preCombinations[1];
            newCombinations[4]+=preCombinations[1];

            //for 2
            newCombinations[1]+=preCombinations[2];
            newCombinations[5]+=preCombinations[2];
            newCombinations[3]+=preCombinations[2];

            //for 3
            newCombinations[2]+=preCombinations[3];
            newCombinations[6]+=preCombinations[3];

            //for 4
            newCombinations[1]+=preCombinations[4];
            newCombinations[5]+=preCombinations[4];
            newCombinations[7]+=preCombinations[4];

            //for 5
            newCombinations[2]+=preCombinations[5];
            newCombinations[4]+=preCombinations[5];
            newCombinations[6]+=preCombinations[5];
            newCombinations[8]+=preCombinations[5];

            //for 6
            newCombinations[3]+=preCombinations[6];
            newCombinations[5]+=preCombinations[6];
            newCombinations[9]+=preCombinations[6];

            //for 7
            newCombinations[0]+=preCombinations[7];
            newCombinations[4]+=preCombinations[7];
            newCombinations[8]+=preCombinations[7];

            //for 8
            newCombinations[7]+=preCombinations[8];
            newCombinations[5]+=preCombinations[8];
            newCombinations[9]+=preCombinations[8];

            //for 9
            newCombinations[6]+=preCombinations[9];
            newCombinations[8]+=preCombinations[9];

            //for 0
            newCombinations[7]+=preCombinations[0];

        for(int j=0; j<12; j++)
           {
               preCombinations[j]=newCombinations[j];
               newCombinations[j]=0;
           }
         }

      long ans = 0;
      for(int i=0; i<=9; i++)
        ans+=preCombinations[i];
      return ans;
    }
};
