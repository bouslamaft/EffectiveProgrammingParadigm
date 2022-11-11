#include <iostream>
using namespace std; 

class CTable {



public:

	int* array;

	string  s_name;

	int iTableLength;


	CTable() {

		s_name = "defaultName";
		iTableLength = 5;
		array = new int[iTableLength];
		cout << "Without : " << s_name << endl;
	}


	CTable(string sName, int iTableLen) {
		s_name = sName;

		iTableLength = iTableLen;

		array = new int[iTableLen];

		fillArray();

		cout << "Parameter : " << s_name << endl;
	}


	CTable(const CTable& pcOther) {

		s_name = pcOther.s_name + "_copy";

		iTableLength = pcOther.iTableLength;

		array = new int[pcOther.iTableLength];

		fillArray();

		cout << "copy: " << s_name << endl;
	}

	void fillArray() {

		for (int i = 0; i < iTableLength; i++) {
			array[i] = i * i;
		}
	}


	~CTable() {
		delete array;
		array = NULL;
		cout << "removing: " << s_name << endl;

	}

	void vSetName(string sName) {
		s_name = sName;
	}
	int i_getLength() {
		return iTableLength;
	}

	string s_getName() {
		return s_name;
	}

	bool bSetNewSize(int iTableLen) {
		if (iTableLen > 0) {

			iTableLength = iTableLen;
			array = new int[iTableLen];
			fillArray();
			cout << "table size setting successful" << endl;
			return true;
		}
		else
		{
			cout << " Invalid Array Size " << endl;
			return false;
		}


	}



	void  vPrint() {
		for (int i = 0; i < iTableLength; i++) {
			cout << (array)[i] << endl;
		}
	}

	CTable* pcClone() {
		return new CTable(*this);
	}


	void v_mod_tab(CTable* pcTab, int iNewSize)
	{
		pcTab->bSetNewSize(iNewSize);
	}

	void v_mod_tab(CTable cTab, int iNewSize)
	{
		cTab.bSetNewSize(iNewSize);
	}


};
int main()
{
	cout << "Static tables creating" << endl;
	CTable s_tab_default;

	CTable s_tab_parametr("Tab size", 10);
	s_tab_parametr.fillArray();
	s_tab_parametr.vPrint();
	cout << endl;

	cout << "Dynamic tables creating" << endl;
	CTable* d_tab_default = new CTable();
	CTable* d_tab_params = new CTable("Dynamic tab", 20);
	cout << endl;

	cout << "Deleting" << endl;
	delete d_tab_default;
}
