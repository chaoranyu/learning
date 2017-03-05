
struct first_t {
    int a;
};

typedef struct {
    int a;
} second_t;

//first_t a;        // wrong in c, right in c++
struct first_t a;   // right in c, right in c++
second_t b;
