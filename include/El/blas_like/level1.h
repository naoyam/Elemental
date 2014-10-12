/*
   Copyright (c) 2009-2014, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#pragma once
#ifndef EL_BLAS_LEVEL1_C_H
#define EL_BLAS_LEVEL1_C_H

#include "El/core/DistMatrix.h"

#ifdef __cplusplus
extern "C" {
#endif

/* B = A^H 
   ======= */
EL_EXPORT ElError ElAdjoint_c( ElConstMatrix_c A, ElMatrix_c B );
EL_EXPORT ElError ElAdjoint_z( ElConstMatrix_z A, ElMatrix_z B );

EL_EXPORT ElError ElAdjointDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B );
EL_EXPORT ElError ElAdjointDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B );

/* Y := alpha A X + Y 
   ================== */
EL_EXPORT ElError ElAxpy_i
( ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y );
EL_EXPORT ElError ElAxpy_s
( float alpha, ElConstMatrix_s X, ElMatrix_s Y );
EL_EXPORT ElError ElAxpy_d
( double alpha, ElConstMatrix_d X, ElMatrix_d Y );
EL_EXPORT ElError ElAxpy_c
( complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y );
EL_EXPORT ElError ElAxpy_z
( complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y );

EL_EXPORT ElError ElAxpyDist_i
( ElInt alpha, ElConstDistMatrix_i X, ElDistMatrix_i Y );
EL_EXPORT ElError ElAxpyDist_s
( float alpha, ElConstDistMatrix_s X, ElDistMatrix_s Y );
EL_EXPORT ElError ElAxpyDist_d
( double alpha, ElConstDistMatrix_d X, ElDistMatrix_d Y );
EL_EXPORT ElError ElAxpyDist_c
( complex_float alpha, ElConstDistMatrix_c X, ElDistMatrix_c Y );
EL_EXPORT ElError ElAxpyDist_z
( complex_double alpha, ElConstDistMatrix_z X, ElDistMatrix_z Y );

/* tri(Y) := tri(alpha A X + Y)
   ============================ */
EL_EXPORT ElError ElAxpyTriangle_i
( ElUpperOrLower uplo, ElInt alpha, ElConstMatrix_i X, ElMatrix_i Y );
EL_EXPORT ElError ElAxpyTriangle_s
( ElUpperOrLower uplo, float alpha, ElConstMatrix_s X, ElMatrix_s Y );
EL_EXPORT ElError ElAxpyTriangle_d
( ElUpperOrLower uplo, double alpha, ElConstMatrix_d X, ElMatrix_d Y );
EL_EXPORT ElError ElAxpyTriangle_c
( ElUpperOrLower uplo, complex_float alpha, ElConstMatrix_c X, ElMatrix_c Y );
EL_EXPORT ElError ElAxpyTriangle_z
( ElUpperOrLower uplo, complex_double alpha, ElConstMatrix_z X, ElMatrix_z Y );

EL_EXPORT ElError ElAxpyTriangleDist_i
( ElUpperOrLower uplo, ElInt alpha, 
  ElConstDistMatrix_i X, ElDistMatrix_i Y );
EL_EXPORT ElError ElAxpyTriangleDist_s
( ElUpperOrLower uplo, float alpha, 
  ElConstDistMatrix_s X, ElDistMatrix_s Y );
EL_EXPORT ElError ElAxpyTriangleDist_d
( ElUpperOrLower uplo, double alpha, 
  ElConstDistMatrix_d X, ElDistMatrix_d Y );
EL_EXPORT ElError ElAxpyTriangleDist_c
( ElUpperOrLower uplo, complex_float alpha, 
  ElConstDistMatrix_c X, ElDistMatrix_c Y );
EL_EXPORT ElError ElAxpyTriangleDist_z
( ElUpperOrLower uplo, complex_double alpha, 
  ElConstDistMatrix_z X, ElDistMatrix_z Y );

/* A := Conj(A) 
   ============ */
EL_EXPORT ElError ElConjugate_c( ElMatrix_c A );
EL_EXPORT ElError ElConjugate_z( ElMatrix_z A );

EL_EXPORT ElError ElConjugateDist_c( ElDistMatrix_c A );
EL_EXPORT ElError ElConjugateDist_z( ElDistMatrix_z A );

/* B = A 
   ===== */
EL_EXPORT ElError ElCopy_i( ElConstMatrix_i A, ElMatrix_i B );
EL_EXPORT ElError ElCopy_s( ElConstMatrix_s A, ElMatrix_s B );
EL_EXPORT ElError ElCopy_d( ElConstMatrix_d A, ElMatrix_d B );
EL_EXPORT ElError ElCopy_c( ElConstMatrix_c A, ElMatrix_c B );
EL_EXPORT ElError ElCopy_z( ElConstMatrix_z A, ElMatrix_z B );

EL_EXPORT ElError ElCopyDist_i( ElConstDistMatrix_i A, ElDistMatrix_i B );
EL_EXPORT ElError ElCopyDist_s( ElConstDistMatrix_s A, ElDistMatrix_s B );
EL_EXPORT ElError ElCopyDist_d( ElConstDistMatrix_d A, ElDistMatrix_d B );
EL_EXPORT ElError ElCopyDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B );
EL_EXPORT ElError ElCopyDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B );

/* DiagonalScale 
   ============= */
EL_EXPORT ElError ElDiagonalScale_i
( ElLeftOrRight side, 
  ElConstMatrix_i d, ElMatrix_i X );
EL_EXPORT ElError ElDiagonalScale_s
( ElLeftOrRight side,
  ElConstMatrix_s d, ElMatrix_s X );
EL_EXPORT ElError ElDiagonalScale_d
( ElLeftOrRight side, 
  ElConstMatrix_d d, ElMatrix_d X );
EL_EXPORT ElError ElDiagonalScale_c
( ElLeftOrRight side, ElOrientation orientation, 
  ElConstMatrix_c d, ElMatrix_c X );
EL_EXPORT ElError ElDiagonalScale_z
( ElLeftOrRight side, ElOrientation orientation, 
  ElConstMatrix_z d, ElMatrix_z X );

EL_EXPORT ElError ElDiagonalScaleDist_i
( ElLeftOrRight side, 
  ElConstDistMatrix_i d, ElDistMatrix_i X );
