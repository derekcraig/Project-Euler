#include <iostream>
   //Declaration
int evenFibonacci();
long long largestFactor(long long);
bool isPrime(long long);

int main() 
{
   long long test = 600851475143;
   long long result = 0;
   result = largestFactor( test ); 

   std::cout << result;
}

   //Definition
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

long long largestFactor(long long test )   //Uses isPrime() and an index to find the largest prime factor
{
   long long largestPrime = 1;
   long long i = 2;
  
   for( i = 2; i <= test; i++ )   //As long as the tested number is less than the index
   {
      if( test % i == 0 && isPrime( i ) )   //And the prime index is a factor
      {
         largestPrime = i;  //Update index

         while( test % i == 0 )
            { test /= i; }  //Update test number to a factor the index
      }
      
   }
   return largestPrime;
}

int evenFibonacci() 
{
   int num1 = 1;
   int num2 = 1;
   int nextNum = 0;
   int evenSum = 0;
   int MAX = 4000000;

   while (num1 <= MAX) 
   {
      if (num1 % 2 == 0)
         evenSum += num1;

      // Calculate the next Fibonacci number using the two variables technique
      nextNum = num1 + num2;
      num1 = num2;
      num2 = nextNum;
   }

   return evenSum;
}