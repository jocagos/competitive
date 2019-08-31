#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFSZE 200

struct book{
  char title[100];
  char author[100];
};

typedef struct book Book;

int findTitle( Book * array, char * query, int maxSize ){
  int k = 0;
  for( k; k < maxSize; ++k ){
    if( strcmp(array[k].title, query) == 0 ) return k;
  }
  return -1;
}

int find( Book * array, Book * query, int maxSize ){
  int k = 0;
  for( k; k < maxSize; ++k ){
    if( strcmp(array[k].title, query->title) == 0 && strcmp(array[k].author, query->author) == 0 ) return k;
  }
  return -1;
}

int main(){
  int i = 0, j = 0, maxBooks = 0;
  char line[BUFSZE];
  Book shelves[10000];
  Book borrowed[10000];
  Book returned[10000];
  while( strncmp(line, "END", 3) != 0 ){
    fgets( line, BUFSZE, stdin );
    if( strncmp(line, "END", 3) == 0 ) break;
    sscanf( line, "\"%[^\"]\" by %[^\n]", shelves[maxBooks].title, shelves[maxBooks].author );
    maxBooks++;
  }
  qsort( shelves, maxBooks, sizeof(Book), cmp );
  char query[100];
  int maxBorrowed = 0;
  int maxReturned = 0;
  while( 1 ){
    fgets( line, BUFSZE, stdin );
    if( strncmp(line, "END", 3) == 0 ) break;
    if( strncmp(line, "SHELVE", 6) == 0 ){
      if( maxReturned == 0 ) printf("END\n");
      else{
	for( j = 0; j < maxReturned; ++j ){
	  int idx = find( shelves, (returned+j), maxReturned );
	  if( idx == 0 ) printf("Put \"%s\" first\n", shelves[idx].title);
	  else printf("Put \"%s\" after \"%s\"\n", shelves[idx].title, shelves[idx-1].title);
	}
	memset( returned, 0, sizeof(returned) );
	maxReturned = 0;
	printf("END\n");
      }
    }
    if( strncmp(line, "RETURN", 6) == 0 ){
      sscanf( line, "RETURN \"%[^\"]\"", query );
      int idx = findTitle(shelves, query, maxBorrowed);
      strcpy(returned[maxReturned].title, shelves[idx].title);
      strcpy(returned[maxReturned].author, shelves[idx].author);
      maxReturned++;
      if( idx == maxBorrowed - 1 ) maxBorrowed--;
      else{
	for( i = idx; i < maxBorrowed-1; ++i ){
	  strcpy(borrowed[i+1].title, borrowed[i].title);
	  strcpy(borrowed[i+1].author, borrowed[i].author);
	}
	maxBorrowed--;
      }
    }
    if( strncmp(line, "BORROW", 6) == 0 ){
      sscanf(line, "BORROW \"%[^\"]\" ", query );
      int id = findTitle(shelves, query, maxBooks);
      strcpy(borrowed[maxBorrowed].title, shelves[id].title);
      strcpy(borrowed[maxBorrowed].author, shelves[id].author);
      maxBorrowed++;
    }
  }
  return 0;
}
