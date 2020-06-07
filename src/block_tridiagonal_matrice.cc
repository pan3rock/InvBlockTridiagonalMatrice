#include "block_tridiagonal_matrice.hpp"

#include <Eigen/Dense>

using namespace Eigen;

BlockTridiagonalMatrice::BlockTridiagonalMatrice(int size_block, int num_block)
    : sb_(size_block), nb_(num_block), ndim_(sb_ * nb_), tA_(sb_, sb_, nb_),
      tB_(sb_, sb_, nb_ - 1) {}

MatrixXd BlockTridiagonalMatrice::inverse() {}

void BlockTridiagonalMatrice::setA(
    const Eigen::Ref<const Eigen::MatrixXd> &block, int index) {
  ;
}
void BlockTridiagonalMatrice::setB(
    const Eigen::Ref<const Eigen::MatrixXd> &block, int index) {
  ;
}