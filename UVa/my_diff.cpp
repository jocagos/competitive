#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compare_files( string& filename_lhs, string& filename_rhs ){
  string line_lhs, line_rhs;
  string filename_out = "delta-" + filename_lhs + "-" + filename_rhs + ".out";
  ifstream lhs_handle( filename_lhs ), rhs_handle( filename_rhs );
  ofstream out_handle( filename_out );
  int line_no = 0;
  while( getline( lhs_handle, line_lhs ) and getline( rhs_handle, line_rhs ) ){
    if( line_lhs != line_rhs ){
      out_handle << "delta @ " << line_no << ":\n\tLHS: " << line_lhs << "\n\tRHS: " << line_rhs << '\n';
    }
    ++ line_no;
  }
}

int main(){
  string lhs = "UVa10942-right.out";
  string rhs = "UVa10942-gen.out";
  compare_files( lhs, rhs );
  return 0;
}
