/*=============================================================
| Source code:Perfect_number_roots.c
|      Author:Alexis Gonzalez
|   Assignment:2
|
|      Course:Programing 3
|     Section:U03
|  Instructor:William Feild
|    Due Date:25 September, 2018
|
|	I hereby certify that this collective work is my own
|	and none of it is the work of any other person or entity
|
|	___________________________________________________
|
|    Language:C
| Compile/Run: gcc Perfect_number_roots.c -lm
|              ./a.out
|+--------------------------------------------------------------
| Description: This program finds perfect numbers within a pre-
|              determined range, and for every perfect number it 
|              finds, it calculates the square root of it using
|              the Babylonian Method and prints the results.
|
|       Input:N/A
|
|      Output: For every perfect number, the following should be
|              printed to the screen:
|               Perfect number X = factor1 + factor 2 + .....
|               Expected square root of x = 
|               Computed square root of x = 
|               Iterations: 
|
|
|     Process: This program starts by looping through every number
|              in the pre-programed range. Each number is passed
|              into the Perfect_number_calculation function.
|              If it's found to be a perfect number, the function
|              prints out it's factors and returns a 1. 
|              When a 1 is returned, that number is then passed
|              into the Calculated_inital_seed and Babylonian_
|              method where a calculated square root is printed.
|
| Required Features Not Included: n/a
|
|  Known Bugs: n/a
|
|*===============================================================*/
#include <stdio.h>
/*
| math.h is for the square root function and power function
|
*/
#include <math.h>

double Calculated_inital_seed(int number);
void Babylonian_method(double seed , int number);
int Perfect_number_calculation(int number);
void Number_loop();
void Intro();
/*
|
| Max_a_value - Maximum value a can be in seed calculation for 
|               Babylonian method
|
| A_determinant - Value that helps determine final  a value for 
|                 Babylonian method
|
*/
const int Max_a_value = 100;
const int A_determinant = 10;
const int decimal_precision = 15;
const int Array_max = 300;
const int Start_factor = 2;
const int Number_check_min = 0;
const int Number_check_max = 10000;
// Calls number_loop to start looping in the given range
int main()
   {
   Intro();
   Number_loop();
   }
/*
| int current_number (set to Number_check_min)
|               Used to keep track of the loop position
| double expected_root ( square function)
|               Used to print expected square root
| int seed - ( set with calculated inital seed function)
|              Used to pass a seed number into the Babylonian method
|
|
| This function loops from Number_check_min to Number_check_max
| and passes values into the Perfect_number_calculation method.
| If a 1 is returned, the actual square root is printed and the
| number is passed into the Calculated_inital_seed function.
| The resulting seed and number are then passed into the 
| Babylonian_method function.
*/
void Number_loop()
   {
   int current_number=Number_check_min;
   for(current_number;current_number <= Number_check_max;
       current_number++)
      {
      if(Perfect_number_calculation(current_number) == 1)
         { 
         double expected_root = sqrt(current_number);
         printf("Expected Square Root = %.*f \n", 
         decimal_precision,expected_root);
         int seed = Calculated_inital_seed(current_number);
         Babylonian_method(seed,current_number);
         printf(" \n \n \n");
         }
  
      }
   return;
   }
   // Prints the introduction
void Intro()
   {
   printf("This program loops through numbers from %d to %d to \n"
          "find perfect numbers. If one is found, the number \n"
          "is printed with it's factors. Perfect numbers will \n"
          "also have their square roots calculated using \n"
          "the Babylonian method. \n \n \n \n \n "
          ,Number_check_min,Number_check_max);
   }

/*
| Number- (Function Argument)
|        Used so this function can find a square root seed of it
| Power- (set to 0)
|        Used to keep track of the power used in the seed formula
| Seed- ( set  based on inputed number)
|        Used to return calculated inital seed
|
| This Function generates a seed to be used in the Babylonian method.
|
|    The formula used : 
|
|     S=a * pow(10, 2n) 
|       
|     Square_root(S) = Square_root(a) * pow( 10, n) can be estimated
|                        as
|     Square_root(S)=|2 * pow(10 , n)  if a<10
|                    |6 * pow(10 , n) if a>= 10
|
|  Source : https://en.wikipedia.org/wiki/Methods_of_computing_squares
|
|    This Function takes in a number (S), and sets the base power(n) to 1
|
|    Next the function executes the following loop : 
|       Checks if number (a) is between 1 and 100.
|             if not:  divide number by 100, add 1 to power
|
|    After the loop, the function checks if number is less than
|    10 or equal/greater to 10 and assigns the correct seed.
|
|    Returns the calculated seed
*/
double Calculated_inital_seed(int number)
   {
   int power = 0;
   double seed = 0;
   while(number > Max_a_value )
      {
      power++;
      number = number / 100;
      }
   if (number < A_determinant)
      {
      seed = 2 * pow(10 , power) ;
      }
   else 
      {
      seed = 6 * pow(10 , power);
      }
   return seed;
   }
