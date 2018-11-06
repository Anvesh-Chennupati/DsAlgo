import java.util.HashMap;
import java.util.Map;

public class TwoSum{

    public static int[] Twosums(int[] nums,int target){
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i]) {
                    return new int[] { i, j };
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    public static int[] TwosumsM(int[] nums, int target){
        Map<Integer,Integer> m1 = new HashMap<>();
        for(int i = 0;i<nums.length;i++){
            m1.put(nums[i],i);
        }
        System.out.println(m1.size());
        int comp;
        for(int i =0;i<nums.length;i++){
            comp = target - nums[i];
            if(m1.containsKey(comp) && m1.get(comp)!=i){
                return new int[] {i,m1.get(comp)}; 
            }
        }
        throw new IllegalArgumentException("No element");
    }

    public static void main(String args[]){
        int[] arr  = {2, 7, 11, 15};
        int target = 13;
        int[] ans =Twosums(arr,target);
        int[] ansM = TwosumsM(arr,target);
        //for(int x:ans)
          //  System.out.println(x);
        System.out.println(java.util.Arrays.toString(ans));
        System.out.println(java.util.Arrays.toString(ansM));
    }
}