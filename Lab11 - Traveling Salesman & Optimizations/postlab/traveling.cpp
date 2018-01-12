// Charles Buyas, cjb8qf, 4-25-17, traveling.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <string>
#include "middleearth.h"

using namespace std;

/** @brief This is the method declaration for my computeDistance function.
 *
 * This function will add up the distances between all nodes in a path.
 * @param me This takes in my Middle Earth object
 * @param start This holds the start of the path.
 * @param dests This is the itinerary vector.
 * @return This returns the total distance.
 * @todo Compute the distance
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests);

/** @brief This is the method declaration for my printRoute function.
 *
 * This function will loop through my itinerary and print
 * out all the locations I will visit in Middle Earth.
 * @param start Gets the start of the itinerary.
 * @param dests Gets the itinerary vector.
 * @todo Print the route
 */
void printRoute (string start, vector<string> dests);

int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    int width, height, num_cities, rand_seed, cities_to_visit;
    sscanf (argv[1], "%d", &width);
    sscanf (argv[2], "%d", &height);
    sscanf (argv[3], "%d", &num_cities);
    sscanf (argv[4], "%d", &rand_seed);
    sscanf (argv[5], "%d", &cities_to_visit);
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
    
    // YOUR CODE HERE
    
    float f = 0;
    string start;
    sort(dests.begin()+1, dests.end());
    start = dests[0];
    float tempSmallest = computeDistance(me, dests[0], dests);
    map<float, vector<string> > smallestMap;
    
    do {
      //cout << "Hello";
      f = computeDistance(me, dests[0], dests);
      if (f < tempSmallest) {
	tempSmallest = f;
	smallestMap[tempSmallest] = dests;
      }
    } while (next_permutation(dests.begin()+1, dests.end()));

    cout << "Your journey will take you along the path ";
    printRoute((smallestMap[tempSmallest])[0], smallestMap[tempSmallest]);
    cout << "and will have length ";
    cout << tempSmallest << endl;
    
    return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parameter, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  float totalDist = 0;
  for (int i = 0; i < dests.size()-1; i++) {
    totalDist += me.getDistance(dests[i], dests[i+1]);
    }
  totalDist += me.getDistance(dests[dests.size()-1], dests[0]);
  return totalDist;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
  string arrow = " -> ";
  for (int i = 0; i < dests.size(); i++) {
    if (i == dests.size()-1) {
      cout << dests[i];
    }
    else {
      cout << dests[i] << arrow;
    }
  }
  cout << arrow << start << endl;
}
