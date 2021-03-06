/**
 *    Copyright (C) 2010 Deep Software Foundation
 *
 *    This program is free software: you can redistribute it and/or  modify
 *    it under the terms of the GNU Affero General Public License, version 3,
 *    as published by the Free Software Foundation.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Affero General Public License for more details.
 *
 *    You should have received a copy of the GNU Affero General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the GNU Affero General Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */
#ifndef CXX_LANG_INTEGER_H_
#define CXX_LANG_INTEGER_H_

#include "cxx/lang/Object.h"
#include "cxx/lang/Comparable.h"

namespace cxx { namespace lang {

class Integer : public Comparable {

	private:
		const int m_value;

		Integer(const Integer& obj);
		Integer& operator=(Integer& obj);

	public:
		static const int MIN_VALUE = 0x80000000;
		static const int MAX_VALUE = 0x7FFFFFFF;

		inline Integer(void):
			m_value(0) {
		}

		inline Integer(int value):
			m_value(value) {
		}

		inline int intValue() const {
			return m_value;
		}

		virtual Object* clone() const {
			return new Integer(m_value);
		}

		virtual long hashCode(void) const {
			return (long) m_value;
		}

		virtual boolean equals(const Object* obj) const {
			return obj != null && m_value == ((Integer*) obj)->m_value;
		}

		virtual int compareTo(const Object* obj) const {
			return (m_value < ((Integer*) obj)->m_value ? -1 : (m_value == ((Integer*) obj)->m_value ? 0 : 1));
		}
};

} } // namespace

#endif /*CXX_LANG_INTEGER_H_*/
