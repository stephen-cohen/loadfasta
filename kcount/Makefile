#
# loadfasta by Stephen Cohen <cohen.1107@osu.edu>
# Released under CC0 1.0 Universal - see LICENSE
#

TARGET=kcount
CC?=cc
CFLAGS=-Wall -Wextra -Wpedantic
CFILES=kcount.c ../loadfasta.c
default:
	$(CC) -o $(TARGET) $(CFILES) $(CFLAGS)
all: default
