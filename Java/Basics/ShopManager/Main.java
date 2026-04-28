import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Shop s = new Shop();
		Scanner sc = new Scanner(System.in);
		System.out.print("Which product you like to buy? : ");
		s.productNameSetter(sc.nextLine());
		try{
			System.out.print("What is the price of that product? : ");
			s.productPriceSetter(sc.nextDouble());
			System.out.print("How many products you want to buy? : ");
			s.productQuantitySetter(sc.nextInt());
		}
		catch(Exception e){
			System.out.println("Product price or quantity can not be string !!");
			System.exit(1);
		}

		s.output();
		sc.close();
	}
}
