#include <iostream>

struct test_t
{
    int val;
    test_t(int i = 0) : val(i) {}
};

int main()
{
    char *a = new char('a');
    char *b = new char('b');
    char *c = new char('c');
    char *d = new char('d');
    std::cout << a << "  " << b << "  "
              << c << "  " << d << '\n';

    char *h = new char[5] {'h', 'i', 'j', 'k', '\0'};
    std::cout << h << std::endl;

    test_t *t = new test_t[8] {1, 2, 3, 4, 5, 6, 7, 8};
    std::cout << t[0].val << std::endl;

    return 0;
}
