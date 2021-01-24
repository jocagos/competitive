#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#include <functional>
#include <tuple>
#include <cstring>
#include <cstdio>

using namespace std;
constexpr int MAXT = 26, MAXP = 8;
bool done[MAXT][MAXP] {}; // {} nos permite inicializarlo por defecto
int rejections[MAXT][MAXP] {};

struct Submission{
  int team, time, prob;
  bool status;
  Submission( int team_ = 0, int time_ = 0, int prob_ = 0, bool status_ = false ) : team(team_), time(time_), prob(prob_), status(status_) {}
  bool operator<( const Submission& rhs ){
    if( time != rhs.time )
      return time < rhs.time;
    else if( prob != rhs.prob )
      return prob < rhs.prob;
    else if( team != rhs.team )
      return team < rhs.team;
    else
      return status < rhs.status;
  }
};

struct Team{
  int no, total_time, solved;
  Team( int no_ = 0, int total_time_ = 0, int solved_ = 0 ) : no(no_), total_time(total_time_), solved(solved_) {}
  bool operator<( Team& rhs ){
    if( solved != rhs.solved )
      return solved > rhs.solved;
    else if( total_time != rhs.total_time )
      return total_time < rhs.total_time;
    else
      return no < rhs.no;
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int tc {}, max_team {}, team {}, hrs {}, min {};
  char c {}, status {};
  string line {}, PROB {};
  getline( cin, line );
  tc = stoi( line ); // string to integer, C++11 // tc = atoi( line.c_str() );
  getline( cin, line ); // blank line
  while( tc -- ){
    memset( done, 0, sizeof done );
    memset( rejections, 0, sizeof rejections );
    max_team = 0;
    vector<Submission> subs;
    while( getline( cin, line ) ){
      if( line == "" ) // whenever we find a blank line, we stop processing input
	break;
      istringstream iss( line ); // assigns line to the input string stream
      iss >> team >> PROB >> hrs >> c >> min >> status;
      // constructs a Submission object at the back
      subs.emplace_back( team, hrs * 60 + min, PROB[0] - 'A', (status == 'Y') );
      max_team = max( team, max_team );
    } // end while getline
    // 2 ways of sorting:
    // * Overloading a comparison operator you are going to use
    // * Create a lambda function
    sort( subs.begin(), subs.end() );
    // LAMBDA
    // sort( subs.begin(), subs.end(),
    // []( Submission& lhs, Submission& rhs ) -> bool {
    //   if( lhs.time != rhs.time ) return lhs.time < rhs.time;
    //   else if( lhs.prob != rhs.prob ) return lhs.prob < rhs.prob;
    //   else if( lhs.team != rhs.team ) return lhs.team < rhs.team;
    //   else return lhs.status < rhs.status;
    // } );
    /* FIN LAMBDA */
    // using 1-based index
    vector<Team> teams( max_team + 1 );
    for( int i = 1; i <= max_team; ++ i )
      teams[i].no = i;
    for( int i = 0; i < (int)subs.size(); ++ i ){
      int p = subs[i].prob, n = subs[i].team, t = subs[i].time;
      bool s = subs[i].status;
      if( s ){
	if( not done[n][p] )
	  done[n][p] = true;
	else
	  continue;
	++ teams[n].solved;
	teams[n].total_time += t + rejections[n][p] * 20;
      } // end if s
      else{
	if( not done[n][p] )
	  ++ rejections[n][p];
      } // end else
    } // end for i in subs
    sort( teams.begin() + 1, teams.end() );
    cout << "RANK TEAM PRO/SOLVED TIME\n";
    int rank {}, prev {}, t_time {}, pr {};
    for( int i = 1; i < (int) teams.size(); ++ i ){
      pr = teams[i].solved;
      t_time = teams[i].total_time;
      team = teams[i].no;
      int prev_pr {}, prev_t_time {};
      prev = rank;
      if( i > 1 ){
	prev_pr = teams[i - 1].solved;
	prev_t_time = teams[i - 1].total_time;
	if( prev_pr == pr and prev_t_time == t_time )
	  rank = prev;
	else
	  rank = i;
      } // end if i > 1
      else
	rank = i;
      cout << setw( 4 ) << right << rank << " "
	   << setw( 4 ) << right << team;
      if( pr > 0 ){
	cout << " " << setw( 4 ) << right << pr << "       "
	     << setw( 4 ) << right << t_time;
      }
      cout << '\n';
    } // for i in teams
    if( tc )
      cout << '\n';
  } // end tc --
  return 0;
}
