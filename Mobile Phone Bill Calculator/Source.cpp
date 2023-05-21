#include <iostream>
using namespace std;

bool inputCheck(int& a)
{
	if (a >= 0) {
		return false;
	}
	else {
		return true;
	}
}

bool getInputs(string location, int& quantityMinutes, int& quantitySMS, int& quantityMB, int& packageForCalls, int& packageForSMS, int& packageForInternet)
{
	if (location == "Turkey") {
		cout << "Please enter how many minutes you used this month in Turkey: ";
		cin >> quantityMinutes;
		if (inputCheck(quantityMinutes)) {
			cout << "Number of minutes cannot be smaller than 0.";
			return true;
		}

		cout << "Please enter how many SMSs you sent this month in Turkey: ";
		cin >> quantitySMS;
		if (inputCheck(quantitySMS)) {
			cout << "Number of SMSs cannot be smaller than 0.";
			return true;
		}

		cout << "Please enter how many MBs you used this month in Turkey: ";
		cin >> quantityMB;
		if (inputCheck(quantityMB)) {
			cout << "Number of MBs cannot be smaller than 0.";
			return true;
		}

		cout << "Please specify how many additional packages you bought for calls, SMS and internet in this order: ";
		cin >> packageForCalls >> packageForSMS >> packageForInternet;
		if (inputCheck(packageForCalls)) {
			cout << "Number of additional minutes packages cannot be smaller than 0.";
			return true;
		}
		else {
			if (inputCheck(packageForSMS)) {
				cout << "Number of additional SMS packages cannot be smaller than 0.";
				return true;
			}
			else {
				if (inputCheck(packageForInternet)) {
					cout << "Number of additional internet packages cannot be smaller than 0.";
					return true;
				}
			}
		}
	}
	else if (location == "International") {
		cout << "Please enter how many minutes you used this month Internationally: ";
		cin >> quantityMinutes;
		if (inputCheck(quantityMinutes)) {
			cout << "Number of minutes cannot be smaller than 0.";
			return true;
		}

		cout << "Please enter how many SMSs you sent this month Internationally: ";
		cin >> quantitySMS;
		if (inputCheck(quantitySMS)) {
			cout << "Number of SMSs cannot be smaller than 0.";
			return true;
		}

		cout << "Please enter how many MBs you used this month Internationally: ";
		cin >> quantityMB;
		if (inputCheck(quantityMB)) {
			cout << "Number of MBs cannot be smaller than 0.";
			return true;
		}

		cout << "Please specify how many additional packages you bought for calls, SMS and internet in this order: ";
		cin >> packageForCalls >> packageForSMS >> packageForInternet;
		if (inputCheck(packageForCalls)) {
			cout << "Number of additional minutes packages cannot be smaller than 0.";
			return true;
		}
		else {
			if (inputCheck(packageForSMS)) {
				cout << "Number of additional SMS packages cannot be smaller than 0.";
				return true;
			}
			else {
				if (inputCheck(packageForInternet)) {
					cout << "Number of additional internet packages cannot be smaller than 0.";
					return true;
				}
			}
		}
	}

	return false;
}

double costCalculate(int& cost, int& quantityMinutes, int& quantitySMS, int& quantityMB, int& packageForCalls, int& packageForSMS, int& packageForInternet, int& priceBasePackage, int& priceAdditionalPackage, int& minutesByBasePackage, int& smsByBasePackage, int& mbByBasePackage, int& minutesByAdditionalPackage, int& smsByAdditionalPackage, int& mbByAdditionalPackage, int& callsRate, int& smsRate, int& mbRate)
{
	cost = 0;

	cost += priceBasePackage + priceAdditionalPackage * (packageForCalls + packageForSMS + packageForInternet);

	quantityMinutes -= (minutesByBasePackage + (minutesByAdditionalPackage * packageForCalls));
	if (quantityMinutes < 0) {
		quantityMinutes = 0;
	}

	quantitySMS -= (smsByBasePackage + (smsByAdditionalPackage * packageForSMS));
	if (quantitySMS < 0) {
		quantitySMS = 0;
	}

	quantityMB -= (mbByBasePackage + (mbByAdditionalPackage * packageForInternet));
	if (quantityMB < 0) {
		quantityMB = 0;
	}

	cost += (quantityMinutes * callsRate) + (quantitySMS * smsRate) + (quantityMB * mbRate * 10.24);
	return cost;
}

