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
Basically the code is not working, however I can explain what are the functions did. 

1. struct city and Salesman : To create an object.
2. double distance() : Calculate the distance between two cities using formula sqrt ( x power of 2 + y power of 2 ) 
3. CalculateFitness() : to calculate the fitness and store in the object man 
4. initialCities() and initialPopulation() : to initialize initial city and population 
5. selectParent()	: Randomly select parent from Salesman
6. crossover(Salesman A, Salesman B) : The process for creating the child involves copying a piece of the route (which represents the sequence of visiting cities) from A to the child and then filling in the remaining cities from B while making sure there are no duplicates in the child's path.
7. Mutation(Salesman &man) : provides a mutation operation, a genetic operator that switches two cities to modify the solution at random.
8. Evaluate() : create a new population
9. Optinmal() : to calculate the optimal solution and display it. 

