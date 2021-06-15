# OuterProduct
Project Description:
The objective of this program is to implement a function that can compute a generalized outer product. The function
can accept an arbitrary number of 1D vectors and compute the multi dimensional outer product. The outer product is returned as
a 1D column vector arranged in lexicographical order (row-major order).

An outer-product between two 1D vectors can be computed by taking their Kronecker product (see: https://en.wikipedia.org/wiki/Kronecker_product).
The generalized outer-product can be computed by recursively taking the Kronecker product of each vector with the subsequent vector.   

Compile using the follwing command:
g++ main.cpp -o main.exe
