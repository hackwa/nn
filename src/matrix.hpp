#include <memory>
#include <random>
#include <iostream>

template <typename T>
class matrix {

private:    
  uint32_t rows;
  uint32_t cols;
  std::unique_ptr<T []> mat;

public:

  matrix(uint32_t r, uint32_t c, bool random)
  : rows(r)
  , cols(c)
  , mat(new T[rows*cols]{0})
  {
    if (random)
      randinit();
  }

  void
  print()
  {
    std::cout << std::endl;
    for (uint32_t i = 0; i < rows; i++) {
      for (uint32_t j = 0; j < cols; j++)
        std::cout << mat[i*cols + j] << " ";
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  void
  randinit()
  {
    std::random_device dev;
    std::mt19937 rng(dev());
    static std::uniform_real_distribution<> dist(0.1,9.0);

    for (uint32_t i = 0; i < rows; i++)
      for (uint32_t j = 0; j < cols; j++)
        mat[i*cols + j] = static_cast<T>(dist(rng));
  }

  matrix<T>
  operator*(const matrix& other)
  {
    auto res_r = rows;
    auto res_c = other.cols;
    matrix<T> res(res_r, res_c, false);

    for (uint32_t i = 0; i < res_r; i++)
      for (uint32_t j = 0; j < res_c; j++)
        for (uint32_t k = 0; k < cols; k++)
          res.mat[i*res_c + j] += mat[i*cols + k] * other.mat[k*res_c + j];

    return res;
  }
};
