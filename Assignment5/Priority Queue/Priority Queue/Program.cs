using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Priority_Queue;

namespace Priority_Queue
{
    class Program
    {
        static void Main(string[] args)
        {
            
            //variables
            string addName = "please give a name of a person";
            string addPriority = "please give a priority to that person";
            string numofPeople = "how many people do you want to put in the queue";
            string pName = null;

            queue temp;
            queue newest = null;
            int index = 0;
            int priority = 0;
            int entered = 0;
            int used = 0;
            const int SIZE = 50;

            //test case create queue
            queue[] pq = new queue[SIZE];

            //test case add a person
            //test case modify code to add multiple people
            // insert the people into proper positions

            Console.WriteLine(numofPeople);
            entered = Convert.ToInt32(Console.ReadLine())-1;

            for (int i = 0; i <= entered; i++)
            {
                Console.WriteLine(addName);
                pName = Console.ReadLine();

                Console.WriteLine(addPriority);
                priority = Convert.ToInt32(Console.ReadLine());

                newest = new queue(pName, priority);
                if (pq[0] == null)
                {
                    pq[0] = newest;
                    used++;
                }
                else
                {
                    newest.sort(used, newest, pq);
                }

            } // close for loop

              
            //test case print out the queue
            for (int i = 0; i <= entered; i++)
            {
                Console.WriteLine(pq[i]._getName()+"\n");
            }

            Console.ReadLine();

        } // end main





            } // close for loop
        }// end namespace 
   