EL_EXPORT ElError ElDiagonalScaleDist_s
( ElLeftOrRight side, 
  ElConstDistMatrix_s d, ElDistMatrix_s X );
EL_EXPORT ElError ElDiagonalScaleDist_d
( ElLeftOrRight side,
  ElConstDistMatrix_d d, ElDistMatrix_d X );
EL_EXPORT ElError ElDiagonalScaleDist_c
( ElLeftOrRight side, ElOrientation orientation, 
  ElConstDistMatrix_c d, ElDistMatrix_c X );
EL_EXPORT ElError ElDiagonalScaleDist_z
( ElLeftOrRight side, ElOrientation orientation, 
  ElConstDistMatrix_z d, ElDistMatrix_z X );

/* DiagonalScaleTrapezoid
   ====================== */
EL_EXPORT ElError ElDiagonalScaleTrapezoid_i
( ElLeftOrRight side, ElUpperOrLower uplo, 
  ElConstMatrix_i d, ElMatrix_i X, ElInt offset );
EL_EXPORT ElError ElDiagonalScaleTrapezoid_s
( ElLeftOrRight side, ElUpperOrLower uplo,
  ElConstMatrix_s d, ElMatrix_s X, ElInt offset );
EL_EXPORT ElError ElDiagonalScaleTrapezoid_d
( ElLeftOrRight side, ElUpperOrLower uplo,
  ElConstMatrix_d d, ElMatrix_d X, ElInt offset );
EL_EXPORT ElError ElDiagonalScaleTrapezoid_c
( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, 
  ElConstMatrix_c d, ElMatrix_c X, ElInt offset );
EL_EXPORT ElError ElDiagonalScaleTrapezoid_z
( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, 
  ElConstMatrix_z d, ElMatrix_z X, ElInt offset );

EL_EXPORT ElError ElDiagonalScaleTrapezoidDist_i
( ElLeftOrRight side, ElUpperOrLower uplo, 
  ElConstDistMatrix_i d, ElDistMatrix_i X, ElInt offset );
EL_EXPORT ElError ElDiagonalScaleTrapezoidDist_s
( ElLeftOrRight side, ElUpperOrLower uplo, 
  ElConstDistMatrix_s d, ElDistMatrix_s X, ElInt offset );
EL_EXPORT ElError ElDiagonalScaleTrapezoidDist_d
( ElLeftOrRight side, ElUpperOrLower uplo, 
  ElConstDistMatrix_d d, ElDistMatrix_d X, ElInt offset );
EL_EXPORT ElError ElDiagonalScaleTrapezoidDist_c
( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, 
  ElConstDistMatrix_c d, ElDistMatrix_c X, ElInt offset );
EL_EXPORT ElError ElDiagonalScaleTrapezoidDist_z
( ElLeftOrRight side, ElUpperOrLower uplo, ElOrientation orientation, 
  ElConstDistMatrix_z d, ElDistMatrix_z X, ElInt offset );

/* DiagonalSolve 
   ============= */
EL_EXPORT ElError ElDiagonalSolve_s
( ElLeftOrRight side, 
  ElConstMatrix_s d, ElMatrix_s X );
EL_EXPORT ElError ElDiagonalSolve_d
( ElLeftOrRight side, 
  ElConstMatrix_d d, ElMatrix_d X );
EL_EXPORT ElError ElDiagonalSolve_c
( ElLeftOrRight side, ElOrientation orientation, 
  ElConstMatrix_c d, ElMatrix_c X );
EL_EXPORT ElError ElDiagonalSolve_z
( ElLeftOrRight side, ElOrientation orientation, 
  ElConstMatrix_z d, ElMatrix_z X );

EL_EXPORT ElError ElDiagonalSolveDist_s
( ElLeftOrRight side,
  ElConstDistMatrix_s d, ElDistMatrix_s X );
EL_EXPORT ElError ElDiagonalSolveDist_d
( ElLeftOrRight side, 
  ElConstDistMatrix_d d, ElDistMatrix_d X );
EL_EXPORT ElError ElDiagonalSolveDist_c
( ElLeftOrRight side, ElOrientation orientation, 
  ElConstDistMatrix_c d, ElDistMatrix_c X );
EL_EXPORT ElError ElDiagonalSolveDist_z
( ElLeftOrRight side, ElOrientation orientation, 
  ElConstDistMatrix_z d, ElDistMatrix_z X );

/* Dot 
   === */
EL_EXPORT ElError ElDot_i
( ElConstMatrix_i A, ElConstMatrix_i B, ElInt* prod );
EL_EXPORT ElError ElDot_s
( ElConstMatrix_s A, ElConstMatrix_s B, float* prod );
EL_EXPORT ElError ElDot_d
( ElConstMatrix_d A, ElConstMatrix_d B, double* prod );
EL_EXPORT ElError ElDot_c
( ElConstMatrix_c A, ElConstMatrix_c B, complex_float* prod );
EL_EXPORT ElError ElDot_z
( ElConstMatrix_z A, ElConstMatrix_z B, complex_double* prod );

EL_EXPORT ElError ElDotDist_i
( ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElInt* prod );
EL_EXPORT ElError ElDotDist_s
( ElConstDistMatrix_s A, ElConstDistMatrix_s B, float* prod );
EL_EXPORT ElError ElDotDist_d
( ElConstDistMatrix_d A, ElConstDistMatrix_d B, double* prod );
EL_EXPORT ElError ElDotDist_c
( ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float* prod );
EL_EXPORT ElError ElDotDist_z
( ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double* prod );

/* Dotu
   ==== */
EL_EXPORT ElError ElDotu_c
( ElConstMatrix_c A, ElConstMatrix_c B, complex_float* prod );
EL_EXPORT ElError ElDotu_z
( ElConstMatrix_z A, ElConstMatrix_z B, complex_double* prod );

EL_EXPORT ElError ElDotuDist_c
( ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float* prod );
EL_EXPORT ElError ElDotuDist_z
( ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double* prod );

/* EntrywiseFill
   ============= */