/*
| Double seed - (function argument)
|          seed used in the Babylonian method
| int number - (function argument)
|           number for which the square root is being calculated
| double next_calculated_seed- (set to 0)
|           seed calculated using the Babylonian method
| int iterations - (set to 0)
|            number used to track iterations 
| int solved - (set to 0)
|            number used to see if the Babylonian method can stop
| double high_prec ( set to 0)
|            number to test precision of next_calculated_seed
| double low_prec ( set to 0) 
|             number to test precision of next_calculated_seed
|
|    This function uses the Babylonian Method to calculate the square 
|    root of a number. ( http://en.wikipedia.org/wiki/Methods_of
|                        _computing_square_roots)
|
|      Formula- X_n+1=.5(X_n + S/X_n)
|
|
|   The function starts with the loop that calculates the Square
|   root. The function calculates X_n+1, then checks if it is equal
|   to X_n for up to a specific precision ( decimal_precision). If
|   it is, solved = 1 and the loop stops. If not, X_n+1 is set to 
|   seed, and X_n+2 is calculated.
|
|   After the loop, the answer is printed to terminal along with 
|   the number of iterations.
|
|
*/


void Babylonian_method(double seed ,int number )
   {
   double next_calculated_seed = 0.0;
   int iterations = 0;
   int solved = 0;
   double low_prec = 0;
   double high_prec = 0;
   do
      {
      next_calculated_seed = 0.5 * ( seed + ( number / seed) );
      iterations++;
      high_prec = next_calculated_seed * pow( 10, decimal_precision); 
      low_prec = seed * pow( 10, decimal_precision);
     
      if ((long int)high_prec == (long int)low_prec)
         {
         solved = 1;
         }
      else
         {
         seed = next_calculated_seed;
         }
      }
   while ( solved == 0);
   printf("Computed square root of %d: %.*lf \n "
          "Iterations: %d \n" ,number,decimal_precision,
          next_calculated_seed,iterations);
 
   return;

   }
/* 
| int number - (function paramater)
|           number thats being checked if it's a perfect number
| int current_factor - (set to 2)
|           number used to check factors in a loop.
| int max_factor ( set to number)
|           used to keep track of the highest possible factor
| int sum_of_factors ( set to 1)
|           used to keep track of the sum of founf factors
| int factor_array ( max array = 300)
|          used to store factors found for possible output
| int current_array_left (set to 0)
|          used to keep track of location for storing on the left side
|          of the array
| int current_array_right ( set to max_array - 1)
|          used to keep track of location for storing for the right 
|          side of the aray
| int print_array ( set to 0)
|          used to keep track of location when printing values in 
|          the array
|
|   This function checks if the inputed number is a perfect number.
|   A perfect number is a number whose factor's sum ( excluding the
|   number ) is the number.  ( https://en.wikipedia.org/wiki/
|    Perfect_number) The function prints out the number and it's
|   factors and returns a 1. If not, a 0 is returned.
|                  
|    The inital for loop that checks if number is perfect is :
|       for every possible factor up to the max possible factor:
|       if it is a factor:
|          add to sum, store the factor on the left side of array
|          get the other factor that multiplies it to get number,
|          add that to sum, and store on right side of array
|       after the loop changes the max possible to the rounded int
|       of the previous number divided by current tested factor .
|
|    Ex- 120, start = 2 , max = 120
|        2 % 120 = 0, sum+2,array [current_left]=2,
|        120/2 = 60 , sum +60, array [ current_right] = 60
|        max = 120/2 = 60
|
|   If the number is found to be a perfect number, then the following
|   is outputed: 
|   Perfect number : 6 = 1 + 2 + 3
|   
|   This is done by outputting the values in the left side of the array,
|   then the right side.
|
| returns 1 if perfect, 0 if not.
|
*/

int Perfect_number_calculation(int number)
   {
   int current_factor = Start_factor;
   int max_factor = number;
   int sum_of_factors = 1;
   int factor_array [Array_max];
   int current_array_left = 0; 
   int current_array_right = Array_max - 1;
   int print_array = 0;
   {
   for ( current_factor; current_factor < max_factor; current_factor ++)
      { 
      if ( number % current_factor == 0)
         {
         sum_of_factors += current_factor;
         factor_array [ current_array_left] = current_factor;
         current_array_left++;
         if ( number / current_factor != current_factor)
            {
            factor_array [ current_array_right] = number / current_factor;
            sum_of_factors += number / current_factor;
            current_array_right--;
            }
         }
      max_factor = number / current_factor;
      }
   if( number == sum_of_factors && number != 1)
      {
      printf("Perfet number: %d = 1 ", number);
      for(print_array;print_array < current_array_left; print_array++)
         {
         printf("+ %d ",factor_array [ print_array ]);
         }
      print_array = current_array_right + 1;
      for(print_array ; print_array < Array_max ; print_array++ )
         {
         printf("+ %d ",factor_array [ print_array ]);
         }
      printf(" \n");
      return 1;
   }
   return 0;

   }
   } 
