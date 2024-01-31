using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace supermarket 
{
    // this class for Adminstritor 
    public class Admin
    {
        public string Name { get; set; }
        public string Password { get; set; }
        private List<Product> products { get; set; }

        // athantcation and verify #################
        public int verify(string name, string passowrd)
        {
            if (name == "Hazem" && passowrd == "123")
            {
                return 1;

            }
            else
            {


                return 0;
            }
        }
        public void mange()
        {
            int AdminInput;
            Console.WriteLine("1-products \n2-costumers  \n3-order  \n4-Backspace ");
        adinput:
            try
            {
                AdminInput = int.Parse(Console.ReadLine());
            }
            catch
            {
                goto adinput;
            }
            //switch for check admininput what is it product customer invoice or order...
            switch (AdminInput)
            {
                case 1:
                    Product product = new Product();
                    product.choose();

                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                default:
                    Console.WriteLine("sorry Enter number 1-4 ");
                    goto adinput;
                    break;
            }
        }

        private void DisplayInfo()
        {
            Console.WriteLine($"Name: {Name}");
            Console.WriteLine($"Email: {Password}");
        }

    }
}