EL_EXPORT ElError ElEntrywiseFill_i( ElMatrix_i A, ElInt (*fill)() );
EL_EXPORT ElError ElEntrywiseFill_s( ElMatrix_s A, float (*fill)() );
EL_EXPORT ElError ElEntrywiseFill_d( ElMatrix_d A, double (*fill)() );
EL_EXPORT ElError ElEntrywiseFill_c( ElMatrix_c A, complex_float (*fill)() );
EL_EXPORT ElError ElEntrywiseFill_z( ElMatrix_z A, complex_double (*fill)() );

EL_EXPORT ElError ElEntrywiseFillDist_i
( ElDistMatrix_i A, ElInt (*fill)() );
EL_EXPORT ElError ElEntrywiseFillDist_s
( ElDistMatrix_s A, float (*fill)() );
EL_EXPORT ElError ElEntrywiseFillDist_d
( ElDistMatrix_d A, double (*fill)() );
EL_EXPORT ElError ElEntrywiseFillDist_c
( ElDistMatrix_c A, complex_float (*fill)() );
EL_EXPORT ElError ElEntrywiseFillDist_z
( ElDistMatrix_z A, complex_double (*fill)() );

/* EntrywiseMap
   ============ */
EL_EXPORT ElError ElEntrywiseMap_i
( ElMatrix_i A, ElInt (*func)(ElInt) );
EL_EXPORT ElError ElEntrywiseMap_s
( ElMatrix_s A, float (*func)(float) );
EL_EXPORT ElError ElEntrywiseMap_d
( ElMatrix_d A, double (*func)(double) );
EL_EXPORT ElError ElEntrywiseMap_c
( ElMatrix_c A, complex_float (*func)(complex_float) );
EL_EXPORT ElError ElEntrywiseMap_z
( ElMatrix_z A, complex_double (*func)(complex_double) );

EL_EXPORT ElError ElEntrywiseMapDist_i
( ElDistMatrix_i A, ElInt (*func)(ElInt) );
EL_EXPORT ElError ElEntrywiseMapDist_s
( ElDistMatrix_s A, float (*func)(float) );
EL_EXPORT ElError ElEntrywiseMapDist_d
( ElDistMatrix_d A, double (*func)(double) );
EL_EXPORT ElError ElEntrywiseMapDist_c
( ElDistMatrix_c A, complex_float (*func)(complex_float) );
EL_EXPORT ElError ElEntrywiseMapDist_z
( ElDistMatrix_z A, complex_double (*func)(complex_double) );

/* TODO: Version which maps to a different matrix of possibly different type? */

/* Fill
   ==== */
EL_EXPORT ElError ElFill_i( ElMatrix_i A, ElInt alpha );
EL_EXPORT ElError ElFill_s( ElMatrix_s A, float alpha );
EL_EXPORT ElError ElFill_d( ElMatrix_d A, double alpha );
EL_EXPORT ElError ElFill_c( ElMatrix_c A, complex_float alpha );
EL_EXPORT ElError ElFill_z( ElMatrix_z A, complex_double alpha );

EL_EXPORT ElError ElFillDist_i( ElDistMatrix_i A, ElInt alpha );
EL_EXPORT ElError ElFillDist_s( ElDistMatrix_s A, float alpha );
EL_EXPORT ElError ElFillDist_d( ElDistMatrix_d A, double alpha );
EL_EXPORT ElError ElFillDist_c( ElDistMatrix_c A, complex_float alpha );
EL_EXPORT ElError ElFillDist_z( ElDistMatrix_z A, complex_double alpha );

/* Hadamard
   ======== */
EL_EXPORT ElError ElHadamard_i
( ElConstMatrix_i A, ElConstMatrix_i B, ElMatrix_i C );
EL_EXPORT ElError ElHadamard_s
( ElConstMatrix_s A, ElConstMatrix_s B, ElMatrix_s C );
EL_EXPORT ElError ElHadamard_d
( ElConstMatrix_d A, ElConstMatrix_d B, ElMatrix_d C );
EL_EXPORT ElError ElHadamard_c
( ElConstMatrix_c A, ElConstMatrix_c B, ElMatrix_c C );
EL_EXPORT ElError ElHadamard_z
( ElConstMatrix_z A, ElConstMatrix_z B, ElMatrix_z C );

EL_EXPORT ElError ElHadamardDist_i
( ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElDistMatrix_i C );
EL_EXPORT ElError ElHadamardDist_s
( ElConstDistMatrix_s A, ElConstDistMatrix_s B, ElDistMatrix_s C );
EL_EXPORT ElError ElHadamardDist_d
( ElConstDistMatrix_d A, ElConstDistMatrix_d B, ElDistMatrix_d C );
EL_EXPORT ElError ElHadamardDist_c
( ElConstDistMatrix_c A, ElConstDistMatrix_c B, ElDistMatrix_c C );
EL_EXPORT ElError ElHadamardDist_z
( ElConstDistMatrix_z A, ElConstDistMatrix_z B, ElDistMatrix_z C );

/* HilbertSchmidt
   ============== */
/* NOTE: This is the same as Dot */
EL_EXPORT ElError ElHilbertSchmidt_i
( ElConstMatrix_i A, ElConstMatrix_i B, ElInt* prod );
EL_EXPORT ElError ElHilbertSchmidt_s
( ElConstMatrix_s A, ElConstMatrix_s B, float* prod );
EL_EXPORT ElError ElHilbertSchmidt_d
( ElConstMatrix_d A, ElConstMatrix_d B, double* prod );
EL_EXPORT ElError ElHilbertSchmidt_c
( ElConstMatrix_c A, ElConstMatrix_c B, complex_float* prod );
EL_EXPORT ElError ElHilbertSchmidt_z
( ElConstMatrix_z A, ElConstMatrix_z B, complex_double* prod );

EL_EXPORT ElError ElHilbertSchmidtDist_i
( ElConstDistMatrix_i A, ElConstDistMatrix_i B, ElInt* prod );
EL_EXPORT ElError ElHilbertSchmidtDist_s
( ElConstDistMatrix_s A, ElConstDistMatrix_s B, float* prod );
EL_EXPORT ElError ElHilbertSchmidtDist_d
( ElConstDistMatrix_d A, ElConstDistMatrix_d B, double* prod );
EL_EXPORT ElError ElHilbertSchmidtDist_c
( ElConstDistMatrix_c A, ElConstDistMatrix_c B, complex_float* prod );
EL_EXPORT ElError ElHilbertSchmidtDist_z
( ElConstDistMatrix_z A, ElConstDistMatrix_z B, complex_double* prod );

