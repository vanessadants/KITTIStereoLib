.SUFFIXES:
.SUFFIXES: .c .cpp

CC = gcc
GCC = g++

.c:
	$(CC) -I$(INCDIR) $(CFLAGS) $< $(GL_LIBS) -o $@

.cpp:
	$(GCC) -Wall -Wunused -std=c++11 -O2 kitti_stereo_loader.cpp kitti_stereo_loader.h `pkg-config --cflags opencv` $< -o $@ `pkg-config --libs opencv` 
