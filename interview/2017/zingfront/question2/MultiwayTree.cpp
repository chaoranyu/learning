#include "MultiwayTree.h"

void CMultiwayTree::prepare()
{
	std::fstream myfile;
	myfile.open("input.txt", std::ios_base::in);

	if (myfile.is_open()) {
		int value, num;
		while (myfile >> value >> num) {
			construct_queue.push({ value, num });
		}
	}
	else {
		std::cerr << "opening input.txt failed\n";
		std::cerr << errno << '\n';
	}
}

Node* CMultiwayTree::create_tree()
{
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

	Node *root = nullptr;

	if (!construct_queue.empty()) {
		std::pair<int, int> tree_data = construct_queue.front();
		root = new Node(tree_data.first);
		int num = tree_data.second;
		construct_queue.pop();

		for (int i = 0; i < num; i++) {
			root->child_list.push_back(create_tree());
		}
	}
	return root;
}

void CMultiwayTree::destroy_tree(Node *root)
{
	// omit
}

void CMultiwayTree::get_shortest_path(Node* root, Node* nodeA, Node* nodeB)
{
	//Node *parent = get_LCA(root, nodeA, nodeB);
	//std::cout << parent->value << std::endl;
	find_node(root, nodeA);
	std::list<int> listA = path_list;
	path_list.clear();

	find_node(root, nodeB);
	std::list<int> listB = path_list;
	path_list.clear();

	std::cout << "the shortest path of " << nodeA->value
        << " and " << nodeB->value << " is: ";
	for (auto &a : listA) {
		std::cout << a << "  ";
		int c = 0;
		for (auto &b : listB) {
			if (b == a) {
				listB.resize(c);
				listB.reverse();
				for (auto &b2 : listB) {
					std::cout << b2 << "  ";
				}
				std::cout << std::endl;
				return;
			}
			c++;
		}
	}
}
/*
Node* CMultiwayTree::get_LCA(Node* root, Node* nodeA, Node* nodeB)
{
	if (root == nullptr)
		return nullptr;
	if (root == nodeA || root == nodeB) {
		//std::cout << root->value << '\n';
		return root;
	}
	if (root->child_list.size() == 0)
		return nullptr;

	int count = 0;
	Node* arr[2] = { nullptr, nullptr };

	for (auto &a : root->child_list) {
		Node* tmp = get_LCA(a, nodeA, nodeB);
		if (tmp != nullptr) {
			arr[count++] = tmp;
			//std::cout << root->value << '\n';
		}
	}
	if (count == 2) {
		return root;
	}
	else
	{
		return arr[0];
	}
}
*/
Node* CMultiwayTree::find_node_by_value(Node *root, int value)
{
	if (root->value == value) {
		return root;
	}

	for (auto & a : root->child_list) {
		Node* tmp = find_node_by_value(a, value);
		if (tmp != nullptr) {
			return tmp;
		}
	}
	return nullptr;
}

// preorder traversal
void CMultiwayTree::output_tree(const Node* root)
{
	std::cout << root->value << std::endl;

	for (const auto &a : root->child_list) {
		output_tree(a);
	}
}

Node* CMultiwayTree::find_node(Node *root, Node *nodeA)
{
	if (root == nodeA) {
		path_list.push_back(root->value);
		//std::cout << root->value << '\n';
		return root;
	}

	for (auto & a : root->child_list) {
		Node* tmp = find_node(a, nodeA);
		if (tmp != nullptr) {
			path_list.push_back(root->value);
			//std::cout << root->value << '\n';
			return tmp;
		}
	}
	return nullptr;
}
