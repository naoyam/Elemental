/*
   Copyright (c) 2009-2012, Jack Poulson
   All rights reserved.

   This file is part of Elemental.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

    - Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

    - Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.

    - Neither the name of the owner nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef ELEMENTAL_SPECIAL_MATRICES_HPP
#define ELEMENTAL_SPECIAL_MATRICES_HPP 1

namespace elem {

//----------------------------------------------------------------------------//
// Deterministic                                                              //
//----------------------------------------------------------------------------//

// Generate an m x n Cauchy matrix, i.e., 
//
//   A(i,j) = 1/(x(i)-y(j)), where x(i) != y(j), 
//                           for all (i,j) such that 0 <= i < m, 0 <= j < n.
//
template<typename F>
void Cauchy
( const std::vector<F>& x, const std::vector<F>& y, Matrix<F>& A );
template<typename F,Distribution U,Distribution V>
void Cauchy
( const std::vector<F>& x, const std::vector<F>& y, DistMatrix<F,U,V>& A );

// Generate an m x n Cauchy-like matrix, i.e., 
//
//   A(i,j) = r(i)s(j)/(x(i)-y(j)), where x(i) != y(j), 
//                                  for all (i,j) such that 
//                                  0 <= i < m, 0 <= j < n.
//
template<typename F>
void CauchyLike
( const std::vector<F>& r, const std::vector<F>& s,
  const std::vector<F>& x, const std::vector<F>& y,
  Matrix<F>& A );
template<typename F,Distribution U,Distribution V>
void CauchyLike
( const std::vector<F>& r, const std::vector<F>& s,
  const std::vector<F>& x, const std::vector<F>& y,
  DistMatrix<F,U,V>& A );

// Generate an n x n circulant matrix, i.e., 
//
//   A(i,j) = a((i-j) mod n), for all (i,j) such that 0 <= i,j < n.
//
// Note that circulant matrices are special cases of Toeplitz matrices, but 
// that our indexing scheme for 'a' is different.
//
template<typename T>
void Circulant( const std::vector<T>& a, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void Circulant( const std::vector<T>& a, DistMatrix<T,U,V>& A );

// Generate an n x n diagonal matrix, i.e., 
//
//   D(i,j) = d(j), if i = j, and zero otherwise.
//
template<typename T>
void Diagonal( const std::vector<T>& d, Matrix<T>& D );
template<typename T,Distribution U,Distribution V>
void Diagonal( const std::vector<T>& d, DistMatrix<T,U,V>& D );

// Generate an m x n Hankel matrix, i.e.,
//
//    A(i,j) = a(i+j), for all (i,j) such that 0 <= i < m, 0 <= j < n.
//
template<typename T>
void Hankel( int m, int n, const std::vector<T>& a, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void Hankel( int m, int n, const std::vector<T>& a, DistMatrix<T,U,V>& A );

// Generate an n x n Hilbert matrix, i.e., 
//
//   H(i,j) = 1/(i+j+1), for all (i,j) such that 0 <= i, j < n.
//
template<typename F>
void Hilbert( int n, Matrix<F>& H );
template<typename F,Distribution U,Distribution V>
void Hilbert( int n, DistMatrix<F,U,V>& H );
// Turn the existing square matrix into a Hilbert matrix
template<typename F>
void MakeHilbert( int n, Matrix<F>& H );
template<typename F,Distribution U,Distribution V>
void MakeHilbert( int n, DistMatrix<F,U,V>& H );

// Generate an m x n identity-like matrix, i.e., 
//
//   I(i,j) = 1, if i = j, and zero otherwise.
//
template<typename T>
void Identity( int m, int n, Matrix<T>& I );
template<typename T,Distribution U,Distribution V>
void Identity( int m, int n, DistMatrix<T,U,V>& I );
// Turn the existing matrix into an identity-like matrix
template<typename T>
void MakeIdentity( Matrix<T>& I );
template<typename T,Distribution U,Distribution V>
void MakeIdentity( DistMatrix<T,U,V>& I );

// Generate an m x n matrix of all ones.
template<typename T>
void Ones( int m, int n, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void Ones( int m, int n, DistMatrix<T,U,V>& A ); 
// Turn the existing matrix into a matrix of all ones.
template<typename T>
void MakeOnes( Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void MakeOnes( DistMatrix<T,U,V>& A );

// Generate a so-called "1-2-1" matrix of order k (and dimension k), 
// which is tridiagonal with a diagonal of all twos and sub- and super-diagonals
// of all ones.
template<typename T>
void OneTwoOne( int k, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void OneTwoOne( int k, DistMatrix<T,U,V>& A );
// Turn the existing matrix into a 1-2-1 matrix.
template<typename T>
void MakeOneTwoOne( int k, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void MakeOneTwoOne( int k, DistMatrix<T,U,V>& A );

// Generate an m x n Toeplitz matrix, i.e.,
//
//   A(i,j) = a(i-j+(n-1)), for all (i,j) such that 0 <= i < m, 0 <= j < n.
//
template<typename T>
void Toeplitz( int m, int n, const std::vector<T>& a, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void Toeplitz( int m, int n, const std::vector<T>& a, DistMatrix<T,U,V>& A );

// Generate a Walsh matrix of order k (and dimension 2^k), where
//
//    W_1 = | 1  1 |, and
//          | 1 -1 |
//
//    W_k = | W(k-1)  W(k-1) |, for k >= 2.
//          | W(k-1) -W(k-1) |
//
// A binary Walsh matrix is the same as above, but with all -1 entries replaced
// with zeros.
//
template<typename T>
void Walsh( int k, Matrix<T>& W, bool binary=false );
template<typename T,Distribution U,Distribution V>
void Walsh( int k, DistMatrix<T,U,V>& W, bool binary=false );

// Generate a Wilkinson matrix of order k (and dimension 2k+1), 
// which is tridiagonal with
//             
//   diag(W_k) = [k,k-1,k-2,...,1,0,1,...,k-2,k-1,k],
// 
// and sub- and super-diagonals of all ones.
template<typename T>
void Wilkinson( int k, Matrix<T>& W );
template<typename T,Distribution U,Distribution V>
void Wilkinson( int k, DistMatrix<T,U,V>& W );

// Generate an m x n matrix of all zeros
template<typename T>
void Zeros( int m, int n, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void Zeros( int m, int n, DistMatrix<T,U,V>& A );
// Turn the existing matrix into a matrix of all zeros
template<typename T>
void MakeZeros( Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void MakeZeros( DistMatrix<T,U,V>& A );

//----------------------------------------------------------------------------//
// Random                                                                     //
//----------------------------------------------------------------------------//

// Generate an m x n matrix of samples from the uniform PDF over the 
// closed unit ball.
template<typename T>
void UniformRandom( int m, int n, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void UniformRandom( int m, int n, DistMatrix<T,U,V>& A );
// Turn the existing matrix into a uniform random matrix
template<typename T>
void MakeUniformRandom( Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void MakeUniformRandom( DistMatrix<T,U,V>& A );

// Same as UniformRandom, but the diagonal is forced to be real-valued
template<typename T>
void HermitianUniformRandom( int n, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void HermitianUniformRandom( int n, DistMatrix<T,U,V>& A );
// Turn the existing matrix into an (implicitly) Hermitian uniform random matrix
template<typename T>
void MakeHermitianUniformRandom( Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void MakeHermitianUniformRandom( DistMatrix<T,U,V>& A );

// Same as UniformRandom, but the diagonal is forced to be real-valued and 
// the diagonal is shifted up by n in order to ensure that the matrix is HPD.
template<typename T>
void HPDUniformRandom( int n, Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void HPDUniformRandom( int n, DistMatrix<T,U,V>& A );
// Turn the existing matrix into an (implicitly) HPD uniform random matrix
template<typename T>
void MakeHPDUniformRandom( Matrix<T>& A );
template<typename T,Distribution U,Distribution V>
void MakeHPDUniformRandom( DistMatrix<T,U,V>& A );

// TODO: Gaussian

} // namespace elem

//----------------------------------------------------------------------------//
// Implementation begins here                                                 //
//----------------------------------------------------------------------------//

//
// Deterministic
//

#include "./special_matrices/Cauchy.hpp"
#include "./special_matrices/CauchyLike.hpp"
#include "./special_matrices/Circulant.hpp"
#include "./special_matrices/Diagonal.hpp"
#include "./special_matrices/Hankel.hpp"
#include "./special_matrices/Hilbert.hpp"
#include "./special_matrices/Identity.hpp"
#include "./special_matrices/Ones.hpp"
#include "./special_matrices/OneTwoOne.hpp"
#include "./special_matrices/Toeplitz.hpp"
#include "./special_matrices/Walsh.hpp"
#include "./special_matrices/Wilkinson.hpp"
#include "./special_matrices/Zeros.hpp"

//
// Random
//

#include "./special_matrices/UniformRandom.hpp"
#include "./special_matrices/HermitianUniformRandom.hpp"
#include "./special_matrices/HPDUniformRandom.hpp"

// TODO: Gaussian

#endif /* ELEMENTAL_SPECIAL_MATRICES_HPP */