void displayResults(string& location, int& cost, int& priceBasePackage)
{
	if (location == "Turkey") {
		cout << "Total cost of your phone usage in Turkey is " << cost << " TL. ";

		if (cost == priceBasePackage) {
			cout << "You did not exceed your package. " << endl;
		}
		else if (cost > (priceBasePackage * 2)) {
			cout << "You exceeded your package too much. We suggest you to change your package. " << endl;
		}
		else {
			cout << "You exceeded your package. " << endl;
		}
	}
	else if (location == "International") {
		cout << "Total cost of your phone usage Internationally is " << cost << " TL. ";

		if (cost == priceBasePackage) {
			cout << "You did not exceed your package. " << endl;
		}
		else if (cost > (priceBasePackage * 2)) {
			cout << "You exceeded your package too much. We suggest you to change your package. " << endl;
		}
		else {
			cout << "You exceeded your package. " << endl;
		}
	}
}


int main()
{
	string tr = "Turkey", ir = "International";
	int quantityMinutes, quantitySMS, quantityMB, packageForCalls, packageForSMS, packageForInternet, cost;
	int priceBasePackageTR = 120, priceAdditionalPackageTR = 30, minutesByBasePackageTR = 250, smsByBasePackageTR = 1000, mbByBasePackageTR = 5120, minutesByAdditionalPackageTR = 250, smsByAdditionalPackageTR = 250, mbByAdditionalPackageTR = 1024, callsRateTR = 2, smsRateTR = 1, mbRateTR = 2;
	int priceBasePackageIR = 300, priceAdditionalPackageIR = 100, minutesByBasePackageIR = 100, smsByBasePackageIR = 200, mbByBasePackageIR = 2048, minutesByAdditionalPackageIR = 50, smsByAdditionalPackageIR = 100, mbByAdditionalPackageIR = 1024, callsRateIR = 15, smsRateIR = 3, mbRateIR = 5;
	bool inputCheck;
	//for local
	inputCheck = getInputs(tr, quantityMinutes, quantitySMS, quantityMB, packageForCalls, packageForSMS, packageForInternet);
	if (inputCheck) {
		return 0;
	}
	cost = costCalculate(cost, quantityMinutes, quantitySMS, quantityMB, packageForCalls, packageForSMS, packageForInternet, priceBasePackageTR, priceAdditionalPackageTR, minutesByBasePackageTR, smsByBasePackageTR, mbByBasePackageTR, minutesByAdditionalPackageTR, smsByAdditionalPackageTR, mbByAdditionalPackageTR, callsRateTR, smsRateTR, mbRateTR);
	displayResults(tr, cost, priceBasePackageTR);
	// for ir
	inputCheck = getInputs(ir, quantityMinutes, quantitySMS, quantityMB, packageForCalls, packageForSMS, packageForInternet);
	if (inputCheck) {
		return 0;
	}
	cost = costCalculate(cost, quantityMinutes, quantitySMS, quantityMB, packageForCalls, packageForSMS, packageForInternet, priceBasePackageIR, priceAdditionalPackageIR, minutesByBasePackageIR, smsByBasePackageIR, mbByBasePackageIR, minutesByAdditionalPackageIR, smsByAdditionalPackageIR, mbByAdditionalPackageIR, callsRateIR, smsRateIR, mbRateIR);
	displayResults(ir, cost, priceBasePackageIR);

	return 0;
}
