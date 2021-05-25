#pragma once
#include <string>

using namespace std;

class CommonTree
{
	class Node
	{
		friend class CommonTree;
		int info;
		Node* parent;
		Node* first_son;
		Node* brother;
	public:
		Node(int key, Node* p = nullptr);
	};

	Node* root;
	int GetNumber(string s, int& i);
public:
	CommonTree();
	CommonTree(string s);
	string CommonTreeToString();
	~CommonTree();
};

