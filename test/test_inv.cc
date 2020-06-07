#include "catch.hpp"
#include "timer.hpp"

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>
#include <iostream>
#include <vector>

using namespace Eigen;
using Td = Triplet<double>;

TEST_CASE("tridiagonal eye", "[inv]") {
  int sb = 4;
  int nb = 4;
  int ndim = nb * sb;
  SparseMatrix<double> matA(ndim, ndim);
  std::vector<Td> tripletList;
  tripletList.reserve(ndim * 3 - sb * 2);
  for (int i = 0; i < ndim; ++i) {
    tripletList.push_back(Td(i, i, 1.0));
  }
  for (int i = sb; i < ndim; ++i) {
    tripletList.push_back(Td(i - sb, i, 1.0));
    tripletList.push_back(Td(i, i - sb, 1.0));
  }
  matA.setFromTriplets(tripletList.begin(), tripletList.end());
  SparseMatrix<double> matI(ndim, ndim);
  matI.setIdentity();

  Timer::begin("eigen sparse solver");
  SimplicialLDLT<SparseMatrix<double>> solver;
  solver.compute(matA);
  MatrixXd A_inv = solver.solve(matI);
  Timer::end("eigen sparse solver");

  IOFormat fmt(1, 0, ", ", "\n", "[", "]");
  std::cout << A_inv.format(fmt) << std::endl;

  std::cout << Timer::summery() << std::endl;
}