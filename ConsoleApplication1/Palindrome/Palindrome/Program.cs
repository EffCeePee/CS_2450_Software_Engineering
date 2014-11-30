//Franklin Colton Parry
//CS 2450 Section 002
//Assignment 5
// 2/19/14


/* Psuedocode for the Palindrome project:
 * 
 * I fliped tails then tails which mains I will be using the clean room technique to write this project.
 * 
 * 
 *  Test Cases
 *  Test1:  Did we open a file?
 *  Test2:  Did we read in the file?
 *  Test3:  Move to position 1 in the array and test left and right for palindrome
 *      -  if it is save the info
 *  Test4: move to next letter in the string and test for palindrome
 *      -	If it is a palindrome then check to see if it is larger than the current palindrome 
 *      After we move through the array we should have the largest palindrome
 *      -	Print it out to the user
 *      
 * Variables:  I think I will need
 *  string largestPalindrome, characterSet, palData;
 *  bool continue, ispal;
 *  int pallength, palStart, index, ptrLeft, ptrRight, two, plongestStart, pLongestLength;
 *  
 * Test 1
 * try
 * {
 *  palData = System.IO.File.ReadAllLines(file);
 *  
 *  test 2
 *  Console.WriteLine(palData);
 * }
 * catch (IOException ioException)
 * {
 *   Console.WriteLine("IOEXCEPTION - {0}", ioException);
 * }
 * 
 * test 3,4
 * //find middle
 * index = 1;
 * 
 * for(int i = 0; i <= palData.Length; i++)
 * {
 * 
 * continue = true;
 * ptrLeft= index -1;
 * ptrRight = index +1;
 * plength = 0;
 * 
 * while(continue == true){
 * 
 * if(palData[ptrLeft] == palData[ptrRight])
 * {
 *    continue = true;
 *    pstart = ptrLeft;
 *    plength++;
 *    ptrLeft--;
 *    ptrRight++;
 *    
 * }
 * else
 * {
 *    if(plength > 0)
 *    {
 *      if(plength > pLongetstLength)
 *      {
 *          pLongestLength = plength;
 *          plongestStart = --ptrleft;
 *          plength = 0;
 *          continue = false;
 *      }
 *    } 
 *      else
 *      {
 *          continue = false;
 *      }
 *     }
 * }// end while loop
 * 
 *  
 * index++;
 * 
 * }// end forloop
 * 
 * for(int i = 0; i <= pLongestLength ; i++)
 * {
 *  Console.Write(Convert.ToString(palData[pLongestStart]);
 *  pLongestStart++;
 * }
 * 
 * 
 * 
 */


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
namespace Palindrome
{
    class Program
    {
        static void Main(string[] args)
        {
            bool goOn;
            int pallength, palStart, index, ptrLeft, ptrRight;
            int pLongestLength = 0;
            char[] data;

            int plongestStart = 0;
            string[] fileLine;
            string line;
            try
            {
                fileLine = System.IO.File.ReadAllLines("text.txt");
                line = fileLine[0];
                data = line.ToCharArray();
                Console.WriteLine(line);

                index = 1; 
                for(int i = 0; i <= data.Length; i++)
                {

                    goOn = true;
                    ptrLeft = index - 1;
                    ptrRight = index + 1;
                    pallength = 0;

                    while(goOn == true)
                    {
                        if (ptrLeft < 0)
                        {
                           break;
                        }

                        if (ptrRight > data.Length - 1)
                        {
                            break;
                        }
                        
                        
                        if (data[ptrLeft] == data[ptrRight])
                        {
                            goOn = true;
                            palStart = ptrLeft;
                            pallength++;
                            ptrLeft--;
                            ptrRight++;
                        }
                        else
                        {
                            if (pallength > 0)
                            {
                                if (pallength > pLongestLength)
                                {
                                    pLongestLength = pallength;

                                    if (ptrLeft == 0)
                                        plongestStart = 0;
                                    else
                                        plongestStart = ptrLeft + 1;
                                    
                                    pallength = 0;
                                    goOn = false;
                                }
                                else
                                {
                                    goOn = false;
                                }

                            }
                            else
                            {
                                goOn = false;
                            }
                        }
                    }// end while

                    index++;
                }// end for loop

                pLongestLength = pLongestLength * 2;
                pLongestLength++;

                for (int i = 0; i < pLongestLength; i++)
                {
                    Console.Write(data[plongestStart]);
                    plongestStart++;

                }
            
            }// end try

            catch (IOException ioexp)
            {
                Console.WriteLine("IOException - {0}", ioexp.Message);
            }
            catch (Exception exp)
            {
                Console.WriteLine("Exception - {0}", exp.Message);
            }

            Console.ReadLine();

        }
    }
}
