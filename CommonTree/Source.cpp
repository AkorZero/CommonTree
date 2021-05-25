#include "CommonTree.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	try
	{
		cout << "Input string: ";
		string treeString;
		getline(cin, treeString);

		CommonTree tree(treeString);

		cout << tree.CommonTreeToString();
		cout << endl << tree.height();
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		system("pause");
		return -1;
	}

	system("pause");
	return 0;
}