#include <iostream>
#include <fstream>
#include <list>
#include <queue>

struct Node {
	int value;
	std::list<Node *> child_list;// No List in c++, only have list
	Node(int x = 0) : value(x){}
};

class CMultiwayTree
{
public:
	void prepare(); // read input.txt and construct a data
	Node* create_tree();
	void destroy_tree(Node* root);
	void get_shortest_path(Node* root, Node* nodeA, Node* nodeB);
	void output_tree(const Node* root);	// preorder traversal
	////get Lowest Common Ancestor
	//Node* get_LCA(Node* root, Node* nodeA, Node* nodeB);
	Node* find_node_by_value(Node *root, int value);
	
private:
	Node* find_node(Node *root, Node* nodeA);

	std::queue<std::pair<int, int>> construct_queue;
	std::list<int> path_list;
};
