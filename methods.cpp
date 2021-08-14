#include <iostream>
#include <string>
using namespace std;
#include "class.h";

# define Q_MAX 2
# define S_MAX 3

using namespace GSP;

//accepting orders from the customers
int GroceryStore ::enqueue(Customer *a)
{
    if ((front == rear + 1) || (front == 0 && rear == Q_MAX - 1))
    {
        cout << "\nSORRY !! The customer QUEUE is FULL\n";
        return -1;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % Q_MAX;
        queue[rear] = a;
    }
    return 1;
}

//removing orders from the queue and allocating the job to the delivery boys
Customer *GroceryStore ::dequeue()
{
    if (front == -1)
    {
        cout << "Queue is EMPTY\n";
    }
    if (front == rear)
    {
        int temp = front;
        front = rear = -1;
        return queue[temp];
    }
    else
    {
        int temp = front;
        front = (front + 1) % Q_MAX;
        return queue[temp];
    }
}

//customers has to enter the PRODUCT ID to buy the products from the store
void GroceryStore::Product :: read()
{
    int ch;
    try{
        cout<<"\nEnter the product ID : ";
        cin>>ch;
        switch(ch){ //raising paramCtor for corresponding product ID
            case 1:
                prodID = ch;prodName = "ONION";price = 60;tax = 0.0;
                break;
            case 2:
                prodID = ch;prodName = "POTATO";price = 35;tax = 0.0;
                break;
            case 3:
                prodID = ch;prodName = "TOMATO";price = 10;tax = 0.0;
                break;
            case 4:
                prodID = ch;prodName = "CARROT";price = 12;tax = 0.0;
                break;
            case 5:
                prodID = ch;prodName = "SPINACH";price = 11;tax = 0.0;
                break;
            case 6:
                prodID = ch;prodName = "APPLE";price = 155;tax = 0.0;
                break;
            case 7:
                prodID = ch;prodName = "ORANGE";price = 50;tax = 0.0;
                break;
            case 8:
                prodID = ch;prodName = "BANANA";price = 55;tax = 0.0;
                break;
            case 9:
                prodID = ch;prodName = "PAPAYA";price = 42;tax = 0.0;
                break;
            case 10:
                prodID = ch;prodName = "POMOGRANATE";price = 228;tax = 0.0;
                break;
            case 11:
                prodID = ch;prodName = "MILK";price = 40;tax = 0.25;
                break;
            case 12:
                prodID = ch;prodName = "CURD";price = 90;tax = 0.5;
                break;
            case 13:
                prodID = ch;prodName = "BUTTER";price = 46;tax = 1.3;
                break;
            case 14:
                prodID = ch;prodName = "CHEESE";price = 245;tax = 1.75;
                break;
            case 15:
                prodID = ch;prodName = "PANEER";price = 174;tax = 1.5;
                break;
            case 16:
                prodID = ch;prodName = "EGGS";price = 7;tax = 0.3;
                break;
            case 17:
                prodID = ch;prodName = "CORN";price = 41;tax = 1.2;break;
            case 18:
                prodID = ch;prodName = "PEAS";price = 55;tax = 1.2;
                break;
            case 19:
                prodID = ch;prodName = "ICE CREAM(VANILLA)";price = 160;tax = 2.5;
                break;
            case 20:
                prodID = ch;prodName = "ICE CREAM(MANGO)";price = 160;tax = 2.5;
                break;
            case 21:
                prodID = ch;prodName = "SALT";price = 20;tax = 1.1;
                break;
            case 22:
                prodID = ch;prodName = "SUGAR";price = 45;tax = 1.1;
                break;
            case 23:
                prodID = ch;prodName = "BLACK PEPPER";price = 53;tax = 1.5;
                break;
            case 24:
                prodID = ch;prodName = "RED CHILLI POWDER";price = 43;tax = 1.5;
                break;
            case 25:
                prodID = ch;prodName = "CHIPS";price = 15;tax = 2;
                break;
            case 26:
                prodID = ch;prodName = "CHOCOLATE";price = 45;tax = 2;
                break;
            case 27:
                prodID = ch;prodName = "PAPER BOAT";price = 20;tax = 2.5;
                break;
            case 28:
                prodID = ch;prodName = "COCACOLA";price = 124;tax = 3.5;
                break;
            case 29:
                prodID = ch;prodName = "BREAD";price = 39;tax = 1.3;
                break; 
            case 30:
                prodID = ch;prodName = "WHEAT BREAD";price = 49;tax = 1.3;
                break;
            case 31:
                prodID = ch;prodName = "BISCUITS";price = 30;tax = 2.2;
                break;           
            default:
                throw ch;
        }
    }catch(int ch){
        cout<<"\nSorry the product with ID "<<ch<<" is not available yet!\nSelect product from catalogue\n"<<endl;
        read();
    }
}


