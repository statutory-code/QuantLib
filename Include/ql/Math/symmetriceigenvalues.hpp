
/*
 * Copyright (C) 2000-2001 QuantLib Group
 *
 * This file is part of QuantLib.
 * QuantLib is a C++ open source library for financial quantitative
 * analysts and developers --- http://quantlib.org/
 *
 * QuantLib is free software and you are allowed to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of it under the conditions stated
 * in the QuantLib License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the license for more details.
 *
 * You should have received a copy of the license along with this file;
 * if not, please email quantlib-users@lists.sourceforge.net
 * The license is also available at http://quantlib.org/LICENSE.TXT
 *
 * The members of the QuantLib Group are listed in the Authors.txt file, also
 * available at http://quantlib.org/group.html
*/

/*! \file symmetriceigenvalues.hpp
    \brief Eigenvalues / eigenvectors of a real symmetric matrix

    $Id$
*/

// $Source$
// $Log$
// Revision 1.7  2001/08/07 11:25:54  sigmud
// copyright header maintenance
//
// Revision 1.6  2001/07/25 15:47:28  sigmud
// Change from quantlib.sourceforge.net to quantlib.org
//
// Revision 1.5  2001/06/22 16:38:15  lballabio
// Improved documentation
//
// Revision 1.4  2001/06/05 09:35:13  lballabio
// Updated docs to use Doxygen 1.2.8
//
// Revision 1.3  2001/05/24 15:38:08  nando
// smoothing #include xx.hpp and cutting old Log messages
//

#ifndef quantlib_symmetric_eigenvalues_h
#define quantlib_symmetric_eigenvalues_h

#include "ql/Math/symmetricschurdecomposition.hpp"

namespace QuantLib {

    namespace Math {

        // Eigenvalues of a symmetric matrix
        Array SymmetricEigenvalues(Matrix &s);
        
        // Eigenvectors of a symmetric matrix
        Matrix SymmetricEigenvectors(Matrix &s);
        

        // inline definitions
        
        inline Array SymmetricEigenvalues(Matrix &s) {
            return SymmetricSchurDecomposition(s).eigenvalues();
        }

        inline Matrix SymmetricEigenvectors(Matrix &s) {
            return SymmetricSchurDecomposition(s).eigenvectors();
        }

    }

}

#endif


