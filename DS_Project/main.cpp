#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
	Tree<int> temp;
	temp.insert_item(4);
	temp.insert_item(2);
	temp.insert_item(6);
	temp.insert_item(1);
	temp.insert_item(3);
	temp.insert_item(5);
	temp.insert_item(7);

	temp.reset_tree(IN_ORDER);

	int aa;
	bool chk = false;
	while (!chk)
	{
		temp.get_next_item(IN_ORDER, aa, chk);
		cout << aa << endl;
	}
	return 0;
}