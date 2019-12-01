#include <bits/stdc++.h>

using namespace std;

bool fits( vector<string>& large, vector<string>& small, int offx, int offy ){
  int sdim = small.size();
  for( int i {}; i < sdim; ++ i ){
    if( large[i + offx].substr( offy, sdim ) != small[i] ){
      cerr << "Checking >" << large[i + offx].substr( offy, sdim ) << "<"
	   << endl
	   << " and >" << small[i] << "<"
	   << endl;
      return false;
    }
    // for( unsigned j {}; j < small[i].length(); ++ j ){
    //   if( large[i + offx][j + offy] != small[i][j] )
    // 	return false;
    // }
  }
  return true;
}

void rotate( vector<string>& mat ){
  vector<string> tmp = mat;
  int dim = mat.size();
  for( int i {}; i < dim; ++ i ){
    for( int j {}; j < dim; ++ j ){
      mat[i][j] = tmp[j][dim - (i + 1)];
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string line {};
  while( getline( cin, line ) ){
    cerr << "line was >" << line << "<" << endl;
    int n {}, m {};
    istringstream iss( line );
    iss >> n >> m;
    if( (n | m) == 0 )
      break;
    int rot[4] {};
    vector<string> bmat( n, string(n, 'A') );
    for( int i {}; i < n; ++ i ){
      getline( cin, line );
      bmat[i] = line;
    }
    vector<string> smat( m, string(m, 'A') );
    for( int i {}; i < m; ++ i ){
      getline( cin, line );
      smat[i] = line;
    }
    int times = n - m;
    for( int rot_times {}; rot_times < 4; ++ rot_times ){
      for( int offx {}; offx < times; ++ offx )
	for( int offy {}; offy < times; ++ offy )
	  if( fits( bmat, smat, offx, offy ) )
	    rot[rot_times] ++;
      if( rot_times != 3 ){
	rotate( smat );
      }
    }
    for( int i = 0; i < 4; ++ i )
      cout << rot[i] << ( i < 3 ? " " : "\n" );
  }
  return 0;
}
