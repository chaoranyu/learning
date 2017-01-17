#include <iostream>
#include <iomanip>

int maxbit(int data[], int n)
{
    int maxData = data[0];
    for (int i = 1; i < n; i++) {
        if (data[i] > maxData) {
            maxData = data[i];
        }
    }

    int d = 1;
    int p = 10;
    while (maxData >= p) {
        maxData /= 10;
        d++;
    }
    return d;
}

// Radixsort
void radixsort(int data[], int n)
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10];
    int i, j, k;
    int radix = 1;

    for (i = 1; i <= d; i++) {
        for (j = 0; j < 10; j++) {
            count[j] = 0;
        }
        for (j = 0; j < n; j++) {
            k = (data[j] / radix)  % 10;
            count[k]++;
        }
        for (j = 1; j < 10; j++) {
            count[j] += count[j-1];
        }
        for (j = n - 1; j >= 0; j--) {
            k = (data[j] / radix) % 10;
            tmp[count[k]-1] = data[j];
            count[k]--;
        }
        for (int j = 0; j < n; j++) {
            data[j] = tmp[j];
        }
        radix *= 10;
    }

    delete [] tmp;
    delete [] count;
}

int main()
{
    const int N = 12;
    int data[N] = {112, 7, 13, 20, 931, 9, 11, 12, 66, 6, 666, 70};

    for(auto &a : data)
        std::cout << std::setw(5) << a;
        //std::cout << a << "  ";
    std::cout << std::endl;

    radixsort(data, N);

    for(auto &a : data)
        std::cout << std::setw(5) << a;
    std::cout << std::endl;

    return 0;
}
