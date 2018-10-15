// Java program to perform 3 way Merge Sort 
public class MergeSort3Way 
{ 
    public static void printArray(Integer[] arr){
        System.out.println(java.util.Arrays.toString(arr));
        }
    
    // Function  for 3-way merge sort process 
    public static void mergeSort3Way(Integer[] gArray) 
    { 
        // if array of size is zero returns null 
        if (gArray == null) 
            return; 
  
        // creating duplicate of given array 
        Integer[] fArray = new Integer[gArray.length]; 
  
        // copying alements of given array into 
        // duplicate array 
        for (int i = 0; i < fArray.length; i++) 
            fArray[i] = gArray[i]; 
  
        // sort function 
        mergeSort3WayRec(fArray, 0, gArray.length, gArray); 
  
        // copy back elements of duplicate array 
        // to given array 
        for (int i = 0; i < fArray.length; i++) 
            gArray[i] = fArray[i]; 
    } 
  
    /* Performing the merge sort algorithm on the 
       given array of values in the rangeof indices 
       [low, high).  low is minimum index, high is 
       maximum index (exclusive) */
    public static void mergeSort3WayRec(Integer[] gArray, int low, int high, Integer[] destArray) 
    { 
        // If array size is 1 then do nothing 
        if (high - low < 2) 
            return; 
  
        // Splitting array into 3 parts 
        int mid1 = low + ((high - low) / 3); 
        int mid2 = low + 2 * ((high - low) / 3) + 1; 
        System.out.println("low: "+ low +" Mid1: " + mid1 + " Mid2: " +mid2+ " high: "+ high);
  
        // Sorting 3 arrays recursively 
        mergeSort3WayRec(destArray, low, mid1, gArray); 
        mergeSort3WayRec(destArray, mid1, mid2, gArray); 
        mergeSort3WayRec(destArray, mid2, high, gArray); 
  
        // Merging the sorted arrays 
        merge(destArray, low, mid1, mid2, high, gArray); 
    } 
  
    /* Merge the sorted ranges [low, mid1), [mid1, 
       mid2) and [mid2, high) mid1 is first midpoint 
       index in overall range to merge mid2 is second 
       midpoint index in overall range to merge*/
    public static void merge(Integer[] gArray, int low, 
                           int mid1, int mid2, int high, 
                                   Integer[] destArray) 
    { 
        int i = low, j = mid1, k = mid2, l = low; 
  
        // choose smaller of the smallest in the three ranges 
        while ((i < mid1) && (j < mid2) && (k < high)) 
        { 
            if (gArray[i].compareTo(gArray[j]) < 0) 
            { 
                if (gArray[i].compareTo(gArray[k]) < 0) 
                    destArray[l++] = gArray[i++]; 
  
                else
                    destArray[l++] = gArray[k++]; 
            } 
            else
            { 
                if (gArray[j].compareTo(gArray[k]) < 0) 
                    destArray[l++] = gArray[j++]; 
                else
                    destArray[l++] = gArray[k++]; 
            } 
        } 
  
        // case where first and second ranges have 
        // remaining values 
        while ((i < mid1) && (j < mid2)) 
        {   
            if (gArray[i].compareTo(gArray[j]) < 0) 
                destArray[l++] = gArray[i++]; 
            else
                destArray[l++] = gArray[j++];
            printArray(destArray);  
        } 
  
        // case where second and third ranges have 
        // remaining values 
        while ((j < mid2) && (k < high)) 
        {    
            if (gArray[j].compareTo(gArray[k]) < 0) 
                destArray[l++] = gArray[j++]; 
  
            else
                destArray[l++] = gArray[k++];  
        } 
  
        // case where first and third ranges have 
        // remaining values 
        while ((i < mid1) && (k < high)) 
        { 
            if (gArray[i].compareTo(gArray[k]) < 0) 
                destArray[l++] = gArray[i++]; 
            else
                destArray[l++] = gArray[k++]; 
            printArray(destArray);  
        } 
  
        // copy remaining values from the first range 
        while (i < mid1) 
            destArray[l++] = gArray[i++]; 
  
        // copy remaining values from the second range 
        while (j < mid2) 
            destArray[l++] = gArray[j++]; 
  
        // copy remaining values from the third range 
        while (k < high) 
            destArray[l++] = gArray[k++]; 
    } 
  
    // Driver function 
    public static void main(String args[]) 
    { 
        // test case of values 
        //Integer[] data = new Integer[] {9,8,7,6,5,4}; 
        Integer[] data = new Integer[] {3,2,1};
        mergeSort3Way(data); 
  
        System.out.println("After 3 way merge sort: "); 
        for (int i = 0; i < data.length; i++) 
            System.out.print(data[i] + " "); 
    } 
} 