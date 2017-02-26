#include <vector>
#include <map>

int main() {
    int a[] = {1, 3, 5};
    int b[] {2, 4, 6};  //c++98 err
    std::vector<int> c{1, 2, 3}; //c++98 err
    std::map<int, float> d = 
        {{1, 1.0f}, {2, 2.0f}, {5, 3.2f}}; //c++98 err

    return 0;
}