/* Imaginary part
   ============== */
EL_EXPORT ElError ElImagPart_i( ElConstMatrix_i A, ElMatrix_i AImag );
EL_EXPORT ElError ElImagPart_s( ElConstMatrix_s A, ElMatrix_s AImag );
EL_EXPORT ElError ElImagPart_d( ElConstMatrix_d A, ElMatrix_d AImag );
EL_EXPORT ElError ElImagPart_c( ElConstMatrix_c A, ElMatrix_s AImag );
EL_EXPORT ElError ElImagPart_z( ElConstMatrix_z A, ElMatrix_d AImag );
EL_EXPORT ElError ElImagPartDist_i
( ElConstDistMatrix_i A, ElDistMatrix_i AImag );
EL_EXPORT ElError ElImagPartDist_s
( ElConstDistMatrix_s A, ElDistMatrix_s AImag );
EL_EXPORT ElError ElImagPartDist_d
( ElConstDistMatrix_d A, ElDistMatrix_d AImag );
EL_EXPORT ElError ElImagPartDist_c
( ElConstDistMatrix_c A, ElDistMatrix_s AImag );
EL_EXPORT ElError ElImagPartDist_z
( ElConstDistMatrix_z A, ElDistMatrix_d AImag );

/* IndexDependentFill
   ================== */
