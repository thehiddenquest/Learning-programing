package Stack;
public class Main {
        public static void main(String[] args) {
            Stack st = new Stack(20);
            st.push(1);
            st.push(2);
            int d = st.pop();
            System.out.println(d+ " is popped");
            st.peek();
            st.push(99);
            System.out.println(st);
            st.remainingCapacity();
        }
}
