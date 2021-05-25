#include "CommonTree.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	cout << "Input string: ";
	string treeString;
	getline(cin, treeString);

	CommonTree tree(treeString);

	system("pause");
	return 0;
}