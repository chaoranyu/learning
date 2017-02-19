// string::operator[]
#include <iostream>
#include <string>

int main ()
{
  std::string str ("Test string");
  for (int i=0; i<str.length() + 9; ++i)
  {
    std::cout << str[i];
  }
  std::cout << std::endl;
  return 0;
}
