using System;
using System.Text.Json;
using System.Collections.ObjectModel;
using System.Linq;
using System.IO;

namespace supermarket
{
    class ClassMain
    {
        static void Main()
        { 
            string json = JsonSerializer.Serialize(new Product().AddProduct());
            Console.WriteLine("json objec \n");
            Console.WriteLine(json);
            var products = JsonSerializer.Deserialize<ObservableCollection<Product>>(json);
            products.ToList().ForEach(p => Console.WriteLine(p.Name));
            Console.WriteLine("1-admin \n2-seller \n3-buyer");
validNumber: int input=0;
            try
            {
             input = int.Parse(Console.ReadLine());
            }
            catch (Exception e)
            {
                
            }
            
            switch(input)
            {
                case 1:
                    // display for adminstration #######################################################
                    Admin Ad = new Admin();
                    Console.Clear();
                    Console.WriteLine($" welcome");
              again:
                    try
                    {
                        Console.WriteLine($" please enter your name ? ");
                        Ad.Name =Convert.ToString(Console.ReadLine());
                    }
                    catch
                    {
                        Console.WriteLine("sorry don't enter number or simboles ");
                        goto again;
                    }
                        Console.WriteLine("enter you password ? ");
                        Ad.Password =Convert.ToString(Console.ReadLine());
                    
                    int verify_return = Ad.verify(Ad.Name, Ad.Password);
                    if(verify_return==0)
                    {
                        Console.Clear();
                        Console.WriteLine("your name or password INVALID ");
                        goto again;
                    }
                    Ad.mange();
                    break;
                case 2: 
                    Console.WriteLine($" welcome our customer");
                    break;
                default:
                    Console.WriteLine($" sorry entter number valid       1-3 ");
                    goto validNumber;
                    break;
            }
            
        }
    }
}

