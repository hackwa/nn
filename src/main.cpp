#include <iostream>

#include "matrix.hpp"

int
main()
{
  std::cout << "A :" << std::endl;
  matrix<int> a(3, 2, true);
  a.print();
  std::cout << "B :" << std::endl;
  matrix<int> b(2, 3, true);
  b.print();
  std::cout << "A*B :" << std::endl;
  auto c = a * b;
  c.print();
  return 0;
}
