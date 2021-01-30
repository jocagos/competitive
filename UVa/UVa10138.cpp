/*
 * Rank 334 in UVa Online Judge!
 * It could be improved, but it already has 0.000s as time
 * The main idea is: sort input => process input
 */
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <sstream>
#include <tuple>
#include <vector>
#include <cmath>
#include <functional>
#include <algorithm>

using namespace std;
constexpr int HOURS = 24;
constexpr int MAX_PLATE = 1010;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc {};
  int hrate[HOURS] {};
  string line {};
  vector<tuple<long long, string, int, int>> input( MAX_PLATE );
  getline( cin, line );
  tc = stoi( line );
  getline( cin, line ); // blank
  while( tc -- ){
    getline( cin, line );
    istringstream isss( line );
    for( int i = 0; i < HOURS; ++ i )
      isss >> hrate[i];
    int input_idx {};
    while( getline( cin, line ) ){
      if( line == "" ) break;
      istringstream iss( line );
      string plate {}, tag {};
      char colon1 {}, colon2 {}, colon3 {} ;
      int month {}, day {}, hour {}, mins {}, km {};
      iss >> plate >> month >> colon1 >> day >> colon2
	  >> hour >> colon3 >> mins
	  >> tag >> km;
      input[input_idx ++] = make_tuple( month * 1000000LL + day * 10000LL + hour * 100LL + mins,
					plate,
					(tag[1] == 'n' ? 0 : 1), // this means "enter" since "exit" has no 'n' at pos 1
					km
					);
    }
    sort( input.begin(), input.begin() + input_idx,
	  []( tuple<long long, string, int, int>& lhs,
	      tuple<long long, string, int, int>& rhs ) -> bool{
	    if( get<0>( lhs ) != get<0>( rhs ) )
	      return get<0>( lhs ) < get<0>( rhs );
	    else
	      return get<1>( lhs ) < get<1>( rhs );
	  });
    map<string, int> enters, rates, bills;
    for( int i = 0; i < input_idx; ++ i ){
      if( get<2>( input[i] ) == 0 ){ // enter
	enters[get<1>( input[i] )] = get<3>( input[i] );
	rates[get<1>( input[i] )] = hrate[get<0>( input[i] ) / 100 % 100];
      }
      else if( get<2>( input[i] ) == 1 ){
	if( enters.find( get<1>( input[i] ) ) != enters.end() ){
	  bills[get<1>( input[i] )] +=
	    abs(
		enters[get<1>( input[i] )]
		-
		get<3>( input[i] )
		) * rates[get<1>( input[i] )] + 100;
	  enters.erase( get<1>( input[i] ) );
	}
      }
    }
    for( auto& bill : bills )
      cout << bill.first << " $"
	   << bill.second / 100 + 2 << "."
	   << setw( 2 ) << setfill( '0' )
	   << bill.second % 100 << '\n';
    if( tc ) cout << '\n';
  }
  return 0;
}
