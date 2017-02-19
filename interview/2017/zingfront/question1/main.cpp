#include "Cache.h"

int main()
{
	Cache c;

	for (int i = 0; i < 50; i++) {
		c.add();
		c.pass_one_second();
	}
	c.output_items();
	std::cout << "\n-------------\n";

	for (int i = 0; i < 45; i++) {
		c.del();
		c.pass_one_second();
	}
	c.output_items();
	std::cout << "\n-------------\n";

	for (int i = 0; i < 55; i++) {
		c.del();
		c.add();
		c.pass_one_second();
	}
	c.output_items();
	std::cout << "\n-------------\n";

	for (int i = 0; i < 100; i++) {
		c.add();
		c.pass_one_second();
	}
	c.output_items();
	std::cout << "\n-------------\n";

	for (int i = 0; i < 80; i++) {
		c.del();
		c.add();
		c.pass_one_second();
	}
	c.output_items();

	return 0;
}
