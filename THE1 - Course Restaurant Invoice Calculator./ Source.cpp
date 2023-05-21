#include <iostream>
using namespace std;
int main() {
	int orderedWater = 0, orderedSoda = 0, orderedFries = 0, orderedHamburger = 0, s = 0, c = 0, priceWater = 10, priceSoda = 30, priceHamburger = 100;
	double priceFries = 59.5, subTotal = 0, totalPrice = 0, vat = 0, studentDiscount = 0, serviceFee = 0;

	//taking inputs
	cout << "Enter the quantity of each product you have ordered: " << endl;
	cout << "Water: ";
	cin >> orderedWater;
	cout << "Soda: ";
	cin >> orderedSoda;
	cout << "Fries: ";
	cin >> orderedFries;
	cout << "Hamburger: ";
	cin >> orderedHamburger;

	// asking cheese if yes updating hamburger's money
	if (orderedHamburger) {
		cout << "Add cheese to your hamburger(s)? (1 for yes, 0 for no): ";
		cin >> c;
	}
	if (c) {
		priceHamburger = 111;
	}

	// asking student if yes discount apply
	cout << "Are you a student? (1 for yes, 0 for no): ";
	cin >> s;
	if (s) {
		cout << "Student discount applied!";
	}

	// interface starting
	cout << endl;
	cout << "===================================" << endl;
	cout << "         Restaurant Invoice        " << endl;
	cout << "===================================" << endl;

	// if/else   no order
	if (orderedWater == 0 && orderedSoda == 0 && orderedFries == 0 && orderedHamburger == 0) {
		cout << "The customer has not made a purchase or placed an order!";
	}

	else {

		//seperately output orders if they exist
		if (orderedWater) {
			cout << "Water (" << orderedWater << "): " << orderedWater * priceWater << " TL" << endl;
		}
		if (orderedSoda) {
			cout << "Soda (" << orderedSoda << "): " << orderedSoda * priceSoda << " TL" << endl;
		}
		if (orderedFries) {
			cout << "Fries (" << orderedFries << "): " << orderedFries * priceFries << " TL" << endl;
		}
		if (orderedHamburger) {
			cout << "Hamburgers (" << orderedHamburger << "): " << orderedHamburger * priceHamburger << " TL" << endl;
		}

		//subtotal and vat calculating, and vat output
		subTotal = orderedWater * priceWater + orderedSoda * priceSoda + orderedFries * priceFries + orderedHamburger * priceHamburger;
		vat = (orderedSoda * priceSoda * 0.5) + (orderedFries * priceFries + orderedHamburger * priceHamburger) * 0.1;
		cout << "Subtotal: " << subTotal << " TL" << endl << endl;
		subTotal += vat;
		cout << "VAT: " << vat << " TL" << endl;

		//if student yes, discount calculating and subtotal updating
		if (s) {
			studentDiscount -= subTotal * 0.25;
			cout << "Student discount: " << studentDiscount << " TL" << endl;
			subTotal += studentDiscount;
		}

		//calculating service fee
		if (subTotal < 175) {
			serviceFee = (subTotal) * 0.1;
		}
		else if (subTotal < 375) {
			serviceFee = (subTotal) * 0.08;
		}
		else {
			serviceFee = (subTotal) * 0.06;
		}

		// output service fee and total price
		cout << "Service fee: " << serviceFee << " TL" << endl;
		subTotal += studentDiscount;
		totalPrice = subTotal + serviceFee - studentDiscount;
		cout << "Total price: " << totalPrice << " TL";
	}
	return 0;
}
