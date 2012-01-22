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
#ifndef ELEMENTAL_ENVIRONMENT_HPP
#define ELEMENTAL_ENVIRONMENT_HPP 1

#include "mpi.h"
#include <algorithm>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

#include "elemental/config.h"

#ifdef HAVE_F90_INTERFACE
# include "elemental/FCMangle.h"
#endif

// If defined, the _OPENMP macro contains the date of the specification
#ifdef _OPENMP
# include <omp.h>
# if _OPENMP >= 200805
#  define COLLAPSE(N) collapse(N)
# else
#  define COLLAPSE(N) 
# endif 
#endif

namespace elemental {

// Forward declarations
class Grid;
template<typename Z> struct Complex;

// For initializing and finalizing Elemental
void Initialize( int& argc, char**& argv );
void Finalize();
bool Initialized();

// Return a grid constructed using mpi::COMM_WORLD.
const Grid& DefaultGrid();

// For getting and setting the algorithmic blocksize
int Blocksize();
void SetBlocksize( int blocksize );

// For manipulating the algorithmic blocksize as a stack
void PushBlocksizeStack( int blocksize );
void PopBlocksizeStack();

// Euclidean (l_2) magnitudes
template<typename R>
R Abs( R alpha );
template<typename R>
R Abs( Complex<R> alpha );

// Square-root free (l_1) magnitudes
template<typename Z>
Z FastAbs( Z alpha );
template<typename Z>
Z FastAbs( Complex<Z> alpha );

// Conjugation
template<typename Z>
Z Conj( Z alpha );
template<typename Z>
Complex<Z> Conj( Complex<Z> alpha );

// An exception which signifies that a matrix was unexpectedly singular.
class SingularMatrixException : public std::runtime_error 
{
public:
    SingularMatrixException( const char* msg="Matrix was singular" ) 
    : std::runtime_error( msg ) { }
};

// An exception which signifies that a matrix was unexpectedly non-HPD
class NonHPDMatrixException  : public std::runtime_error
{
public:
    NonHPDMatrixException( const char* msg="Matrix was not HPD" )
    : std::runtime_error( msg ) { }
};

// An exception which signifies that a matrix was unexpectedly non-HPSD
class NonHPSDMatrixException  : public std::runtime_error
{
public:
    NonHPSDMatrixException( const char* msg="Matrix was not HPSD" )
    : std::runtime_error( msg ) { }
};

#ifndef RELEASE
void PushCallStack( std::string s );
void PopCallStack();
void DumpCallStack();
#endif // ifndef RELEASE

// For extracting the underlying real datatype, 
// e.g., typename Base<Scalar>::type a = 3.0;
template<typename Z>
struct Base { typedef Z type; };
template<typename Z>
struct Base<Complex<Z> > { typedef Z type; };

// For querying whether or not a scalar is complex,
// e.g., IsComplex<Scalar>::val
template<typename Z>
struct IsComplex { enum { val=0 }; };
template<typename Z>
struct IsComplex<Complex<Z> > { enum { val=1 }; };

// We define an output stream that does nothing. This is done so that the 
// root process can be used to print data to a file's ostream while all other 
// processes use a null ostream. This is used within the DistMatrix class's
// 'Write' functions.
struct NullStream : std::ostream
{
    struct NullStreamBuffer : std::streambuf
    {
        int overflow( int c ) { return traits_type::not_eof(c); }
    } nullStreamBuffer_;

    NullStream() 
    : std::ios(&nullStreamBuffer_), std::ostream(&nullStreamBuffer_) 
    { }
};

} // namespace elemental

#include "elemental/core/types.hpp"
#include "elemental/core/utilities.hpp"

#include "elemental/imports.hpp"

#include "elemental/core/memory.hpp"
#include "elemental/core/grid.hpp"
#include "elemental/core/random.hpp"
#include "elemental/core/timer.hpp"

//
// Implementation begins here
//

namespace elemental {

template<typename R>
inline R 
Abs( R alpha )
{ return std::abs(alpha); }

template<typename R>
inline R
Abs( Complex<R> alpha )
{
    const R x=alpha.real, y=alpha.imag;
    if( x >= y )
    {
        const R xMag = Abs( x );
        const R ratio = y/x;
        return xMag*sqrt(1+ratio*ratio);
    }
    else
    {
        const R yMag = Abs( y );
        const R ratio = x/y;
        return yMag*sqrt(1+ratio*ratio);
    }
}

template<typename Z>
inline Z
FastAbs( Z alpha )
{ return std::abs(alpha); }

template<typename Z>
inline Z
FastAbs( Complex<Z> alpha )
{ return std::abs(alpha.real) + std::abs(alpha.imag); }

template<typename Z>
inline Z
Conj( Z alpha )
{ return alpha; }

template<typename Z>
inline Complex<Z>
Conj( Complex<Z> alpha )
{ return Complex<Z>(alpha.real,-alpha.imag); }

} // namespace elemental

#endif /* ELEMENTAL_ENVIRONMENT_HPP */

