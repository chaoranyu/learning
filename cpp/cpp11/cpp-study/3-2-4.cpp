#include <iostream>

class Info {
public:
    Info() : Info(1, 'a') {}
    Info(int i) : Info(i, 'a') {}
    Info(char e) : Info(1, e) {}

private:
    Info(int i, char e) : type(i), name(e) {/*Other initialize*/}
    int type;
    char name;
    //...
};

int main()
{
    Info info;

    return 0;
}
