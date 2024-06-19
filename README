rc - a shell
============

This is rc, the Plan 9 shell, reimplemented for Unix by Byron Rakitzis.

The original rc was designed and implemented by Tom Duff at Bell Labs.
It has a small feature set similar to a traditional Bourne shell, but
with a much cleaner and simpler syntax. Among other things, this makes
rc much better than Bourne-compatible shells at handling filenames which
contain spaces. Thus, writing rc scripts is less error-prone than
writing sh scripts.

This reimplementation of rc can be linked with GNU readline, BSD
libedit, or similar line editing libraries, to make a pleasant
interactive shell.

See COPYING for copying information. All files are

   Copyright 1991, 1999, 2001-2003, 2014, 2015 Byron Rakitzis.


Installation
------------

rc is built and installed using the following commands:

	$ make
	# make install

Please note, that the second command requires root privileges. By
default, rc is installed using the prefix "/usr/local", so the full path
of the executable will be "/usr/local/bin/rc".

You can install rc into a directory of your choice by changing the
second command to:

	# make PREFIX="/your/dir" install

The EDIT make macro controls which line-editing library to use: null,
edit, editline, readline, vrl, bestline. For example, to make rc use the
readline library, you have to build it with the following command:

	$ make EDIT=readline

All other build-time specific settings of rc can be found in the file
config.h. Please check and change them, so that they fit your needs. If
the file config.h does not already exist, then you have to create it
with the following command:

	$ make config.h
