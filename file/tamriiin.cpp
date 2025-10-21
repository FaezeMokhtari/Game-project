#include <iostream>
#include <string>
using namespace std;
 class car
 {
 	private :
 		string brand;
 		string model;
 		int year;
 		int fuel;
 		int speed;
 	public:
 		car(string b ="Honda", string m ="Civic" , int y = 1350, int  f=0) {
	        setbrand(b);
	        setmodel(m);
	        setyear(y);
	        setfuel(f);
	        speed = 0;
	    }
 		void setbrand(string b){
 			brand=b;
		 }
		 void setmodel(string m)
		 {
			model=m;
		 }
		 void setyear(int y){
		 	if(y>1350)
		 		year=y;
		 	else
		 	{
		 		year=0;
			}
		}
		void setfuel(int n){
			fuel=n;
		}
		int getfuel(){
			return fuel;
		}
		
			string getbrand(){
				return brand;
			}
			string getmodel(){
				return model;
			}
			int getyear(){
				return year;
			}
			void carinfo(){
				cout<<brand<<model<<year;
			}
			void checkFuel(int n){
				if(n>50)
					cout<<"Fuel level is sufficient";
				else
					cout<<"Fuel level is low";
			}
			void changespeed(int newspeed)
			{
				   speed = newspeed;
        			cout << "newspeed : " << speed << endl;
			}
		 
};
 int main() {
 	car car1("jili","mgrand",2020,50);
 	car1.carinfo();
 	cout<<endl;
 	car1.checkFuel(33);
 }
