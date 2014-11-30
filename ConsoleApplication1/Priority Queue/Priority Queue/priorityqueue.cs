using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Priority_Queue
{
    class queue
    {

        private string _name;
        private int _priority;

        public queue()
        {
            _name = null;
            _priority = 0;
        }

        public queue(string n, int p)
        {
            _name = n;
            _priority = p;
        }

        public string _getName()
        {
            return _name;
        }

        public int _getPriority()
        {
            return _priority;
        }

    }
}
