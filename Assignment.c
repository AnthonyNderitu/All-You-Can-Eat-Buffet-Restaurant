#include <iostream>
#include<bits/stdc++.h>
using namespace std;

// constant declarations
const float ADULT_MEAL = 6.00;
const float CHILD_MEAL = 3.00;
const float TAX = 0.065;
const float DESERT_PIE = 1;
const float GRATUITY = 0.15;

// struct type
typedef struct bill {
string date;
string cust_name;
int no_of_adult_meals;
int no_of_child_meals;
int no_of_deserts;
float adult_meal_charges;
float child_meal_charges;
float desert_charges;
float taxes;
float gratuity;
float subtotal;
} customer_bill;


int main()
{
// variable declarations
customer_bill customer;
char ch = 'Y';

// function declarations
customer_bill accept_data();
customer_bill calculate_bill(customer_bill);
void display_bill(customer_bill);


do {
// function calls
customer = accept_data();
customer = calculate_bill(customer);
display_bill(customer);
cout<<endl;
cout<<"Do you want to process another Customer's Bill(Y or N) :";
cin>>ch;
} while(ch=='Y');

return 0;
}


// function to accept data (input)
customer_bill accept_data()
{
customer_bill customer;
// accepting values
// for clearing input buffer
cin.sync();
cout<<"Please enter following Customer's Information:"<<endl;
cout<<"Date:";
getline(cin,customer.date);
// for clearing input buffer
cin.sync();
cout<<"Customer's Name:";
getline(cin,customer.cust_name);
// for clearing input buffer
cin.sync();
// validation for adult meals
do {
cout<<"Number of adult meals:";
cin>>customer.no_of_adult_meals;
if(customer.no_of_adult_meals <= 0)
cout<<"Sorry invalid input....Please give valid input"<<endl;
}while(customer.no_of_adult_meals <= 0);

// validation for child meals
do {
cout<<"Number of child meals:";
cin>>customer.no_of_child_meals;
if(customer.no_of_child_meals <= 0)
cout<<"Sorry invalid input....Please give valid input"<<endl;
}while(customer.no_of_child_meals <= 0);

// validation for deserts
do {
cout<<"Number of deserts:";
cin>>customer.no_of_deserts;
if(customer.no_of_deserts <= 0)
cout<<"Sorry invalid input....Please give valid input"<<endl;
}while(customer.no_of_deserts <= 0);

// returning customer
return customer;
}


// function to do the calculation (process)
customer_bill calculate_bill(customer_bill customer)
{

// calculating adult meal charges
customer.adult_meal_charges = customer.no_of_adult_meals * ADULT_MEAL;
// calculating child meal charges
customer.child_meal_charges = customer.no_of_child_meals * CHILD_MEAL ;
// calculating desert charges
customer.desert_charges = customer.no_of_deserts * DESERT_PIE;
// calculating taxes
customer.taxes = (customer.adult_meal_charges + customer.child_meal_charges + customer.desert_charges) * TAX;
// calculating subtotal
customer.subtotal = (customer.adult_meal_charges + customer.child_meal_charges + customer.desert_charges) + customer.taxes;
// returning customer
return customer;
}


// function to display output:- (output)
void display_bill(customer_bill customer)
{
// displaying bill information
cout<<"The All-you-Can-Eat-Buffet Restaurant"<<endl;
cout<<"Date :"<<customer.date<<endl;
cout<<"Customer Name:"<<customer.cust_name<<endl<<endl;
cout<<"Adult Meal Charge: "<<customer.no_of_adult_meals<<"@"<<ADULT_MEAL<<" each\t$"<<customer.adult_meal_charges<<endl;
cout<<"Child Meal Charge: "<<customer.no_of_child_meals<<"@"<<CHILD_MEAL<<" each\t$"<<customer.child_meal_charges<<endl;
cout<<"Desert Charge: "<<customer.no_of_deserts<<"@"<<DESERT_PIE<<" each\t\t$"<<customer.desert_charges<<endl;
  cout<<"Taxes :"<<"\t\t\t\t\t"<<"$"<<customer.taxes<<endl;
cout<<"\tSubtotal:\t\t\t$"<<customer.subtotal<<endl;
cout<<"\tGratuity Charges (15%)\t\t$"<<fixed<<setprecision(2)<<customer.subtotal * GRATUITY<<endl;
cout<<"\tTOTAL DUE :\t\t\t$"<<setprecision(2)<<customer.subtotal + (customer.subtotal * GRATUITY)<<endl;

   cout<<endl;
cout<<"Thanks for eating at All-you-Can-Eat-Buffet Restaurant"<<endl;
cout<<"Please come again..."<<endl;

}
