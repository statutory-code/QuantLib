
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

/*! \file frankfurt.cpp
	\brief Frankfurt calendar

    $Id$
*/

// $Source$
// $Log$
// Revision 1.20  2001/08/07 11:25:54  sigmud
// copyright header maintenance
//
// Revision 1.19  2001/07/25 15:47:28  sigmud
// Change from quantlib.sourceforge.net to quantlib.org
//
// Revision 1.18  2001/05/24 15:40:09  nando
// smoothing #include xx.hpp and cutting old Log messages
//

#include "ql/Calendars/frankfurt.hpp"

namespace QuantLib {

	namespace Calendars {

		bool Frankfurt::isBusinessDay(const Date& date) const {
			Weekday w = date.weekday();
			Day d = date.dayOfMonth(), dd = date.dayOfYear();
			Month m = date.month();
			Year y = date.year()-1900;
			if ((w == Saturday || w == Sunday)
				// New Year's Day
				|| (d == 1 && m == January)
				// Good Friday
				|| (dd == easterMonday[y]-3)
				// Easter Monday
				|| (dd == easterMonday[y])
				// Ascension Thursday
				|| (dd == easterMonday[y]+38)
				// Whit Monday
				|| (dd == easterMonday[y]+49)
				// Corpus Christi
				|| (dd == easterMonday[y]+59)
				// Labour Day
				|| (d == 1 && m == May)
				// National Day
				|| (d == 3 && m == October)
				// Christmas Eve
				|| (d == 24 && m == December)
				// Christmas
				|| (d == 25 && m == December)
				// Boxing Day
				|| (d == 26 && m == December)
				// New Year's Eve
				|| (d == 31 && m == December))
					return false;
			return true;
		}

	}

}

