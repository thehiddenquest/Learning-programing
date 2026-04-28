public class Shop{
	private String productName;
	private double productPrice;
	private int productQuantity;

	public Shop(){
		productName = "";
		productPrice = 0;
		productQuantity = 0;

	}
	public void output(){
		if(inputValidator()){
			System.out.println("\nYou have ordered "+productQuantity+" "+productName+"/s");
			System.out.println("Your total is Rs."+calculateTotal());
		}
	}
	private double calculateTotal(){
		return productPrice*productQuantity;
	}
	public void productNameSetter(String productName){
		this.productName = productName;
	}
	public void productPriceSetter(double productPrice){
		this.productPrice = productPrice;
	}
	public void productQuantitySetter(int productQuantity){
		this.productQuantity = productQuantity;
	}
	private Boolean inputValidator(){

		if(productName == null || productName.isEmpty()){
			System.out.println("Please enter a valid product name.");
			return false;
		}
		if(productPrice <0){
			System.out.println("Product price cannot be 0 or less.");
			return false;
		}
		if(productQuantity <0){
			System.out.println("Product quantity cannot be 0 or less.");
			return false;
		}
		return true;
	}
}

