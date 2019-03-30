import java.util.HashSet;
import java.util.Set;


public class LongestSubstring {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0;
        while (i < n && j < n) {
            System.out.println("before i val: " + i + " j val: " +j);
            // try to extend the range [i, j]
            if (!set.contains(s.charAt(j))){
                set.add(s.charAt(j++));
                ans = Math.max(ans, j - i);
            }
            else {
                set.remove(s.charAt(i++));
            }
            System.out.println("after i val: "+i + " j val: "+j );
            System.out.println(set);

        }
        return ans;
    }

    public static void main(String[] args){
        LongestSubstring l = new LongestSubstring();
        String s = "axbcdabcdabc";
        System.out.println(l.lengthOfLongestSubstring(s));
    }
}