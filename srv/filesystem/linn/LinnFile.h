/*
 * Copyright (C) 2009 Niek Linnenbank
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __FILESYSTEM_LINN_FILE_H
#define __FILESYSTEM_LINN_FILE_H
#ifndef __HOST__

#include <File.h>
#include <FileSystemMessage.h>
#include <Types.h>
#include <Error.h>
#include "LinnFileSystem.h"
#include "LinnInode.h"

/**
 * @defgroup linn Linnenbank Filesystem (LinnFS)
 * @{
 */

/**
 * Represents a file on a mounted LinnFS filesystem.
 */
class LinnFile : public File
{
    public:

	/**
	 * Constructor function.
	 * @param fs LinnFS filesystem pointer.
	 * @param inode Inode pointer.
	 */
	LinnFile(LinnFileSystem *fs, LinnInode *inode);

	/**
	 * Destructor function.
	 */
	~LinnFile();

	/**
	 * Read out the file.
	 * @param msg Read request.
	 * @return Number of bytes read, or Error number.
	 */
	Error read(FileSystemMessage *msg);

        /** 
         * Write bytes to the file.
	 * @param msg Write request.
         * @return Number of bytes written on success, Error on failure.
         */
	Error write(FileSystemMessage *msg);

    private:

	/** Filesystem pointer. */
	LinnFileSystem *fs;
	
	/** Inode pointer. */
	LinnInode *inode;
};

/**
 * @}
 */

#endif /* __HOST__ */
#endif /* __FILESYSTEM_LINN_FILE_H */