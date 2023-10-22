public class Solution
{
    public int[][] merge(int[][] intervals)
    {
        if(intervals==null)return null;
        
        int numOfPairs=intervals.length;
        for(int i=0; i<numOfPairs-1; i++)
        {
            for(int j=i+1; j<numOfPairs; j++)
            {
                //-------------------------------------------------
                if(intervals[i]==null || intervals[j]==null) 
                {      }
                //----------------if pairA inside pairB-------------
                else if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1])
                {   intervals[i]=null;    }
                //----------------if pairB inside pairA-------------
                else if(intervals[j][0]>=intervals[i][0] && intervals[j][1]<=intervals[i][1])
                {   intervals[j]=null;    }
                //----------------if pairA leftMerges pairB--------- 
                else if(intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][0] && intervals[i][1]<=intervals[j][1])
                {   intervals[i][1]=intervals[j][1]; intervals[j]=null; j=i;  }
                 //----------------if pairA rightMerges pairB---------
                else if(intervals[i][0]>=intervals[j][0] && intervals[i][0]<=intervals[j][1] && intervals[i][1]>=intervals[j][1])
                {   intervals[i][0]=intervals[j][0]; intervals[j]=null; j=i;  }
            }
        }
        int mergeCount=0;
        for(int[] pair : intervals)
        {   if(pair==null)mergeCount++;   }
        int[][] output = new int[numOfPairs-mergeCount][];
        for(int i=0,j=0; i<numOfPairs; i++)
        {
            if(intervals[i]!=null)
            {
                output[j]=intervals[i]; 
                j++;
            }
        }
        return output;
    }
}
