/*
Author: Ariel Habshush
 
Project Name: Generalized Outer Product

Project Description:
The objective of this program is to implement a function that can compute a generalized outer product. The function
can accept an arbitrary number of 1D vectors and compute the multi dimensional outer product. The outer product is returned as
a 1D column vector arranged in lexicographical order (row-major order).

An outer-product between two 1D vectors can be computed by taking their Kronecker product (see: https://en.wikipedia.org/wiki/Kronecker_product).
The generalized outer-product can be computed by recursively taking the Kronecker product of each vector with the subsequent vector.   

Date: 5/14/2019
*/

#include <iostream>
#include <vector>

template<typename T>
void printArray(std::vector<T> A1){
	if(A1.size()==0)
		return;
	for(int i = 0; i < A1.size()-1; i++)
		std::cout << A1[i] << ",\n";
	std::cout << A1[A1.size()-1] << "\n";
}

// Kronecker product of two column vectors.
template<typename T>
std::vector<T> kron(std::vector<T> A1, std::vector<T> B1){
	int L = A1.size() * B1.size();
	std::vector<T> c (L,0);
	int iC = 0;
	for(int iA = 0; iA < A1.size(); iA++){
		for(int iB = 0; iB < B1.size(); iB++){
			c[iC] = A1[iA]*B1[iB];
			iC++;
		}//iA
	}//iB
	return c;
}

template<typename T>
std::vector<T> outer_product(std::vector< std::vector<T> > V){
	std::vector<T> result;
	if(V.size() == 0)
		return result;
	
	//Initialize result vector to 1 and begin recursion.
	result.push_back(1); 
	for(int iV = 0; iV < V.size(); iV++){
		result = kron(result,V[iV]);
	}
	return result;
}

int main (){	
	std::vector<double> A1 = {1,2};
	std::vector<double> B1 = {3,4,5};
	std::vector<double> C1 = {6,7,8,9};

	std::vector< std::vector<double> > V = {A1,B1,C1};

	std::vector<double> OP = outer_product(V);
	std::cout << "Outer Product = {" <<std::endl;
	printArray(OP);
	std::cout << "}"; 
	return 0;
}