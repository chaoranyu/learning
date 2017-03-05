// g++ -std=c++11 7-3-10.cpp

int main() {
    int girls = 3, boys = 4;
    auto totalChild = [](int x, int y) ->int { return x+y; };
    typedef int (*allChild)(int x, int y);
    typedef int (*oneChild)(int x);

    allChild p = totalChild;

    oneChild q;
    //q = totalChild;

    decltype(totalChild) allPeople = totalChild;
    //decltype(totalChild) totalPeople = p;
 
    return 0;
}
