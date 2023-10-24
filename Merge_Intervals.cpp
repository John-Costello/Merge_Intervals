#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals){

        int numOfPairs=intervals.size();
        for(int i=0; i<numOfPairs-1; i++)
        {
            for(int j=i+1; j<numOfPairs; j++)
            {
                //-------------------------------------------------
                if(intervals[i].empty() || intervals[j].empty()) 
                {      }
                //----------------if pairA inside pairB-------------
                else if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1])
                {   intervals[i].clear();    }
                //----------------if pairB inside pairA-------------
                else if(intervals[j][0]>=intervals[i][0] && intervals[j][1]<=intervals[i][1])
                {   intervals[j].clear();    }
                //----------------if pairA leftMerges pairB--------- 
                else if(intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][0] && intervals[i][1]<=intervals[j][1])
                {   intervals[i][1]=intervals[j][1]; intervals[j].clear(); j=i;  }
                 //----------------if pairA rightMerges pairB---------
                else if(intervals[i][0]>=intervals[j][0] && intervals[i][0]<=intervals[j][1] && intervals[i][1]>=intervals[j][1])
                {   intervals[i][0]=intervals[j][0]; intervals[j].clear(); j=i;  }
            }
        }
        
        int mergeCount=0;
        for(auto pair : intervals)
        {   if(pair.empty())mergeCount++;   }
        vector<vector<int>> output(numOfPairs-mergeCount, vector<int>(2));
        for(int i=0,j=0; i<numOfPairs; i++)
        {
            if(!(intervals[i].empty()) )
            {
                output[j]=intervals[i]; 
                j++;
            }
        }
        return output;
   }
};

int main()
{
   cout << "==========Merge Intervals==============" << endl;
   cout << "=======================================" << endl;
   cout << "============ Before ===================" << endl;
   vector<vector<int>> intervals 
   {
      {1,1},
      {2,5},
      {3,4},
      {6,15},
      {10,20},
      {30,40},
      {36,45},
      {50,59},
      {56,57}
   };
   for(int i=0; i<intervals.size(); i++)
   {
      cout << "[";
      for(int j=0; j<intervals[i].size(); j++)
      {
         cout << intervals[i][j];
         if(j<intervals[i].size()-1){   cout<<", ";   }
      }
      cout << "]" << endl;
   }
   cout << "============ After ====================" << endl;
   Solution solution;
   vector<vector<int>> output = solution.merge(intervals);
   for(int i=0; i<output.size(); i++)
   {
      cout << "[";
      for(int j=0; j<output[i].size(); j++)
      {
         cout << output[i][j];
         if(j<output[i].size()-1){   cout<<", ";   }
      }
      cout << "]" << endl;
   }
   cout << "=======================================\n" << endl;
}