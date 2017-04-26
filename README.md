# McFTP
Multi-core Fast Thermal Prototyping framework

McFTP is a general thermal framework enabling the designers to prototype
different thermal managing approaches in a fast, efficient manner. 
It offers reasonable accurate temperature results to compare the relative 
performance of different thermal approaches.

How to install McFTP in Linux:

The installation requires CMake 2.8.
1. switch to the build directory:

	cd build
	
2. invoke CMake. 
	
	cmake ..
	
3. compile with make.
	
	make
	
Then the executable program named 'mcftp' will be created.
Users should run mcftp with root priviledge.

Example:

	sudo ./mcftp test.xml
