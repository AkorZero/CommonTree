#include "CommonTree.h"

int cnt = 0;
int max = 0;

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

void CommonTree::treeToString(Node * tmp, string & tree)
{
	if (tmp == nullptr)
	{
		return;
	}

	tree += to_string(tmp->info);

	if (tmp->first_son != nullptr)
	{
		tree += "(";
		treeToString(tmp->first_son, tree);
		tree += ")";
	}

	if (tmp->brother != nullptr)
	{
		tree += ",";
		treeToString(tmp->brother, tree);
	}
}

//int CommonTree::height(Node* tmp)
//{
//	if (tmp == nullptr)
//	{
//		cnt = 0, max = 0;
//		tmp = this->root;
//	}
//	if (tmp->first_son != nullptr)
//	{
//		cnt++;
//		height(tmp->first_son);
//	}
//	else if (tmp->brother != nullptr)
//	{
//		height(tmp->brother);
//	}
//	else
//	{
//		if (cnt > max)
//			max = cnt;
//	}
//	return max;
//}

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
	// О чем нам говорит запятая?
	// -- Что у нас появился брат!
	// Какие радостные у нас события в жизни!

	for (; i < s.length(); )
	{
		if (tmp == nullptr)
			throw "Incorrect string";

		if (s[i] == '(')
		{
			i++;
			number = GetNumber(s, i);
			tmp->first_son = new Node(number, tmp);
			tmp = tmp->first_son;
		}
		else if (s[i] == ',')
		{
			i++;
			number = GetNumber(s, i);
			tmp->brother = new Node(number, tmp->parent);
			tmp = tmp->brother;
		}
		else if (s[i] == ')')
		{
			i++;
			tmp = tmp->parent;

			if (tmp == root && i < s.length())
				throw "Incorrect string";
		}
		else
		{
			throw "Incorrect symbol";
		}
	}
}

string CommonTree::CommonTreeToString()
{
	string tree;
	treeToString(root, tree);
	return tree;
}


CommonTree::~CommonTree()
{
}