//displaying the product catelogue for the customers's reference
void GroceryStore::Product ::readFile()
{
    char ch;
    ifstream infile("products.txt");
    while (infile)
    {
        infile.get(ch);
        cout << ch;
    }
    cout << endl;
}

//calculating net amount
GroceryStore::Product GroceryStore::Product :: operator* (int quantity)
{
    this->quantity = quantity;
    this->netAmount = quantity*price + tax;
    return *this;
} 

//displaying the details of the delivery boy(employee)
void Employee ::display()
{
    cout << "NAME : " << empName << endl;
    cout << "PHONE : " << phNo << endl;
    cout << "EMPLOYEE ID : " << empID << endl;
}

//counting number of customers
int Customer ::operator++()
{
    return ++count_cust;
}

//customer is asked to give feedback based on the store's service
int Customer ::giveFeedBack()
{
    try
    {
        char fb;char r;
        string suggest;
        cout << "\n\n***** Please give us your FEEDBACK.(1 = GOOD/0 = BAD) *****" << endl;
        cin >> fb;
        if (fb != '1' && fb != '0')
        {
            throw fb;
        }
        myFeedBack = myFeedBack + (fb-48);
        cout << "\nWould you like to provide any suggestions to improve our store services?(y/n)\n";
        cin>>r;
        if(r=='y'){
            getline(cin.ignore(),suggest);
            ofstream fout;
            //ifstream fin;
            //fin.open("suggestions.txt");
            fout.open ("suggestions.txt",ios::app);
            if(fout.is_open())
                fout << "\n=> "<<custName<<": "<<suggest;
            //fin.close();
            fout.close();
        }
        cout<<"\nThank you for your feedback!"<<endl;
    }
    catch (char fb)
    {
        cout << "INVALID FEEDBACK->>> ENTER either 1 OR 0\n";
        giveFeedBack();
    }
    return myFeedBack;
}

//reading customer details
void Customer ::read()
{
    cout << "Customer ID : ";
    cin >> custID;
    cout << "Customer Name : ";
    cin >> custName;
    cout << "Customer Phone No. : ";
    cin >> custPh;
    cout << "Distance : ";
    cin >> distance;
}

//number of products purchased by the customer
void Customer::numProd(int n)
{
    noOfProd = n;
}

//calculating the total purchase price
Customer Customer :: operator+= (GroceryStore::Product p)
{
    amount += p.netAmount;
    return *this;
}

//producing the discount amount based on the purchase amount
float Customer ::discount()
{
    if (amount > 500)
        return amount * 0.1;
    if (amount > 100)
        return amount * 0.05;
    else
        return 0;
}

//displaying the bill
void Customer :: display(GroceryStore::Product* p)
{
    cout<<endl<<"==============================================INVOICE=============================================="<<endl;
    cout<<"ID: "<<custID<<endl;
    cout<<"Name: "<<custName<<endl;
    cout<<"Contact: "<<custPh<<endl;
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Sl No."<<setw(12)<<"Product ID"<<setw(20)<<"Product Name"<<setw(16)<<"Quantity(unit)"<<setw(17)<<"Price(Rs./unit)"<<setw(11)<<"Tax (Rs.)"<<setw(17)<<"Net Amount(Rs.)"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;    
    for(int i=0; i<noOfProd; i++){
        cout<<setw(5)<<i+1<<setw(12)<<p->prodID<<setw(20)<<p->prodName<<setw(16)<<p->quantity<<setw(17)<<p->price<<setw(11)<<p->tax<<setw(17)<<p->netAmount<<endl;
        p++;
    }
    cout<<endl<<"\t\t\t\t\t\t\t\t\tPurchase Amount = Rs."<<amount<<endl;
    cout<<"\t\t\t\t\t\t\t\t\tDiscount Amount = Rs."<<discount()<<endl;
    cout<<"\t\t\t\t\t\t\t\tTotal Amount to be Paid = Rs."<<amount-discount()<<endl<<endl;
    cout<<"===========================================END OF INVOICE==========================================="<<endl;
    cout<<"                                  *****Thank You for visiting :)*****"<<endl;
}

