# Makefile for psf.c percepsfon predictor.
# Makes ./psf (C version)  Linux terminal applications.
# Windows can run Linux as a subsystem.
# (C) Copyright 2026 Larry B. Daniel Atlanta, Ga.

.c.o:
	cc -c $< -o $@

psf: 	psf.o
	cc $< -o $@ -lm

clean: 
	rm *.o
