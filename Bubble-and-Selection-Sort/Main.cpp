// Bubble Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{

	int listsize;
	int selection;
	int temp;
	int counter = 0;

	time_t t;
	time(&t);

	srand((unsigned int)t);

	vector < int > list;

	cout << "Enter size of list " << endl;
	cin >> listsize;

	for (int i = 0; i < listsize; i++){
		list.push_back(rand() % 1000);

	}
	for (int i = 0; i < list.size(); i++){
		cout << list[i] << " " << endl;

	}

	cout << "Please select sorting method:" << endl;
	cout << "-1- Bubble Sort" << endl;
	cout << "-2- Selection Sort" << endl;
	cin >> selection;
	if (selection == 1)
	{
		//bubbleSort

		bool flagFinished = false;

		for (int i = 0; (i < (list.size() - 1)) && (flagFinished == false); i++){
			for (int j = 0; j < list.size() - i - 1; j++){
				flagFinished = true;
				if (list[j + 1] < list[j])
				{
					temp = list[j];
					list[j] = list[j + 1];
					list[j + 1] = temp;
					counter++;
					flagFinished = false;
					cout << "Test2" << endl;
				}

			}

		}

	}
	else
	{
		//selectionSort
		for (int i = 0; i < list.size() - 1; i++){
			for (int j = i; j < list.size(); j++){

				int temploc = i;

				if (list[j]<list[i])
				{
					temploc = j;
				}
				if (temploc != i)
				{
					temp = list[i];
					list[i] = list[temploc];
					list[temploc] = temp;
					counter++;
				}
			}

		}


	}
	for (int i = 0; i < list.size(); i++){
		cout << list[i] << " " << endl;

	}
	cout << "Runs: " << counter << endl;

	system("PAUSE");


	return 0;
}
