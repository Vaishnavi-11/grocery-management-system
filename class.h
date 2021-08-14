#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

 
# define Q_MAX 2
# define S_MAX 3
 
namespace GSP
{
    class Customer;
    class DeliveryBoys;
    class Person;
}

namespace GSP
{

    class GroceryStore
    {
        static int rear, front;
        Customer *queue[Q_MAX];

    public:
        class Product
        {
            int prodID;
            string prodName;
            float price, netAmount, tax;
            int quantity;

        public:
            Product() : prodID(0), prodName("NULL"), price(0.0), quantity(0), netAmount(0.0), tax(0.0) {}
            Product(int pID, string pname, float pPrice) : prodID(pID), prodName(pname), price(pPrice) {}
            void read();
            void readFile();
            Product operator* (int quantity);
            friend class Customer;
        } p[50];

        int enqueue(Customer *a);
        Customer *dequeue();

        friend class Customer;
        friend void allocateJob(GroceryStore &g, DeliveryBoys &d1, DeliveryBoys &d2, DeliveryBoys &d3);
    };

    class Person //an abstract class
    {        
        public:
            virtual void display() = 0;
    };

    class Customer : public Person
    {
        string custID, custName, custPh;
        int noOfProd;
        static int count_cust;
        static int myFeedBack;
        float amount, distance;
        public:
        Customer() : custID("NULL"), custName("NULL"), custPh("NULL"), amount(0.0), distance(0.0), noOfProd(0) {}
        void read();
        void numProd(int);
        Customer operator+=(GroceryStore::Product);
        int operator++();
        float discount();
        int giveFeedBack();
        void display();
        void display(GroceryStore::Product *);

        friend class GroceryStore;
        friend class DeliveryBoys;
    };

    
    class Employee : public Person
    {
        protected :
        int top;
        string empName, phNo, empID;
        public:
        Employee() : top(-1), empName("NULL"), phNo("NULL"), empID("NULL") {}
        Employee(string name, string ph, string id, int _top) : empName(name), phNo(ph), empID(id), top(_top) {}
        void display();
    };

    class DeliveryBoys : public Employee
    {
        Customer *stack[S_MAX];
        public :
        DeliveryBoys():Employee(){}
        DeliveryBoys(string name, string ph, string id, int _top) : Employee(name,ph,id,_top){}
        void push(Customer *a);
        void pop();
        void bubbleSort();
        void deliverProducts(DeliveryBoys &d2, DeliveryBoys &d3);
        void compare(DeliveryBoys &d1,DeliveryBoys &d2);
        void display();
        friend class Customer;
        friend void allocateJob(GroceryStore &g, DeliveryBoys &d1, DeliveryBoys &d2, DeliveryBoys &d3);
    };

    void allocateJob(GroceryStore &g, DeliveryBoys &d1, DeliveryBoys &d2, DeliveryBoys &d3);
    
}