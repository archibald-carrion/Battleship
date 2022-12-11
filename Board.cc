/**
 * CI-0118
 * Grupo 2 (Fco. Arroyo), 2022-ii
 *
 *  Ejemplo de una clase con interacción de métodos en ensamblador
 *
 *
 *   Compile: g++ -g testBoard.cc Vectoc.cc vector.s -o testBoard.out 
 *
**/

#include <iostream>
#include "Board.hpp"

/**
 *  Interface to assembly routines
**/
extern "C" long init( int );				// size
extern "C" void destroy( long * );			// addr
extern "C" void allset( long *, int, int );		// addr, size, value
extern "C" void eleset( long *, int, int );		// addr, pos, value
extern "C" long eleget( long *, int );			// addr, pos

/**
 *
 *  Creates a vector of size elements (long)
 *
**/
Board::Board(int size) {
   this->vector = (long *) init( size );	// Call init assembly routine
   if ( 0 == this->vector) {
      exit( 1 );
   }
   this->size = size;
}

/**
 *  Board constructor of size elements, initialized to value
 *  
**/
Board::Board(int size, long value) {
   this->vector = (long *) init(size);	// Call init assembly routine
   if ( 0 == this->vector) {
      exit(1);
   }
   this->size = size;
   this->allSet(value);
}

/**
 *
 *  Board destructor, assembly routine calls free method
 *
**/
Board::~Board() {
   destroy( this->vector );
}

/**
 *   Set the entire vector to an initial value
**/
void Board::allSet(long value) {
   allset(this->vector, this->size, value);
}

/**
 *   Set a specific position to a value
**/
void Board::set(int position, long value) {
   if ( position >=0 && position < this->size ) {
      eleset( this->vector, position, value );
   }
}

/**
 *   Get the vector to init value
**/
long Board::get(int position) {
   long rv = 0;

   if (position >=0 && position < this->size) {
      rv = eleget( this->vector, position );
   }

   return rv;
}

/**
 *   Print the vector
**/
void Board::print() {
   for (int pos = 0; pos < this->size; pos++) {
      std::cout << this->get(pos) << std::endl;
   }
   std::cout << std::endl;
}

void Board::printBoard() {
   for (int i = 0; i < 49; i++) {
      int symbol = this->get(i);
      if (symbol == 0) {
         std::cout << "~\t";
      } else {
         std::cout << this->get(i) << "\t";
      }
      if (i % 7 == 6) std::cout << std::endl;
   }
}