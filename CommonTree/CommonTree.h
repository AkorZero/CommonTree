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
	void treeToString(Node* tmp, string& tree);
public:
	CommonTree();
	CommonTree(string s);
	string CommonTreeToString();
	int height(Node* tmp = nullptr);
	~CommonTree();
};