EL_EXPORT ElError ElIndexDependentFill_i
( ElMatrix_i A, ElInt (*fill)(ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentFill_s
( ElMatrix_s A, float (*fill)(ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentFill_d
( ElMatrix_d A, double (*fill)(ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentFill_c
( ElMatrix_c A, complex_float (*fill)(ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentFill_z
( ElMatrix_z A, complex_double (*fill)(ElInt,ElInt) );

EL_EXPORT ElError ElIndexDependentFillDist_i
( ElDistMatrix_i A, ElInt (*fill)(ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentFillDist_s
( ElDistMatrix_s A, float (*fill)(ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentFillDist_d
( ElDistMatrix_d A, double (*fill)(ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentFillDist_c
( ElDistMatrix_c A, complex_float (*fill)(ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentFillDist_z
( ElDistMatrix_z A, complex_double (*fill)(ElInt,ElInt) );

/* IndexDependentMap
   ================= */
EL_EXPORT ElError ElIndexDependentMap_i
( ElMatrix_i A, ElInt (*func)(ElInt,ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentMap_s
( ElMatrix_s A, float (*func)(ElInt,ElInt,float) );
EL_EXPORT ElError ElIndexDependentMap_d
( ElMatrix_d A, double (*func)(ElInt,ElInt,double) );
EL_EXPORT ElError ElIndexDependentMap_c
( ElMatrix_c A, complex_float (*func)(ElInt,ElInt,complex_float) );
EL_EXPORT ElError ElIndexDependentMap_z
( ElMatrix_z A, complex_double (*func)(ElInt,ElInt,complex_double) );

EL_EXPORT ElError ElIndexDependentMapDist_i
( ElDistMatrix_i A, ElInt (*func)(ElInt,ElInt,ElInt) );
EL_EXPORT ElError ElIndexDependentMapDist_s
( ElDistMatrix_s A, float (*func)(ElInt,ElInt,float) );
EL_EXPORT ElError ElIndexDependentMapDist_d
( ElDistMatrix_d A, double (*func)(ElInt,ElInt,double) );
EL_EXPORT ElError ElIndexDependentMapDist_c
( ElDistMatrix_c A, complex_float (*func)(ElInt,ElInt,complex_float) );
EL_EXPORT ElError ElIndexDependentMapDist_z
( ElDistMatrix_z A, complex_double (*func)(ElInt,ElInt,complex_double) );

/* MakeHermitian 
   ============= */
EL_EXPORT ElError ElMakeHermitian_c
( ElUpperOrLower uplo, ElMatrix_c A );
EL_EXPORT ElError ElMakeHermitian_z
( ElUpperOrLower uplo, ElMatrix_z A );

EL_EXPORT ElError ElMakeHermitianDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A );
EL_EXPORT ElError ElMakeHermitianDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A );

/* MakeReal
   ======== */
EL_EXPORT ElError ElMakeReal_c( ElMatrix_c A );
EL_EXPORT ElError ElMakeReal_z( ElMatrix_z A );

EL_EXPORT ElError ElMakeRealDist_c( ElDistMatrix_c A );
EL_EXPORT ElError ElMakeRealDist_z( ElDistMatrix_z A );

/* MakeSymmetric 
   ============= */
EL_EXPORT ElError ElMakeSymmetric_i( ElUpperOrLower uplo, ElMatrix_i A );
EL_EXPORT ElError ElMakeSymmetric_s( ElUpperOrLower uplo, ElMatrix_s A );
EL_EXPORT ElError ElMakeSymmetric_d( ElUpperOrLower uplo, ElMatrix_d A );
EL_EXPORT ElError ElMakeSymmetric_c( ElUpperOrLower uplo, ElMatrix_c A );
EL_EXPORT ElError ElMakeSymmetric_z( ElUpperOrLower uplo, ElMatrix_z A );

EL_EXPORT ElError ElMakeSymmetricDist_i
( ElUpperOrLower uplo, ElDistMatrix_i A );
EL_EXPORT ElError ElMakeSymmetricDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A );
EL_EXPORT ElError ElMakeSymmetricDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A );
EL_EXPORT ElError ElMakeSymmetricDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A );
EL_EXPORT ElError ElMakeSymmetricDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A );

/* MakeTrapezoidal
   =============== */
EL_EXPORT ElError ElMakeTrapezoidal_i
( ElUpperOrLower uplo, ElMatrix_i A, ElInt offset );
EL_EXPORT ElError ElMakeTrapezoidal_s
( ElUpperOrLower uplo, ElMatrix_s A, ElInt offset );
EL_EXPORT ElError ElMakeTrapezoidal_d
( ElUpperOrLower uplo, ElMatrix_d A, ElInt offset );
EL_EXPORT ElError ElMakeTrapezoidal_c
( ElUpperOrLower uplo, ElMatrix_c A, ElInt offset );
EL_EXPORT ElError ElMakeTrapezoidal_z
( ElUpperOrLower uplo, ElMatrix_z A, ElInt offset );

EL_EXPORT ElError ElMakeTrapezoidalDist_i
( ElUpperOrLower uplo, ElDistMatrix_i A, ElInt offset );
EL_EXPORT ElError ElMakeTrapezoidalDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElInt offset );
EL_EXPORT ElError ElMakeTrapezoidalDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElInt offset );
EL_EXPORT ElError ElMakeTrapezoidalDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElInt offset );
EL_EXPORT ElError ElMakeTrapezoidalDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElInt offset );

/* MakeTriangular
   ============== */
EL_EXPORT ElError ElMakeTriangular_i( ElUpperOrLower uplo, ElMatrix_i A );
EL_EXPORT ElError ElMakeTriangular_s( ElUpperOrLower uplo, ElMatrix_s A );
EL_EXPORT ElError ElMakeTriangular_d( ElUpperOrLower uplo, ElMatrix_d A );
EL_EXPORT ElError ElMakeTriangular_c( ElUpperOrLower uplo, ElMatrix_c A );
EL_EXPORT ElError ElMakeTriangular_z( ElUpperOrLower uplo, ElMatrix_z A );

EL_EXPORT ElError ElMakeTriangularDist_i
( ElUpperOrLower uplo, ElDistMatrix_i A );
EL_EXPORT ElError ElMakeTriangularDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A );
EL_EXPORT ElError ElMakeTriangularDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A );
EL_EXPORT ElError ElMakeTriangularDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A );
EL_EXPORT ElError ElMakeTriangularDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A );

/* Max
   === */
EL_EXPORT ElError ElMax_i( ElConstMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElMax_s( ElConstMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMax_d( ElConstMatrix_d A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElMaxDist_i( ElConstDistMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElMaxDist_s( ElConstDistMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMaxDist_d( ElConstDistMatrix_d A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElSymmetricMax_i
( ElUpperOrLower uplo, ElConstMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElSymmetricMax_s
( ElUpperOrLower uplo, ElConstMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMax_d
( ElUpperOrLower uplo, ElConstMatrix_d A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElSymmetricMaxDist_i
( ElUpperOrLower uplo, ElConstDistMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElSymmetricMaxDist_s
( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMaxDist_d
( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElVectorMax_i( ElConstMatrix_i x, ElValueInt_i* entry );
EL_EXPORT ElError ElVectorMax_s( ElConstMatrix_s x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMax_d( ElConstMatrix_d x, ElValueInt_d* entry );

EL_EXPORT ElError ElVectorMaxDist_i
( ElConstDistMatrix_i x, ElValueInt_i* entry );
EL_EXPORT ElError ElVectorMaxDist_s
( ElConstDistMatrix_s x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMaxDist_d
( ElConstDistMatrix_d x, ElValueInt_d* entry );

/* MaxAbs
   ====== */
EL_EXPORT ElError ElMaxAbs_i( ElConstMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElMaxAbs_s( ElConstMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMaxAbs_d( ElConstMatrix_d A, ElValueIntPair_d* entry );
EL_EXPORT ElError ElMaxAbs_c( ElConstMatrix_c A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMaxAbs_z( ElConstMatrix_z A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElMaxAbsDist_i
( ElConstDistMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElMaxAbsDist_s
( ElConstDistMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMaxAbsDist_d
( ElConstDistMatrix_d A, ElValueIntPair_d* entry );
EL_EXPORT ElError ElMaxAbsDist_c
( ElConstDistMatrix_c A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMaxAbsDist_z
( ElConstDistMatrix_z A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElSymmetricMaxAbs_i
( ElUpperOrLower uplo, ElConstMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElSymmetricMaxAbs_s
( ElUpperOrLower uplo, ElConstMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMaxAbs_d
( ElUpperOrLower uplo, ElConstMatrix_d A, ElValueIntPair_d* entry );
EL_EXPORT ElError ElSymmetricMaxAbs_c
( ElUpperOrLower uplo, ElConstMatrix_c A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMaxAbs_z
( ElUpperOrLower uplo, ElConstMatrix_z A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElSymmetricMaxAbsDist_i
( ElUpperOrLower uplo, ElConstDistMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElSymmetricMaxAbsDist_s
( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMaxAbsDist_d
( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElValueIntPair_d* entry );
EL_EXPORT ElError ElSymmetricMaxAbsDist_c
( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMaxAbsDist_z
( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElVectorMaxAbs_i( ElConstMatrix_i x, ElValueInt_i* entry );
EL_EXPORT ElError ElVectorMaxAbs_s( ElConstMatrix_s x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMaxAbs_d( ElConstMatrix_d x, ElValueInt_d* entry );
EL_EXPORT ElError ElVectorMaxAbs_c( ElConstMatrix_c x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMaxAbs_z( ElConstMatrix_z x, ElValueInt_d* entry );

EL_EXPORT ElError ElVectorMaxAbsDist_i
( ElConstDistMatrix_i x, ElValueInt_i* entry );
EL_EXPORT ElError ElVectorMaxAbsDist_s
( ElConstDistMatrix_s x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMaxAbsDist_d
( ElConstDistMatrix_d x, ElValueInt_d* entry );
EL_EXPORT ElError ElVectorMaxAbsDist_c
( ElConstDistMatrix_c x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMaxAbsDist_z
( ElConstDistMatrix_z x, ElValueInt_d* entry );

/* Min
   === */
EL_EXPORT ElError ElMin_i( ElConstMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElMin_s( ElConstMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMin_d( ElConstMatrix_d A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElMinDist_i( ElConstDistMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElMinDist_s( ElConstDistMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMinDist_d( ElConstDistMatrix_d A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElSymmetricMin_i
( ElUpperOrLower uplo, ElConstMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElSymmetricMin_s
( ElUpperOrLower uplo, ElConstMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMin_d
( ElUpperOrLower uplo, ElConstMatrix_d A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElSymmetricMinDist_i
( ElUpperOrLower uplo, ElConstDistMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElSymmetricMinDist_s
( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMinDist_d
( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElVectorMin_i( ElConstMatrix_i x, ElValueInt_i* entry );
EL_EXPORT ElError ElVectorMin_s( ElConstMatrix_s x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMin_d( ElConstMatrix_d x, ElValueInt_d* entry );

EL_EXPORT ElError ElVectorMinDist_i
( ElConstDistMatrix_i x, ElValueInt_i* entry );
EL_EXPORT ElError ElVectorMinDist_s
( ElConstDistMatrix_s x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMinDist_d
( ElConstDistMatrix_d x, ElValueInt_d* entry );

/* MinAbs
   ====== */
EL_EXPORT ElError ElMinAbs_i( ElConstMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElMinAbs_s( ElConstMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMinAbs_d( ElConstMatrix_d A, ElValueIntPair_d* entry );
EL_EXPORT ElError ElMinAbs_c( ElConstMatrix_c A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMinAbs_z( ElConstMatrix_z A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElMinAbsDist_i
( ElConstDistMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElMinAbsDist_s
( ElConstDistMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMinAbsDist_d
( ElConstDistMatrix_d A, ElValueIntPair_d* entry );
EL_EXPORT ElError ElMinAbsDist_c
( ElConstDistMatrix_c A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElMinAbsDist_z
( ElConstDistMatrix_z A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElSymmetricMinAbs_i
( ElUpperOrLower uplo, ElConstMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElSymmetricMinAbs_s
( ElUpperOrLower uplo, ElConstMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMinAbs_d
( ElUpperOrLower uplo, ElConstMatrix_d A, ElValueIntPair_d* entry );
EL_EXPORT ElError ElSymmetricMinAbs_c
( ElUpperOrLower uplo, ElConstMatrix_c A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMinAbs_z
( ElUpperOrLower uplo, ElConstMatrix_z A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElSymmetricMinAbsDist_i
( ElUpperOrLower uplo, ElConstDistMatrix_i A, ElValueIntPair_i* entry );
EL_EXPORT ElError ElSymmetricMinAbsDist_s
( ElUpperOrLower uplo, ElConstDistMatrix_s A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMinAbsDist_d
( ElUpperOrLower uplo, ElConstDistMatrix_d A, ElValueIntPair_d* entry );
EL_EXPORT ElError ElSymmetricMinAbsDist_c
( ElUpperOrLower uplo, ElConstDistMatrix_c A, ElValueIntPair_s* entry );
EL_EXPORT ElError ElSymmetricMinAbsDist_z
( ElUpperOrLower uplo, ElConstDistMatrix_z A, ElValueIntPair_d* entry );

EL_EXPORT ElError ElVectorMinAbs_i( ElConstMatrix_i x, ElValueInt_i* entry );
EL_EXPORT ElError ElVectorMinAbs_s( ElConstMatrix_s x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMinAbs_d( ElConstMatrix_d x, ElValueInt_d* entry );
EL_EXPORT ElError ElVectorMinAbs_c( ElConstMatrix_c x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMinAbs_z( ElConstMatrix_z x, ElValueInt_d* entry );

EL_EXPORT ElError ElVectorMinAbsDist_i
( ElConstDistMatrix_i x, ElValueInt_i* entry );
EL_EXPORT ElError ElVectorMinAbsDist_s
( ElConstDistMatrix_s x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMinAbsDist_d
( ElConstDistMatrix_d x, ElValueInt_d* entry );
EL_EXPORT ElError ElVectorMinAbsDist_c
( ElConstDistMatrix_c x, ElValueInt_s* entry );
EL_EXPORT ElError ElVectorMinAbsDist_z
( ElConstDistMatrix_z x, ElValueInt_d* entry );

/* Nrm2
   ==== */
EL_EXPORT ElError ElNrm2_s( ElConstMatrix_s A, float* gamma );
EL_EXPORT ElError ElNrm2_d( ElConstMatrix_d A, double* gamma );
EL_EXPORT ElError ElNrm2_c( ElConstMatrix_c A, float* gamma );
EL_EXPORT ElError ElNrm2_z( ElConstMatrix_z A, double* gamma );

EL_EXPORT ElError ElNrm2Dist_s( ElConstDistMatrix_s A, float* gamma );
EL_EXPORT ElError ElNrm2Dist_d( ElConstDistMatrix_d A, double* gamma );
EL_EXPORT ElError ElNrm2Dist_c( ElConstDistMatrix_c A, float* gamma );
EL_EXPORT ElError ElNrm2Dist_z( ElConstDistMatrix_z A, double* gamma );

/* Real part
   ========= */
EL_EXPORT ElError ElRealPart_i( ElConstMatrix_i A, ElMatrix_i AReal );
EL_EXPORT ElError ElRealPart_s( ElConstMatrix_s A, ElMatrix_s AReal );
EL_EXPORT ElError ElRealPart_d( ElConstMatrix_d A, ElMatrix_d AReal );
EL_EXPORT ElError ElRealPart_c( ElConstMatrix_c A, ElMatrix_s AReal );
EL_EXPORT ElError ElRealPart_z( ElConstMatrix_z A, ElMatrix_d AReal );
EL_EXPORT ElError ElRealPartDist_i
( ElConstDistMatrix_i A, ElDistMatrix_i AReal );
EL_EXPORT ElError ElRealPartDist_s
( ElConstDistMatrix_s A, ElDistMatrix_s AReal );
EL_EXPORT ElError ElRealPartDist_d
( ElConstDistMatrix_d A, ElDistMatrix_d AReal );
EL_EXPORT ElError ElRealPartDist_c
( ElConstDistMatrix_c A, ElDistMatrix_s AReal );
EL_EXPORT ElError ElRealPartDist_z
( ElConstDistMatrix_z A, ElDistMatrix_d AReal );

/* Scale
   ===== */
EL_EXPORT ElError ElScale_i( ElInt alpha, ElMatrix_i A );
EL_EXPORT ElError ElScale_s( float alpha, ElMatrix_s A );
EL_EXPORT ElError ElScale_d( double alpha, ElMatrix_d A );
EL_EXPORT ElError ElScale_c( complex_float alpha, ElMatrix_c A );
EL_EXPORT ElError ElScale_z( complex_double alpha, ElMatrix_z A );

EL_EXPORT ElError ElScaleDist_i( ElInt alpha, ElDistMatrix_i A );
EL_EXPORT ElError ElScaleDist_s( float alpha, ElDistMatrix_s A );
EL_EXPORT ElError ElScaleDist_d( double alpha, ElDistMatrix_d A );
EL_EXPORT ElError ElScaleDist_c( complex_float alpha, ElDistMatrix_c A );
EL_EXPORT ElError ElScaleDist_z( complex_double alpha, ElDistMatrix_z A );

/* ScaleTrapezoid
   ============== */
EL_EXPORT ElError ElScaleTrapezoid_i
( ElInt alpha, ElUpperOrLower uplo, ElMatrix_i A, ElInt offset );
EL_EXPORT ElError ElScaleTrapezoid_s
( float alpha, ElUpperOrLower uplo, ElMatrix_s A, ElInt offset );
EL_EXPORT ElError ElScaleTrapezoid_d
( double alpha, ElUpperOrLower uplo, ElMatrix_d A, ElInt offset );
EL_EXPORT ElError ElScaleTrapezoid_c
( complex_float alpha, ElUpperOrLower uplo, ElMatrix_c A, ElInt offset );
EL_EXPORT ElError ElScaleTrapezoid_z
( complex_double alpha, ElUpperOrLower uplo, ElMatrix_z A, ElInt offset );

EL_EXPORT ElError ElScaleTrapezoidDist_i
( ElInt alpha, ElUpperOrLower uplo, ElDistMatrix_i A, ElInt offset );
EL_EXPORT ElError ElScaleTrapezoidDist_s
( float alpha, ElUpperOrLower uplo, ElDistMatrix_s A, ElInt offset );
EL_EXPORT ElError ElScaleTrapezoidDist_d
( double alpha, ElUpperOrLower uplo, ElDistMatrix_d A, ElInt offset );
EL_EXPORT ElError ElScaleTrapezoidDist_c
( complex_float alpha, ElUpperOrLower uplo, ElDistMatrix_c A, ElInt offset );
EL_EXPORT ElError ElScaleTrapezoidDist_z
( complex_double alpha, ElUpperOrLower uplo, ElDistMatrix_z A, ElInt offset );

/* SetDiagonal
   =========== */
EL_EXPORT ElError ElSetDiagonal_i
( ElMatrix_i A, ElInt alpha, ElInt offset );
EL_EXPORT ElError ElSetDiagonal_s
( ElMatrix_s A, float alpha, ElInt offset );
EL_EXPORT ElError ElSetDiagonal_d
( ElMatrix_d A, double alpha, ElInt offset );
EL_EXPORT ElError ElSetDiagonal_c
( ElMatrix_c A, complex_float alpha, ElInt offset );
EL_EXPORT ElError ElSetDiagonal_z
( ElMatrix_z A, complex_double alpha, ElInt offset );

EL_EXPORT ElError ElSetDiagonalDist_i
( ElDistMatrix_i A, ElInt alpha, ElInt offset );
EL_EXPORT ElError ElSetDiagonalDist_s
( ElDistMatrix_s A, float alpha, ElInt offset );
EL_EXPORT ElError ElSetDiagonalDist_d
( ElDistMatrix_d A, double alpha, ElInt offset );
EL_EXPORT ElError ElSetDiagonalDist_c
( ElDistMatrix_c A, complex_float alpha, ElInt offset );
EL_EXPORT ElError ElSetDiagonalDist_z
( ElDistMatrix_z A, complex_double alpha, ElInt offset );

/* Swap
   ==== */
EL_EXPORT ElError ElSwap_i
( ElOrientation orientation, ElMatrix_i X, ElMatrix_i Y );
EL_EXPORT ElError ElSwap_s
( ElOrientation orientation, ElMatrix_s X, ElMatrix_s Y );
EL_EXPORT ElError ElSwap_d
( ElOrientation orientation, ElMatrix_d X, ElMatrix_d Y );
EL_EXPORT ElError ElSwap_c
( ElOrientation orientation, ElMatrix_c X, ElMatrix_c Y );
EL_EXPORT ElError ElSwap_z
( ElOrientation orientation, ElMatrix_z X, ElMatrix_z Y );

EL_EXPORT ElError ElSwapDist_i
( ElOrientation orientation, ElDistMatrix_i X, ElDistMatrix_i Y );
EL_EXPORT ElError ElSwapDist_s
( ElOrientation orientation, ElDistMatrix_s X, ElDistMatrix_s Y );
EL_EXPORT ElError ElSwapDist_d
( ElOrientation orientation, ElDistMatrix_d X, ElDistMatrix_d Y );
EL_EXPORT ElError ElSwapDist_c
( ElOrientation orientation, ElDistMatrix_c X, ElDistMatrix_c Y );
EL_EXPORT ElError ElSwapDist_z
( ElOrientation orientation, ElDistMatrix_z X, ElDistMatrix_z Y );

EL_EXPORT ElError ElRowSwap_i( ElMatrix_i A, ElInt to, ElInt from );
EL_EXPORT ElError ElRowSwap_s( ElMatrix_s A, ElInt to, ElInt from );
EL_EXPORT ElError ElRowSwap_d( ElMatrix_d A, ElInt to, ElInt from );
EL_EXPORT ElError ElRowSwap_c( ElMatrix_c A, ElInt to, ElInt from );
EL_EXPORT ElError ElRowSwap_z( ElMatrix_z A, ElInt to, ElInt from );

EL_EXPORT ElError ElRowSwapDist_i( ElDistMatrix_i A, ElInt to, ElInt from );
EL_EXPORT ElError ElRowSwapDist_s( ElDistMatrix_s A, ElInt to, ElInt from );
EL_EXPORT ElError ElRowSwapDist_d( ElDistMatrix_d A, ElInt to, ElInt from );
EL_EXPORT ElError ElRowSwapDist_c( ElDistMatrix_c A, ElInt to, ElInt from );
EL_EXPORT ElError ElRowSwapDist_z( ElDistMatrix_z A, ElInt to, ElInt from );

EL_EXPORT ElError ElColSwap_i( ElMatrix_i A, ElInt to, ElInt from );
EL_EXPORT ElError ElColSwap_s( ElMatrix_s A, ElInt to, ElInt from );
EL_EXPORT ElError ElColSwap_d( ElMatrix_d A, ElInt to, ElInt from );
EL_EXPORT ElError ElColSwap_c( ElMatrix_c A, ElInt to, ElInt from );
EL_EXPORT ElError ElColSwap_z( ElMatrix_z A, ElInt to, ElInt from );

EL_EXPORT ElError ElColSwapDist_i( ElDistMatrix_i A, ElInt to, ElInt from );
EL_EXPORT ElError ElColSwapDist_s( ElDistMatrix_s A, ElInt to, ElInt from );
EL_EXPORT ElError ElColSwapDist_d( ElDistMatrix_d A, ElInt to, ElInt from );
EL_EXPORT ElError ElColSwapDist_c( ElDistMatrix_c A, ElInt to, ElInt from );
EL_EXPORT ElError ElColSwapDist_z( ElDistMatrix_z A, ElInt to, ElInt from );

EL_EXPORT ElError ElSymmetricSwap_i
( ElUpperOrLower uplo, ElMatrix_i A, ElInt to, ElInt from );
EL_EXPORT ElError ElSymmetricSwap_s
( ElUpperOrLower uplo, ElMatrix_s A, ElInt to, ElInt from );
EL_EXPORT ElError ElSymmetricSwap_d
( ElUpperOrLower uplo, ElMatrix_d A, ElInt to, ElInt from );
EL_EXPORT ElError ElSymmetricSwap_c
( ElUpperOrLower uplo, ElMatrix_c A, ElInt to, ElInt from );
EL_EXPORT ElError ElSymmetricSwap_z
( ElUpperOrLower uplo, ElMatrix_z A, ElInt to, ElInt from );

EL_EXPORT ElError ElSymmetricSwapDist_i
( ElUpperOrLower uplo, ElDistMatrix_i A, ElInt to, ElInt from );
EL_EXPORT ElError ElSymmetricSwapDist_s
( ElUpperOrLower uplo, ElDistMatrix_s A, ElInt to, ElInt from );
EL_EXPORT ElError ElSymmetricSwapDist_d
( ElUpperOrLower uplo, ElDistMatrix_d A, ElInt to, ElInt from );
EL_EXPORT ElError ElSymmetricSwapDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElInt to, ElInt from );
EL_EXPORT ElError ElSymmetricSwapDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElInt to, ElInt from );

EL_EXPORT ElError ElHermitianSwap_c
( ElUpperOrLower uplo, ElMatrix_c A, ElInt to, ElInt from );
EL_EXPORT ElError ElHermitianSwap_z
( ElUpperOrLower uplo, ElMatrix_z A, ElInt to, ElInt from );

EL_EXPORT ElError ElHermitianSwapDist_c
( ElUpperOrLower uplo, ElDistMatrix_c A, ElInt to, ElInt from );
EL_EXPORT ElError ElHermitianSwapDist_z
( ElUpperOrLower uplo, ElDistMatrix_z A, ElInt to, ElInt from );

/* B = A^T 
   ======= */
EL_EXPORT ElError ElTranspose_i( ElConstMatrix_i A, ElMatrix_i B );
EL_EXPORT ElError ElTranspose_s( ElConstMatrix_s A, ElMatrix_s B );
EL_EXPORT ElError ElTranspose_d( ElConstMatrix_d A, ElMatrix_d B );
EL_EXPORT ElError ElTranspose_c( ElConstMatrix_c A, ElMatrix_c B );
EL_EXPORT ElError ElTranspose_z( ElConstMatrix_z A, ElMatrix_z B );

EL_EXPORT ElError ElTransposeDist_i( ElConstDistMatrix_i A, ElDistMatrix_i B );
EL_EXPORT ElError ElTransposeDist_s( ElConstDistMatrix_s A, ElDistMatrix_s B );
EL_EXPORT ElError ElTransposeDist_d( ElConstDistMatrix_d A, ElDistMatrix_d B );
EL_EXPORT ElError ElTransposeDist_c( ElConstDistMatrix_c A, ElDistMatrix_c B );
EL_EXPORT ElError ElTransposeDist_z( ElConstDistMatrix_z A, ElDistMatrix_z B );

/* UpdateDiagonal
   ============== */
EL_EXPORT ElError ElUpdateDiagonal_i
( ElMatrix_i A, ElInt alpha, ElInt offset );
EL_EXPORT ElError ElUpdateDiagonal_s
( ElMatrix_s A, float alpha, ElInt offset );
EL_EXPORT ElError ElUpdateDiagonal_d
( ElMatrix_d A, double alpha, ElInt offset );
EL_EXPORT ElError ElUpdateDiagonal_c
( ElMatrix_c A, complex_float alpha, ElInt offset );
EL_EXPORT ElError ElUpdateDiagonal_z
( ElMatrix_z A, complex_double alpha, ElInt offset );

EL_EXPORT ElError ElUpdateDiagonalDist_i
( ElDistMatrix_i A, ElInt alpha, ElInt offset );
EL_EXPORT ElError ElUpdateDiagonalDist_s
( ElDistMatrix_s A, float alpha, ElInt offset );
EL_EXPORT ElError ElUpdateDiagonalDist_d
( ElDistMatrix_d A, double alpha, ElInt offset );
EL_EXPORT ElError ElUpdateDiagonalDist_c
( ElDistMatrix_c A, complex_float alpha, ElInt offset );
EL_EXPORT ElError ElUpdateDiagonalDist_z
( ElDistMatrix_z A, complex_double alpha, ElInt offset );

/* Zero
   ==== */
EL_EXPORT ElError ElZero_i( ElMatrix_i A );
EL_EXPORT ElError ElZero_s( ElMatrix_s A );
EL_EXPORT ElError ElZero_d( ElMatrix_d A );
EL_EXPORT ElError ElZero_c( ElMatrix_c A );
EL_EXPORT ElError ElZero_z( ElMatrix_z A );

EL_EXPORT ElError ElZeroDist_i( ElDistMatrix_i A );
EL_EXPORT ElError ElZeroDist_s( ElDistMatrix_s A );
EL_EXPORT ElError ElZeroDist_d( ElDistMatrix_d A );
EL_EXPORT ElError ElZeroDist_c( ElDistMatrix_c A );
EL_EXPORT ElError ElZeroDist_z( ElDistMatrix_z A );

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* ifndef EL_BLAS_LEVEL1_C_H */
