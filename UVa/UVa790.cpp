#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
#include <tuple>
#include <utility>
#include <functional>
#include <vector>
#include <cstring>

using namespace std;
constexpr int MAXT = 27, MAXP = 9;
struct Submission{
  int team, time, prob;
  bool status;
  Submission( int team_ = 0, int prob_ = 0, int time_ = 0, bool status_ = false) : team(team_), time(time_), prob(prob_), status(status_) {}
  bool operator<( Submission& rhs ){
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
  int solved, no, total_time;
  Team( int no_ = 0, int solved_ = 0, int total_time_ = 0 ) : solved(solved_), no(no_), total_time(total_time_) {}
  bool operator<( Team& rhs ){
    if( solved != rhs.solved )
      return solved > rhs.solved;
    else if( total_time != rhs.total_time )
      return total_time < rhs.total_time;
    else
      return no < rhs.no;
  }
  bool operator==( Team& rhs ){
    return solved == rhs.solved and total_time == rhs.total_time;
  }
};

int rejections[MAXT][MAXP] {};
bool done[MAXT][MAXP] {};
int max_sub {};
vector<Submission> subs( 10000 );

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  char c {}, st {};
  int TEAM {}, MAX_TEAM {}, tc {}, HRS {}, MIN {};
  string PROB {}, STATUS {}, SUB_TIME {}, line {};
  getline( cin, line );
  tc = stoi( line );
  getline( cin, line ); // blank line
  while( tc -- ){
    memset( rejections, 0, sizeof rejections );
    memset( done, 0, sizeof done );
    max_sub = 0;
    MAX_TEAM = 0;
    while( getline( cin, line ) ){
      if( line == "" )
	break;
      // get data separated, tokenized
      istringstream iss( line );
      iss >> TEAM >> PROB >> HRS >> c >> MIN >> st;
      // convert the values
      // save the submission
      subs[max_sub].team = TEAM;
      subs[max_sub].prob = PROB[0] - 'A';
      subs[max_sub].time = HRS * 60 + MIN;
      subs[max_sub].status = (st == 'Y');

      ++ max_sub;
      if( TEAM > MAX_TEAM ) MAX_TEAM = TEAM;
    }
    sort( subs.begin(), subs.begin() + max_sub );
    vector<Team> teams( MAX_TEAM + 1 );
    for( int i = 0; i < max_sub; ++ i ){
      int P = subs[i].prob, M = subs[i].team, T = subs[i].time;
      bool S = subs[i].status;
      if( S ){
	if( not done[M][P] )
	  done[M][P] = true;
	else
	  continue;
	// add the problem
	++ teams[M].solved;
	teams[M].no = M;
	// add time and penalty
	teams[M].total_time += T + rejections[M][P] * 20;
      }
      else{ // status = false
	if( not done[M][P] )
	  ++ rejections[M][P];
      }
    }
    for( int i = 1; i < teams.size(); ++ i )
      if( teams[i].no == 0 )
	teams[i].no = i;
    sort( teams.begin() + 1, teams.end() );
    cout << "RANK TEAM PRO/SOLVED TIME\n";
    int probs {}, total_time {}, rank {}, prev {};
    for( int i = 1; i < (int)teams.size(); ++ i ){
      probs = teams[i].solved;
      total_time = teams[i].total_time;
      TEAM = teams[i].no;
      int prev_probs {}, prev_total_time {};
      prev = rank;
      if( i > 1 ){
	prev_probs = teams[i - 1].solved;
	prev_total_time = teams[i - 1].total_time;
	if( prev_probs == probs and prev_total_time == total_time )
	  rank = prev;
	else
	  rank = i;
      }
      else
	rank = i;
      cout << setw( 4 ) << right << rank << " "
	   << setw( 4 ) << right << TEAM;
      if( probs > 0 ){
	cout << " " << setw( 4 ) << right << probs << "       "
	     << setw( 4 ) << right << total_time;
      }
      cout << '\n';
    }
    if( tc )
      cout << '\n';
  }
  return 0;
}
