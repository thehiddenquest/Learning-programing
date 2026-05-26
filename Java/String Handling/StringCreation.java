// where string is stored? 
// What is string pool? 
public class StringCreation{
        public static void main(String args[]){
        // using "new" keyword : creates an object reference in heap memory
                String s1 = new String("Hello");
                System.out.println(s1);
                char[] c = {'H','e','l','l','o'};
                String s2 = new String(c);
                System.out.println(s2);
                String s3 = new String(s2);
                System.out.println(s3);
                char[] c2 ={'H','e','l','l','o',' ','w','o','r','l','d'};
                String s4 = new String(c2,0,5);
                System.out.println(s4);
                byte[] ascii = {104,101,108,108,111};
                String s5 = new String(ascii);
                System.out.println(s5);
                String s6 = "Hello";
                System.out.println(s6);

        }
}
