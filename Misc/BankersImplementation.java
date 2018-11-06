class BankersImplementation{

    public static int P = 5;
    public static int R = 3;
    public static int max[][] = new int[][R]; {}
     public static void main(String[] args) {
        int processes[] = {0, 1, 2, 3, 4}; 
  
    // Available instances of resources 
    int avail[] = {3, 3, 2}; 
  
    // Maximum R that can be allocated 
    // to processes 
    int maxm[][] = new int[][R] {{7, 5, 3}, 
                                {3, 2, 2}, 
                     {9, 0, 2}, 
                     {2, 2, 2}, 
                     {4, 3, 3}}; 
  
    // Resources allocated to processes 
    int allot[][] = new int[][R]{{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}}; 
    }
}