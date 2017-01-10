#include <iostream>
#include <random>
#include <string>

const int MAX_NUM = 1000;

void human_guess(int num)
{
    int input, c = 0;
    std::cout << ">>>>>  your game start(type -1 exit)  <<<<<\n";
    std::cin >> input;


    while (input != -1) {
        c++;
        if (input == num) {
            std::cout << "*****  You win! Guess " << c << " times  ******\n";
            break;
        } else if (input > num) {
            std::cout << "        greater.\n";
            std::cin >> input;
        } else {
            std::cout << "        less.\n";
            std::cin >> input;
        }
    }
}

void pc_guess(int num)
{
    int guess, c = 0, left = 0, right = MAX_NUM;
    std::cout << ">>>>> pc guess number start  <<<<<\n";

    while (c++ < 32) {
        guess = (left + right) / 2;
        std::cout << "[" << c << "]" << guess << std::endl;
        if (guess == num) {
            std::cout << "*****  PC win! Guess " << c << " times  ******\n";
            break;
        } else if (guess > num) {
            std::cout << "        greater\n";
            right = guess;
        } else {
            std::cout << "        less\n";
            left = guess;
        }
    }
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, MAX_NUM);
    int num = dis(gen);
    std::cout << "number is " << num << std::endl;

    std::cout << "you guess / PC guess (i/p)?\n";
    std::string str;
    std::cin >> str;
    std::cout << std::endl;
    if (!str.compare("i"))
        human_guess(num);
    if (!str.compare("p"))
        pc_guess(num);

	return 0;
}
