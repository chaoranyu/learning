#include "MultiwayTree.h"

int main()
{
	CMultiwayTree mt;
	mt.prepare();

    // create a tree as below
	//              1
	//           /  |   \
	//        2     3      4
	//      / | \        / | \
	//     5  6  7      8  9  10
	//      / | \     / | \
	//    11 12 13  14 15 16
	//         / | \
	//       17 18 19

	Node* root = mt.create_tree();
	//mt.output_tree(root); // for testing
	//std::cout << "-----------\n";

	Node* nodeA = mt.find_node_by_value(root, 7);
	Node* nodeB = mt.find_node_by_value(root, 17);
	if (nodeA != nullptr && nodeB != nullptr)
		mt.get_shortest_path(root, nodeA, nodeB);

	return 0;
}
