#include<iostream>
#include<fstream>
using namespace std;

class Vehicle{
	private:
		int wheels;
	protected:
		int passenger,wh;
	public:
		Vehicle(){
		}
		
		Vehicle(int wh,int passenger):wh(wh),passenger(passenger){
		}
		void inputvehicle(){
			cout<<"enter number of wheels"<<endl;
			cin>>this->wheels;
			cout<<"enter number of passengers"<<endl;
			cin>>this->passenger;
			}
		void outputvehicle(){
			cout<<"wheels: "<<wheels<<endl;
			cout<<"passengers:"<<passenger<<endl;
			
			
		}
};

class Heavyvehicle:public Vehicle{
	protected:
		double diesel,load;
		int w,passengers;
	public:
		Heavyvehicle(){
		}
		Heavyvehicle(int w,int passenger,double diesel,double load):Vehicle(w,passenger){
			this->diesel=diesel;
			this->load=load;
			writedata();
		
		}
		void readdata(){
			string line;
			ifstream file("vehicle.txt");
			if(file.is_open())
			{
				while(getline(file,line)){
					cout<<line<<endl;
				}
			}
			
			
		}
		void writedata(){
			ofstream myfile("vehicle.txt",ios::app);
			if(myfile.is_open()){
				myfile<<" wheels:"<<wh<<" passenger:"<<passenger<<" diesel:"<<diesel<<" liters "<<" load:"<<load<<" tons"<<endl;
			}
			myfile.close();
			
			
		}
		
};

int main(){
	int ch=1;
	int w, passenger;
	double diesel, load;
	Heavyvehicle hv;
	
	//for heavyvehicle class
	
	while(ch!=0){
		cout<<"enter wheels: ";
		cin>>w;
		cout<<"\nenter passenger:";
		cin>>passenger;
		cout<<"\nenter diesel capacity:";
		cin>>diesel;
		cout<<"\nenter load capacity";
		cin>>load;
		Heavyvehicle *obj=new Heavyvehicle(w,passenger,diesel,load);
		
		cout<<"want to continue? 0/1"<<endl;
		cin>>ch;

		}
		hv.readdata();
//vehicle class object called
		cout<<"\n -------------this is vehicle class--------------"<<endl;
		Vehicle v;
		v.inputvehicle();
		v.outputvehicle();
		
	
	
	
}
