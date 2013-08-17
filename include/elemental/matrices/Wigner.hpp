/*
   Copyright (c) 2009-2013, Jack Poulson
   All rights reserved.

   This file is part of Elemental and is under the BSD 2-Clause License, 
   which can be found in the LICENSE file in the root directory, or at 
   http://opensource.org/licenses/BSD-2-Clause
*/
#pragma once
#ifndef ELEM_MATRICES_WIGNER_HPP
#define ELEM_MATRICES_WIGNER_HPP

#include "elemental/matrices/Gaussian.hpp"

namespace elem {

template<typename T>
inline void
Wigner( Matrix<T>& A, Int n, T mean=0, BASE(T) stddev=1 )
{
#ifndef RELEASE
    CallStackEntry entry("Wigner");
#endif
    Gaussian( A, n, n, mean, stddev );
    MakeHermitian( LOWER, A );
}

template<typename T,Distribution U,Distribution V>
inline void
Wigner( DistMatrix<T,U,V>& A, Int n, T mean=0, BASE(T) stddev=1 )
{
#ifndef RELEASE
    CallStackEntry entry("Wigner");
#endif
    Gaussian( A, n, n, mean, stddev );
    MakeHermitian( LOWER, A );
}

} // namespace elem

#endif // ifndef ELEM_MATRICES_WIGNER_HPP
