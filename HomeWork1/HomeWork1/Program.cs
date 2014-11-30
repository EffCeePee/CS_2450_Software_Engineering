// Project Prologue
// Franklin Colton Parry
// Course: CS 2450
// File: Homework #1
// Date: 1/13/2014

// I declare that the following source code was written by me, or provided
// by the instructor for this project. I understand that copying
// source code from any other source constitutes cheating, and that I will
// receive a zero grade on this project if I am found in violation of
// this policy.


//Using Statements
using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//namespace declaration
namespace HomeWork1
{
    
    // class declaration
    class Program
    {
        /// <summary>
        ///  Purpose:  Program to open a file, read in the file
        ///  pull out the minimum and maximum numbers
        ///  Requirements:  a file to open assumed to be given by the programmer
        ///  Parameters:  None
        ///  Return: None
        /// </summary>
        static void Main()
        {

            // declare variables
            string file = "text.txt";   
            double minimum = 0;
            double maximum = 0;
            double number = 0;

            // tell the user to make sure there is a file available to open
            Console.WriteLine("Please place a file called 'text.txt' in the root directory");
            Console.WriteLine("Press enter when ready");

            Console.ReadLine();

            string[] data = System.IO.File.ReadAllLines(file);


            // for loop for each line in the array
            for (int i = 0; i < data.Length; i++)
            {
                string line = data[i];    // put each line into a string
                if (line.All(Char.IsDigit) || (line.All(Char.IsDigit) && line.Contains("."))) // check to see if the line is full of digits
                    number = Convert.ToDouble(line);  // convert line to a number if it is full of digits
                

                // use logic to determin if it is new largest or smallest
                if(number < minimum)
                {
                    minimum = number;
                }
                else if (number > maximum)
                {
                    maximum = number;
                }
            }


            // print to console
            Console.WriteLine("The maximum number is " + maximum);
            Console.WriteLine("The minimum number is " + minimum);

            Console.ReadLine();

        }
    }
}
