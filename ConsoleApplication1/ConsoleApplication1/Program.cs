using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] data;
             FileStream line;
            try
            {
                line = System.IO.File.Open("text.txt",FileMode.Open);
                Console.WriteLine(line);
            }
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
