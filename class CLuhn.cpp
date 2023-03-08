/**  @Author Eloide Novela on 23/01/31.  **/
 
#include <iostream>

using namespace std;

class CLuhn{
public:
	
	CLuhn();
	~CLuhn();
	void setCardNumber(long long int card_number){ this->card_number = card_number; }
	string typeCard();	

protected:
	// This method can be used in a class hierarchy, so I left it protected.
	
	bool luhnCheck();
		
private:
	int digits_quantity;
	long long int card_number;
	
};

CLuhn::CLuhn(){
	
	this->card_number = 0;
	this->digits_quantity = 0;
	
}

CLuhn::~CLuhn(){}

string CLuhn::typeCard(){
	
	short int counter = 0; 
	long long int start_digits = 0, card_number = this->card_number;
	
	
	if(luhnCheck()){
		
		while(counter < (digits_quantity - 2)){
		
		
			start_digits = card_number / 10;
			card_number = start_digits;
		
			counter++;
		}
		
		if(((digits_quantity == 16) || (digits_quantity == 13)) && (start_digits >= 40 && start_digits <=49)){
			
			return "VISA";
			
		}else if((digits_quantity == 16) && (start_digits >= 51 && start_digits <= 55)){
			
			return "MASTERCARD";
			
		}else if((digits_quantity == 15) && (start_digits == 34 || start_digits == 37)){
			
			return "AMEX";
			
		}
			
	}

	return "INVALId CARD";

}

bool CLuhn::luhnCheck(){
	
	// This is Luhn's check-> if the check is successful, the method returns true.
	
	short int right_digits = 0, counter = 0, left_digits = 0, right_numbers = 0, leftAndRightSum = 0;
	
	long long int card_number = this->card_number;
	this->digits_quantity = 0; // if you invoke the method a second time.
	
	while(card_number != 0){
		
		digits_quantity++;
		counter++;
		
		if(counter % 2 != 0){
			
			left_digits+= card_number % 10;
			
		}else{
		
			right_numbers = card_number % 10;
			right_numbers = right_numbers * 2;
			
			while(right_numbers != 0){
				
				right_digits+= right_numbers % 10;
				
				right_numbers = right_numbers / 10;
			}
				
		}
		
		card_number = card_number / 10;
	}
	
	leftAndRightSum = left_digits + right_digits;
	
	if(leftAndRightSum % 10 == 0){
		
		return true;
		
	}
	
	return false;
	
}

int main(){
	
	long long int card_number;
	CLuhn object;
	
	cout << "Enter an Card Number: ";
	cin >> card_number;
	
	object.setCardNumber(card_number);
	cout << object.typeCard() << endl;
	
	return 0;
}