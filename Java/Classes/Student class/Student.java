public class Student{
        String name;
        int roll;
        String[] subjects;
        University university;
        int[] marks;
        public String study(String subject){
                return "Studying "+subject+"......";
        }
        public String goUniv(){
                return "Going "+university.name;
        }
        public String getName(){
                return name;
        }
        public void setName(String name){
                this.name = name;
        }
        public String callName(Student s2){
                return s2.getName();
        }
        public void getStudent(Student s2){
                
        }
}