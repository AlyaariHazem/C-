using System;
using System.IO;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.Json.Serialization;

namespace supermarket
{
  public  class Product 
    {
        protected int ProductId { get; set; }
        public string Name { get; set; }
        public double Price { get; set; }
        public int Quantity { get; set; }

        public Product(int productId, string name, double price, int quantity)
        {
            ProductId = productId;
            Name = name;
            Price = price;
            Quantity = quantity;
        }
        public Product() { }
        public void choose()
        {
    num:      Console.WriteLine("1-add products \n 2-delete products \n3-display products\n4-Backspace ");
            
            int SelectNumber = int.Parse(Console.ReadLine());
            switch (SelectNumber)
            {
                
                case 1:
                       AddProduct();
                 

                    break;
                case 2:
                       DeleteProduct();
                    break;
                case 3:
                      DisplayProduct();
                    break;
                default:
                    goto num;
                    break;
                    goto num;
            }
            
        }

        public ObservableCollection<Product> AddProduct()
        {
            return new ObservableCollection<Product>();
        }



        public ObservableCollection<Product> DeleteProduct()
        {
            return new ObservableCollection<Product>();
        }
        public ObservableCollection<Product> DisplayProduct()
        {

            return new ObservableCollection<Product>();
        }



    }
    
}
