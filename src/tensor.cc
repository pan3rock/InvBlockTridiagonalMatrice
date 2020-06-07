#include "tensor.hpp"

#include <Eigen/Dense>

using namespace Eigen;

TensorXd::TensorXd(int nrow, int ncol, int nslice)
    : nrow_(nrow), ncol_(ncol), nslice_(nslice),
      value_(MatrixXd::Zero(nrow_, ncol_ * nslice_)) {}

Block<MatrixXd> TensorXd::operator[](int slice) {
  return value_.block(0, slice * ncol_, nrow_, ncol_);
}