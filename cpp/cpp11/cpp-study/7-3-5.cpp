// g++ 7-3-5.cpp
// ./a.out
// echo $?

class _functor {
public:
    int operator() (int x, int y) { return x + y; }
};

int main() {
    int girls = 3, boys = 4;
    _functor totalChild;

    return totalChild(girls, boys);
}
