/*
*    Author: Brandon West
*    Practice with pointers, the tortiose and the hare race
*    Use pointers to control where the turtle and the hare are located
*
*    April 2018
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

#define FINISH 70 // definition for race length

// function calls for pointer to hare and tortiose
void position1 ( int* tPtr );
void position2 ( int* hPtr );
void printPositions ( int* tPtr , int* hPtr );

int main (void) //start main
{

    int turtle = 1, hare = 1, movement1 = 1, movement2 = 1, timer = 0, start = 0; // variables
    int choice; // Exit choice
    int *tPtr = &turtle; // tort pointer
    int *hPtr = &hare; // hare pointer



    printf ( "To have the tortiose and the hare race, press 1 [Any other character to exit]: " );
    scanf ( "%d", &start ); // input to start

    while ( start == 1 )
    {
         // HT is the visual for the pointers
        puts ( "BANG!!!!!!" );
        puts ( "AND THEY'RE OFF!!!!!" );
        puts ( "\nHT" );

        // while the hare or turtle isnt complete the course
        while ( turtle != FINISH, hare != FINISH )
        {
             // if hare and turtle is less than finish
            if ( turtle < FINISH, hare < FINISH )
            {
                 // second of sleep
                sleep(1);
                position1 ( &turtle );     //function call tort
                position2 ( &hare );    // fucntion call hare
                printPositions ( &turtle, &hare ); // function call print result
                timer++;
            }
            else
                break;
        }
               // the tortiose won
            if ( turtle > hare )
            {
                printf ( "THE TORTIOSE WINS!!!!\n" );
                printf ( "The race took: %ds\n", timer );
            }
          // hare has won
            else if ( hare > turtle )
            {
                printf ( "The hare wins. Yuch\n" );
                printf ( "The race took: %ds\n", timer );
            }

            else
            {
                printf ( "Tie race!\n" );
                printf ( "The race took: %ds\n", timer );
            }

        break; // stops while loop (No exit condition)
    } // end main while loop


} // end main

void position1 ( int *tPtr ) // function call for tortoise
{
     // random number
    srand (time ( 0 ));
    int turtle;

    // the turtles move
    turtle = 1 + ( rand() % 10 ) ;

    if ( turtle <= 5 )// movement1 <=5
    {
        *tPtr += 3;
    }

    else if ( turtle == 6 ) // movement1 = 6 && movement1 = 7
    {
        *tPtr -= 6;
    }
    else if ( turtle >= 7 ) // movement1 >=8
    {
        *tPtr += 1;
    }

    else // (movement1 < 1 )
    {
        *tPtr = 1;
    }
}// end of turtle fucntion

void position2 ( int *hPtr ) // function call for hare
{
     // hare random varailbe
    srand (time ( 0 ));
    int hare;

    hare = 1 + ( rand() % 10 );

    if ( hare <= 2)// movement2 <=2
    {
        *hPtr += 1;
    }
    else if ( hare == 3 || hare == 4 ) // movement2 = 6 && movement2 = 7
    {
        *hPtr = *hPtr;
    }

    else if ( hare >= 5 || hare <= 7 ) // movement2 >=8
    {
        *hPtr += 9;
    }

    else if ( hare >= 8 || hare <= 9 )// fall back 2 spaces
    {
        *hPtr -= 2;
    }

    else if ( hare == 10 )// (movement2 < 1 )
    {
        *hPtr -= 12;
    }

    else // sets to 1 if >1
    {
        *hPtr = 1;
    }
}// end of hare fucntion

void printPositions ( int *tPtr, int *hPtr ) // Race Print function start
{
    int movement;
    int turtle;
    int hare;
    // if turtle and hare are on same block
    if ( &turtle == &hare )
    {
        for ( movement = 0; movement < *tPtr; movement++ )
            {
                printf ( " " );
            }
        printf ( "OUCH!" );
    }
    // turtule ptr is lesstahn hare ptr
    else if ( *tPtr < *hPtr )
    {
         // moves position of turtle with white space
        for ( movement = 0; movement < *tPtr; movement++ )
            printf ( " " );

        printf ( "T" );
        // moves position of the hare with white sapce
        for ( movement = 0; movement < (*hPtr - *tPtr); movement++ )
            printf ( " " );

        printf ( "H" );
    }

    else
    {
         // move hare with white space
        for ( movement = 0; movement < *hPtr; movement++)
        {
            printf ( " " );
        }
        printf ( "H" );
        // move turtle
        for (movement = 0; movement < ( *tPtr - *hPtr ); movement++ )
        {
            printf ( " " );
        }
        printf ( "T" );
    }
    printf ( "\n" );


} // race print function, end.
