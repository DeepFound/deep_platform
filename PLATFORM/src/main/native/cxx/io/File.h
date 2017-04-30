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
#ifndef CXX_IO_FILE_H_
#define CXX_IO_FILE_H_

#include "cxx/lang/Object.h"
#include "cxx/lang/String.h"
#include "cxx/util/ArrayList.h"

using namespace cxx::lang;
using namespace cxx::util;

namespace cxx { namespace io {

class File : public String {

	public:
		static const String separator;
		static const char separatorChar;

	public:
		static boolean mkdirs(const char* path, int mode);

		File(const char* pathname);
		File(const String& pathname);

		const char* getName() const;
		const char* getPath() const;
		/*
		const char* getAbsolutePath();
		const char* getCanonicalPath();
		*/

		long long length() const;
		boolean exists() const;

		/*
		boolean isAbsolute();
		boolean isDirectory();
		boolean isHidden();
		boolean isFile();

		long lastModified();
		*/
		boolean mkdir();
		boolean mkdirs();
		boolean renameTo(const char* dest);
		/*
		boolean setLastModified(long time);
		boolean createNewFile();

		boolean canRead();
		boolean canWrite();
		boolean canExecute();

		boolean setReadOnly();
		boolean setWritable(bool writable);
		boolean setReadable(bool readable);
		boolean setExecutable(bool executable);
		*/

		ArrayList<String*>* list(ArrayList<String*>* list = null) const;

		boolean clobber(); // XXX: delete();

		/*
		int compareTo(const File* pathname);
		boolean equals(Object* obj);
		long hashCode();
		*/
		
		File getParentFile();
};

} } // namespace

#endif /*FILE_H_*/
