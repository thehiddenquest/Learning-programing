package Stack;
public class Stack {
        private int stck[];
        private int tpos = -1;
        private int capacity;
        public Stack(){
                stck = new int[10];
                this.capacity=10;
        }
        public Stack(int n){
                stck = new int[n];
                this.capacity = n;
        }

        public void push(int data){
                if(tpos == capacity){
                     System.out.println("error :: Stack overflow");
                }
                stck[++tpos] = data;
                System.out.println("inserted :: "+data); 
        }
        public int pop(){
                if(tpos < 0){
                        System.out.println( "error :: Stack underflow");
                        return -99999;
                }else{
                        int data = stck[tpos--];
                        return data;
                }

        }
        public void peek(){
                System.out.println("Top element :: "+stck[tpos]);
        }

        @Override
        public String toString() {
                String result = "Stack: ";
                for (int i = 0; i <= tpos; i++) {
                        result += stck[i] + " ";
                }
                return result;
        }

        public void remainingCapacity(){
                System.out.println("Remaining capacity :: "+(capacity-(tpos+1)));
        }

}
