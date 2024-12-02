SubsetsII: SubsetsII.o
	g++ -g -o SubsetsII.exe SubsetsII.o -pthread    

SubsetsII.o: SubsetsII/SubsetsII.cpp
	g++ -g  -c -pthread SubsetsII/SubsetsII.cpp
