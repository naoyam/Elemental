/*
   Copyright (c) 2009-2015, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#include "El.hpp"

using El::scomplex;
using El::dcomplex;

extern "C" {

// Level 1 BLAS
// ============
void EL_BLAS(saxpy)
( const int* n, const float* alpha, const float* x, const int* incx,
                                          float* y, const int* incy );
void EL_BLAS(daxpy)
( const int* n, const double* alpha, const double* x, const int* incx,
                                           double* y, const int* incy );
void EL_BLAS(caxpy)
( const int* n, const scomplex* alpha,
  const scomplex* x, const int* incx,
        scomplex* y, const int* incy );
void EL_BLAS(zaxpy)
( const int* n, const dcomplex* alpha,
  const dcomplex* x, const int* incx,
        dcomplex* y, const int* incy );

void EL_BLAS(scopy)
( const int* n, const float* x, const int* incx,
                      float* y, const int* incy );
void EL_BLAS(dcopy)
( const int* n, const double* x, const int* incx,
                      double* y, const int* incy );
void EL_BLAS(ccopy)
( const int* n, const scomplex* x, const int* incx,
                      scomplex* y, const int* incy );
void EL_BLAS(zcopy)
( const int* n, const dcomplex* x, const int* incx,
                      dcomplex* y, const int* incy );

float EL_BLAS(sdot)
( const int* n, const float* x, const int* incx,
                const float* y, const int* incy );
double EL_BLAS(ddot)
( const int* n, const double* x, const int* incx,
                const double* y, const int* incy );
// To avoid the compatibility issue, we simply handroll our own complex dots
float  EL_BLAS(snrm2) ( const int* n, const float   * x, const int* incx );
double EL_BLAS(dnrm2) ( const int* n, const double  * x, const int* incx );
float  EL_BLAS(scnrm2)( const int* n, const scomplex* x, const int* incx );
double EL_BLAS(dznrm2)( const int* n, const dcomplex* x, const int* incx );

// Apply a Givens rotation to a pair of vectors
void EL_BLAS(srot)
( const int* n, float* x, const int* incx, float* y, const int* incy,
  const float* c, const float* s );
void EL_BLAS(drot)
( const int* n, double* x, const int* incx, double* y, const int* incy,
  const double* c, const double* s );
void EL_BLAS(crot)
( const int* n, scomplex* x, const int* incx, scomplex* y, const int* incy,
  const float* c, const scomplex* s );
void EL_BLAS(zrot)
( const int* n, dcomplex* x, const int* incx, dcomplex* y, const int* incy,
  const double* c, const dcomplex* s );

// Quickly compute a Givens rotation
void EL_BLAS(srotg)
( float* alpha, float* beta, float* c, float* s );
void EL_BLAS(drotg)
( double* alpha, double* beta, double* c, double* s );
void EL_BLAS(crotg)
( scomplex* alpha, scomplex* beta, float* c, scomplex* s );
void EL_BLAS(zrotg)
( dcomplex* alpha, dcomplex* beta, double* c, dcomplex* s );

// Scale a vector
void EL_BLAS(sscal)
( const int* n, const float   * alpha, float   * x, const int* incx );
void EL_BLAS(dscal)
( const int* n, const double  * alpha, double  * x, const int* incx );
void EL_BLAS(cscal)
( const int* n, const scomplex* alpha, scomplex* x, const int* incx );
void EL_BLAS(zscal)
( const int* n, const dcomplex* alpha, dcomplex* x, const int* incx );

float  EL_BLAS(sasum) ( const int* n, const float   * x, const int* incx );
double EL_BLAS(dasum) ( const int* n, const double  * x, const int* incx );
float  EL_BLAS(scasum)( const int* n, const scomplex* x, const int* incx );
double EL_BLAS(dzasum)( const int* n, const dcomplex* x, const int* incx );
float  EL_LAPACK(scsum1)( const int* n, const scomplex* x, const int* incx );
double EL_LAPACK(dzsum1)( const int* n, const dcomplex* x, const int* incx );

void EL_BLAS(sswap)
( const int* n, float   * x, const int* incx, float   * y, const int* incy );
void EL_BLAS(dswap)
( const int* n, double  * x, const int* incx, double  * y, const int* incy );
void EL_BLAS(cswap)
( const int* n, scomplex* x, const int* incx, scomplex* y, const int* incy );
void EL_BLAS(zswap)
( const int* n, dcomplex* x, const int* incx, dcomplex* y, const int* incy );

// Level 2 BLAS
// ============
void EL_BLAS(sgemv)
( const char* trans, const int* m, const int* n,
  const float* alpha, const float* A, const int* lda,
                      const float* x, const int* incx,
  const float* beta,        float* y, const int* incy );
void EL_BLAS(dgemv)
( const char* trans, const int* m, const int* n,
  const double* alpha, const double* A, const int* lda,
                       const double* x, const int* incx,
  const double* beta,        double* y, const int* incy );
void EL_BLAS(cgemv)
( const char* trans, const int* m, const int* n,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
  const scomplex* x, const int* incx,
  const scomplex* beta,
        scomplex* y, const int* incy );
void EL_BLAS(zgemv)
( const char* trans, const int* m, const int* n,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
  const dcomplex* x, const int* incx,
  const dcomplex* beta,
        dcomplex* y, const int* incy );

void EL_BLAS(sger)
( const int* m, const int* n,
  const float* alpha, const float* x, const int* incx,
                      const float* y, const int* incy,
                            float* A, const int* lda  );
void EL_BLAS(dger)
( const int* m, const int* n,
  const double* alpha, const double* x, const int* incx,
                       const double* y, const int* incy,
                             double* A, const int* lda  );
void EL_BLAS(cgerc)
( const int* m, const int* n,
  const scomplex* alpha,
  const scomplex* x, const int* incx,
  const scomplex* y, const int* incy,
        scomplex* A, const int* lda  );
void EL_BLAS(zgerc)
( const int* m, const int* n,
  const dcomplex* alpha,
  const dcomplex* x, const int* incx,
  const dcomplex* y, const int* incy,
        dcomplex* A, const int* lda  );

void EL_BLAS(cgeru)
( const int* m, const int* n,
  const scomplex* alpha,
  const scomplex* x, const int* incx,
  const scomplex* y, const int* incy,
        scomplex* A, const int* lda  );
void EL_BLAS(zgeru)
( const int* m, const int* n,
  const dcomplex* alpha,
  const dcomplex* x, const int* incx,
  const dcomplex* y, const int* incy,
        dcomplex* A, const int* lda  );

void EL_BLAS(chemv)
( const char* uplo, const int* m,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
  const scomplex* x, const int* incx,
  const scomplex* beta,
        scomplex* y, const int* incy );
void EL_BLAS(zhemv)
( const char* uplo, const int* m,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
  const dcomplex* x, const int* incx,
  const dcomplex* beta,
        dcomplex* y, const int* incy );

void EL_BLAS(cher)
( const char* uplo, const int* m,
  const float* alpha,
  const scomplex* x, const int* incx,
        scomplex* A, const int* lda  );
void EL_BLAS(zher)
( const char* uplo, const int* m,
  const double* alpha,
  const dcomplex* x, const int* incx,
        dcomplex* A, const int* lda  );

void EL_BLAS(cher2)
( const char* uplo, const int* m,
  const scomplex* alpha,
  const scomplex* x, const int* incx,
  const scomplex* y, const int* incy,
        scomplex* A, const int* lda  );
void EL_BLAS(zher2)
( const char* uplo, const int* m,
  const dcomplex* alpha,
  const dcomplex* x, const int* incx,
  const dcomplex* y, const int* incy,
        dcomplex* A, const int* lda  );

void EL_BLAS(ssymv)
( const char* uplo, const int* m,
  const float* alpha, const float* A, const int* lda,
                      const float* x, const int* incx,
  const float* beta,        float* y, const int* incy );
void EL_BLAS(dsymv)
( const char* uplo, const int* m,
  const double* alpha, const double* A, const int* lda,
                       const double* x, const int* incx,
  const double* beta,        double* y, const int* incy );
// 'csymv' is an auxiliary LAPACK routine, but we will treat it as BLAS
void EL_LAPACK(csymv)
( const char* uplo, const int* m,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
  const scomplex* x, const int* incx,
  const scomplex* beta,
        scomplex* y, const int* incy );
// 'zsymv' is an auxiliary LAPACK routine, but we will treat it as BLAS
void EL_LAPACK(zsymv)
( const char* uplo, const int* m,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
  const dcomplex* x, const int* incx,
  const dcomplex* beta,
        dcomplex* y, const int* incy );

void EL_BLAS(ssyr)
( const char* uplo, const int* m,
  const float* alpha, const float* x, const int* incx,
                            float* A, const int* lda  );
void EL_BLAS(dsyr)
( const char* uplo, const int* m,
  const double* alpha, const double* x, const int* incx,
                             double* A, const int* lda  );
// 'csyr' is an auxilliary LAPACK routine, but we will treat it as BLAS
void EL_LAPACK(csyr)
( const char* uplo, const int* m,
  const scomplex* alpha,
  const scomplex* x, const int* incx,
        scomplex* A, const int* lda  );
// 'zsyr' is an auxilliary LAPACK routine, but we will treat it as BLAS
void EL_LAPACK(zsyr)
( const char* uplo, const int* m,
  const dcomplex* alpha,
  const dcomplex* x, const int* incx,
        dcomplex* A, const int* lda  );

void EL_BLAS(ssyr2)
( const char* uplo, const int* m,
  const float* alpha, const float* x, const int* incx,
                      const float* y, const int* incy,
                            float* A, const int* lda  );
void EL_BLAS(dsyr2)
( const char* uplo, const int* m,
  const double* alpha, const double* x, const int* incx,
                       const double* y, const int* incy,
                             double* A, const int* lda  );

void EL_BLAS(strmv)
( const char* uplo, const char* trans, const char* diag, const int* m,
  const float* A, const int* lda, float* x, const int* incx );
void EL_BLAS(dtrmv)
( const char* uplo, const char* trans, const char* diag, const int* m,
  const double* A, const int* lda, double* x, const int* incx );
void EL_BLAS(ctrmv)
( const char* uplo, const char* trans, const char* diag, const int* m,
  const scomplex* A, const int* lda,
        scomplex* x, const int* incx );
void EL_BLAS(ztrmv)
( const char* uplo, const char* trans, const char* diag, const int* m,
  const dcomplex* A, const int* lda,
        dcomplex* x, const int* incx );

void EL_BLAS(strsv)
( const char* uplo, const char* trans, const char* diag, const int* m,
  const float* A, const int* lda, float* x, const int* incx );
void EL_BLAS(dtrsv)
( const char* uplo, const char* trans, const char* diag, const int* m,
  const double* A, const int* lda, double* x, const int* incx );
void EL_BLAS(ctrsv)
( const char* uplo, const char* trans, const char* diag, const int* m,
  const scomplex* A, const int* lda,
        scomplex* x, const int* incx );
void EL_BLAS(ztrsv)
( const char* uplo, const char* trans, const char* diag, const int* m,
  const dcomplex* A, const int* lda,
        dcomplex* x, const int* incx );

// Level 3 BLAS 
// ============
void EL_BLAS(sgemm)
( const char* transA, const char* transB,
  const int* m, const int* n, const int* k,
  const float* alpha, const float* A, const int* lda,
                      const float* B, const int* ldb,
  const float* beta,        float* C, const int* ldc );
void EL_BLAS(dgemm)
( const char* transA, const char* transB,
  const int* m, const int* n, const int* k,
  const double* alpha, const double* A, const int* lda,
                       const double* B, const int* ldb,
  const double* beta,        double* C, const int* ldc );
void EL_BLAS(cgemm)
( const char* transA, const char* transB,
  const int* m, const int* n, const int* k,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
  const scomplex* B, const int* ldb,
  const scomplex* beta,
        scomplex* C, const int* ldc );
void EL_BLAS(zgemm)
( const char* transA, const char* transB,
  const int* m, const int* n, const int* k,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
  const dcomplex* B, const int* ldb,
  const dcomplex* beta,
        dcomplex* C, const int* ldc );

void EL_BLAS(chemm)
( const char* side, const char* uplo,
  const int* m, const int* n,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
  const scomplex* B, const int* ldb,
  const scomplex* beta,
        scomplex* C, const int* ldc );
void EL_BLAS(zhemm)
( const char* side, const char* uplo,
  const int* m, const int* n,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
  const dcomplex* B, const int* ldb,
  const dcomplex* beta,
        dcomplex* C, const int* ldc );

void EL_BLAS(cher2k)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
  const scomplex* B, const int* ldb,
  const float* beta,
        scomplex* C, const int* ldc );
void EL_BLAS(zher2k)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
  const dcomplex* B, const int* ldb,
  const double* beta,
        dcomplex* C, const int* ldc );

void EL_BLAS(cherk)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const float* alpha,
  const scomplex* A, const int* lda,
  const float* beta,
        scomplex* C, const int* ldc );
void EL_BLAS(zherk)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const double* alpha,
  const dcomplex* A, const int* lda,
  const double* beta,
        dcomplex* C, const int* ldc );

void EL_BLAS(ssymm)
( const char* side, const char* uplo,
  const int* m, const int* n,
  const float* alpha, const float* A, const int* lda,
                      const float* B, const int* ldb,
  const float* beta,        float* C, const int* ldc );
void EL_BLAS(dsymm)
( const char* side, const char* uplo,
  const int* m, const int* n,
  const double* alpha, const double* A, const int* lda,
                       const double* B, const int* ldb,
  const double* beta,        double* C, const int* ldc );
void EL_BLAS(csymm)
( const char* side, const char* uplo,
  const int* m, const int* n,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
  const scomplex* B, const int* ldb,
  const scomplex* beta,
        scomplex* C, const int* ldc );
void EL_BLAS(zsymm)
( const char* side, const char* uplo,
  const int* m, const int* n,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
  const dcomplex* B, const int* ldb,
  const dcomplex* beta,
        dcomplex* C, const int* ldc );

void EL_BLAS(ssyr2k)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const float* alpha, const float* A, const int* lda,
                      const float* B, const int* ldb,
  const float* beta,        float* C, const int* ldc );
void EL_BLAS(dsyr2k)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const double* alpha, const double* A, const int* lda,
                       const double* B, const int* ldb,
  const double* beta,        double* C, const int* ldc );
void EL_BLAS(csyr2k)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
  const scomplex* B, const int* ldb,
  const scomplex* beta,
        scomplex* C, const int* ldc );
void EL_BLAS(zsyr2k)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
  const dcomplex* B, const int* ldb,
  const dcomplex* beta,
        dcomplex* C, const int* ldc );

void EL_BLAS(ssyrk)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const float* alpha, const float* A, const int* lda,
  const float* beta,        float* C, const int* ldc );
void EL_BLAS(dsyrk)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const double* alpha, const double* A, const int* lda,
  const double* beta,        double* C, const int* ldc );
void EL_BLAS(csyrk)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
  const scomplex* beta,
        scomplex* C, const int* ldc );
void EL_BLAS(zsyrk)
( const char* uplo, const char* trans,
  const int* n, const int* k,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
  const dcomplex* beta,
        dcomplex* C, const int* ldc );

void EL_BLAS(strmm)
( const char* side, const char* uplo, const char* trans, const char* diag,
  const int* m, const int* n,
  const float* alpha, const float* A, const int* lda,
                            float* B, const int* ldb );
void EL_BLAS(dtrmm)
( const char* side, const char* uplo, const char* trans, const char* diag,
  const int* m, const int* n,
  const double* alpha, const double* A, const int* lda,
                             double* B, const int* ldb );
void EL_BLAS(ctrmm)
( const char* side, const char* uplo, const char* trans, const char* diag,
  const int* m, const int* n,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
        scomplex* B, const int* ldb );
void EL_BLAS(ztrmm)
( const char* side, const char* uplo, const char* trans, const char* diag,
  const int* m, const int* n,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
        dcomplex* B, const int* ldb );

void EL_BLAS(strsm)
( const char* side, const char* uplo, const char* transA, const char* diag,
  const int* m, const int* n,
  const float* alpha, const float* A, const int* lda,
                            float* B, const int* ldb );
void EL_BLAS(dtrsm)
( const char* side, const char* uplo, const char* transA, const char* diag,
  const int* m, const int* n,
  const double* alpha, const double* A, const int* lda,
                             double* B, const int* ldb );
void EL_BLAS(ctrsm)
( const char* side, const char* uplo, const char* transA, const char* diag,
  const int* m, const int* n,
  const scomplex* alpha,
  const scomplex* A, const int* lda,
        scomplex* B, const int* ldb );
void EL_BLAS(ztrsm)
( const char* side, const char* uplo, const char* transA, const char* diag,
  const int* m, const int* n,
  const dcomplex* alpha,
  const dcomplex* A, const int* lda,
        dcomplex* B, const int* ldb );

} // extern "C"

namespace El {
namespace blas {

// Level 1 BLAS
// ============
template<typename T>
void Axpy( int n, T alpha, const T* x, int incx, T* y, int incy )
{
    for( int i=0; i<n; ++i )
        y[i*incy] += alpha*x[i*incx];
}
template void Axpy
( int n, Int alpha, const Int* x, int incx, Int* y, int incy );
#ifdef EL_HAVE_QUAD
template void Axpy
( int n, Quad alpha, 
  const Quad* x, int incx, Quad* y, int incy );
template void Axpy
( int n, Complex<Quad> alpha, 
  const Complex<Quad>* x, int incx, Complex<Quad>* y, int incy );
#endif

void Axpy
( int n, float alpha, const float* x, int incx, float* y, int incy )
{ EL_BLAS(saxpy)( &n, &alpha, x, &incx, y, &incy ); }
void Axpy
( int n, double alpha, const double* x, int incx, double* y, int incy )
{ EL_BLAS(daxpy)( &n, &alpha, x, &incx, y, &incy ); }
void Axpy
( int n, scomplex alpha, const scomplex* x, int incx, scomplex* y, int incy )
{ EL_BLAS(caxpy)( &n, &alpha, x, &incx, y, &incy ); }
void Axpy
( int n, dcomplex alpha, const dcomplex* x, int incx, dcomplex* y, int incy )
{ EL_BLAS(zaxpy)( &n, &alpha, x, &incx, y, &incy ); }

template<typename T>
void Copy( int n, const T* x, int incx, T* y, int incy )
{
    for( int i=0; i<n; ++i )
        y[i*incy] = x[i*incx];
}
template void Copy( int n, const Int* x, int incx, Int* y, int incy );
#ifdef EL_HAVE_QUAD
template void Copy
( int n, const Quad* x, int incx, Quad* y, int incy );
template void Copy
( int n, const Complex<Quad>* x, int incx, Complex<Quad>* y, int incy );
#endif

void Copy( int n, const float* x, int incx, float* y, int incy )
{ EL_BLAS(scopy)( &n, x, &incx, y, &incy ); }
void Copy( int n, const double* x, int incx, double* y, int incy )
{ EL_BLAS(dcopy)( &n, x, &incx, y, &incy ); }
void Copy( int n, const scomplex* x, int incx, scomplex* y, int incy )
{ EL_BLAS(ccopy)( &n, x, &incx, y, &incy ); }
void Copy( int n, const dcomplex* x, int incx, dcomplex* y, int incy )
{ EL_BLAS(zcopy)( &n, x, &incx, y, &incy ); }

template<typename T>
T Dot( int n, const T* x, int incx, const T* y, int incy )
{
    T alpha = 0;
    for( int i=0; i<n; ++i )
        alpha += Conj(x[i*incx])*y[i*incy];
    return alpha;
}
template Int Dot( int n, const Int* x, int incx, const Int* y, int incy );
#ifdef EL_HAVE_QUAD
template Quad Dot( int n, const Quad* x, int incx, const Quad* y, int incy );
template Complex<Quad> Dot
( int n, const Complex<Quad>* x, int incx, const Complex<Quad>* y, int incy );
#endif

float Dot( int n, const float* x, int incx, const float* y, int incy )
{ return EL_BLAS(sdot)( &n, x, &incx, y, &incy ); }
double Dot( int n, const double* x, int incx, const double* y, int incy )
{ return EL_BLAS(ddot)( &n, x, &incx, y, &incy ); }
scomplex Dot( int n, const scomplex* x, int incx, const scomplex* y, int incy )
{ 
    scomplex alpha = 0;
    for( int i=0; i<n; ++i ) 
        alpha += Conj(x[i*incx])*y[i*incy];
    return alpha;
}
dcomplex Dot( int n, const dcomplex* x, int incx, const dcomplex* y, int incy )
{
    dcomplex alpha = 0;
    for( int i=0; i<n; ++i ) 
        alpha += Conj(x[i*incx])*y[i*incy];
    return alpha;
}

template<typename T>
T Dotu( int n, const T* x, int incx, const T* y, int incy )
{
    T alpha = 0;
    for( int i=0; i<n; ++i )
        alpha += x[i*incx]*y[i*incy];
    return alpha;
}
template Int Dotu( int n, const Int* x, int incx, const Int* y, int incy );
#ifdef EL_HAVE_QUAD
template Quad Dotu( int n, const Quad* x, int incx, const Quad* y, int incy );
template Complex<Quad> Dotu
( int n, const Complex<Quad>* x, int incx, const Complex<Quad>* y, int incy );
#endif

float Dotu( int n, const float* x, int incx, const float* y, int incy )
{ return EL_BLAS(sdot)( &n, x, &incx, y, &incy ); }
double Dotu( int n, const double* x, int incx, const double* y, int incy )
{ return EL_BLAS(ddot)( &n, x, &incx, y, &incy ); }
scomplex Dotu( int n, const scomplex* x, int incx, const scomplex* y, int incy )
{
    scomplex alpha = 0;
    for( int i=0; i<n; ++i ) 
        alpha += x[i*incx]*y[i*incy];
    return alpha;
}
dcomplex Dotu( int n, const dcomplex* x, int incx, const dcomplex* y, int incy )
{
    dcomplex alpha = 0;
    for( int i=0; i<n; ++i ) 
        alpha += x[i*incx]*y[i*incy];
    return alpha;
}

template<typename F>
Base<F> Nrm2( int n, const F* x, int incx )
{
    typedef Base<F> Real;
    Real scale = 0; 
    Real scaledSquare = 1;
    for( int i=0; i<n; ++i )
        UpdateScaledSquare( x[i*incx], scale, scaledSquare );
    return scale*Sqrt(scaledSquare);
}
#ifdef EL_HAVE_QUAD
template Quad Nrm2( int n, const Quad* x, int incx );
template Quad Nrm2( int n, const Complex<Quad>* x, int incx );
#endif

float Nrm2( int n, const float* x, int incx )
{ return EL_BLAS(snrm2)( &n, x, &incx ); }
double Nrm2( int n, const double* x, int incx )
{ return EL_BLAS(dnrm2)( &n, x, &incx ); }
float Nrm2( int n, const scomplex* x, int incx )
{ return EL_BLAS(scnrm2)( &n, x, &incx ); }
double Nrm2( int n, const dcomplex* x, int incx )
{ return EL_BLAS(dznrm2)( &n, x, &incx ); }

float Givens
( float alpha, float beta, float* c, float* s )
{ EL_BLAS(srotg)( &alpha, &beta, c, s ); return alpha; }
double Givens
( double alpha, double beta, double* c, double* s )
{ EL_BLAS(drotg)( &alpha, &beta, c, s ); return alpha; }
scomplex Givens
( scomplex alpha, scomplex beta, float* c, scomplex* s )
{ EL_BLAS(crotg)( &alpha, &beta, c, s ); return alpha; }
dcomplex Givens
( dcomplex alpha, dcomplex beta, double* c, dcomplex* s )
{ EL_BLAS(zrotg)( &alpha, &beta, c, s ); return alpha; }

void Rot
( int n, float* x, int incx, float* y, int incy, float c, float s )
{ EL_BLAS(srot)( &n, x, &incx, y, &incy, &c, &s ); }
void Rot
( int n, double* x, int incx, double* y, int incy, double c, double s )
{ EL_BLAS(drot)( &n, x, &incx, y, &incy, &c, &s ); }
void Rot
( int n, scomplex* x, int incx, scomplex* y, int incy, float c, scomplex s )
{ EL_BLAS(crot)( &n, x, &incx, y, &incy, &c, &s ); }
void Rot
( int n, dcomplex* x, int incx, dcomplex* y, int incy, double c, dcomplex s )
{ EL_BLAS(zrot)( &n, x, &incx, y, &incy, &c, &s ); }

template<typename T>
void Scal( int n, T alpha, T* x, int incx )
{
    for( int j=0; j<n; ++j )
        x[j*incx] *= alpha;
}
template<typename T>
void Scal( int n, Base<T> alpha, T* x, int incx )
{
    for( int j=0; j<n; ++j )
        x[j*incx] *= alpha;
}
template void Scal( int n, int alpha, int* x, int incx );
#ifdef EL_HAVE_QUAD
template void Scal( int n, Quad alpha, Quad* x, int incx );
template void Scal( int n, Complex<Quad> alpha, Complex<Quad>* x, int incx );
#endif
template void Scal( int n, float alpha, Complex<float>* x, int incx );
template void Scal( int n, double alpha, Complex<double>* x, int incx );
#ifdef EL_HAVE_QUAD
template void Scal( int n, Quad alpha, Complex<Quad>* x, int incx );
#endif

void Scal( int n, float alpha, float* x, int incx )
{ EL_BLAS(sscal)( &n, &alpha, x, &incx ); }
void Scal( int n, double alpha, double* x, int incx )
{ EL_BLAS(dscal)( &n, &alpha, x, &incx ); }
void Scal( int n, scomplex alpha, scomplex* x, int incx )
{ EL_BLAS(cscal)( &n, &alpha, x, &incx ); }
void Scal( int n, dcomplex alpha, dcomplex* x, int incx )
{ EL_BLAS(zscal)( &n, &alpha, x, &incx ); }

// NOTE: 'nrm1' is not the official name but is consistent with 'nrm2'
float Nrm1( int n, const float* x, int incx )
{ return EL_BLAS(sasum)( &n, x, &incx ); }
double Nrm1( int n, const double* x, int incx )
{ return EL_BLAS(dasum)( &n, x, &incx ); }
float Nrm1( int n, const scomplex* x, int incx )
{ return EL_LAPACK(scsum1)( &n, x, &incx ); }
double Nrm1( int n, const dcomplex* x, int incx )
{ return EL_LAPACK(dzsum1)( &n, x, &incx ); }

template<typename T>
void Swap( int n, T* x, int incx, T* y, int incy )
{
    for( int i=0; i<n; ++i )
    {
        const T temp = x[i*incx];
        x[i*incx] = y[i*incy];
        y[i*incy] = temp;
    }
}
template void Swap( int n, Int* x, int incx, Int* y, int incy );
#ifdef EL_HAVE_QUAD
template void Swap( int n, Quad* x, int incx, Quad* y, int incy );
template void Swap
( int n, Complex<Quad>* x, int incx, Complex<Quad>* y, int incy );
#endif

void Swap( int n, float* x, int incx, float* y, int incy )
{ EL_BLAS(sswap)( &n, x, &incx, y, &incy ); }
void Swap( int n, double* x, int incx, double* y, int incy )
{ EL_BLAS(dswap)( &n, x, &incx, y, &incy ); }
void Swap( int n, scomplex* x, int incx, scomplex* y, int incy )
{ EL_BLAS(cswap)( &n, x, &incx, y, &incy ); }
void Swap( int n, dcomplex* x, int incx, dcomplex* y, int incy )
{ EL_BLAS(zswap)( &n, x, &incx, y, &incy ); }

// Level 2 BLAS
// ============
template<typename T>
void Gemv
( char trans, int m, int n,
  T alpha, const T* A, int lda, const T* x, int incx,
  T beta,        T* y, int incy )
{
    if( trans == 'N' )
    {
        if( m > 0 && n == 0 && beta == T(0) )
        {
            for( int i=0; i<m; ++i )
                y[i*incy] = 0;
            return;
        }
        Scal( m, beta, y, incy );
        for( int i=0; i<m; ++i )
            for( int j=0; j<n; ++j )
                y[i*incy] += alpha*A[i+j*lda]*x[j*incx];
    }
    else if( trans == 'T' )
    {
        if( n > 0 && m == 0 && beta == T(0) )
        {
            for( int i=0; i<n; ++i )
                y[i*incy] = 0;
            return;
        }
        Scal( n, beta, y, incy );
        for( int i=0; i<n; ++i )
            for( int j=0; j<m; ++j )
                y[i*incy] += alpha*A[j+i*lda]*x[j*incx];
    }
    else
    {
        if( n > 0 && m == 0 && beta == T(0) )
        {
            for( int i=0; i<n; ++i )
                y[i*incy] = 0;
            return;
        }
        Scal( n, beta, y, incy );
        for( int i=0; i<n; ++i )
            for( int j=0; j<m; ++j )
                y[i*incy] += alpha*Conj(A[j+i*lda])*x[j*incx];
    }
}
template void Gemv
( char trans, int m, int n, 
  Int alpha, const Int* A, int lda, const Int* x, int incx, 
  Int beta, Int* y, int incy );
#ifdef EL_HAVE_QUAD
template void Gemv
( char trans, int m, int n, 
  Quad alpha, const Quad* A, int lda, const Quad* x, int incx, 
  Quad beta, Quad* y, int incy );
template void Gemv
( char trans, int m, int n, 
  Complex<Quad> alpha, const Complex<Quad>* A, int lda, 
                       const Complex<Quad>* x, int incx, 
  Complex<Quad> beta,        Complex<Quad>* y, int incy );
#endif

void Gemv
( char trans, int m, int n,
  float alpha, const float* A, int lda, const float* x, int incx,
  float beta,        float* y, int incy )
{
    const char fixedTrans = ( trans == 'C' ? 'T' : trans );
    EL_BLAS(sgemv)
    ( &fixedTrans, &m, &n, &alpha, A, &lda, x, &incx, &beta, y, &incy );
}

void Gemv
( char trans, int m, int n,
  double alpha, const double* A, int lda, const double* x, int incx,
  double beta,        double* y, int incy )
{
    const char fixedTrans = ( trans == 'C' ? 'T' : trans );
    EL_BLAS(dgemv)
    ( &fixedTrans, &m, &n, &alpha, A, &lda, x, &incx, &beta, y, &incy );
}

void Gemv
( char trans, int m, int n,
  scomplex alpha, const scomplex* A, int lda, const scomplex* x, int incx,
  scomplex beta,        scomplex* y, int incy )
{ EL_BLAS(cgemv)
  ( &trans, &m, &n, &alpha, A, &lda, x, &incx, &beta, y, &incy ); }

void Gemv
( char trans, int m, int n,
  dcomplex alpha, const dcomplex* A, int lda, const dcomplex* x, int incx,
  dcomplex beta,        dcomplex* y, int incy )
{ EL_BLAS(zgemv)
  ( &trans, &m, &n, &alpha, A, &lda, x, &incx, &beta, y, &incy ); }

template<typename T>
void Ger
( int m, int n,
  T alpha, const T* x, int incx, const T* y, int incy,
                                       T* A, int lda )
{
    for( int j=0; j<n; ++j )
        for( int i=0; i<m; ++i )
            A[i+j*lda] += alpha*x[i*incx]*Conj(y[j*incy]);
}
template void Ger
( int m, int n, 
  Int alpha, const Int* x, int incx, const Int* y, int incy, 
                   Int* A, int lda );
#ifdef EL_HAVE_QUAD
template void Ger
( int m, int n, 
  Quad alpha, const Quad* x, int incx, const Quad* y, int incy, 
                    Quad* A, int lda );
template void Ger
( int m, int n, 
  Complex<Quad> alpha, const Complex<Quad>* x, int incx, 
                       const Complex<Quad>* y, int incy, 
                             Complex<Quad>* A, int lda );
#endif

void Ger
( int m, int n,
  float alpha, const float* x, int incx, const float* y, int incy,
                     float* A, int lda )
{ EL_BLAS(sger)( &m, &n, &alpha, x, &incx, y, &incy, A, &lda ); }

void Ger
( int m, int n,
  double alpha, const double* x, int incx, const double* y, int incy,
                      double* A, int lda  )
{ EL_BLAS(dger)( &m, &n, &alpha, x, &incx, y, &incy, A, &lda ); }

void Ger
( int m, int n,
  scomplex alpha, const scomplex* x, int incx, const scomplex* y, int incy,
                        scomplex* A, int lda )
{ EL_BLAS(cgerc)( &m, &n, &alpha, x, &incx, y, &incy, A, &lda ); }

void Ger
( int m, int n,
  dcomplex alpha, const dcomplex* x, int incx, const dcomplex* y, int incy,
                        dcomplex* A, int lda )
{ EL_BLAS(zgerc)( &m, &n, &alpha, x, &incx, y, &incy, A, &lda ); }

template<typename T>
void Geru
( int m, int n,
  T alpha, const T* x, int incx, const T* y, int incy,
                                       T* A, int lda )
{
    for( int j=0; j<n; ++j )
        for( int i=0; i<m; ++i )
            A[i+j*lda] += alpha*x[i*incx]*y[j*incy];
}
template void Geru
( int m, int n, 
  Int alpha, const Int* x, int incx, const Int* y, int incy, 
                   Int* A, int lda );
#ifdef EL_HAVE_QUAD
template void Geru
( int m, int n, 
  Quad alpha, const Quad* x, int incx, const Quad* y, int incy, 
                    Quad* A, int lda );
template void Geru
( int m, int n, 
  Complex<Quad> alpha, const Complex<Quad>* x, int incx, 
                       const Complex<Quad>* y, int incy, 
                             Complex<Quad>* A, int lda );
#endif

void Geru
( int m, int n,
  float alpha, const float* x, int incx, const float* y, int incy,
                     float* A, int lda )
{ EL_BLAS(sger)( &m, &n, &alpha, x, &incx, y, &incy, A, &lda ); }

void Geru
( int m, int n,
  double alpha, const double* x, int incx, const double* y, int incy,
                      double* A, int lda )
{ EL_BLAS(dger)( &m, &n, &alpha, x, &incx, y, &incy, A, &lda ); }

void Geru
( int m, int n,
  scomplex alpha, const scomplex* x, int incx, const scomplex* y, int incy,
                        scomplex* A, int lda )
{ EL_BLAS(cgeru)( &m, &n, &alpha, x, &incx, y, &incy, A, &lda ); }

void Geru
( int m, int n,
  dcomplex alpha, const dcomplex* x, int incx, const dcomplex* y, int incy,
                        dcomplex* A, int lda )
{ EL_BLAS(zgeru)( &m, &n, &alpha, x, &incx, y, &incy, A, &lda ); }

// TODO: Introduce some sort of blocking
template<typename T>
void Hemv
( char uplo, int m,
  T alpha, const T* A, int lda, const T* x, int incx,
  T beta,        T* y, int incy )
{
    // y := beta*y
    if( beta == T(0) )
    {
        for( int i=0; i<m; ++i )
            y[i*incy] = 0;
    }
    else if( beta != T(1) )
    {
        for( int i=0; i<m; ++i )
            y[i*incy] *= beta;
    }

    if( uplo == LOWER )
    {
        // Multiply with the lower triangle
        for( int j=0; j<m; ++j )
            for( int i=j; i<m; ++i )
                y[i*incy] += alpha*A[i+j*lda]*x[j*incx];

        // Multiply with the adjoint of the strictly lower triangle
        for( int j=0; j<m; ++j ) 
            for( int i=j+1; i<m; ++i )
                y[j*incy] += alpha*Conj(A[i+j*lda])*x[i*incx];
    }
    else
    {
        // Multiply with the upper triangle
        for( int j=0; j<m; ++j )
            for( int i=0; i<=j; ++i )
                y[i*incy] += alpha*A[i+j*lda]*x[j*incx];

        // Multiply with the adjoint of the strictly upper triangle
        for( int j=0; j<m; ++j ) 
            for( int i=0; i<j; ++i )
                y[j*incy] += alpha*Conj(A[i+j*lda])*x[i*incx];
    }
}

template void Hemv
( char uplo, int m, 
  Int alpha, const Int* A, int lda, const Int* x, int incx, 
  Int beta,                               Int* y, int incy );
#ifdef EL_HAVE_QUAD
template void Hemv
( char uplo, int m, 
  Quad alpha, const Quad* A, int lda, const Quad* x, int incx, 
  Quad beta,                                Quad* y, int incy );
template void Hemv
( char uplo, int m, 
  Complex<Quad> alpha, const Complex<Quad>* A, int lda, 
                       const Complex<Quad>* x, int incx, 
  Complex<Quad> beta,        Complex<Quad>* y, int incy );
#endif

void Hemv
( char uplo, int m,
  float alpha, const float* A, int lda, const float* x, int incx,
  float beta,        float* y, int incy )
{ EL_BLAS(ssymv)( &uplo, &m, &alpha, A, &lda, x, &incx, &beta, y, &incy ); }

void Hemv
( char uplo, int m,
  double alpha, const double* A, int lda, const double* x, int incx,
  double beta,        double* y, int incy )
{ EL_BLAS(dsymv)( &uplo, &m, &alpha, A, &lda, x, &incx, &beta, y, &incy ); }

void Hemv
( char uplo, int m,
  scomplex alpha, const scomplex* A, int lda, const scomplex* x, int incx,
  scomplex beta,        scomplex* y, int incy )
{ EL_BLAS(chemv)( &uplo, &m, &alpha, A, &lda, x, &incx, &beta, y, &incy ); }

void Hemv
( char uplo, int m,
  dcomplex alpha, const dcomplex* A, int lda, const dcomplex* x, int incx,
  dcomplex beta,        dcomplex* y, int incy )
{ EL_BLAS(zhemv)( &uplo, &m, &alpha, A, &lda, x, &incx, &beta, y, &incy ); }

template<typename T>
void Her
( char uplo, int m, Base<T> alpha, const T* x, int incx, T* A, int lda )
{
    if( uplo == 'L' )
    {
        for( int j=0; j<m; ++j )
            for( int i=j; i<m; ++i )
                A[i+j*lda] += alpha*x[i*incx]*Conj(x[j*incx]);
    }
    else
    {
        for( int j=0; j<m; ++j )
            for( int i=0; i<=j; ++i )
                A[i+j*lda] += alpha*x[i*incx]*Conj(x[j*incx]);
    }
}
template void Her
( char uplo, int m, Int alpha, const Int* x, int incx, Int* A, int lda );
#ifdef EL_HAVE_QUAD
template void Her
( char uplo, int m, 
  Quad alpha, const Quad* x, int incx, Quad* A, int lda );
template void Her
( char uplo, int m, 
  Quad alpha, const Complex<Quad>* x, int incx, Complex<Quad>* A, int lda );
#endif

void Her
( char uplo, int m,
  float alpha, const float* x, int incx, float* A, int lda )
{ EL_BLAS(ssyr)( &uplo, &m, &alpha, x, &incx, A, &lda ); }

void Her
( char uplo, int m,
  double alpha, const double* x, int incx, double* A, int lda )
{ EL_BLAS(dsyr)( &uplo, &m, &alpha, x, &incx, A, &lda ); }

void Her
( char uplo, int m,
  float alpha, const scomplex* x, int incx, scomplex* A, int lda )
{ EL_BLAS(cher)( &uplo, &m, &alpha, x, &incx, A, &lda ); }

void Her
( char uplo, int m,
  double alpha, const dcomplex* x, int incx, dcomplex* A, int lda )
{ EL_BLAS(zher)( &uplo, &m, &alpha, x, &incx, A, &lda ); }

template<typename T>
void Her2
( char uplo, int m, 
  T alpha, const T* x, int incx, const T* y, int incy,
                 T* A, int lda )
{
    if( uplo == 'L' )
    {
        for( int j=0; j<m; ++j )
            for( int i=j; i<m; ++i )
                A[i+j*lda] += alpha*      x[i*incx]*Conj(y[j*incy]) + 
                              Conj(alpha)*y[i*incy]*Conj(x[j*incx]);
    }
    else
    {
        for( int j=0; j<m; ++j )
            for( int i=0; i<=j; ++i )
                A[i+j*lda] += alpha*      x[i*incx]*Conj(y[j*incy]) + 
                              Conj(alpha)*y[i*incy]*Conj(x[j*incx]);
    }
}
template void Her2
( char uplo, int m, 
  Int alpha, const Int* x, int incx, const Int* y, int incy, 
                   Int* A, int lda );
#ifdef EL_HAVE_QUAD
template void Her2
( char uplo, int m, 
  Quad alpha, const Quad* x, int incx, 
              const Quad* y, int incy, 
                    Quad* A, int lda );
template void Her2
( char uplo, int m, 
  Complex<Quad> alpha, const Complex<Quad>* x, int incx, 
                       const Complex<Quad>* y, int incy, 
                             Complex<Quad>* A, int lda );
#endif

void Her2
( char uplo, int m,
  float alpha, const float* x, int incx, const float* y, int incy,
                     float* A, int lda )
{ EL_BLAS(ssyr2)( &uplo, &m, &alpha, x, &incx, y, &incy, A, &lda ); }

void Her2
( char uplo, int m,
  double alpha, const double* x, int incx, const double* y, int incy,
                      double* A, int lda )
{ EL_BLAS(dsyr2)( &uplo, &m, &alpha, x, &incx, y, &incy, A, &lda ); }

void Her2
( char uplo, int m,
  scomplex alpha, const scomplex* x, int incx, const scomplex* y, int incy,
                        scomplex* A, int lda )
{ EL_BLAS(cher2)( &uplo, &m, &alpha, x, &incx, y, &incy, A, &lda ); }

void Her2
( char uplo, int m,
  dcomplex alpha, const dcomplex* x, int incx, const dcomplex* y, int incy,
                        dcomplex* A, int lda )
{ EL_BLAS(zher2)( &uplo, &m, &alpha, x, &incx, y, &incy, A, &lda ); }

// TODO: Introduce some sort of blocking
template<typename T>
void Symv
( char uplo, int m,
  T alpha, const T* A, int lda, const T* x, int incx,
  T beta,        T* y, int incy )
{
    // y := beta*y
    if( beta == T(0) )
    {
        for( int i=0; i<m; ++i )
            y[i*incy] = 0;
    }
    else if( beta != T(1) )
    {
        for( int i=0; i<m; ++i )
            y[i*incy] *= beta;
    }

    if( uplo == LOWER )
    {
        // Multiply with the lower triangle
        for( int j=0; j<m; ++j )
            for( int i=j; i<m; ++i )
                y[i*incy] += alpha*A[i+j*lda]*x[j*incx];

        // Multiply with the transpose of the strictly lower triangle
        for( int j=0; j<m; ++j ) 
            for( int i=j+1; i<m; ++i )
                y[j*incy] += alpha*A[i+j*lda]*x[i*incx];
    }
    else
    {
        // Multiply with the upper triangle
        for( int j=0; j<m; ++j )
            for( int i=0; i<=j; ++i )
                y[i*incy] += alpha*A[i+j*lda]*x[j*incx];

        // Multiply with the transpose of the strictly upper triangle
        for( int j=0; j<m; ++j ) 
            for( int i=0; i<j; ++i )
                y[j*incy] += alpha*A[i+j*lda]*x[i*incx];
    }
}

template void Symv
( char uplo, int m, 
  Int alpha, const Int* A, int lda, const Int* x, int incx, 
  Int beta,                               Int* y, int incy );
#ifdef EL_HAVE_QUAD
template void Symv
( char uplo, int m, 
  Quad alpha, const Quad* A, int lda, const Quad* x, int incx, 
  Quad beta,                                Quad* y, int incy );
template void Symv
( char uplo, int m, 
  Complex<Quad> alpha, const Complex<Quad>* A, int lda, 
                       const Complex<Quad>* x, int incx, 
  Complex<Quad> beta,        Complex<Quad>* y, int incy );
#endif

void Symv
( char uplo, int m,
  float alpha, const float* A, int lda, const float* x, int incx,
  float beta,        float* y, int incy )
{ EL_BLAS(ssymv)( &uplo, &m, &alpha, A, &lda, x, &incx, &beta, y, &incy ); }

void Symv
( char uplo, int m,
  double alpha, const double* A, int lda, const double* x, int incx,
  double beta,        double* y, int incy )
{ EL_BLAS(dsymv)( &uplo, &m, &alpha, A, &lda, x, &incx, &beta, y, &incy ); }

void Symv
( char uplo, int m,
  scomplex alpha, const scomplex* A, int lda, const scomplex* x, int incx,
  scomplex beta,        scomplex* y, int incy )
{
    // Recall that 'csymv' is an LAPACK auxiliary routine
    EL_LAPACK(csymv)( &uplo, &m, &alpha, A, &lda, x, &incx, &beta, y, &incy );
}

void Symv
( char uplo, int m,
  dcomplex alpha, const dcomplex* A, int lda, const dcomplex* x, int incx,
  dcomplex beta,        dcomplex* y, int incy )
{
    // Recall that 'zsymv' is an LAPACK auxiliary routine
    EL_LAPACK(zsymv)( &uplo, &m, &alpha, A, &lda, x, &incx, &beta, y, &incy );
}

template<typename T>
void Syr
( char uplo, int m, T alpha, const T* x, int incx, T* A, int lda )
{
    if( uplo == 'L' )
    {
        for( int j=0; j<m; ++j )
            for( int i=j; i<m; ++i )
                A[i+j*lda] += alpha*x[i*incx]*x[j*incx];
    }
    else
    {
        for( int j=0; j<m; ++j )
            for( int i=0; i<=j; ++i )
                A[i+j*lda] += alpha*x[i*incx]*x[j*incx];
    }
}
template void Syr
( char uplo, int m, Int alpha, const Int* x, int incx, Int* A, int lda );
#ifdef EL_HAVE_QUAD
template void Syr
( char uplo, int m, 
  Quad alpha, const Quad* x, int incx, Quad* A, int lda );
template void Syr
( char uplo, int m, 
  Complex<Quad> alpha, const Complex<Quad>* x, int incx, 
                             Complex<Quad>* A, int lda );
#endif

void Syr
( char uplo, int m,
  float alpha, const float* x, int incx, float* A, int lda  )
{ EL_BLAS(ssyr)( &uplo, &m, &alpha, x, &incx, A, &lda ); }

void Syr
( char uplo, int m,
  double alpha, const double* x, int incx, double* A, int lda )
{ EL_BLAS(dsyr)( &uplo, &m, &alpha, x, &incx, A, &lda ); }

void Syr
( char uplo, int m,
  scomplex alpha, const scomplex* x, int incx, scomplex* A, int lda )
{
    // Recall that 'csyr' is an LAPACK auxiliary routine
    EL_LAPACK(csyr)( &uplo, &m, &alpha, x, &incx, A, &lda ); 
}

void Syr
( char uplo, int m,
  dcomplex alpha, const dcomplex* x, int incx, dcomplex* A, int lda )
{
    // Recall that 'zsyr' is an LAPACK auxiliary routine
    EL_LAPACK(zsyr)( &uplo, &m, &alpha, x, &incx, A, &lda ); 
}

template<typename T>
void Syr2
( char uplo, int m, 
  T alpha, const T* x, int incx, const T* y, int incy,
                 T* A, int lda )
{
    if( uplo == 'L' )
    {
        for( int j=0; j<m; ++j )
            for( int i=j; i<m; ++i )
                A[i+j*lda] += alpha*(x[i*incx]*y[j*incy]+y[i*incy]*x[j*incx]);
    }
    else
    {
        for( int j=0; j<m; ++j )
            for( int i=0; i<=j; ++i )
                A[i+j*lda] += alpha*(x[i*incx]*y[j*incy]+y[i*incy]*x[j*incx]);
    }
}
template void Syr2
( char uplo, int m, 
  Int alpha, const Int* x, int incx, const Int* y, int incy, 
                   Int* A, int lda );
#ifdef EL_HAVE_QUAD
template void Syr2
( char uplo, int m, 
  Quad alpha, const Quad* x, int incx, 
              const Quad* y, int incy, 
                    Quad* A, int lda );
template void Syr2
( char uplo, int m, 
  Complex<Quad> alpha, const Complex<Quad>* x, int incx, 
                       const Complex<Quad>* y, int incy, 
                             Complex<Quad>* A, int lda );
#endif

void Syr2
( char uplo, int m,
  float alpha, const float* x, int incx, const float* y, int incy,
                     float* A, int lda )
{ EL_BLAS(ssyr2)( &uplo, &m, &alpha, x, &incx, y, &incy, A, &lda ); }

void Syr2
( char uplo, int m,
  double alpha, const double* x, int incx, const double* y, int incy,
                      double* A, int lda )
{ EL_BLAS(dsyr2)( &uplo, &m, &alpha, x, &incx, y, &incy, A, &lda ); }

void Syr2
( char uplo, int m,
  scomplex alpha, const scomplex* x, int incx, const scomplex* y, int incy,
                        scomplex* A, int lda )
{
    // csyr2 doesn't exist, so we route through csyr2k. However, csyr2k expects 
    // contiguous access of 'x', so we treat x and y as a row vectors where 
    // their leading dimensions are 'incx' and 'incy'. Thus we must perform 
    // A += x' y + y' x
    const char trans = 'T';
    const int k = 1;
    const scomplex beta = 1.;
    EL_BLAS(csyr2k)
    ( &uplo, &trans, &m, &k, &alpha, x, &incx, y, &incy, &beta, A, &lda );
}

void Syr2
( char uplo, int m,
  dcomplex alpha, const dcomplex* x, int incx, const dcomplex* y, int incy,
                        dcomplex* A, int lda )
{
    // zsyr2 doesn't exist, so we route through zsyr2k. However, zsyr2k expects 
    // contiguous access of 'x', so we treat x and y as a row vectors where 
    // their leading dimensions are 'incx' and 'incy'. Thus we must perform 
    // A += x' y + y' x
    const char trans = 'T';
    const int k = 1;
    const dcomplex beta = 1.;
    EL_BLAS(zsyr2k)
    ( &uplo, &trans, &m, &k, &alpha, x, &incx, y, &incy, &beta, A, &lda );
}

// TODO: Verify correctness and introduce blocking
template<typename T>
void Trmv
( char uplo, char trans, char diag, int m,
  const T* A, int lda, T* x, int incx )
{
    const bool conj = ( trans == 'C' );
    if( uplo == LOWER )
    {
        if( trans == 'N' )
        {
            for( int j=m-1; j>=0; --j )
            {
                T gamma = x[j*incx]; 
                if( gamma != T(0) )
                {
                    for( int i=m-1; i>j; --i )
                        x[i*incx] += gamma*A[i+j*lda];
                    if( diag != 'N' )
                        x[j*incx] *= A[j+j*lda];
                }
            }
        }
        else
        {
            for( int j=0; j<m; ++j )
            {
                T gamma = x[j*incx]; 
                if( conj )
                {
                    if( diag != 'N' )
                        gamma *= Conj(A[j+j*lda]);
                    for( int i=j+1; i<m; ++i )
                        gamma += Conj(A[i+j*lda])*x[i*incx];
                }
                else
                {
                    if( diag != 'N' )
                        gamma *= A[j+j*lda];
                    for( int i=j+1; i<m; ++i )
                        gamma += A[i+j*lda]*x[i*incx];
                }
                x[j*incx] = gamma;
            }
        }
    }
    else
    {
        if( trans == 'N' )
        {
            for( int j=0; j<m; ++j )
            {
                T gamma = x[j*incx]; 
                if( gamma != T(0) )
                {
                    for( int i=0; i<j; ++i )
                        x[i*incx] += gamma*A[i+j*lda];
                    if( diag != 'N' )
                        x[j*incx] *= A[j+j*lda];
                }
            }
        }
        else
        {
            for( int j=m-1; j>=0; --j )
            {
                T gamma = x[j*incx]; 
                if( conj )
                {
                    if( diag != 'N' )
                        gamma *= Conj(A[j+j*lda]);
                    for( int i=j-1; i>=0; --i )
                        gamma += Conj(A[i+j*lda])*x[i*incx];
                }
                else
                {
                    if( diag != 'N' )
                        gamma *= A[j+j*lda];
                    for( int i=j-1; i>=0; --i )
                        gamma += A[i+j*lda]*x[i*incx];
                }
                x[j*incx] = gamma;
            }
        }
    }
}
template void Trmv
( char uplo, char trans, char diag, int m,
  const Int* A, int lda, Int* x, int incx );
#ifdef EL_HAVE_QUAD
template void Trmv
( char uplo, char trans, char diag, int m,
  const Quad* A, int lda, Quad* x, int incx );
template void Trmv
( char uplo, char trans, char diag, int m,
  const Complex<Quad>* A, int lda, Complex<Quad>* x, int incx );
#endif

void Trmv
( char uplo, char trans, char diag, int m,
  const float* A, int lda, float* x, int incx )
{ EL_BLAS(strmv)( &uplo, &trans, &diag, &m, A, &lda, x, &incx ); }

void Trmv
( char uplo, char trans, char diag, int m,
  const double* A, int lda, double* x, int incx )
{ EL_BLAS(dtrmv)( &uplo, &trans, &diag, &m, A, &lda, x, &incx ); }

void Trmv
( char uplo, char trans, char diag, int m,
  const scomplex* A, int lda, scomplex* x, int incx )
{ EL_BLAS(ctrmv)( &uplo, &trans, &diag, &m, A, &lda, x, &incx ); }

void Trmv
( char uplo, char trans, char diag, int m,
  const dcomplex* A, int lda, dcomplex* x, int incx )
{ EL_BLAS(ztrmv)( &uplo, &trans, &diag, &m, A, &lda, x, &incx ); }

template<typename F>
void Trsv
( char uplo, char trans, char diag, int m,
  const F* A, int lda, F* x, int incx )
{
    const bool conj = ( trans == 'C' );
    if( uplo == 'L' )
    {
        if( trans == 'N' )
        {
            for( int j=0; j<m; ++j )
            {
                if( diag == 'N' ) 
                    x[j*incx] /= A[j+j*lda];
                const F gamma = x[j*incx];
                for( int i=j+1; i<m; ++i )
                    x[i*incx] -= gamma*A[i+j*lda];
            }
        }
        else
        {
            for( int j=m-1; j>=0; --j )
            {
                if( conj )
                {
                    if( diag == 'N' )
                        x[j*incx] /= Conj(A[j+j*lda]);
                    const F gamma = x[j*incx];
                    for( int i=j-1; i>=0; --i )
                        x[i*incx] -= gamma*Conj(A[j+i*lda]);
                }
                else
                {
                    if( diag == 'N' )
                        x[j*incx] /= A[j+j*lda];
                    const F gamma = x[j*incx];
                    for( int i=j-1; i>=0; --i )
                        x[i*incx] -= gamma*A[j+i*lda];
                }
            }
        }
    }
    else
    {
        if( trans == 'N' )
        {
            for( int j=m-1; j>=0; --j )
            {
                if( diag == 'N' )
                    x[j*incx] /= A[j+j*lda];
                const F gamma = x[j*incx];
                for( int i=j-1; i>=0; --i )
                    x[i*incx] -= gamma*A[i+j*lda];
            }
        }
        else
        {
            for( int j=0; j<m; ++j )
            {
                if( conj )
                {
                    if( diag == 'N' ) 
                        x[j*incx] /= A[j+j*lda];
                    const F gamma = x[j*incx];
                    for( int i=j+1; i<m; ++i )
                        x[i*incx] -= gamma*A[j+i*lda];
                }
                else
                {
                    if( diag == 'N' ) 
                        x[j*incx] /= Conj(A[j+j*lda]);
                    const F gamma = x[j*incx];
                    for( int i=j+1; i<m; ++i )
                        x[i*incx] -= gamma*Conj(A[j+i*lda]);
                }
            }
        }
    }
}
#ifdef EL_HAVE_QUAD
template void Trsv
( char uplo, char trans, char diag, int m,
  const Quad* A, int lda, Quad* x, int incx );
template void Trsv
( char uplo, char trans, char diag, int m,
  const Complex<Quad>* A, int lda, Complex<Quad>* x, int incx );
#endif

void Trsv
( char uplo, char trans, char diag, int m,
  const float* A, int lda, float* x, int incx )
{ EL_BLAS(strsv)( &uplo, &trans, &diag, &m, A, &lda, x, &incx ); }

void Trsv
( char uplo, char trans, char diag, int m,
  const double* A, int lda, double* x, int incx )
{ EL_BLAS(dtrsv)( &uplo, &trans, &diag, &m, A, &lda, x, &incx ); }

void Trsv
( char uplo, char trans, char diag, int m,
  const scomplex* A, int lda, scomplex* x, int incx )
{ EL_BLAS(ctrsv)( &uplo, &trans, &diag, &m, A, &lda, x, &incx ); }

void Trsv
( char uplo, char trans, char diag, int m,
  const dcomplex* A, int lda, dcomplex* x, int incx )
{ EL_BLAS(ztrsv)( &uplo, &trans, &diag, &m, A, &lda, x, &incx ); }

// Level 3 BLAS
// ============
template<typename T>
void Gemm
( char transA, char transB, int m, int n, int k,
  T alpha, const T* A, int lda, const T* B, int ldb,
  T beta,        T* C, int ldc )
{
    if( m > 0 && n > 0 && k == 0 && beta == T(0) )
    {
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                C[i+j*ldc] = 0;
        return;
    }

    // Scale C
    if( beta != T(1) )
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                C[i+j*ldc] *= beta;

    // Naive implementation
    if( transA == 'N' && transB == 'N' )
    {
        // C := alpha A B + C
        for( int j=0; j<n; ++j )
        {
            for( int l=0; l<k; ++l )
            {
                const T gamma = alpha*B[l+j*ldb];
                for( int i=0; i<m; ++i )
                    C[i+j*ldc] += gamma*A[i+l*lda];
            }
        }
    }
    else if( transA == 'N' )
    {
        if( transB == 'T' )
        {
            // C := alpha A B^T + C
            for( int j=0; j<n; ++j )
            {
                for( int l=0; l<k; ++l )
                {
                    const T gamma = alpha*B[j+l*ldb];
                    for( int i=0; i<m; ++i )
                        C[i+j*ldc] += gamma*A[i+l*lda];
                }
            }
        }
        else
        {
            // C := alpha A B^H + C
            for( int j=0; j<n; ++j )
            {
                for( int l=0; l<k; ++l )
                {
                    const T gamma = alpha*Conj(B[j+l*ldb]);
                    for( int i=0; i<m; ++i )
                        C[i+j*ldc] += gamma*A[i+l*lda];
                }
            }
        }
    }
    else if( transB == 'N' )
    {
        if( transA == 'T' )
        {
            // C := alpha A^T B + C
            for( int j=0; j<n; ++j )
            {
                for( int i=0; i<m; ++i )
                {
                    T gamma = 0;
                    for( int l=0; l<k; ++l )
                        gamma += A[l+i*lda]*B[l+j*ldb];
                    C[i+j*ldc] += alpha*gamma;
                }
            }
        }
        else
        {
            // C := alpha A^H B + C
            for( int j=0; j<n; ++j )
            {
                for( int i=0; i<m; ++i )
                {
                    T gamma = 0;
                    for( int l=0; l<k; ++l )
                        gamma += Conj(A[l+i*lda])*B[l+j*ldb];
                    C[i+j*ldc] += alpha*gamma;
                }
            }
        }
    }
    else
    {
        if( transA == 'T' && transB == 'T' )
        {
            // C := alpha A^T B^T + C
            for( int j=0; j<n; ++j )
                for( int i=0; i<m; ++i )
                    for( int l=0; l<k; ++l )
                        C[i+j*ldc] += alpha*A[l+i*lda]*B[j+l*ldb];
        }
        else if( transA == 'T' )
        {
            // C := alpha A^T B^H + C
            for( int j=0; j<n; ++j )
                for( int i=0; i<m; ++i )
                    for( int l=0; l<k; ++l )
                        C[i+j*ldc] += alpha*A[l+i*lda]*Conj(B[j+l*ldb]);
        }
        else if( transB == 'T' )
        {
            // C := alpha A^H B^T + C
            for( int j=0; j<n; ++j )
                for( int i=0; i<m; ++i )
                    for( int l=0; l<k; ++l )
                        C[i+j*ldc] += alpha*Conj(A[l+i*lda])*B[j+l*ldb];
        }
        else
        {
            // C := alpha A^H B^H + C
            for( int j=0; j<n; ++j )
                for( int i=0; i<m; ++i )
                    for( int l=0; l<k; ++l )
                        C[i+j*ldc] += alpha*Conj(A[l+i*lda])*Conj(B[j+l*ldb]);
        }
    }
}
template void Gemm
( char transA, char transB, int m, int n, int k, 
  Int alpha, const Int* A, int lda, const Int* B, int ldb,
  Int beta,        Int* C, int ldc );
#ifdef EL_HAVE_QUAD
template void Gemm
( char transA, char transB, int m, int n, int k, 
  Quad alpha, const Quad* A, int lda, const Quad* B, int ldb,
  Quad beta,        Quad* C, int ldc );
template void Gemm
( char transA, char transB, int m, int n, int k, 
  Complex<Quad> alpha, const Complex<Quad>* A, int lda, 
                       const Complex<Quad>* B, int ldb,
  Complex<Quad> beta,        Complex<Quad>* C, int ldc );
#endif

void Gemm
( char transA, char transB, int m, int n, int k, 
  float alpha, const float* A, int lda, const float* B, int ldb,
  float beta,        float* C, int ldc )
{
    DEBUG_ONLY(
      CallStackEntry cse("blas::Gemm");
      if( transA == 'N' )
      {
          if( lda < Max(m,1) )
              LogicError("lda was too small: lda=",lda,",m=",m);
      }
      else
      {
          if( lda < Max(k,1) )
              LogicError("lda was too small: lda=",lda,",k=",k);
      }

      if( transB == 'N' )
      {
          if( ldb < Max(k,1) )
              LogicError("ldb was too small: ldb=",ldb,",k=",k);
      }
      else
      {
          if( ldb < Max(n,1) )
              LogicError("ldb was too small: ldb=",ldb,",n=",n);
      }

      if( ldc < Max(m,1) )
          LogicError("ldc was too small: ldc=",ldc,",m=",m);
    )
    const char fixedTransA = ( transA == 'C' ? 'T' : transA );
    const char fixedTransB = ( transB == 'C' ? 'T' : transB );
    EL_BLAS(sgemm)
    ( &fixedTransA, &fixedTransB, &m, &n, &k,
      &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Gemm
( char transA, char transB,
  int m, int n, int k, 
  double alpha, const double* A, int lda, const double* B, int ldb,
  double beta,        double* C, int ldc )
{
    DEBUG_ONLY(
      CallStackEntry cse("blas::Gemm");

      if( transA == 'N' )
      {
          if( lda < Max(m,1) )
              LogicError("lda was too small: lda=",lda,",m=",m);
      }
      else
      {
          if( lda < Max(k,1) )
              LogicError("lda was too small: lda=",lda,",k=",k);
      }      

      if( transB == 'N' )
      {
          if( ldb < Max(k,1) )
              LogicError("ldb was too small: ldb=",ldb,",k=",k);
      }
      else
      {
          if( ldb < Max(n,1) )
              LogicError("ldb was too small: ldb=",ldb,",n=",n);
      }

      if( ldc < Max(m,1) )
          LogicError("ldc was too small: ldc=",ldc,",m=",m);
    )
    const char fixedTransA = ( transA == 'C' ? 'T' : transA );
    const char fixedTransB = ( transB == 'C' ? 'T' : transB );
    EL_BLAS(dgemm)
    ( &fixedTransA, &fixedTransB, &m, &n, &k,
      &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Gemm
( char transA, char transB, int m, int n, int k, 
  scomplex alpha, const scomplex* A, int lda, const scomplex* B, int ldb,
  scomplex beta,        scomplex* C, int ldc )
{
    DEBUG_ONLY(
      CallStackEntry cse("blas::Gemm");

      if( transA == 'N' )
      {
          if( lda < Max(m,1) )
              LogicError("lda was too small: lda=",lda,",m=",m);
      }
      else
      {
          if( lda < Max(k,1) )
              LogicError("lda was too small: lda=",lda,",k=",k);
      }      

      if( transB == 'N' )
      {
          if( ldb < Max(k,1) )
              LogicError("ldb was too small: ldb=",ldb,",k=",k);
      }
      else
      {
          if( ldb < Max(n,1) )
              LogicError("ldb was too small: ldb=",ldb,",n=",n);
      }

      if( ldc < Max(m,1) )
          LogicError("ldc was too small: ldc=",ldc,",m=",m);
    )
    EL_BLAS(cgemm)
    ( &transA, &transB, &m, &n, &k,
      &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Gemm
( char transA, char transB, int m, int n, int k, 
  dcomplex alpha, const dcomplex* A, int lda, const dcomplex* B, int ldb,
  dcomplex beta,        dcomplex* C, int ldc )
{
    DEBUG_ONLY(
      CallStackEntry cse("blas::Gemm");

      if( transA == 'N' )
      {
          if( lda < Max(m,1) )
              LogicError("lda was too small: lda=",lda,",m=",m);
      }
      else
      {
          if( lda < Max(k,1) )
              LogicError("lda was too small: lda=",lda,",k=",k);
      }      

      if( transB == 'N' )
      {
          if( ldb < Max(k,1) )
              LogicError("ldb was too small: ldb=",ldb,",k=",k);
      }
      else
      {
          if( ldb < Max(n,1) )
              LogicError("ldb was too small: ldb=",ldb,",n=",n);
      }

      if( ldc < Max(m,1) )
          LogicError("ldc was too small: ldc=",ldc,",m=",m);
    )
    EL_BLAS(zgemm)
    ( &transA, &transB, &m, &n, &k,
      &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

template<typename T>
void Hemm
( char side, char uplo, int m, int n, 
  T alpha, const T* A, int lda, const T* B, int ldb,
  T beta,        T* C, int ldc )
{
    if( beta == T(0) )
    {
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                C[i+j*ldc] = 0;
        return;
    }

    // Scale C
    if( beta != T(1) )
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                C[i+j*ldc] *= beta;

    // Naive implementation
    if( side == 'L' && uplo == 'L' )
    {
        // C := alpha tril(A) B + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=0; l<=i; ++l )
                    C[i+j*ldc] += alpha*A[i+l*lda]*B[l+j*ldb];

        // C := alpha tril(A,-1)^H B + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=i+1; l<m; ++l )
                    C[i+j*ldc] += alpha*Conj(A[l+i*lda])*B[l+j*ldb];
    }
    else if( side == 'L' && uplo == 'U' )
    {
        // C := alpha triu(A) B + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=i; l<m; ++l )
                    C[i+j*ldc] += alpha*A[i+l*lda]*B[l+j*ldb];

        // C := alpha triu(A,-)^H B + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=0; l<i; ++l )
                    C[i+j*ldc] += alpha*Conj(A[l+i*lda])*B[l+j*ldb];
    }
    else if( side == 'R' && uplo == 'L' )
    {
        // C := alpha B tril(A) + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=j; l<n; ++l )
                    C[i+j*ldc] += alpha*B[i+l*ldb]*A[l+j*lda];

        // C := alpha B tril(A,-1)^H + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=0; l<j; ++l )
                    C[i+j*ldc] += alpha*B[i+l*ldb]*Conj(A[j+l*lda]);
    }
    else if( side == 'R' && uplo == 'U' )
    {
        // C := alpha B triu(A) + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=0; l<=j; ++l )
                    C[i+j*ldc] += alpha*B[i+l*ldb]*A[l+j*lda];

        // C := alpha B triu(A,1)^H + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=j+1; l<n; ++l )
                    C[i+j*ldc] += alpha*B[i+l*ldb]*Conj(A[j+l*lda]);
    }
    else
        LogicError("Unsuported Hemm option");
}
template void Hemm
( char side, char uplo, int m, int n,
  Int alpha, const Int* A, int lda, const Int* B, int ldb,
  Int beta,        Int* C, int ldc );
#ifdef EL_HAVE_QUAD
template void Hemm
( char side, char uplo, int m, int n,
  Quad alpha, const Quad* A, int lda, 
              const Quad* B, int ldb,
  Quad beta,        Quad* C, int ldc );
template void Hemm
( char side, char uplo, int m, int n,
  Complex<Quad> alpha, const Complex<Quad>* A, int lda, 
                       const Complex<Quad>* B, int ldb,
  Complex<Quad> beta,        Complex<Quad>* C, int ldc );
#endif

void Hemm
( char side, char uplo, int m, int n,
  float alpha, const float* A, int lda, const float* B, int ldb,
  float beta,        float* C, int ldc )
{
    EL_BLAS(ssymm)
    ( &side, &uplo, &m, &n,
      &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Hemm
( char side, char uplo, int m, int n,
  double alpha, const double* A, int lda, const double* B, int ldb,
  double beta,        double* C, int ldc )
{
    EL_BLAS(dsymm)
    ( &side, &uplo, &m, &n,
      &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Hemm
( char side, char uplo, int m, int n,
  scomplex alpha, const scomplex* A, int lda, const scomplex* B, int ldb,
  scomplex beta,        scomplex* C, int ldc )
{
    EL_BLAS(chemm)
    ( &side, &uplo, &m, &n,
      &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Hemm
( char side, char uplo, int m, int n,
  dcomplex alpha, const dcomplex* A, int lda, const dcomplex* B, int ldb,
  dcomplex beta,        dcomplex* C, int ldc )
{
    EL_BLAS(zhemm)
    ( &side, &uplo, &m, &n,
      &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Her2k
( char uplo, char trans, int n, int k,
  float alpha, const float* A, int lda, const float* B, int ldb,
  float beta,        float* C, int ldc )
{
    const char transFixed = ( trans == 'C' ? 'T' : trans );
    EL_BLAS(ssyr2k)
    ( &uplo, &transFixed, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Her2k
( char uplo, char trans, int n, int k,
  double alpha, const double* A, int lda, const double* B, int ldb,
  double beta,        double* C, int ldc )
{
    const char transFixed = ( trans == 'C' ? 'T' : trans );
    EL_BLAS(dsyr2k)
    ( &uplo, &transFixed, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Her2k
( char uplo, char trans, int n, int k,
  scomplex alpha, const scomplex* A, int lda, const scomplex* B, int ldb,
  float beta,           scomplex* C, int ldc )
{
    EL_BLAS(cher2k)
    ( &uplo, &trans, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Her2k
( char uplo, char trans, int n, int k,
  dcomplex alpha, const dcomplex* A, int lda, const dcomplex* B, int ldb,
  double beta,          dcomplex* C, int ldc )
{
    EL_BLAS(zher2k)
    ( &uplo, &trans, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

template<typename T>
void Herk
( char uplo, int n, int k, 
  Base<T> alpha, const T* A, int lda, 
  Base<T> beta,        T* C, int ldc )
{
    if( uplo == 'L' )
    {
        for( int j=0; j<n; ++j )
            for( int i=j; i<n; ++i )
                for( int l=0; l<k; ++l )
                    C[i+j*ldc] += alpha*A[i+l*lda]*Conj(A[j+l*lda]);
    }
    else
    {
        for( int j=0; j<n; ++j )
            for( int i=0; i<=j; ++i )
                for( int l=0; l<k; ++l )
                    C[i+j*ldc] += alpha*A[i+l*lda]*Conj(A[j+l*lda]);
    }
}
template void Herk
( char uplo, int n, int k, 
  Int alpha, const Int* A, int lda, 
  Int beta,        Int* C, int ldc );
#ifdef EL_HAVE_QUAD
template void Herk
( char uplo, int n, int k, 
  Quad alpha, const Quad* A, int lda, 
  Quad beta,        Quad* C, int ldc );
template void Herk
( char uplo, int n, int k,
  Quad alpha, const Complex<Quad>* A, int lda, 
  Quad beta,        Complex<Quad>* C, int ldc );
#endif

void Herk
( char uplo, char trans, int n, int k,
  float alpha, const float* A, int lda,
  float beta,        float* C, int ldc )
{
    const char transFixed = ( trans == 'C' ? 'T' : trans );
    EL_BLAS(ssyrk)
    ( &uplo, &transFixed, &n, &k, &alpha, A, &lda, &beta, C, &ldc );
}

void Herk
( char uplo, char trans, int n, int k,
  double alpha, const double* A, int lda,
  double beta,        double* C, int ldc )
{
    const char transFixed = ( trans == 'C' ? 'T' : trans );
    EL_BLAS(dsyrk)
    ( &uplo, &transFixed, &n, &k, &alpha, A, &lda, &beta, C, &ldc );
}

void Herk
( char uplo, char trans, int n, int k,
  float alpha, const scomplex* A, int lda,
  float beta,        scomplex* C, int ldc )
{ EL_BLAS(cherk)( &uplo, &trans, &n, &k, &alpha, A, &lda, &beta, C, &ldc ); }

void Herk
( char uplo, char trans, int n, int k,
  double alpha, const dcomplex* A, int lda,
  double beta,        dcomplex* C, int ldc )
{ EL_BLAS(zherk)( &uplo, &trans, &n, &k, &alpha, A, &lda, &beta, C, &ldc ); }

template<typename T>
void Symm
( char side, char uplo, int m, int n, 
  T alpha, const T* A, int lda, const T* B, int ldb,
  T beta,        T* C, int ldc )
{
    if( beta == T(0) )
    {
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                C[i+j*ldc] = 0;
        return;
    }

    // Scale C
    if( beta != T(1) )
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                C[i+j*ldc] *= beta;

    // Naive implementation
    if( side == 'L' && uplo == 'L' )
    {
        // C := alpha tril(A) B + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=0; l<=i; ++l )
                    C[i+j*ldc] += alpha*A[i+l*lda]*B[l+j*ldb];

        // C := alpha tril(A,-1)^T B + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=i+1; l<m; ++l )
                    C[i+j*ldc] += alpha*A[l+i*lda]*B[l+j*ldb];
    }
    else if( side == 'L' && uplo == 'U' )
    {
        // C := alpha triu(A) B + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=i; l<m; ++l )
                    C[i+j*ldc] += alpha*A[i+l*lda]*B[l+j*ldb];

        // C := alpha triu(A,-)^T B + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=0; l<i; ++l )
                    C[i+j*ldc] += alpha*A[l+i*lda]*B[l+j*ldb];
    }
    else if( side == 'R' && uplo == 'L' )
    {
        // C := alpha B tril(A) + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=j; l<n; ++l )
                    C[i+j*ldc] += alpha*B[i+l*ldb]*A[l+j*lda];

        // C := alpha B tril(A,-1)^T + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=0; l<j; ++l )
                    C[i+j*ldc] += alpha*B[i+l*ldb]*A[j+l*lda];
    }
    else if( side == 'R' && uplo == 'U' )
    {
        // C := alpha B triu(A) + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=0; l<=j; ++l )
                    C[i+j*ldc] += alpha*B[i+l*ldb]*A[l+j*lda];

        // C := alpha B triu(A,1)^T + C
        for( int j=0; j<n; ++j )
            for( int i=0; i<m; ++i )
                for( int l=j+1; l<n; ++l )
                    C[i+j*ldc] += alpha*B[i+l*ldb]*A[j+l*lda];
    }
    else
        LogicError("Unsuported Hemm option");
}
template void Symm
( char side, char uplo, int m, int n,
  Int alpha, const Int* A, int lda, const Int* B, int ldb,
  Int beta,        Int* C, int ldc );
#ifdef EL_HAVE_QUAD
template void Symm
( char side, char uplo, int m, int n,
  Quad alpha, const Quad* A, int lda, 
              const Quad* B, int ldb,
  Quad beta,        Quad* C, int ldc );
template void Symm
( char side, char uplo, int m, int n,
  Complex<Quad> alpha, const Complex<Quad>* A, int lda, 
                       const Complex<Quad>* B, int ldb,
  Complex<Quad> beta,        Complex<Quad>* C, int ldc );
#endif

void Symm
( char side, char uplo, int m, int n,
  float alpha, const float* A, int lda, const float* B, int ldb,
  float beta,        float* C, int ldc )
{
    EL_BLAS(ssymm)
    ( &side, &uplo, &m, &n, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Symm
( char side, char uplo, int m, int n,
  double alpha, const double* A, int lda, const double* B, int ldb,
  double beta,        double* C, int ldc )
{
    EL_BLAS(dsymm)
    ( &side, &uplo, &m, &n, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Symm
( char side, char uplo, int m, int n,
  scomplex alpha, const scomplex* A, int lda, const scomplex* B, int ldb,
  scomplex beta,        scomplex* C, int ldc )
{
    EL_BLAS(csymm)
    ( &side, &uplo, &m, &n, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Symm
( char side, char uplo, int m, int n,
  dcomplex alpha, const dcomplex* A, int lda, const dcomplex* B, int ldb,
  dcomplex beta,        dcomplex* C, int ldc )
{
    EL_BLAS(zsymm)
    ( &side, &uplo, &m, &n, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Syr2k
( char uplo, char trans, int n, int k,
  float alpha, const float* A, int lda, const float* B, int ldb,
  float beta,        float* C, int ldc )
{
    EL_BLAS(ssyr2k)
    ( &uplo, &trans, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Syr2k
( char uplo, char trans, int n, int k,
  double alpha, const double* A, int lda, const double* B, int ldb,
  double beta,        double* C, int ldc )
{
    EL_BLAS(dsyr2k)
    ( &uplo, &trans, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Syr2k
( char uplo, char trans, int n, int k,
  scomplex alpha, const scomplex* A, int lda, const scomplex* B, int ldb,
  scomplex beta,        scomplex* C, int ldc )
{
    EL_BLAS(csyr2k)
    ( &uplo, &trans, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

void Syr2k
( char uplo, char trans, int n, int k,
  dcomplex alpha, const dcomplex* A, int lda, const dcomplex* B, int ldb,
  dcomplex beta,        dcomplex* C, int ldc )
{
    EL_BLAS(zsyr2k)
    ( &uplo, &trans, &n, &k, &alpha, A, &lda, B, &ldb, &beta, C, &ldc );
}

template<typename T>
void Syrk
( char uplo, int n, int k, 
  T alpha, const T* A, int lda, 
  T beta,        T* C, int ldc )
{
    if( uplo == 'L' )
    {
        for( int j=0; j<n; ++j )
            for( int i=j; i<n; ++i )
                for( int l=0; l<k; ++l )
                    C[i+j*ldc] += alpha*A[i+l*lda]*A[j+l*lda];
    }
    else
    {
        for( int j=0; j<n; ++j )
            for( int i=0; i<=j; ++i )
                for( int l=0; l<k; ++l )
                    C[i+j*ldc] += alpha*A[i+l*lda]*A[j+l*lda];
    }
}
template void Syrk
( char uplo, int n, int k, 
  Int alpha, const Int* A, int lda, 
  Int beta,        Int* C, int ldc );
#ifdef EL_HAVE_QUAD
template void Syrk
( char uplo, int n, int k, 
  Quad alpha, const Quad* A, int lda, 
  Quad beta,        Quad* C, int ldc );
template void Syrk
( char uplo, int n, int k,
  Complex<Quad> alpha, const Complex<Quad>* A, int lda, 
  Complex<Quad> beta,        Complex<Quad>* C, int ldc );
#endif

void Syrk
( char uplo, char trans, int n, int k,
  float alpha, const float* A, int lda,
  float beta,        float* C, int ldc )
{ EL_BLAS(ssyrk)( &uplo, &trans, &n, &k, &alpha, A, &lda, &beta, C, &ldc ); }

void Syrk
( char uplo, char trans, int n, int k,
  double alpha, const double* A, int lda,
  double beta,        double* C, int ldc )
{ EL_BLAS(dsyrk)( &uplo, &trans, &n, &k, &alpha, A, &lda, &beta, C, &ldc ); }

void Syrk
( char uplo, char trans, int n, int k,
  scomplex alpha, const scomplex* A, int lda,
  scomplex beta,        scomplex* C, int ldc )
{ EL_BLAS(csyrk)( &uplo, &trans, &n, &k, &alpha, A, &lda, &beta, C, &ldc ); }

void Syrk
( char uplo, char trans, int n, int k,
  dcomplex alpha, const dcomplex* A, int lda,
  dcomplex beta,        dcomplex* C, int ldc )
{ EL_BLAS(zsyrk)( &uplo, &trans, &n, &k, &alpha, A, &lda, &beta, C, &ldc ); }

void Trmm
( char side, char uplo, char trans, char unit, int m, int n,
  float alpha, const float* A, int lda, float* B, int ldb )
{
    const char fixedTrans = ( trans == 'C' ? 'T' : trans );    
    EL_BLAS(strmm)
    ( &side, &uplo, &fixedTrans, &unit, &m, &n, &alpha, A, &lda, B, &ldb );
}

void Trmm
( char side, char uplo, char trans, char unit, int m, int n,
  double alpha, const double* A, int lda, double* B, int ldb )
{
    const char fixedTrans = ( trans == 'C' ? 'T' : trans );    
    EL_BLAS(dtrmm)
    ( &side, &uplo, &fixedTrans, &unit, &m, &n, &alpha, A, &lda, B, &ldb );
}

void Trmm
( char side, char uplo, char trans, char unit, int m, int n,
  scomplex alpha, const scomplex* A, int lda, scomplex* B, int ldb )
{
    EL_BLAS(ctrmm)
    ( &side, &uplo, &trans, &unit, &m, &n, &alpha, A, &lda, B, &ldb );
}

void Trmm
( char side, char uplo, char trans, char unit, int m, int n,
  dcomplex alpha, const dcomplex* A, int lda, dcomplex* B, int ldb )
{
    EL_BLAS(ztrmm)
    ( &side, &uplo, &trans, &unit, &m, &n, &alpha, A, &lda, B, &ldb );
}

void Trsm
( char side, char uplo, char trans, char unit, int m, int n,
  float alpha, const float* A, int lda, float* B, int ldb )
{
    const char fixedTrans = ( trans == 'C' ? 'T' : trans );
    EL_BLAS(strsm)
    ( &side, &uplo, &fixedTrans, &unit, &m, &n, &alpha, A, &lda, B, &ldb );
} 

void Trsm
( char side, char uplo, char trans, char unit, int m, int n,
  double alpha, const double* A, int lda, double* B, int ldb )
{
    const char fixedTrans = ( trans == 'C' ? 'T' : trans );
    EL_BLAS(dtrsm)
    ( &side, &uplo, &fixedTrans, &unit, &m, &n, &alpha, A, &lda, B, &ldb );
} 

void Trsm
( char side, char uplo, char trans, char unit, int m, int n,
  scomplex alpha, const scomplex* A, int lda, scomplex* B, int ldb )
{
    EL_BLAS(ctrsm)
    ( &side, &uplo, &trans, &unit, &m, &n, &alpha, A, &lda, B, &ldb );
} 

void Trsm
( char side, char uplo, char trans, char unit, int m, int n,
  dcomplex alpha, const dcomplex* A, int lda, dcomplex* B, int ldb )
{
    EL_BLAS(ztrsm)
    ( &side, &uplo, &trans, &unit, &m, &n, &alpha, A, &lda, B, &ldb );
} 

} // namespace blas
} // namespace El
