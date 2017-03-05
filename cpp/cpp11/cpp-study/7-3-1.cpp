// g++ -std=c++11 7-3-1.cpp
// ./a.out
// echo $?

int main() {
    int girls = 3, boys = 4;
    auto totalChild = [](int x, int y) ->int { return x+y; };
    //auto totalChild = [](int x, int y) { return x+y; };
    
    return totalChild(girls, boys);
}
