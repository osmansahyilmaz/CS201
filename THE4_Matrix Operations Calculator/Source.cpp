#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

void displayMenu();
void getOperationChoice(int& operationChoice);
void getDimensionsChoice(int& operationChoice, int& row1, int& column1, int& row2, int& column2);
void checkDimensions(int& operationChoice, int& row1, int& column1, int& row2, int& column2, bool& operationCheck);
void getNumbers1(int& operationsChoice, vector<vector<int> >& matrix1, int& row1, int& column1);
void getNumbers2(int& operationsChoice, vector<vector<int> >& matrix2, int& row2, int& column2);
void operationRouter1(int& operationChoice, vector<vector<int> >& matrix1, vector<vector<int>>& matrix2);
void operationRouter2(int& operationChoice, vector<vector<int> >& matrix1);
void operationAddition(vector<vector<int> >& matrix1, vector<vector<int>>& matrix2);
void operationMultiplication(vector<vector<int> >& matrix1, vector<vector<int>>& matrix2);
void operationPower(vector<vector<int> >& matrix1);
void operationTranspose(vector<vector<int> >& matrix1);

int main() {
	int operationChoice, row1, column1, row2, column2;
	bool operationCheck = true;

	while (true) {
		operationCheck = true;
		displayMenu();
		getOperationChoice(operationChoice);
		if (operationChoice == 5) {
			break;
		}

		getDimensionsChoice(operationChoice, row1, column1, row2, column2);

		checkDimensions(operationChoice, row1, column1, row2, column2, operationCheck);

		if (operationCheck) {

			vector<vector<int> > matrix1(row1);
			getNumbers1(operationChoice, matrix1, row1, column1);

			if (operationChoice == 1 || operationChoice == 2) {
				vector<vector<int>> matrix2(row2);
				getNumbers2(operationChoice, matrix2, row2, column2);
				operationRouter1(operationChoice, matrix1, matrix2);
			}
			
			else if (operationChoice == 3 || operationChoice == 4) {
				operationRouter2(operationChoice, matrix1);
			}
		}

	}


	return 0;
}

void displayMenu() {
	cout << "Pick a choice from the list:" << endl;
	cout << "1- Addition Operation" << endl;
	cout << "2- Multiplication Operation" << endl;
	cout << "3- Power Operation" << endl;
	cout << "4- Transpose Operation" << endl;
	cout << "5- Exit" << endl;
	cout << "Choice: ";
}

void getOperationChoice(int& operationChoice) {
	
	cin >> operationChoice;
	cout << endl;
}

void getDimensionsChoice(int& operationChoice, int& row1, int& column1, int& row2, int& column2) {


	if (operationChoice == 1 || operationChoice == 2) {
		cout << "Please enter the dimensions of the first matrix: ";
		cin >> row1 >> column1;
		while (!cin) {
			cout << "Please enter the dimensions of the first matrix: ";
			cin >> row1 >> column1;

		}
		cout << "Please enter the dimensions of the second matrix: ";
		cin >> row2 >> column2;
		while (!cin) {
			cout << "Please enter the dimensions of the second matrix: ";
			cin >> row2 >> column2;

		}
	}
	else {
		cout << "Please enter the dimensions of the matrix: ";
		cin >> row1 >> column1;
		while (!cin) {
			cout << "Please enter the dimensions of the matrix: ";
			cin >> row1 >> column1;

		}
	}
}

void checkDimensions(int& operationChoice, int& row1, int& column1, int& row2, int& column2, bool& operationCheck) {
	if (operationChoice == 1 && !(row1 == row2 && column1 == column2)) {
		cout << "The two matrices do not have the same dimensions. Addition cannot be performed." << endl;
		row1 = 0;
		column1 = 0;
		row2 = 0;
		column2 = 0;
		operationCheck = false;
	}
	else if (operationChoice == 1) {
		cout << "The two matrices have the same dimensions. Addition can be performed." << endl << endl;
	}

	if (operationChoice == 2 && !(column1 == row2)) {
		cout << "The number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
		cout << "Multiplication cannot be performed." << endl;
		row1 = 0;
		column1 = 0;
		row2 = 0;
		column2 = 0;
		operationCheck = false;
	}
	else if (operationChoice == 2) {
		cout << "The number of columns in the first matrix is equal to the number of rows in the second matrix. Multiplication can be performed. " << endl;

	}

	if (operationChoice == 3 && !(row1 == column1)) {
		cout << "The matrix does not have the same number of rows as columns. Power cannot be performed." << endl << endl;
		row1 = 0;
		column1 = 0;
		row2 = 0;
		column2 = 0;
		operationCheck = false;
	}
	else if (operationChoice == 3) {
		cout << "The matrix has the same number of rows as columns. Power can be performed." << endl << endl;


	}
}

