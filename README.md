# HackRush24Opt
This repository contains the problem description of the HackRush'24 Optimization Problem

### Testing the Code
The file `checker.py` will be the checker used to grade your code.        
   

To run the checker file run the following command    
```python checker.py <test_case_file> <output_file>```    
    
`test.zip` contains the test files.

## Running the solutions

I have inclucded 2 solutions in this repo, sol1.cpp and sol2.cpp you can complie them using the following command:

```
g++ ./sol1.cpp -o ./sol1.exe
./sol1.exe
```
This will compile and run the solution. The solution will read input from the terminal according to the given entry formate.


## Solution explinations:

### Solution 1:

Here I generate a DAG on the events. There will be an edge from a to b (a -> b) iff, a single person can attend a first and then event b. We can easily prove that this will be a dag. Then I identify the nodes with indegree 0 and store them. After that I randomly shuffle the people and I greedily choose the best starting event such that the satisfaction of that person is maximised.

### Solution 2:

Here I sort all the satisfactions in decreasing order and then I choose the ones which are possible based on the previously chosen ones and ignore the remaining.