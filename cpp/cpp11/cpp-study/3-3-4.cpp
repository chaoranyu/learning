// g++ -std=c++11 3-3-4.cpp -fno-elide-constructors
#include <iostream>

class HasPtrMem {
public:
    HasPtrMem() : d(new int(0)) {
        std::cout << "Construct: " << ++n_cstr << std::endl;
    }
    HasPtrMem(const HasPtrMem &h) : d(new int(*h.d)) {
        std::cout << "Copy construct: " << ++n_cptr << std::endl;
    }
    HasPtrMem(HasPtrMem &&h) : d(h.d) {
        h.d = nullptr;
        std::cout << "Move construct: " << ++n_mvtr << std::endl;
    }
    ~HasPtrMem() {
        delete d;
        std::cout << "Destruct: " << ++n_dstr << std::endl;
    }

    //HasPtrMem& operator=(const HasPtrMem &h) {
    //    d = new int(*h.d);
    //    std::cout << "Copy function: " << ++n_cptr << std::endl;
    //}


    int *d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;

HasPtrMem GetTemp() {
    HasPtrMem h;
    std::cout << "Resource from " << __func__ << ": "
        << std::hex << h.d << std::endl;
    return h;
}

int main()
{
    HasPtrMem a = GetTemp();
    std::cout << "Resource from " << __func__ << ": "
        << std::hex << a.d << std::endl;

    return 0;
}
