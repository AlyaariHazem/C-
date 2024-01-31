using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace supermarket
{
    class Customer:Admin
    {
        public int CustomerPhone { get; set; }

        public Customer(int customerPhone, string name, string password)
        {
            CustomerPhone = customerPhone;
            Name = name;
            Password = password;
        }

        public void DisplayInfo()
        {
            Console.WriteLine($"Customer ID: {CustomerPhone}");
            Console.WriteLine($"Name: {Name}");
            Console.WriteLine($"Email: {Password}");
        }
    }
}
