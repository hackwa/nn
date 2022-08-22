#include <iostream>
#include <memory>

template <typename T>
class matrix {

private:    
  uint32_t rows;
  uint32_t cols;
  std::unique_ptr<T []> mat;

public:
  matrix(uint32_t r, uint32_t c, bool random);

  void randinit();
  void print();
  matrix operator*(const matrix& other);
};