void getNumbers1(int& operationChoice, vector<vector<int> >& matrix1, int& row1, int& column1) {
	double input1;
	int intInput1;
	if (operationChoice == 1 || operationChoice == 2) {
		cout << "Please enter the numbers for the first matrix." << endl;
		for (int i = 0; i < row1; i++) {
			cout << "Enter the numbers for row #" << i + 1 << ": ";
			for (int k = 0; k < column1; k++) {
				while (true) {
					cin >> input1;
					intInput1 = input1;
					if (!cin || intInput1 != input1) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else {
						break;
					}

				}
				matrix1[i].push_back(input1);
			}
		}
		cout << "The first matrix is:" << endl;
		for (int i = 0; i < row1; i++) {
			for (int k = 0; k < column1; k++) {
				cout << matrix1[i][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else if (operationChoice == 3 || operationChoice == 4) {
		cout << "Please enter the numbers for the matrix." << endl;
		for (int i = 0; i < row1; i++) {
			cout << "Enter the numbers for row #" << i + 1 << ": ";
			for (int k = 0; k < column1; k++) {
				while (true) {
					cin >> input1;
					intInput1 = input1;
					if (!cin || intInput1 != input1) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					else {
						break;
					}

				}
				matrix1[i].push_back(input1);
			}
		}
		cout << "The matrix is:" << endl;
		for (int i = 0; i < row1; i++) {
			for (int k = 0; k < column1; k++) {
				cout << matrix1[i][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}


void getNumbers2(int& operationsChoice, vector<vector<int> >& matrix2, int& row2, int& column2) {
	double input2;
	int intInput2;
	cout << "Please enter the numbers for the second matrix." << endl;
	for (int i = 0; i < row2; i++) {
		cout << "Enter the numbers for row #" << i + 1 << ": ";
		for (int k = 0; k < column2; k++) {
			while (true) {
				cin >> input2;
				intInput2= input2;
				if (!cin || intInput2 != input2) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else {
					break;
				}

			}
			matrix2[i].push_back(input2);
		}
	}
	cout << "The second matrix is:" << endl;
	for (int i = 0; i < row2; i++) {
		for (int k = 0; k < column2; k++) {
			cout << matrix2[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void operationRouter1(int& operationChoice, vector<vector<int> >& matrix1, vector<vector<int>>& matrix2) {
	if (operationChoice == 1) {
		operationAddition(matrix1, matrix2);
	}
	else {
		operationMultiplication(matrix1, matrix2);
	}
}

void operationRouter2(int& operationChoice, vector<vector<int> >& matrix1) {
	if (operationChoice == 3) {
		operationPower(matrix1);
	}
	else {
		operationTranspose(matrix1);
	}
}

void operationAddition(vector<vector<int> >& matrix1, vector<vector<int>>& matrix2) {
	for (int i = 0; i < matrix1.size(); i++) {
		for (int k = 0; k < matrix1[0].size(); k++) {
			matrix1[i][k] += matrix2[i][k];
		}
	}

	cout << "Result of the Sum Operation:" << endl;
	for (int i = 0; i < matrix1.size(); i++) {
		for (int k = 0; k < matrix1[0].size(); k++) {
			cout << matrix1[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void operationMultiplication(vector<vector<int> >& matrix1, vector<vector<int>>& matrix2) {
	vector<vector<int>> matrixFinal(matrix1.size(), vector<int>(matrix2[0].size(), 0));

	for (int i = 0; i < matrix1.size(); i++) {
		for (int k = 0; k < matrix2[0].size(); k++) {
			for (int j = 0; j < matrix1[0].size(); j++) {
				matrixFinal[i][k] += matrix1[i][j] * matrix2[j][k];
			}
		}
	}


	cout << "Result of the Multiplication Operation:" << endl;
	for (int i = 0; i < matrixFinal.size(); i++) {
		for (int k = 0; k < matrixFinal[0].size(); k++) {
			cout << matrixFinal[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void operationPower(vector<vector<int> >& matrix1) {
	double power = 0, n = 1;
	int intPower;
	cout << "Please enter the power: ";

	while (true) {
		cin >> power;
		intPower = power;
		if (!cin || power < 1 || intPower != power) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			break;
		}

	}

	vector<vector<int>> matrixFinal(matrix1.size(), vector<int>(matrix1[0].size(), 0));
	vector<vector<int>> matrixFinal2(matrix1.size(), vector<int>(matrix1[0].size(), 0));
	vector<vector<int>> matrix2 = matrix1;

	while (n < power) {
		matrixFinal = matrixFinal2;

		for (int i = 0; i < matrix2.size(); i++) {
			for (int k = 0; k < matrix1[0].size(); k++) {
				for (int j = 0; j < matrix2[0].size(); j++) {
					matrixFinal[i][k] += matrix2[i][j] * matrix1[j][k];
				}
			}
		}
		n++;
		matrix2 = matrixFinal;
	}

	if (power == 1) {
		matrixFinal = matrix1;
	}

	cout << "Result of the Power Operation: " << endl;
	for (int i = 0; i < matrixFinal.size(); i++) {
		for (int k = 0; k < matrixFinal[0].size(); k++) {
			cout << matrixFinal[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void operationTranspose(vector<vector<int> >& matrix1) {
	vector<vector<int>> matrixFinal(matrix1[0].size(), vector<int>(matrix1.size(), 0));

	for (int i = 0; i < matrix1.size(); i++) {
		for (int k = 0; k < matrix1[0].size(); k++) {
			matrixFinal[k][i] = matrix1[i][k];
		}
	}

	cout << "Result of the Transpose Operation: " << endl;
	for (int i = 0; i < matrixFinal.size(); i++) {
		for (int k = 0; k < matrixFinal[0].size(); k++) {
			cout << matrixFinal[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
