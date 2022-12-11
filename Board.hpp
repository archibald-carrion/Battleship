#ifndef BOARD
#define BOARD

 class Board {
   public:
      Board( int = 10 );		// Create the vector, malloc
      Board( int, long  );		// Create the vector, malloc
      ~Board();			// Destroy the vector, free
      void allSet( long );		// Set the entire vector to specific value
      void set( int, long );		// Set a position with specific value
      long get( int );			// Get a specific position
      void print();			// Print the vector to stdout
      long * vector;		// vector address
      void printBoard();
   private:
      int size;			// vector size
 };

 #endif