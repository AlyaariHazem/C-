using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace supermarket
{
    class Invoice
    {
        public int InvoiceId { get; set; }
        public Order Order { get; set; }
        public Customer Customer { get; set; }
        public double TotalAmount { get; set; }
        public DateTime InvoiceDate { get; set; }

        public Invoice(int invoiceId, Order order, Customer customer, double totalAmount, DateTime invoiceDate)
        {
            InvoiceId = invoiceId;
            Order = order;
            Customer = customer;
            TotalAmount = totalAmount;
            InvoiceDate = invoiceDate;
        }

        public void DisplayInfo()
        {
            Console.WriteLine($"Invoice ID: {InvoiceId}");
            Console.WriteLine("Order Information:");
            Order.DisplayInfo();
            Console.WriteLine("Seller Information:");
            Customer.DisplayInfo();
            Console.WriteLine($"Total Amount: {TotalAmount:C}");
            Console.WriteLine($"Invoice Date: {InvoiceDate}");
        }
    }
}
