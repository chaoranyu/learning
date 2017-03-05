#include <cstddef>

class NoHeadAlloc {
public:
    void * operator new(std::size_t) = delete;
};

int main() {
    NoHeadAlloc nha;
    //NoHeadAlloc *pnha = new NoHeadAlloc;

    return 1;
}
