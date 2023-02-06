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

## How to use this code

