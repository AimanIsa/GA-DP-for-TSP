# GA + DP to solve Travelling Salesman Problem 

Objective: 
Find the shortest path 

Requirements: 
1. Need to visit all the cities 
2. Need to return to the first point
3. Can not visit the same city twice

## Basic - Genetic Algorithm (GA) 

An optimization technique known as a genetic algorithm (GA) draws its inspiration from natural selection and evolution. 

### Step by step for GA

>1. Begin
 >> 2.    Initialization of the cities;
 >> 3.    Evaluation;
 >> 4.    Repeat 
 >> 5.    Selection ;
 >> 6.    Crossover;
 >> 7.    Mutation;
 >> 8.    Evaluation;
 >> 9.    Until (Criteria Stopping);
>10.  End



## Modified  - GA + Dynamic Programming (DP)

The Traveling Salesman Problem can be resolved by combining Genetic Algorithms (GA) with Dynamic Programming (DP) (TSP). A collection of potential TSP solutions may be created using GA, and these can then be optimised using DP. Because GA can offer a decent initial estimate and DP can refine it, using GA and DP together can produce high-quality solutions for TSP in a reasonable period of time.

In the Dynamic Programming (DP) method, issues are divided into smaller subproblems, each of which is then solved in turn to produce a solution to the larger problem.

### Step by step for DP

>1. Begin
 >> 2.    Initialization of the cities;
 >> 3.    Evaluation;
 >> 4.    Repeat 
 >> 5.    Selection;
 >> 6.    Crossover;
 >> 7.    Mutation;
 >>>  8.   Apply DP approach
 >> 9.    Evaluation;
 >> 10.    Until (Criteria Stopping);
>11.  End


## Sample Problem

This is one of the example of TSP problem.
Let's say we have 4 cities and the path value is given and can be reffered from the figure below:-

![tsp problem](https://user-images.githubusercontent.com/94151132/216835744-7aa47c4d-4c75-4bc4-ab95-7697e626b1b1.png)

Solve this problem using basic and modified algorithm 

### Strategy 

1. Change into matrix form 

![Untitled Diagram drawio](https://user-images.githubusercontent.com/94151132/216835946-73777ecf-10ab-4f68-b4b4-0f570fcf92e9.png)

2. set the matrix
3. follow the basic and modified algorithm 
4. The code as follow 
> 1. [Basic](https://github.com/AimanIsa/GA-DP-for-TSP/blob/main/Basic%20Genetic%20Algorithm.cpp)
> 2. [Modified](https://github.com/AimanIsa/GA-DP-for-TSP/blob/main/Modified%20GA%20%2B%20DP.cpp)

### Expected outcome for optimal solution 

03120 and 02130 with Fitness value is 9. Due to, both paths are the lowest or the shortest path compared the other path. 
