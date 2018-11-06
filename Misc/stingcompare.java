class stingcompare{

    public static void compareString(String s1, String s2){
        String []s1p = s1.split("\\s+");
        String []s2p = s2.split("\\s+");
        for(int i =0;i<s1.length();){
            for(int j =0;j<s2.length(); ){
                if(s1p[i]==s2p[j]){
                    System.out.println(s1p[i]);
                    i++;
                    j++;
                }
                else{
                    System.out.println(s1p[i]);
                    i++;
                    j++;
                }
            }
        }
    }
     public static void main(String[] args) {
         String s1 = "I am Anvesh I live in california";
         String s2 = " Anvesh I in";
         compareString(s1,s2);
    }
}