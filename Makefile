CXXFLAGS = -Wall --std=c++23

1: BTH6_BT01.cpp
	g++ $(CXXFLAGS) BTH6_BT01.cpp -o .output/BT01; .output/BT01

2: BTH6_BT02.cpp
	g++ $(CXXFLAGS) BTH6_BT02.cpp -o .output/BT02; .output/BT02

3: BTH6_BT03.cpp
	g++ $(CXXFLAGS) BTH6_BT03.cpp -o .output/BT03; .output/BT03

4: BTH6_BT04.cpp
	g++ $(CXXFLAGS) BTH6_BT04.cpp -o .output/BT04; .output/BT04

5: BTH6_BT05.cpp
	g++ $(CXXFLAGS) BTH6_BT05.cpp -o .output/BT05; .output/BT05

6: BTH6_BT06.cpp
	g++ $(CXXFLAGS) BTH6_BT06.cpp -o .output/BT06; .output/BT06

7: BTH6_BT07.cpp
	g++ $(CXXFLAGS) BTH6_BT07.cpp -o .output/BT07; .output/BT07

8: BTH6_BT08.cpp
	g++ $(CXXFLAGS) BTH6_BT08.cpp -o .output/BT08; .output/BT08

9: BTH6_BT09.cpp
	g++ $(CXXFLAGS) BTH6_BT09.cpp -o .output/BT09; .output/BT09

10: BTH6_BT10.cpp
	g++ $(CXXFLAGS) BTH6_BT10.cpp -o .output/BT10; .output/BT10

BTL: BTL.cpp
	g++ $(CXXFLAGS) BTL.cpp -o .output/BTL; .output/BTL

clean:
	rm .output/*