//displaying the amount collected from the customer and distance travelled by the delivery boy
void Customer ::display()
{
    cout << "Customer with customer ID " << custID << " orders have been delivered by our delivery boy :\n";
    cout << "Distance Travelled : " << distance << " km\n"
         << "Amount Received : Rs " << (amount - discount()) << endl;
}

//pushing a job to the stack of delivery boy
void DeliveryBoys ::push(Customer *a)
{
    if (top == S_MAX - 1)
    {
        cout << "Stack Full\n";
    }
    else
    {
        stack[++top] = a;
    }
}

//popping the job ,if he has successfully delivered the order to the customers
void DeliveryBoys :: pop()
{
    if (top == -1)
    {
        cout << "Stack Empty\n";
    }
    else
    {
        stack[top--];
    }
}

//displaying the distributed  jobs to all the three delivery boys
void DeliveryBoys :: display()
{
    cout<<"Customer Orders of Delivery Boy, "<<empName<<" : "<<endl<<endl;
    if(top==-1)
    {
        cout<<"*** No job assigned yet ***\n";
        cout<<endl;
        return ;
    }
    for(int i = top;i>=0;i--)
    {
        cout<<" --> Customer ID : "<<stack[i]->custID<<endl;
    }
    cout<<endl;
}

//sorting the stack(containing jobs) of a delivery boy based on the distance of each customer's order.
//shorter distance is at the top of the stack
void DeliveryBoys ::bubbleSort()
{
    Customer *temp;
    for (int i = 0; i < top + 1; i++)
    {
        for (int j = 0; j < top - i; j++)
        {
            if (stack[j]->distance <= stack[j + 1]->distance)
            {
                temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }
}


/*delivering the orders to the customers by the delivery by comparing the shortest distance of all the three stacks
of the delivery boys i.e the tops of all the three stacks are compared ->the top,which has least distance i.e the 
order of the customer with least distance is delivered first.
First Delivery -> least distance
Last Delivery -> largest distance*/

void DeliveryBoys ::deliverProducts(DeliveryBoys &d2, DeliveryBoys &d3)
{
    while (top != -1 || d2.top != -1 || d3.top != -1)
    {
        cout << "*************************************************************************************************************\n";
        if (top != -1 && d2.top != -1 && d3.top != -1)
        {
            if (stack[top]->distance < d2.stack[d2.top]->distance && stack[top]->distance < d3.stack[d3.top]->distance)
            {
                stack[top]->display();
                Employee :: display();
                pop();
                cout<<endl;
            }
            else if (d2.stack[d2.top]->distance < stack[top]->distance && d2.stack[d2.top]->distance < d3.stack[d3.top]->distance)
            {
                d2.stack[d2.top]->display();
                d2.Employee ::display();
                d2.pop();
                cout<<endl;
            }
            else
            {
                d3.stack[d3.top]->display();
                d3.Employee ::display();
                d3.pop();
                cout<<endl;
            }
        }
        else if (top != -1 && d2.top != -1 && d3.top == -1)
        {
            compare(*this, d2);
        }
        else if (top != -1 && d2.top == -1 && d3.top != -1)
        {
            compare(*this, d3);
        }
        else if (top == -1 && d2.top != -1 && d3.top != -1)
        {
            compare(d2, d3);
        }
        else if (top != -1 && d2.top == -1 && d3.top == -1)
        {
            stack[top]->display();
            Employee ::display();
            pop();
            cout<<endl;
        }
        else if (top == -1 && d2.top != -1 && d3.top == -1)
        {
            d2.stack[d2.top]->display();
            d2.Employee ::display();
            d2.pop();
            cout<<endl;
        }
        else if (top == -1 && d2.top == -1 && d3.top != -1)
        {
            d3.stack[d3.top]->display();
            d3.Employee ::display();
            d3.pop();
            cout<<endl;
        }
    }
}

//comaparing distances if only two delivery boys have their job to be done
void DeliveryBoys::compare(DeliveryBoys &d1,DeliveryBoys &d2)
{
    if (d1.stack[d1.top]->distance < d2.stack[d2.top]->distance)
    {
        d1.stack[d1.top]->display();
        d1.Employee ::display();
        d1.pop();
        cout<<endl;
    }
    else
    {
        d2.stack[d2.top]->display();
        d2.Employee ::display();
        d2.pop();
        cout<<endl;
    }
}