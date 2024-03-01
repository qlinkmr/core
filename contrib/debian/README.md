
Debian
====================
This directory contains files used to package qlinkd/qlink-qt
for Debian-based Linux systems. If you compile qlinkd/qlink-qt yourself, there are some useful files here.

## qlink: URI support ##


qlink-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install qlink-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your qlink-qt binary to `/usr/bin`
and the `../../share/pixmaps/qlink128.png` to `/usr/share/pixmaps`

qlink-qt.protocol (KDE)

