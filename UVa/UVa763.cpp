#include <bits/stdc++.h>

using namespace std;

class BigInt{
public:
  vector<int> data;
  int sign;
  BigInt(){};
  BigInt( long long n ){
    if( n == 0 ) sign = 0;
    else sign = (n > 0 ? 1 : -1);
    while( n ){
      data.emplace_back( n % 10 );
      n /= 10;
    }
  };
  BigInt( long long d, long long amount ){
    if( d > 10 )
      d = d % 10;
    data.assign( d, amount );
  };
  
  void set_val( long long n ){
    int idx = 0;
    if( n == 0 ) sign = 0;
    else sign = (n > 0 ? 1 : -1);
    while( n ){
      data[idx ++] = n % 10;
      n /= 10;
    }
  }

  void set_val( long long d, long long amount ){
    data.assign( d, amount );
  }

  int at( unsigned int idx ){
    if( idx < data.size() ) return data[idx];
    else return 10;
  }

  int& operator[]( unsigned int idx ){
    return data[idx];
  }
  
  size_t size(){ return data.size(); }

  void emplace_back( int digit ){
    if( digit > 10 )
      data.emplace_back( digit );
    else{
      while( digit ){
	data.emplace_back( digit % 10 );
	digit /= 10;
      }
    }
  }
  
  BigInt operator+( BigInt& rhs ){
    int carry = 0;
    int mi = min( this->data.size(), rhs.size() ), ma = max( this->data.size(), rhs.size() );
    BigInt ans( 0, ma );
    for( int i = 0; i < mi; ++ i ){
      int a = this->data[i], b = rhs[i];
      int c = a + b + carry;
      if( c >= 10 ){
	carry = 1;
	ans[i] = c % 10;
      }
      else{
	ans[i] = c;
	carry = 0;
      }
    }
    for( int i = mi; i < ma; ++ i ){
      int tmp;
      if( (tmp = rhs[i] + carry) >= 10 ){
	ans[i] = tmp % 10;
	carry = 1;
      }
      else{
	ans[i] = tmp;
	carry = 0;
      }
    }
    if( carry ) ans.emplace_back( carry );
    return ans;
  }

  string to_string(){
    string s( '0', data.size() );
    for( size_t i = 0; i < data.size(); ++ i )
      s[i] = '0' + data[i];
    return s;
  }
};

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  BigInt a(5);
  cout << a.to_string() << endl;
  return 0;
}
