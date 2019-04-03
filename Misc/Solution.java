//https://code.google.com/codejam/resources/quickstart-guide#io-tutorial

import java.util.*;
import java.io.*;
class Solution {
  public void longestPalindrome(String s) {
      if (s == null || s.length() < 1) System.out.println("");
      int start = 0, end = 0;
      for (int i = 0; i < s.length(); i++) {
          int len1 = expandAroundCenter(s, i, i);
          int len2 = expandAroundCenter(s, i, i + 1);
          int len = Math.max(len1, len2);
          System.out.println("i: " + i + " i+1: " + (i+1));
          System.out.println(len1);
          System.out.println(len2);
          System.out.println(len);
          if (len > end - start) {
              start = i - (len - 1) / 2;
              System.out.println(start);
              end = i + len / 2;
              System.out.println(end);
          }
      }

      System.out.println(s.substring(start, end + 1));
  }
      
  
  private int expandAroundCenter(String s, int left, int right) {
      int L = left, R = right;
      while (L >= 0 && R < s.length() && s.charAt(L) == s.charAt(R)) {
          L--;
          R++;
      }
      return R - L - 1;
  }

  public static void main(String[] args){
    Solution s1 = new Solution();
    s1.longestPalindrome("abba");
  }
  }