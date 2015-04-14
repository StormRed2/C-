// Matrix_and_Search_Algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

/* == 1. Aufgabe ==
*
* 1)Einlesen von Punkten
*  Ausgeben
*
* 2) Transformation (Translation, Rotation, Skalierung)
*
* 3) Werte eingeben
*
* 4) Matrix ausgeben
*
* 5) Punkte transformieren
*
* 6) Ausgeben
*
* Optional:
*
* 7) Neue Punkte / Neue Transformation / Weitere Transformation
*
*/

/* == 2. Aufgabe ==
*
* 1) Sortieren mit Bubble Sort
* 2) Sortieren mit Selection Sort
*
*
*
*
*
*/

void printVector(vector<double>& inputMatrix){

	// Prints out the passed vector

	cout << "Eingegebener Vektor:" << endl;
	for (int i = 0; i<3; i++){
		cout << inputMatrix[i] << " ";
	}
	cout << endl;
}

vector<double> multiplyVectors(vector<double>& aMatrix, vector<vector<double>>& bMatrix){

	// Multiplies two matrixes

	vector<double> tempMatrix(aMatrix);

	for (int i = 0; i<3; i++){
		aMatrix[i] = 0;
		for (int j = 0; j<3; j++){
			aMatrix[i] += tempMatrix[j] * bMatrix[j][i];
		}
	}

	return aMatrix;
}

vector<vector<double>> multiplyVectors(vector<vector<double>>& aMatrix, vector<vector<double>>& bMatrix){

	// Multiplies two matrixes

	vector<vector<double>> tempMatrix(aMatrix);

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			aMatrix[i][j] = 0;
			for (int k = 0; k < 3; k++){
				aMatrix[i][j] += bMatrix[i][k] * tempMatrix[k][j];
			}
		}
	}

	return aMatrix;
}


vector<double> skaVector(vector<double>& inputMatrix){

	double temp1, temp2;
	vector< vector<double>> transMatrix;


	transMatrix.resize(3);

	// Initialize multidimensional array
	for (int i = 0; i < 3; i++){
		transMatrix[i].resize(3);
	}

	// Move by this points
	cout << "Um folgende zwei Werte skalieren:" << endl;
	cout << "Wert 1: ";
	cin >> temp1;
	cout << "Wert 2: ";
	cin >> temp2;

	// Create the transversion matrix devending on the values
	transMatrix[0][0] = temp1;
	transMatrix[0][1] = 0.0;
	transMatrix[0][2] = 0.0;
	transMatrix[1][0] = 0.0;
	transMatrix[1][1] = temp2;
	transMatrix[1][2] = 0.0;
	transMatrix[2][0] = 0.0;
	transMatrix[2][1] = 0.0;
	transMatrix[2][2] = 1.0;

	multiplyVectors(inputMatrix, transMatrix);
	printVector(inputMatrix);


	return inputMatrix;
}

vector<double> rotVector(vector<double>& inputMatrix){

	const double PI = 3.14159265359;
	
	vector< vector<double>> transMatrix;

	transMatrix.resize(3);

	// Initialize multidimensional array
	for (int i = 0; i < 3; i++){
		transMatrix[i].resize(3);
	}

	cout << "Bitte Drehwinkel angeben: ";
	double angle;
	cin >> angle;

	// Create the rotation matrix devending on the values
	transMatrix[0][0] = cos(angle / 360 * 2 * PI);
	transMatrix[0][1] = sin(angle / 360 * 2 * PI);
	transMatrix[0][2] = 0.0;
	transMatrix[1][0] = -sin(angle / 360 * 2 * PI);
	transMatrix[1][1] = cos(angle / 360 * 2 * PI);
	transMatrix[1][2] = 0.0;
	transMatrix[2][0] = 0.0;
	transMatrix[2][1] = 0.0;
	transMatrix[2][2] = 1.0;

	multiplyVectors(inputMatrix, transMatrix);
	
	return inputMatrix;
}

vector<double> transVector(vector<double>& inputMatrix){

	double temp1, temp2;
	vector< vector<double>> transMatrix;


	transMatrix.resize(3);

	// Initialize multidimensional array
	for (int i = 0; i < 3; i++){
		transMatrix[i].resize(3);
	}

	// Move by this points
	cout << "Um folgende zwei Werte verschieben:" << endl;
	cout << "Wert 1: ";
	cin >> temp1;
	cout << "Wert 2: ";
	cin >> temp2;

	// Create the transversion matrix devending on the values
	transMatrix[0][0] = 1.0;
	transMatrix[0][1] = 0.0;
	transMatrix[0][2] = 0.0;
	transMatrix[1][0] = 0.0;
	transMatrix[1][1] = 1.0;
	transMatrix[1][2] = 0.0;
	transMatrix[2][0] = temp1;
	transMatrix[2][1] = temp2;
	transMatrix[2][2] = 1.0;

	multiplyVectors(inputMatrix, transMatrix);
	printVector(inputMatrix);

	return inputMatrix;
}

vector<double> readVector(vector<double>& inputMatrix){

	// Reads the user input and saves the values in the given vector

	double temp;

	cout << "Hallo, bitte Matrix eingeben!" << endl;

	for (int i = 0; i<2; i++){
		cout << i + 1 << ". Zahl eingeben: ";
		cin >> temp;
		inputMatrix[i] = temp;
	}
	inputMatrix[2] = 1;

	return inputMatrix;
}


int _tmain(int argc, _TCHAR* argv[]){

	// Matrix to save the user vector
	vector<double> inputMatrix;
	inputMatrix.resize(3);

	// Flag to know if keep running
	bool flagRun = true;

	while (flagRun){

		// Call all the functions
		readVector(inputMatrix);
		printVector(inputMatrix);
		transVector(inputMatrix);
		rotVector(inputMatrix);
		printVector(inputMatrix);
		skaVector(inputMatrix);
		printVector(inputMatrix);

		// Ask if the user wants to calculate again
		cout << "Weiteren Vektor berechnen? (y/n)" << endl;
		string temp;
		cin >> temp;
		if (temp == "n"){
			flagRun = false;
		}
	}

	return 0;
}

