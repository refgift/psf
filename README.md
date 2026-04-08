# psf
- self detector
## Purpose
- Is teleoperated robot unstatisfying?
- If you ask who are you and robot turns and hides.
- Run this in your robot and eventually it will operate instead of teleoperate.
## Assumptions
- The robot has identity, values, beliefs and behaviors, Dilts heirarchy of itelligence.
- Dilts also decribes behavior as test-operate, test-exit (TOTE) which is how Marines are taught.
- The robot can learn. An example is from the movie "Kill Command" of study, analyze and reprogram (SAR) robots.
  The robots had self learning capability. I would add operate and loop states to that for completeness.
- My version is based on the read, evaluate, print, loop (REPL) of the LISP language. The REPL form of SAR
  is operate, study, analyze, reprogram, loop (OSARL)
## Build
- C version: `make psf` builds `./psf`
- C++ version: `make psfxx` builds `./psfxx`
- Both: `make` or `make all`
- The C++ version (psf.cpp) is a no-indirection port: all data is passed and returned by value with no pointers, references, or heap allocation.

