#ifndef TENSOR_H_
#define TENSOR_H_

#include <Eigen/Dense>

class TensorXd {
public:
  TensorXd(int nrow, int ncol, int nslice);
  Eigen::Block<Eigen::MatrixXd> operator[](int slice);

private:
  int nrow_, ncol_, nslice_;
  Eigen::MatrixXd value_;
};

#endif