#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
#include <limits.h>

using namespace std;

//initialize
const int NC = 4;					// Number of cities
const int Start = 0; 				// starting point 
const int population_size = 10; 	// population size

int x[NC], y[NC];
int n, m;
const int INF = 1e9;

// Structure for cities
struct individual{
	string city;					// path traversed
	int fitness;					// value of path length
}temp , new_City, p1, p2, optimal;


// Function to check if the city is already visited (repeat)
bool Visited(string s, char ch)
{
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ch)
			return true;
	}
	return false;
}

// Function to get random number to start and end
int random_num(int start, int end)
{
	int m = end - start;
	int num = start + rand() % m;
	return num;
}


// Function to check Mutated city
string mutatedCity(string city, int NC)

{
	while (true) {
		int r = random_num(1, NC);
		int r1 = random_num(1, NC);
		if (r1 != r) {
			char temp = city[r];
			city[r] = city[r1];
			city[r1] = temp;
			break;
		}
	}
	return city;
}

// Function to return a valid string city
string create_City(int NC)
{
	string city = "0";
	while (true) {
		if (city.size() == NC) {
			city += city[0];
			break;
		}
		int temp = random_num(1, NC);
		if (!Visited(city, (char)(temp + 48)))
			city += (char)(temp + 48);
	}
	return city;
}

// Function to return total path value of Cities
int Calculate_fitness(string city)
{
	int Cities[NC][NC] = {{ 0, 2, 1, 3 },
				       	 { 	2, 0, 3, 2 },
						 {	1, 3, 0, 5 },
						 { 	3, 2, 5, 0 }};

	int Fitness = 0;
	for (int i = 0; i < city.size() - 1; i++) {
		Fitness += Cities[city[i] - 48][city[i + 1] - 48];
	}
	return Fitness;
}

// Function to compare City Structure
bool Comparedlessthan(struct individual t1,	struct individual t2)
{ return t1.fitness < t2.fitness; }

int cooldown(int temp)
{
	return (90 * temp) / 100;
}




// Function to calculate the Euclidean distance between two cities
int distance(int i, int j) {
    return (int)sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}


// Main Function
int main(){

	cout << "--------------------------------------\n";
	cout << "    Modified - GA + DP \n";
	cout << "--------------------------------------\n\n";

     
	int Cities[NC][NC] = {{ 0, 2, 1, 3 },
				       	 { 	2, 0, 3, 2 },
						 {	1, 3, 0, 5 },
						 { 	3, 2, 5, 0 }};
    
    cout << "The matrix are given: " << endl;
    for (int i = 0; i < NC; i++) {
        for (int j = 0; j < NC; j++) {
            cout << Cities[i][j] << " ";
        }
        cout << endl;
    }
					 
						
	int generation 	= 1;		// Number of generation 
	int gen_Iteration = 4; 		// Number of Iteration 
	
	vector <struct individual> population;	

	// Populating the city pool.
	for (int i = 0; i < population_size; i++) {
		temp.city = create_City(NC);
		temp.fitness = Calculate_fitness(temp.city);
		population.push_back(temp);
	}

	cout << endl ;
	cout << "Initial population: " << endl << "Cities	 Path Value\n";
	for (int i = 0; i < population_size; i++)
		cout << population[i].city << " \t " << population[i].fitness << endl;
	cout << "\n";

	bool found = false;
	int temperature = 10000;

	// Function to crossover and mutation of cities.
	
	while (temperature > 1000 && generation <= gen_Iteration) {
	
		sort(population.begin(), population.end(), Comparedlessthan);
//		cout << "\nCurrent temp: " << temperature << "\n";
		vector< struct individual > new_population;

		for (int i = 0; i < population_size; i++) {
			
 			p1 = population[i];

			while (true) {
				
				string New_C  = mutatedCity(p1.city, NC);
				
				new_City.city = New_C ;
				new_City.fitness =Calculate_fitness(new_City.city);

				if (new_City.fitness <= population[i].fitness) {
					new_population.push_back(new_City);
					break;
				}
				else {

					// Accepting the rejected children at a possible probability above threshold.
					float Probability = pow(2.7, -1 * ((float)(new_City.fitness - population[i].fitness) / temperature));
					if (Probability > 0.5) {
						new_population.push_back(new_City);
						break;
					}
				}
			}
		}

		temperature = cooldown(temperature);
		population = new_population;
		cout << "\nGeneration " << generation << " \n\n";
		cout << "Cities	 Path Value\n";

		for (int i = 0; i < population_size; i++)
			cout << population[i].city << " \t " << population[i].fitness << endl;
		generation++;
	}
	
	
	//-------------------------------------------------------------------//
	// Dynamic Programming Approach
	
	
	cout << "Dynamic Programming approach\n";
	
	//  If the set S is empty, return the distance from the current city to the starting city
    if (S == (1<<NC) - 1){
    	distance(v, 0);
	}
    
    if (Cities[S][NC] != INF){
    	
    	 // Iterate through all cities that have not been visited
 		   for (int u = 0; u < NC; u++) {
       		 if (!(S >> u & 1)) {
       		 	
            // Calculate the minimum distance to visit all the cities in the set
            Cities[S][v] = min(Cities[S][v], distance(v, u) + DynamicProgramming(S | (1<<u), u));
        }
	}
    
    cout << Cities[S][v] ;
   
    }
    //-------------------------------------------------------------------//
	
	
	
	// Function to display the optimal solution 
	
	optimal = population[0];
	cout << "\nThe optimal path city is: ";
		
	for (int i = 0; i < population_size; i++){
		if (population[i].fitness < optimal.fitness){
			optimal = population[i];
			cout << population[i].city; 
		}	
	}
	
	cout << "\nThe shortest path : " << optimal.fitness << endl;
	
}

