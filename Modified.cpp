#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//Parameter (Pc and Pm from the article)
const int Num = 4; 					// number of cities
const int Generation = 5; 			// number of generations
const int Pop_size = 10; 			// population size
const double Pc = 0.8; 				// crossover probability
const double Pm = 0.03; 			// mutation probability

int x[Num], y[Num];
int n, m;
int dp[1<<Num][Num];
const int INF = 1e9;

//Structure for city and Salesman 
struct city {int x, y;};

struct Salesman
{
    vector <int> path;
    int fitness;
};

vector <city> cities;
vector <Salesman> population;
//---------------------------------//

//Calculate the distance between two cities
double distance(city A, city B)
{
    double x = pow(A.x - B.x, 2);
    double y = pow(A.y - B.y, 2);
    return sqrt(x + y);
}

//Calculate the fitness between two cities
void calculateFitness()
{
    for (int i = 0; i < Pop_size; i++)
    {
        Salesman man = population[i];
        double totalDistance = 0; 		// Set total distance is 0
        
        for (int j = 0; j < Num - 1; j++)
        {
            int cityA = man.path[j];
            int cityB = man.path[j + 1];
            totalDistance += distance(cities[cityA], cities[cityB]);
        }
        man.fitness = totalDistance;
        population[i] = man;
    }
}
//------------------------------------------------------------------//

//Initialization the cities and population of Salesman 
void initialCities()
{
    for (int i = 0; i < Num; i++)
    {
        city City;
        City.x = rand() % 100;				// Random city Start
        City.y = rand() % 100;				// Random city end
  //      cities.push_back(city);
    }
}

void initialPopulation()
{
    for (int i = 0; i < Pop_size; i++)
    {
        Salesman man;
        man.path.resize(Num);
        for (int j = 0; j < Num; j++)
        {
            man.path[j] = j;
        }
        random_shuffle(man.path.begin(), man.path.end());
        population.push_back(man);
    }
}
//------------------------------------------------------//

//Selection

Salesman selectParent()					// Randomly select parent from population
{
    int i = rand() % Pop_size;
    return population[i];
}

//Crossover 

Salesman crossover(Salesman A, Salesman B)
{
    Salesman child;
    child.path.resize(Num);
    
    int Start = rand() % Num;
    int end = rand() % Num;
    
    if (Start > end){swap(Start, end);} 	// Compare Start and end 
    
    for (int i = Start; i <= end; i++)
    {
        child.path[i] = A.path[i];
    }
    for (int i = 0; i < Num; i++)
    {
        int city = B.path[i];
        if (find(child.path.begin() + Start, child.path.begin() + end + 1, city) == child.path.begin() + end + 1)
        {
            for (int j = 0; j < Num; j++)
            {
                if (child.path[j] == -1)
                {
                    child.path[j] = city;
                    break;
                }
            }
        }
    }
    return child;
}

//Mutation 

void Mutation(Salesman &man)
{
    for (int i = 0; i < Num; i++)
    {
        double random = (double)rand() / RAND_MAX;
        
        if (random < Pm)				// Pm = 0.03; // mutation probability
        {
            int indexA = rand() % Num;
            int indexB = rand() % Num;
            swap(man.path[indexA], man.path[indexB]);
        }
    }
}

//Evaluation

void Evaluate()
{
    vector <Salesman> newPopulation;
    newPopulation.resize(Pop_size);
    
    for (int i = 0; i < Pop_size; i++)
    {
        Salesman pA = selectParent();		//Select parent A
        Salesman pB = selectParent();		//Select parent B
        
        Salesman child = crossover(pA, pB);
        Mutation(child);
        newPopulation[i] = child;
    }
    population = newPopulation;
}

//------------------------------------------------------//
// Function to display the optimal solution 
void optimal(){
	
	int Optimal = 0;
	
    for (int i = 0; i < Pop_size; i++)
    {
        if (population[i].fitness < population[Optimal].fitness)
        {
            Optimal = i;
        }
    }
    Salesman best = population[Optimal];
    
    cout << "The optimal path: ";
    for (int i = 0; i < Num; i++)
    {
        cout << best.path[i] << " ";
    }
    cout << endl;
    cout << "Optimal fitness: " << best.fitness << endl;

}
//------------------------------------------------------//

int dynamic (){
	
		int Cities[Num][Num];
						 
		int S = Num, v;
	
		//  If the set S is empty, return the distance from the current city to the starting city
 	    if (S == (1<<Num) - 1){
 	   		dist(v, 0);
		}
    
        if (Cities[S][Num] != INF){
    		 // Iterate through all cities that have not been visited
 		   for (int i = 0; i < Num; i++) {
       		 if (!(S >> i & 1)) {
       		 	
            // Calculate the minimum distance to visit all the cities in the set
            Cities[S][v] = min(Cities[S][v], dist(v, i) + dynamic(1<<i), i));
            
        return Cities[S][v];
    
}


//Main function
int main(){
	
    initialCities();
    initialPopulation();
    

    
    for (int i = 0; i < Generation; i++)
    {
        calculateFitness();
        Evaluate();	
    }
	
	optimal();
	
	cout << "Dynamic Programming approach\n";
	
	cout << dynamic(1, 0) << endl;
   
    }
	
	return 0;
}


//Note: The code is not working for GA because 
// I only followed the steps needed from article
// Selection , Crossover and Mutation

//for dynamic programming's function also did not work
//Because it must determine a set of data first to solve it. 



