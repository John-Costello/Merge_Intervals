import java.util.Arrays;

public class Main
{
    public static void main(String[] args)
    {
        System.out.println("==========Merge Intervals==============");
        System.out.println("=======================================");
        System.out.println("============ Before ===================");
        int[][] intervals = {{1,1},{2,5},{3,4},{6,15},{10,20},{30,40},{36,45},{50,59},{56,57}};
        System.out.println(Arrays.deepToString(intervals));
        System.out.println("\n============ After ====================");
        int[][] output= new Solution().merge(intervals);
        System.out.println(Arrays.deepToString(output));
        
    }
}
