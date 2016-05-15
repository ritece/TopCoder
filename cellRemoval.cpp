#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CellRemoval
{
    public:
        int countLeafs(int index, int totalCells, vector<int> parent)
        {
           queue<int> q;
           q.push(index);
           int totalLeafs = 0;
           while(!q.empty())
           {
               int current = q.front();
               q.pop();
               bool isCurrentCellLeafCell = true;
               //check if this cell is parent of somebody, if yes then append it to the queue
               //otherwise increment the leaf count
               for(int i=0; i<totalCells; i++)
                   if(parent[i] == current)
                   {
                        q.push(i);
                        isCurrentCellLeafCell = false;
                   }
               if(!isCurrentCellLeafCell)
                   totalLeafs+=1;
           }
        }

        int cellsLeft( vector <int> parent, int deletedCell)
        {
           int totalCells = parent.size();
           
           //find the zygote
           int zygoteIndex = 0;
           for(int i=0; i<totalCells; i++)
               if( parent[i] == -1)
                   zygoteIndex = i;
           
           //count leafs from the zygote
           int totalLeafs = countLeafs(zygoteIndex, totalCells, parent);
           int deletedLeafs = countLeafs(deletedCell, totalCells, parent);

           return totalLeafs - deletedLeafs;
        }
};
