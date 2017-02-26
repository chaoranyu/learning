#include <vector>
#include <string>

enum Gender {boy, girl};

class People {
public:
    People(std::initializer_list<std::pair<std::string, Gender>> l) {
        auto i = l.begin();
        for (; i != l.end(); ++i) {
            data.push_back(*i);
        }
    }

private:
    std::vector<std::pair<std::string, Gender>> data;
};

int main() {
    People ship2012 = {{"Garfield", boy}, {"HelloKitty", girl}};

    return 0;
}
