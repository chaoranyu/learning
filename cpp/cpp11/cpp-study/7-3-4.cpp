// g++ -std=c++11 7-3-4.cpp
// ./a.out
// echo $?

int main() {
    int girls = 3, boys = 4;
    auto totalChild = [=]() ->int { return girls + boys; };

    return totalChild();
}
