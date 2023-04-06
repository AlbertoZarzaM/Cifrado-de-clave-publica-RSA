CXX		  := g++ 
CXX_FLAGS :=   -std=c++17 -ggdb 

all: RSA

RSA: 
	$(CXX)  -o ./RSA ./*.cpp 

clean:

	rm -f ./RSA