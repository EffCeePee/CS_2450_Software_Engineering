// Project Prologue
// Franklin Colton Parry
// Course: CS 3260
// File: HomeWork_2.cs
// Date: 1/21/2014

// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.


// using statement
using System;


// namespace
namespace HomeWork_2
{

    // class calculation
    class calculation
    {
        // variables
        private double result = 0;
        int i = 0;

        /// <summary>
        /// Pupose: To calculate the sum of 10 numbers divided by the 11th
        /// Returns: a double type number
        /// Parameters:  an array of numbers
        /// </summary>
        /// <param name="nums"></param>
        /// <returns></returns>
        public double calculate(double [] nums)
        {
            /// loop to make the calculation
            for (i = 0; i < nums.Length; i++)
            {
                if(i == (nums.Length-1))
                {
                    result = result / nums[i];
                }
                else
                {
                    result += nums[i];
                }
            }

                return result;
        }
    }


    // program
    class Program
    {
        /// <summary>
        /// Purpose: to run a program to calculate a number
        /// </summary>
        static void Main()
        {
            // Constants and Variables
            const int SIZE = 11;

            string instructions = "This program will take 11 numbers.\nIt will add the first 10 and divide the sum by the 11th.";
            string prompt = "Please enter number";
            string error = "Sorry, Please enter a number";
            string result = "the result is: ";
            string notZero = "Sorry, you cannot divide by zero";
            string num = null; 
   
            int i = 0;
            
            double[] numbers = new double[SIZE];
            double number;
            
            // object perform calculation
            calculation calc = new calculation();

            Console.WriteLine(instructions);
            Console.WriteLine();


            /// do while loop to get numbers and test they are numbers and not dividing by zero
            do
            {
                Console.Write(prompt + " " + (i+1) + ": ");
                num = Console.ReadLine();

                bool isNum = double.TryParse(num, out number);

                if (isNum)
                {
                    if (i == (SIZE-1))
                    {
                        if (number == 0)
                        {
                            Console.WriteLine(notZero);
                        }
                        else
                        {
                            numbers[i] = number;
                            i++;
                        }
                    }
                    else
                    {
                        numbers[i] = number;
                        i++;
                    }
                }
                else
                {
                    Console.WriteLine(error);
                }



            } while (i < SIZE);

            Console.WriteLine(result + calc.calculate(numbers));
            Console.ReadLine();
        }
    }
}
