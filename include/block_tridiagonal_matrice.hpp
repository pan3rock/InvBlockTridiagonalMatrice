#ifndef BLOCK_TRIDIAGONAL_MATRICE_H_
#define BLOCK_TRIDIAGONAL_MATRICE_H_

#include "tensor.hpp"
#include <Eigen/Dense>

class BlockTridiagonalMatrice {
public:
  BlockTridiagonalMatrice(int size_block, int num_block);
  Eigen::MatrixXd inverse();
  void setA(const Eigen::Ref<const Eigen::MatrixXd> &block, int index);
  void setB(const Eigen::Ref<const Eigen::MatrixXd> &block, int index);

private:
  const int sb_, nb_, ndim_;
  Tensor tA_; // diagonal blocks
  Tensor tB_; // upper off-diagonal blocks
};

#endif