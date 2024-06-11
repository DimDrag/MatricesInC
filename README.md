# Matrices in C

This is my implementation of the matrix library in C programming language

![matrix](misc/matrix.png)

With this library you can:

- Compare matrices
- Add matrices
- Substract matrices
- Multiply matrices
- Multiply matrix by a number
- Transpose matrix
- Calculate matrix determinant
- Find matrix of algebraic complements
- Find inverse matrix


## Info

- This static library is developed in C language of C11 standard using gcc compiler
- Program code follows Google style
- There is full coverage of library functions code with unit-tests with the Check library
- The gcov_report Makefile target generates a gcov report in the form of an html page
- All operations (except matrix comparison) return the resulting code:
  - 0 - OK
  - 1 - Error, incorrect matrix
  - 2 - Calculation error (mismatched matrix sizes; matrix for which calculations cannot be performed, etc.)