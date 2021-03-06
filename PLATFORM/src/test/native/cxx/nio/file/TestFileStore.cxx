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
#include <stdio.h>
#include <cstdlib>

#include "cxx/io/File.h"
#include "cxx/nio/file/FileStore.h"
#include "cxx/util/Logger.h"

using namespace cxx::io;
using namespace cxx::nio::file;
using namespace cxx::util;

int main(int argc, char** argv) {

	int success = 0;

	File path(".");
	FileStore store = FileStore::getFileStore(path);

	DEEP_LOG(INFO, OTHER, "Mount point: %s | Total: %llu | Unallocated: %llu | Usable: %llu\n", store.name()->data(), store.getTotalSpace(), store.getUnallocatedSpace(), store.getUsableSpace());

	if (store.getTotalSpace() < store.getUnallocatedSpace()) {
		DEEP_LOG(ERROR, OTHER, "Total < Unallocated");
		success = 1;
	}

	if (store.getTotalSpace() < store.getUsableSpace()) {
		DEEP_LOG(ERROR, OTHER, "Total < Usable");
		success = 1;
	}

	return success;
}
