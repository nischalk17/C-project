//Electricty and water bill
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
class electricity{
    public:
    int a,b,t,e;
        int i,j;
    
  void getdata(){
      cout<<"Enter your house number: "<<endl;
      cin>>a;
      srand((unsigned)time(0)); 
    i = (rand()%3000)+1; 
    cout<<"Total electricty consumption of this month is: " << i <<" units"<<endl;
    if(i<=500){
        b=i*5;
        cout<<"Total electricity cost is: "<<b<<" Rupees."<<endl;
    }
    else{
        b=500*5+(i-500)*(5+2);
        cout<<"Total electricity cost is: "<<b<<" Rupees."<<endl;
    }
  }  
  void getdata1(){
      
       srand((unsigned)time(0)); 
    j = (rand()%90000)+1; 
    cout<< "Total water usage of this month is: " <<j<<" litres."<<endl;
    if(j<=35000){
        t=j*0.03;
        cout<<"Total water bill is: "<<t<<" Rupees."<<endl;
    }
    else{
        t=35000*0.03+(j-35000)*(0.05);
        cout<<"Total water bill is:"<<t<<" Rupees."<<endl;
    }
      cout<<endl;
      e=t+b;
      cout<<"Net total is: "<<e<<" Rupees."<<endl;
  }
};
class pay: public electricity{
    public:
    int c,q,z,r,x;
    string d;
  
  void display(){
      fourth:
      cout<<"Enter 1 to pay via e-sewa"<<endl;
      cout<<"Enter 2 to pay via Khalti"<<endl;
      cout<<"Enter 3 to pay via e- banking"<<endl;
      cin>>c;
      switch(c){
          case 1:
          first:
          cout<<"Enter your e-sewa password:"<<endl;
          cin>>d;
          
          
          if(d=="nischal"){
              cout<<"Welcome Back"<<endl;
         
                  cout<<"Enter the amount you want to pay: "<<endl;
                  cin>>z;
                  cout<<"Enter 1 to confirm your payment"<<endl;
                  cout<<"Enter 2 to cancel the payment"<<endl;
                  cin>>r;
                  if(r==1){
                  cout<<"Congratulations, your payment was successful!"<<endl;
                  }
                  else{
                      cout<<"Payment cancelled!"<<endl;
                      goto fourth;
                  }
              }
            
          else{
              cout<<"The password you entered is incorrect, please try again."<<endl;
               goto first;
          }
           if(z==e){
                      cout<<"You have paid the exact amount."<<endl<<"No advance/due amount."<<endl;
                  }
                  else if(z>e){
                      x=z-e;
                      cout<<"You have paid "<<x<<" Rupees in advance."<<endl;
                  }
                  else{
                      x=e-z;
                      cout<<"Due amount is "<<x<<" Rupees."<<endl;
                  }
          break;
         case 2:
          second:
          cout<<"Enter your khalti password:"<<endl;
          cin>>d;
          
          
          if(d=="dhoj"){
              cout<<"Welcome Back"<<endl;
              
                  cout<<"Enter the amount you want to pay:"<<endl;
                  cin>>z;
                  cout<<"Enter 1 to confirm your payment"<<endl;
                  cout<<"Enter 2 to cancel the payment"<<endl;
                  cin>>r;
                  if(r==1){
                  cout<<"Congratulations, your payment was successful!"<<endl;
                  }
                  else{
                      cout<<"Payement cancelled!"<<endl;
                      goto fourth;
                  }
              }
          
          else{
              cout<<"The password you entered is incorrect, please try again."<<endl;
               goto second;
          }
           if(z==e){
                      cout<<"You have paid the exact amount."<<endl<<"No advance/due amount."<<endl;
                  }
                  else if(z>e){
                      x=z-e;
                      cout<<"You have paid "<<x<<" Rupees in advance."<<endl;
                  }
                  else{
                      x=e-z;
                      cout<<"Due amount is:"<<x<<" Rupees."<<endl;
                  }
           
          break;
          
       case 3:
          third:
          cout<<"Enter your e-banking password:"<<endl;
          cin>>d;
          
          
          if(d=="kunwar"){
              cout<<"Welcome Back"<<endl;
          
                  cout<<"Enter the amount you want to pay:"<<endl;
                  cin>>z;
                  cout<<"Enter 1 to confirm your payment"<<endl;
                  cout<<"enter 2 to cancel the payment"<<endl;
                  cin>>r;
                  if(r==1){
                  cout<<"Congratulations, your payment was successful!"<<endl;
                  }
                  else{
                      cout<<"Payement cancelled!"<<endl;
                      goto fourth;
                  }
              }
         
          else{
              cout<<"The password you entered is incorrect, please try again."<<endl;
               goto third;
          }
          if(z==e){
                      cout<<"You have paid the exact amount."<<endl<<"No advance/due amount."<<endl;
                  }
                  else if(z>e){
                      x=z-e;
                      cout<<"You have paid "<<x<<" Rupees in advance."<<endl;
                  }
                  else{
                      x=e-z;
                      cout<<"Due amount is:"<<x<<" Rupees."<<endl;
                  } 
  break;
      }
  
      }
          void hello(){
	  
      	fstream myfile;
		myfile.open("Dhoj.txt",ios::out);
		if(myfile.is_open()){
			myfile<<"The electricity and water bill of house no "<<a<<" is "<<b<<" and the total water bill is "<<j<<endl;
			myfile<<"Your Total bill is "<<e<<endl;
			myfile<<"You payed "<<z<<" rupees"<<endl;
			  time_t currentTime;
  time(&currentTime);
  tm* localTime = localtime(&currentTime);

  // Print the current date and time in Kathmandu
  myfile << "Booking date : " << localTime->tm_mon+1 << "/" << localTime->tm_mday << "/" << localTime->tm_year+1900 << endl;
  myfile <<"Boking time : "<< localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << endl;
  }
}
        
};


int main() {
    pay p;
    p.getdata();
    cout<<endl;
    p.getdata1();
    cout<<endl;
    p.display();
    p.hello();
    time_t currentTime;
  time(&currentTime);
  tm* localTime = localtime(&currentTime);

  // Print the current date and time in Kathmandu
  cout << "Payment date : " << localTime->tm_mon+1 << "/" << localTime->tm_mday << "/" << localTime->tm_year+1900 << endl;
  cout<<"Payment time : "<< localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << endl;

    return 0;
}