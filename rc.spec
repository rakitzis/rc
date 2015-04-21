%define name rc
%define version 1.7.2
%define release 3

Summary:	rc - the Plan 9 and Tenth Edition shell
Name:	%name
Version:	%version
Release:	%release
Group:	Shells
License:	distributable
Source0:	http://static.tobold.org/rc/rc-1.7.2.tar.gz
Buildroot:	/var/tmp/%{name}-rpmroot
BuildRequires:	autoconf
BuildRequires:	readline-devel

%description
This is a reimplementation for Unix, by Byron Rakitzis, of the Plan 9
shell. rc offers much the same capabilities as a traditional Bourne
shell, but with a much cleaner syntax.

%prep
%setup

%build
sh configure --with-edit=gnu --prefix "$RPM_BUILD_ROOT" --mandir "$RPM_BUILD_ROOT/usr/share/man"
make

%install
make install

%files
/bin/rc
/usr/share/man/man1/rc.1.gz
