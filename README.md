 a program in VS C++ 2017 to implement the algorithm for the Floyd's shortest path
 
problem shown in class. Your program should read in an input file containing weights for the

adjacency matrix of a weighted digraph. The input file should be named p4data.txt and hard

coded in your program. Your program then computes the D matrix and the P matrix for the

digraph and displays them to the screen (in a 2-dimensional fashion). The last thing your

program does before it quits is to prompt the user for two vertices (say, i and j) and compute and

display the shortest path from vertex i to vertex j. The following shows a scenario of running a

sample program, where user's inputs are represented in boldface. We assume the input file

contains information shown as follows. Note 9999 is used to represent ∞.

0 1 9999 1 5

9 0 3 2 9999

9999 9999 0 4 9999

9999 9999 2 0 3

3 9999 9999 9999 0

Program starts running ……

The following shows the D matrix and the P matrix, respectively.

0 1 3 1 4

8 0 3 2 5

10 11 0 4 7

6 7 2 0 3

3 4 6 4 0

0 0 4 0 4

5 0 0 0 4

5 5 0 0 4

5 5 0 0 0

0 1 4 1 0

Page 2 of 2

Enter a source vertex and a destination vertex: 2 5

The shortest path between the source and the destination is 2  4  5 with weight 5

More paths? y

Enter a source vertex and a destination vertex: 5 3

The shortest path between the source and destination is 5  1  4  3 with weight 6

More paths? n
