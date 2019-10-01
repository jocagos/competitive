#include <bits/stdc++.h>

/*
 * Let's say we have N chambers and M specimens, we want to divide them in such a way that the average of space occupied in the chambers is as close to X as possible. This is known as load balancing.
 */

vector<int> chambers, specimens;

double load_balancing(){
  double avg = 0;
  // sort them
  sort( begin( specimens ), end( specimens ) );
  // pair the last with the first, second last with second, and so on
  for( unsigned i = 0; i < chambers.size(); ++ i ) chambers[i] += specimens[i] + *(specimens.end() - 1 - i);
  // compute average
  avg = sum( begin( chambers ), end( chambers ) ) / (1. * chambers.size());
  // then just return it
  return avg;
}
