# Makefile for psf.c percepsfon predictor.
# Makes ./psf (C version) and ./psfxx (C++ version) Linux terminal applications.
# Windows can run Linux as a subsystem.
# (C) Copyright 2026 Larry B. Daniel Atlanta, Ga.

all:	psf psfxx

.c.o:
	cc -c $< -o $@

.cpp.o:
	c++ -c $< -o $@

psf: 	psf.o
	cc $< -o $@ -lm

psfxx:	psf.cpp self.h
	c++ psf.cpp -o $@ -lm

clean: 
	rm -f *.o psf psfxx
