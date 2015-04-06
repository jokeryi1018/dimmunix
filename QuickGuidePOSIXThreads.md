# Quick Guide to Using Dimmunix for POSIX Threads #

This guide helps you install POSIX Threads Dimmunix and use it to immunize C/C++ programs against deadlock bugs.

We tested POSIX Threads Dimmunix on the following Linux distributions:
  * Ubuntu 9.10 32 bit
  * Ubuntu 9.04 32 bit
  * Ubuntu 8.10 32 bit
  * Ubuntu 9.10 64 bit
  * Fedora 11 32 bit
  * Fedora 9 32 bit

**We recommend you to run the instructions from this guide in Ubuntu. Run all instructions in the same terminal window.**

## Install POSIX Threads Dimmunix ##

Create a folder where to download Dimmunix
```
mkdir $HOME/Dimmunix
cd $HOME/Dimmunix
```

Install prerequisite packages
```
sudo apt-get install make gcc g++ scons
```
> The versions of these package on our Ubuntu 9.10 32 bit installation are: g++ 4.4.1, gcc 4.4.1, make 3.81, scons 1.2.0.


### Install Dimmunix From Source Code ###

1. Check out POSIX Threads Dimmunix
```
svn checkout http://dimmunix.googlecode.com/svn/trunk/pthreads dimmunix-pthreads
```
2. Compile POSIX Threads Dimmunix
```
cd dimmunix-pthreads/src
scons
cp libdimmunix.so $HOME/Dimmunix
```
> This will create libdimmunix.so shared library (in folder dimmunix-pthreads-src), that can be linked through LD\_PRELOAD to any C/C++ program.

### Install Dimmunix From Precompiled Binaries ###

Download Dimmunix library
```
cd $HOME/Dimmunix
wget http://dimmunix.googlecode.com/files/libdimmunix.so
```

## Use Dimmunix on Test C/C++ Programs ##

### If you installed Dimmunix from source code ###

In dimmunix-pthreads/test/test.cc, dimmunix-pthreads/test/hawknl/src/deadlock3.c and dimmunix-pthreads/test/sqlite/deadlock\_test/deadlock.c, you can find test programs that deadlock deterministically.

To compile and run the tests, run
```
cd $HOME/Dimmunix/dimmunix-pthreads/test
sh ./run_tests
```

In the first run, each test deadlocks and Dimmunix saves the deadlock history in the folder containing the test. In future runs, the test never deadlocks again.

### If you installed Dimmunix from precompiled binaries ###

  1. Check out the test programs
```
cd $HOME/Dimmunix
svn checkout http://dimmunix.googlecode.com/svn/trunk/pthreads/test dimmunix-pthreads-test
```
  1. To compile and run the tests, run
```
cd dimmunix-pthreads-test
sh ./run_tests
```