CXXFLAGS = -Wall --std=c++23
BTL: BTL.cpp
	g++ $(CXXFLAGS) BTL.cpp -o .output/BTL; .output/BTL

clean:
	rm .output/*
