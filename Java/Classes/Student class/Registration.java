public class Registration {
        public static void main(String args[]){
                University univ = new University("calcutta university","saltlake");
                Student s1 = new Student();
                s1.setName("Anuska");
                s1.roll = 28;
                s1.university = univ;
                System.out.println(s1.goUniv());
                System.out.println(s1.university.address); 
                System.out.println(s1.study("SE")); 
                Student s2 = new Student();
                s2.setName("Rahul");
                s2.roll = 16;
                s2.university = univ;
                System.out.println(s1.getName());
                System.out.println(s2.callName(s1));

        }
}
