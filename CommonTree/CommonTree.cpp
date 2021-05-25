#include "CommonTree.h"

CommonTree::Node::Node(int key, CommonTree::Node* p)
{
	info = key;
	parent = p;
	first_son = brother = nullptr;

}

int CommonTree::GetNumber(string s, int & i)
{
	bool isSign = false;
	int number = 0;

	if (s[i] == '-')
	{
		isSign = true;
		i++;
	}

	while (i < s.length() && isdigit(s[i]))
	{
		number = number * 10 + (s[i] - '0');
		i++;
	}

	if (isSign)
	{
		number = -number;
		// isSign = false;
	}

	return number;
}

CommonTree::CommonTree()
{
	root = nullptr;
}

CommonTree::CommonTree(string s)
{
	int number = 0, i = 0;
	
	Node* tmp = nullptr;
	number = GetNumber(s, i);

	root = new Node(number);
	tmp = root;

	// Открывающая скобка - что это значит? Что сейчас пойдут дети. Пойдут они толпой.

	for (; i < s.length(); )
	{
		if (s[i] == '(')
		{
			i++;
			number = GetNumber(s, i);
			tmp->first_son = new Node(number, tmp);
			tmp = tmp->first_son;
		}
	}
}

string CommonTree::CommonTreeToString()
{
	return string();
}


CommonTree::~CommonTree()
{
}
