// WinterSemester2022-2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//playing with tables 

#include <iostream>
using namespace std; 


int const offset = 5;

void arr_delete(int* arr) {
	delete[] arr;
	arr = NULL;
	cout << "memory deallocated successfully" << endl;
}

void v_alloc_table_add_5(int iSize) {
	if (iSize <= 0) {
		return;
	}
	else {
		int* arr = new int[iSize];
		arr = new (nothrow) int[iSize];
		for (int i = 0; i < iSize; i++) {
			arr[i] = i + offset;
		}
		cout << "Array of given size : " << endl;
		for (int i = 0; i < iSize; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
		arr_delete(arr);
	}

}

bool  b_alloc_table_2_dim(int*** pi_Table, int iSizeX, int iSizeY) {

	if (iSizeX < 0 || iSizeY < 0) {

		cout << "Invalid size of Array" << endl;
		return false;
	}

	*pi_Table = new int* [iSizeY];

	for (int i = 0; i < iSizeY; i++) {

		(*pi_Table)[i] = new int[iSizeX];
	}

	for (int i = 0; i < iSizeY; i++) {

		for (int j = 0; j < iSizeX; j++) {

			(*pi_Table)[i][j] = (i * j) + offset;
		}
	}
	cout << "{";
	for (int i = 0; i < iSizeY; i++) {
		cout << "{";
		for (int j = 0; j < iSizeX; j++) {
			cout << (*pi_Table)[i][j] << " ";
		}cout << "}" << ",";
		//cout << endl;
	}cout << "}";
	cout << endl << endl;
	return true;
}

bool b_dealloc_table_2_dim(int*** pi_Table, int iSizeX, int iSizeY) {

	if (iSizeX < 0 || iSizeY < 0) {
		cout << "Invalid size of Array" << endl;
		return false;
	}

	for (int i = 0; i < iSizeY; i++) {
		delete (*pi_Table)[i];
	}
	delete[] * pi_Table;

	pi_Table = NULL;

	cout << "memory deallocated successfully" << endl;

	return true;
}

int main()
{

	int iSize;

	cout << "Please enter a valid array size " << endl;
	cin >> iSize;
	v_alloc_table_add_5(iSize);
	

	int** pi_Table;
	int iSizeX, iSizeY;
	cout << "Please Enter iSizeX : " << endl;
	cin >> iSizeX;
	cout << "Please Enter iSizeY : " << endl;
	cin >> iSizeY;
	cout << "Boolean value : [" << b_alloc_table_2_dim(&pi_Table, iSizeX, iSizeY) << "]" << std::endl;
	cout << "                            " << endl;
	cout << "Boolean value : [" << b_dealloc_table_2_dim(&pi_Table, iSizeX, iSizeY) << "]" << std::endl;
	cout << "                            " << endl;
	cout << "                            " << endl;
	cout << "                            " << endl;
	cout << "Provided Test" << endl;
	cout << b_alloc_table_2_dim(&pi_Table, 5, 3) << "]" << std::endl;
	cout << "                            " << endl;
	cout << b_dealloc_table_2_dim(&pi_Table, 5, 3) << "]" << std::endl;
}

