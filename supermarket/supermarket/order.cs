using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace supermarket
{
    class Order
    {
        public int OrderId { get; set; }
        public Customer Customer { get; set; }
        public Product Product { get; set; }
        public int Quantity { get; set; }
        public DateTime OrderDate { get; set; }

        public Order(int orderId, Customer customer, Product product, int quantity, DateTime orderDate)
        {
            OrderId = orderId;
            Customer = customer;
            Product = product;
            Quantity = quantity;
            OrderDate = orderDate;
        }

        public void DisplayInfo()
        {
            Console.WriteLine($"Order ID: {OrderId}");
            Console.WriteLine("Customer Information:");
            Customer.DisplayInfo();
            Console.WriteLine("Product Information:");
            Product.DisplayProduct();
            Console.WriteLine($"Quantity: {Quantity}");
            Console.WriteLine($"Order Date: {OrderDate}");
        }
    }
}
