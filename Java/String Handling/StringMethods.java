public class StringMethods {
        public static void main(String[] args) {
                String s1 = new String("Hello world");
                System.out.println("The length of String is "+s1.length());

        ////--------------- Character Extraction ------------------
                
                // charAt :: Get a character from specific index
                System.out.println("Character at index 0 is : " + s1.charAt(0));

                // getChars :: Get a part of string to a character buffer 
                int start = 0;
                int end = 5;
                char[] buffer = new char[end - start];
                char[] buffer1 = {'R','a','h','u','l',' ','B','i','s','w','a','s'};
                s1.getChars(start,end,buffer,0);
                s1.getChars(start,end+1,buffer1,6);
                System.out.println(buffer1);
                System.out.println(buffer);


        ////---------------String Comparison------------------

                // equals and equalsIgnoreCase :: matches character of two string
                String s2 = new String("Hello");
                String s3 = new String("HELLO");

                System.out.println(s2.equals(s3));
                System.out.println(s2.equalsIgnoreCase(s3));
                
                // regionMatches : Match specific region of two strings

                System.out.println("region matches example 1: "+
                                s1.regionMatches(0,s2,0,5));
                System.out.println("region matches example 2: "+
                                s1.regionMatches(true,0,s3,0,5));

                // startsWith or endsWith :: specialized form of region matches

                System.out.println("Starts with example 1: "+s1.startsWith(s2));
                System.out.println("Starts with example 2: "+s1.startsWith(s3));

                System.out.println("Ends with example 1: "+s1.endsWith("World"));
                System.out.println("Ends with example 2: "+s1.endsWith("world"));

                // equals vs ==  :: equals matches the content but == matches the object reference 

                String s4 = "Hi";
                String s5 = new String(s4);
                String s6 = s4;
                String s7 = "Hi";

                System.out.println("is s4 equals s5? : " + s4.equals(s5));
                System.out.println("is s4 == s5? : "+ (s4 == s5));
                
                System.out.println("is s4 equals s6? : " + s4.equals(s6));
                System.out.println("is s4 == s6? : "+ (s4 == s6));

                System.out.println("is s4 equals s7? : " + s4.equals(s7));
                System.out.println("is s4 == s7? : "+ (s4 == s7));
                
        ////---------------String Searching------------------

                String s8 = "In this world , the world is too big to fit in the world";
                // indexOf : returns index of a character or string (only the first occurance)
                        
                System.out.println("Index of H in s1 is: "+s1.indexOf("H"));
                System.out.println("Index of world in s1 is: "+s1.indexOf("world"));
                System.out.println("The index of 2nd 'world' in s7 is : "+s8.indexOf("world",9));
                
                // lastIndexOf : returns index of a character or string (only the first occurance)
                        
                System.out.println("The index of last 'world' in s7 is : "+s8.lastIndexOf("world"));
                System.out.println("The index of before last 'world' in s7 is : "+s8.lastIndexOf("world", 50)); 

        }
        

}
