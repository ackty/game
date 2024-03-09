#include <stdio.h>
 
int main(){
  int bounds[ 2 ] = {1, 100};
  char input[ 2 ] = "  ";
    /* second char is for the newline from hitting [return] */
  int choice = (bounds[ 0 ] + bounds[ 1 ]) / 2;
    /* using a binary search */
 
  printf( "Choose a number between %d and %d.\n", bounds[ 0 ], bounds[ 1 ] );
 
  do{
    switch( input[ 0 ] ){
      case 'H':case 'h':
        bounds[ 1 ] = choice;
        break;
      case 'L':case 'l':
        bounds[ 0 ] = choice;
        break;
      case 'Y':case 'y':
        printf( "\nAwwwright\n" );
        return 0;
    }
    choice = (bounds[ 0 ] + bounds[ 1 ]) / 2;
 
    printf( "Is the number %d? (Y/H/L) ", choice );
  }while( scanf( "%1s", input ) == 1 );
 
  return 0;
}
