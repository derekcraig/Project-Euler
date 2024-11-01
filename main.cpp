//This code represents my answeres for problems on projecteuler.net/archives
//Updated: 5/19/23
//Programmer: Derek Craig
#include <iostream>
#include <iomanip>
   //Declaration
int evenFibonacci();   //2
long long largestFactor(long long);   //3
bool isPrime(long long);   //3
   //Find the largest palindrome made from the product of two 3-digit numbers
int largestPalindrome();   //4
bool isPalindrome();   //4
int smallestMultiple( int );   //5
bool isDivisible( int, int );   //5
int gcd( int, int );   //5.5
int lcm( int, int );   //5.5
void sumSquareDifference();   //6

int main() 
{
   sumSquareDifference();
}

   //Definition
void sumSquareDifference()
{
   double sumSqr = 0;
   double sqrdSum = 0;
   int MAX = 100;
   double result = 0;
   int i =0;

   for( i = 1; i <= MAX; i++ )
  {
     sqrdSum += i;
     sumSqr += i * i;
  }

  result = ( sqrdSum * sqrdSum ) - sumSqr;
  std::cout << std::fixed << std::setprecision(2) << result << std::endl;
}

int gcd( int a, int b )   //Calculates the greatest common divisor of two
{                         //numbers using the Euclidean algorithm
   //std::cout << a << " " << b << std::endl;   //Watch it work
   if( b == 0 )   //Repeatedly dividing a by b and taking the remainder until
      return a;   //the remainder becomes zero
   return gcd( b, a % b );
}

int lcm( int a, int b )   //Using the formula: LCM(a, b) = (a * b) / GCD(a, b)
{                                   //By dividing the product of a and b by 
   return( a * b ) / gcd( a, b );   //their GCD, we obtain the LCM
}

bool isDivisible( int number, int MAX )
{   //Checks if number is divisible by 2, 3, 4,..., Max
   for( int i = 2; i <= MAX; i++ )   
   {                                 
      if( number % i != 0)
         return false;
   }
   return true;
}

int smallestMultiple( int MAX )
{
   int result = 1;
   int i = 1;   //If using the do loop
/*  
   do{
        i++;
        result = i;
     }while( !isDivisible( i, MAX ) );
*/
    for(int i = 2; i <= MAX; i++)
    {
        //std::cout << i << " :iteration" << std::endl;   //Watch it work
        result = lcm(result, i);
        //std::cout << result << " :result" << std::endl;   //Watch it work
    }

    return result;
}

bool isPalindrome( int number )   //Uses string to check for palindrome
{
   int length;
      //Turns int into a string and gets its length
   std::string numberStr = std::to_string( number );
   length = numberStr.length();

   for( int i = 0; i < length / 2; i++ )  //Iterates for half length
   {
      if( numberStr[i] != numberStr[ length - i - 1 ])
      {                  //Checks if the character from the beginning of the 
         return false;   //string is not equal to the character at the end of
      }                  //the string
   }
   return true;   //If it passes all iterations!
}

  //Consider updating to control number of digits with pow(10, num - 1)/ -1
int largestPalindrome()   //Utilizes isPalindrome() to find the largest one
{
   int max = 999;   //To find the largest three digit multiple
   int result = 0;   //To hold the result of each iteration 
   int largestResult = 0;   //To hold the largest palindrome
  
   for( int i = 1; i <= max; i++ )   //Starts product loop
   {
      for( int j = i; j <= max; j++ )   //Skips duplicates by initializing
      {                                 //with current i
         result = i * j;   //Product stored in result

         if( isPalindrome( result ) )   //Tests if palindrome
         {
            largestResult = (result > largestResult) ? result : largestResult; 
         }     //If result > largestResult update, else leave it be
      }
   }
   return largestResult;
}

bool isPrime(long long number)   //Designed to go with largestFactor()
{
   long long i = 2;
  
   if( number < 2 )   //2 is the only even prime
   { return false; }
   
  for( i = 2; i * i <= number; i++)   //As long as the increment squared is 
  {                                   //less then the test number
      if( number % i == 0 )   //And the increment is not a factor of the
      { return false; }       //test number
  }
  return true;   //Then it is prime!
}

long long largestFactor(long long test )   //Uses isPrime() and an index to
{                                          //find the largest prime factor
   long long largestPrime = 1;
   long long i = 2;
  
   for( i = 2; i <= test; i++ )   //As long as the tested number is less than
   {                              //the index
      if( test % i == 0 && isPrime( i ) )   //And the prime index is a factor
      {
         largestPrime = i;  //Update index

         while( test % i == 0 )
            { test /= i; }  //Update test number to a factor the index
      }
      
   }
   return largestPrime;
}

int evenFibonacci()   //Sums even terms of Fibonacci sequence up to a given
{                     //number
   int num1 = 1;
   int num2 = 1;
   int nextNum = 0;
   int evenSum = 0;
   int MAX = 4000000;

   while (num1 <= MAX) 
   {
      if (num1 % 2 == 0)   //If it is even, add it to evenSum
         evenSum += num1;

      nextNum = num1 + num2;   //Calculate the next Fibonacci number using
      num1 = num2;             //the two variables technique
      num2 = nextNum;
   }

   return evenSum;
}