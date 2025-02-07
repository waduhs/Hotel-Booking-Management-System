// Menu example for tjnapster
#include <iostream>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <sstream>  

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int,int); // function defined below if this is new to you.
void CheckIn();
void ViewRecord();
void EditRecord();
void DeleteRecord();
void AdministrativeCheckReservation();
void roomFlush();
void receipt();
void intro();
void Exit();

struct guestInformation {
	string name;
	int roomtayp;
	string roomNambar;
	string age;
	string phoneNumber;
	string address;
	string personIncaseofEmergency;
	string numberofpersonICE;
	string birthday;
	string nationality;
	int authenticationCode;
	int numberofDays;
	int expense;
		
};



int main()
{
	
	system("color 02");
	system("cls");

	int menu_item=0, run, x=7;
	bool running = true;
	cout << "\n\n\n";
	
	
	
	


	/*
     Sleep(150); // Transition speed of text.
    cout << "\t\t\t\t * * *  **** *      ****  ***   * *   ****   " << endl;
     Sleep(150);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *        " << endl;
     Sleep(150);
    cout << "\t\t\t\t * * * ***** *     *     *   * * * * *****    " << endl;
     Sleep(150);
    cout << "\t\t\t\t * * * *     *     *     *   * * * * *         " << endl;
     Sleep(150);
    cout << "\t\t\t\t  ***   **** *****  ****  ***  * * *  ****     " << endl;
     Sleep(150);
    cout << endl;
     Sleep(150);
    cout << endl;
    cout << "\t\t\t\t=============================================" << endl;
     Sleep(150);
    cout << "\t\t\t\t\tTHIS IS HOTEL MANEGEMENT SYSTEM" << endl;
     Sleep(150);
    cout << "\t\t\t\t=============================================\n" << endl;
     Sleep(150);
    cout << "press any key to continue... ";
    cin.ignore();
    system("cls");

	*/


	
	while(running)
	{



	
	

		gotoXY(18,1); cout << "=============================================";
		gotoXY(18,2); cout << "HOTEL NAME";
		gotoXY(18,3); cout << "ADDITIONAL INFO";
		gotoXY(18,4); cout << "=============================================";
		gotoXY(18,5); cout << "\tMain Menu";
        gotoXY(20,7);  cout << "1) Check In";
		gotoXY(20,8);  cout << "2) View Record";
		gotoXY(20,9);  cout << "3) Edit Record";
		gotoXY(20,10); cout << "4) Delete Record";
		gotoXY(20,11); cout << "5) Administrative Check Reservation";
		gotoXY(20,12); cout << "6) Room reset";
		gotoXY(20,13); cout << "7) Exit";
		gotoXY(18,14); cout << "=============================================";
		gotoXY(18,15); cout << "\t ----HOTEL MANAGEMENT SYSTEM----";
		gotoXY(18,16); cout << "=============================================";
	

	
		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 14) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				menu_item++;
				continue;
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 6) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					
					gotoXY(20,16);
					running = false;
					CheckIn();
					
					break;
				}
					
					
				case 1: {
					gotoXY(20,16);
					ViewRecord();
					break;
				}
					
				case 2: {
					gotoXY(20,16);
					EditRecord();
					break;
				}
					
				case 3: {
					gotoXY(20,16);
					DeleteRecord();
					break;
				}
					
				case 4: {
					gotoXY(20,16);
					AdministrativeCheckReservation();
					break;
				
					
				case 5: {
					gotoXY(20,16);
					roomFlush();
					break;
				}
				
				case 6: {
					gotoXY(20,16);
					Exit();
					running = false;
					break;
				}
					
				}
				
			}
				
		}		
		
	}
	
	gotoXY(20,21);
	return 0;
}

void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}

void CheckIn(){


	struct guestInformation guest;
	int desiredRoom; 
	int roomPrice;
	char choice;
	int roomNumber;
	int ran;
	bool roomTypebool = false;
	const int ps = 3;
	
	int presedentialSuite [3] = {};
	int suite [5] = {};
	int king [7] = {};
	int queen [7] = {};
	int twinBedroom [10] = {};
	int doubleBedroom [10] = {};
	int singleBedroom [10] = {};
	
	ifstream input;
	input.open("chunk.txt", ios :: in | ios :: binary );
	while(input.read(reinterpret_cast<char *>(&guest),sizeof(guestInformation)))
    {
		cout << guest.name << " " << guest.address;
    
    	cin.get();
	}
	input.close();
	
	//system ("cls");
	cout << "\n";
	cout << "\n\t\t\t========================**********************========================\n";
	cout << "\t\t\t\t\t      WELCOME TO HOTEL Check In!\n";
	cout << "\t\t\t========================**********************========================\n";
	cout << "\n\n\t\t\t***********************************************************************\n";
	cout << "\t\t\tRoom Description :";
	cout << "\t\t\tEvery Room Offer 24 hour rate :";
	cout << "\n\n\t\t\t***********************************************************************\n";
	
	cout << "\n\t\t\t*********************"
			"\n\n\n\t\t\tPresidential Suite\n\t\t\t"
			"\n\t\t\t***************************************************************"
			"\n\t\t\tThe most expensive room offered by the hotel. As a general rule,"
			"\n\t\t\tthe hotel has only one president suite accessible. Presidential"
            "\n\t\t\tsuites, like other suites, always have one or more bedrooms and "
			"\n\t\t\tliving areas, with a focus on luxurious interior design, "
			"\n\t\t\tfirst-class amenities and accessories, and customized services "
			"\n\t\t\tsuch as personal butlers during your stay."
			"\n\n\t\t\tFEATURES"
			"\n\t\t\t-Large living room\t\t-Luxury Etro amenities"
			"\n\t\t\t-Fully equipped kitchen\t\t-Nightly Turndown Service"
			"\n\t\t\t-Working and Dining Area\t-24 Hours Housekeeping Service"
			"\n\t\t\t-Two LCD TVs\t\t\t-24 Hours Room Service"
			"\n\t\t\t-Climate Control\t\t-Complimentary Wi-Fi throughout the hotel"
			"\n\t\t\t-One Bedroom & Living room\t-Complimentary Bottled Mineral Water, Refreshed Daily"
			"\n\t\t\t-Guest bathroom\t";
	cout << "\n\n\t\t\t***********************************************************************\n"
			"\n\t\t\t24 hour rate : 9,500 Php\t";
	cout << "\n\n\t\t\t***********************************************************************\n";

			
	cout << "\n\t\t\t*********************"
			"\n\n\n\t\t\tSuite\n\t\t\t"
			"\n\t\t\t***************************************************************"
			"\n\t\t\tA living room or salon that is attached to one or more bedrooms. "
			"\n\t\t\t(A space containing a separate, living area and one or more bedrooms.)"
			"\n\n\t\t\tFEATURES"
			"\n\t\t\t-Air conditioned\t\t-Dining Setting"
			"\n\t\t\t-Mini Bar\t\t\t-Lounge Area"
			"\n\t\t\t-Views\t\t\t\t-Hairdryer"
			"\n\t\t\t-Room Safe\t\t\t-Room Service"
			"\n\t\t\t-Television\t\t\t-Desk"
			"\n\t\t\t-Cable/Satellite TV\t\t-King Bed"
			"\n\t\t\t-Telephone\t\t\t-Sofa Bed"
			"\n\t\t\t-Daily Room Service\t\t-Broadband Internet Access"
			"\n\t\t\t-Linen Provided\t\t\t-Linen and Towels Provided"
			"\n\t\t\t-Wireless Internet\t\t-Mini Fridge"
			"\n\t\t\t-Bath\tNon-Smoking";
	cout << "\n\n\t\t\t***********************************************************************\n"
			"\n\t\t\t24 hour rate : 7,500 Php\t";
	cout << "\n\n\t\t\t***********************************************************************\n";
			
	cout << "\n\t\t\t*********************"
			"\n\n\n\t\t\tKing\n\t\t\t"
			"\n\t\t\t***************************************************************"
			"\n\t\t\tA king bed is in the king room. 6 feet by 6 feet is the size of "
			"\n\t\t\tthe bed. The guest may request and pay for the addition of "
			"\n\t\t\tadditional beds in this accommodation "
			"\n\n\t\t\tFEATURES"
			"\n\t\t\t-Air conditioned\t\t-Private bathroom"
			"\n\t\t\t-Free WiFi\t\t\t-Free Breakfast"
			"\n\t\t\t-Views\t\t\t\t-Hairdryer"
			"\n\t\t\t-Hot/Cold Shower\t\t-Writing Desk & Chair"
			"\n\t\t\t-Bottled Mineral Water\t\t-Free Mini Bar"
			"\n\t\t\t-32 inch LED TV\t\t\t-King Bed"
			"\n\t\t\t-Telephone\t\t\t-Hair Dryer"
			"\n\t\t\t-Cable/satellite TV channels";
	cout << "\n\n\t\t\t***********************************************************************\n"
			"\n\t\t\t24 hour rate : 6,000 Php\t";
	cout << "\n\n\t\t\t***********************************************************************\n";
			
	cout << "\n\t\t\t*********************"
			"\n\n\n\t\t\tQueen\n\t\t\t"
			"\n\t\t\t***************************************************************"
			"\n\t\t\tA queen-sized bed is in the queen room. 5 feet by 6 feet bed "
			"\n\t\t\tmeasures. The guest may request and pay for the addition of "
			"\n\t\t\tadditional beds in this accommodation"
			"\n\n\t\t\tFEATURES"
			"\n\t\t\t-Air conditioned\t\t-Private bathroom"
			"\n\t\t\t-Free WiFi\t\t\t-Free Breakfast"
			"\n\t\t\t-Views\t\t\t\t-Hairdryer"
			"\n\t\t\t-Hot/Cold Shower\t\t-Writing Desk & Chair"
			"\n\t\t\t-Bottled Mineral Water\t\t-Free Mini Bar"
			"\n\t\t\t-32 inch LED TV\t\t\t-King Bed"
			"\n\t\t\t-Telephone\t\t\t-Hair Dryer"
			"\n\t\t\t-Cable/satellite TV channels\t-Safety Deposit Box";
	cout << "\n\n\t\t\t***********************************************************************\n"
			"\n\t\t\t24 hour rate : 6,000 Php\t";
	cout << "\n\n\t\t\t***********************************************************************\n";
			
	cout << "\n\t\t\t*********************"
			"\n\n\n\t\t\tTwin\n\t\t\t"
			"\n\t\t\t***************************************************************"
			"\n\t\t\tFor two individuals, the twin rooms offer two single beds. The "
			"\n\t\t\tguest may request and pay for the addition of additional beds "
			"\n\t\t\tin this accommodation. The typical bed size in this area is 3 "
			"\n\t\t\tfeet by 6 feet. These spaces are suited for housing shared "
			"\n\t\t\trepresentative meetings between groups."
			"\n\n\t\t\tFEATURES"
			"\n\t\t\t-Two single beds (90cm)\t\t-Free WiFi"
			"\n\t\t\t-Hair dryer\t\t\t-Refrigerator / Minibar"
			"\n\t\t\t-Flat screen LCD TV\t\t-Safe"
			"\n\t\t\t-Views\t\t\t\t-Telephone"
			"\n\t\t\t-Linen and Towels Provided\t-Desk"
			"\n\t\t\t-Laundry Facilities\t\t-Room Service"
			"\n\t\t\t-Wireless Internet"
			"\n\t\t\t-Individual room temperature control"
			"\n\t\t\t-Direct-line telephone in the room";
	cout << "\n\n\t\t\t***********************************************************************\n"
			"\n\t\t\t24 hour rate : 4,000 Php\t";
	cout << "\n\n\t\t\t***********************************************************************\n";


			
	cout << "\n\t\t\t*********************"
			"\n\n\n\t\t\tDouble Bedroom\n\t\t\t"
			"\n\t\t\t***************************************************************"
			"\n\t\t\tA double bed for two persons is in the double room. The guest "
			"\n\t\t\tmay request and pay for the addition of additional beds in this  "
			"\n\t\t\taccommodation. Typically, double beds measure 4.5 feet by 6 feet.  "
			"\n\n\t\t\tFEATURES"
			"\n\t\t\t-Air conditioned\t\t\t-Cable/Satellite TV"
			"\n\t\t\t-Mini Fridge\t\t\t\t-Telephone"
			"\n\t\t\t-Views\t\t\t\t\t-Hairdryer"
			"\n\t\t\t-Balcony\t\t\t\t-Heating"
			"\n\t\t\t-Non-Smoking\t\t\t\t-Television"
			"\n\t\t\t-Linen and Towels Provided\t\t-Desk"
			"\n\t\t\t-Laundry Facilities\t\t\t-Room Service"
			"\n\t\t\t-Wireless Internet\t\t\t-King / 2 single beds"
			"\n\t\t\t-Room Safe\t\t\t\t-Disabled Room";
	cout << "\n\n\t\t\t***********************************************************************\n"
			"\n\t\t\t24 hour rate : 4,500 Php\t";
	cout << "\n\n\t\t\t***********************************************************************\n";
			
	cout << "\n\t\t\t*********************"
			"\n\n\n\t\t\tSingle Bedroom\n\t\t\t"
			"\n\t\t\t***************************************************************"
			"\n\t\t\tThere is a temporary single bed in the single room. At the guest's "
			"\n\t\t\trequest, more beds(so-called extra beds) may be added; a surcharge "
			"\n\t\t\twill apply. "
			"\n\n\t\t\tFEATURES"
			"\n\t\t\t-Single Bed\t\t\t-Cots Available"
			"\n\t\t\t-Hair dryer\t\t\t-Shower over bath"
			"\n\t\t\t-Room Safe\t\t\t-Telephone"
			"\n\t\t\t-Wireless Internet\t\t-Mini Fridge"
			"\n\t\t\t-Laundry Facilities\t\t-Linen and Towels Provided";
	cout << "\n\n\t\t\t***********************************************************************\n"
			"\n\t\t\t24 hour rate : 3,000 Php\t";
	cout << "\n\n\t\t\t***********************************************************************\n";
			
	cout << "\t\t\tDesired room ? : \t\t\tPrice :\n";
	cout << "\t\t\t1) Presidential Suite\t\t\t9,500 Php\n";
	cout << "\t\t\t2) Suite\t\t\t\t7,500 Php\n";
	cout << "\t\t\t3) King\t\t\t\t\t6,000 Php\n";
	cout << "\t\t\t4) Queen\t\t\t\t6,000 Php\n";
	cout << "\t\t\t5) Twin Bedroom\t\t\t\t4,000 Php\n";
	cout << "\t\t\t6) Double Bedroom\t\t\t4,500 Php\n";
	cout << "\t\t\t7) Single Bedroom\t\t\t3,000 Php\n";
	cout << "\t\t\t=======================================================================\n\t\t\t";



	
	
		cout << "\n\t\t\tEnter Room Type : \n\t\t\t";
		cin >> desiredRoom;
		if (desiredRoom == 1)
		{
			ifstream file("presidentialSuite.txt");
		    if(file.is_open())
		    {
		        for(int i = 0; i < 3; ++i)
		        {
		            file >> presedentialSuite[i];
		            cout <<"\n\t\t\tRoom "<<i+1<< " "<< presedentialSuite[i]<<"\n";
		        }
		    }
		}
		
		if (desiredRoom == 2)
		{
			ifstream file("suite.txt");
		    if(file.is_open())
		    {
		        
		
		        for(int i = 0; i < 5; ++i)
		        {
		            file >> suite[i];
		            cout <<"\n\t\t\tRoom "<<i+1<< " "<< suite[i]<<"\n";
		        }
		    }
		}
		
		if (desiredRoom == 3)
		{
			ifstream file("king.txt");
		    if(file.is_open())
		    {
		
		        for(int i = 0; i < 7; ++i)
		        {
		            file >> king[i];
		            cout <<"\n\t\t\tRoom "<<i+1<< " "<< king[i]<<"\n";
		        }
		    }
		}
		
		if (desiredRoom == 4)
		{
			ifstream file("queen.txt");
		    if(file.is_open())
		    {
		
		        for(int i = 0; i < 7; ++i)
		        {
		            file >> queen[i];
		            cout <<"\n\t\t\tRoom "<<i+1<< " "<< queen[i]<<"\n";
		        }
		    }
		}
		
		if (desiredRoom == 5)
		{
			ifstream file("twin.txt");
		    if(file.is_open())
		    {
		        for(int i = 0; i < 10; ++i)
		        {
		            file >> twinBedroom[i];
		            cout <<"\n\t\t\tRoom "<<i+1<< " "<< twinBedroom[i]<<"\n";
		        }
		    }
		}
		
			if (desiredRoom == 6)
		{
			ifstream file("doublebedroom.txt");
		    if(file.is_open())
		    {
		        for(int i = 0; i < 10; ++i)
		        {
		            file >> doubleBedroom[i];
		            cout << "\n\t\t\tRoom " << i + 1 << " "<< doubleBedroom[i] << "\n" ;
		        }
		    }
		}
		

		
		if (desiredRoom == 7)
		{
			ifstream file("single.txt");
		    if(file.is_open())
		    {
		
		        for(int i = 0; i < 10; ++i)
		        {
		            file >> singleBedroom[i];
		            cout <<"\n\t\t\tRoom "<<i+1<< " "<< singleBedroom[i]<<"\n";
		        }
		    }
		}
 	
    

	
	
	cout << "\n\t\t\tContinue ? Yes [Y] or No [N] or Menu [M]  :";
	cin >> choice;
	
	if (choice == 'Y')
	{
		cout << "\n\t\t\tEnter Room Number : ";
		cin >> roomNumber;
		
		ofstream fp; 
		fp.open("chunk.txt",ios::app|ios::binary);
		
		cin.ignore();
		cout << "\n\t\t\tEnter Days of Stay : ";
		cin >> guest.numberofDays;
		cin.ignore();
		cout << "\n\t\t\tEnter Name : ";
		getline(cin, guest.name);
		cout << guest.name;
		cout << "\n\t\t\tEnter Age : ";
		getline(cin, guest.age);
		cout << "\n\t\t\tEnter Birthday : ";
		getline(cin, guest.birthday);
		cout << "\n\t\t\tEnter Nationality : ";
		getline(cin, guest.nationality);
		cout << "\n\t\t\tEnter Phone Number : ";
		getline(cin, guest.phoneNumber);
		cout << "\n\t\t\tEnter Address : ";
		getline(cin, guest.address);
		cout << "\n\t\t\tEnter Person in case of Emergency : ";
		getline(cin, guest.personIncaseofEmergency);
		cout << "\n\t\t\tEnter Number of Person in case of Emergency : ";
		getline(cin, guest.numberofpersonICE);
		cout << "\n\t\t\t===========================Enter To Continue===========================";
		guest.roomNambar = roomNumber;
		guest.roomtayp = desiredRoom;
		
		
		if (desiredRoom == 1){
			guest.expense = 9500;
		}
		if (desiredRoom == 2){
			guest.expense = 7500;
		}
		if (desiredRoom == 3){
			guest.expense = 6000;
		}
		if (desiredRoom == 4){
			guest.expense = 6000;
		}
		if (desiredRoom == 5){
			guest.expense = 4000;
		}
		if (desiredRoom == 6){
			guest.expense = 4500;
		}
		if (desiredRoom == 7){
			guest.expense = 3000;
		}
		
		
		
		srand (time(NULL)); //disadvantage of ctime, it depends on the time the code generated
		ran = rand()%100000; // random code generator
		guest.authenticationCode = ran; //random code saved to res.code
		cin.get();
		
		
		
		
		
		fp.write((char*)&guest, sizeof(guestInformation));//gatthered data
    	fp.close();
  
    	

    	if (desiredRoom == 1){
			presedentialSuite[roomNumber - 1] = guest.authenticationCode;
		}
		if (desiredRoom == 2){
			suite[roomNumber - 1] = guest.authenticationCode;
		}
		if (desiredRoom == 3){
			king[roomNumber - 1] = guest.authenticationCode;
		}
		if (desiredRoom == 4){
			queen[roomNumber - 1] = guest.authenticationCode;
		}
		if (desiredRoom == 5){
			twinBedroom[roomNumber - 1] = guest.authenticationCode;
		}
		if (desiredRoom == 6){
			doubleBedroom[roomNumber - 1] = guest.authenticationCode;
		}
		if (desiredRoom == 7){
			singleBedroom[roomNumber - 1] = guest.authenticationCode;
		}
		
		
		if (desiredRoom == 1){
		fstream myfile ("PresidentialSuite.txt");
		  if (myfile.is_open())
		  {
		    for(int count = 0; count < ps; count ++){	
				myfile << presedentialSuite[count] << " " ;
		    }
		    myfile.close();
		  }
		  else cout << "Unable to open file";
		}
		
		
		if (desiredRoom == 2){
			 const int sw = 5;
		fstream myfile2 ("Suite.txt");
		  if (myfile2.is_open())
		  {
		    for(int count = 0; count < sw; count ++){
		        myfile2 << suite[count] << " " ;
		    }
		    myfile2.close();
		  }
		  else cout << "Unable to open file";
		}
		
		
		if (desiredRoom == 3){
			 
		  const int ki = 7;
		fstream myfile3 ("king.txt");
		  if (myfile3.is_open())
		  {
		    for(int count = 0; count < ki; count ++){
		        myfile3 << king[count] << " " ;
		    }
		    myfile3.close();
		  }
		  else cout << "Unable to open file";
		}
		
		
		if (desiredRoom == 4){
			  const int qu = 7;
		fstream myfile4 ("queen.txt");
		  if (myfile4.is_open())
		  {
		    for(int count = 0; count < qu; count ++){
		        myfile4 << queen[count] << " " ;
		    }
		    myfile4.close();
		  }
		  else cout << "Unable to open file";
		}
		
		
		if (desiredRoom == 5){
				  
		  const int tw = 10;
		fstream myfile5 ("twin.txt");
		  if (myfile5.is_open())
		  {
		    for(int count = 0; count < tw; count ++){
		        myfile5 << twinBedroom[count] << " " ;
		    }
		    myfile5.close();
		  }
		  else cout << "Unable to open file";
		}
		
		
		if (desiredRoom == 6){
			 const int db = 10;
		fstream myfile6 ("double.txt");
		  if (myfile6.is_open())
		  {
		    for(int count = 0; count < db; count ++){
		    	
		        myfile6 << doubleBedroom[count] << " " ;
		    }
		    myfile6.close();
		  }
		  else cout << "Unable to open file";
		}
		
		
		if (desiredRoom == 7){
				  const int si = 10;
		fstream myfile7 ("single.txt");
		  if (myfile7.is_open())
		  {
		    for(int count = 0; count < si; count ++){
		    	
		        myfile7 << singleBedroom[count] << " " ;
		    }
		    myfile7.close();
		  }
		  else cout << "Unable to open file";
		}
		
		
	
		  
		 
		 
		  
		
	

		  
		  
	
		  
		  

   		
   		
    	system("cls");
		system ("color 06");
		cout << "\n\t\t\t========================**********************========================\n";
		Sleep(200);
		cout << "\t\t\t\t\t        Registration Complete !\n";
		Sleep(200);
		cout << "\t\t\t========================**********************========================\n\n\n";
		Sleep(200);
		cout << "\n\t\t\t========================**********************========================\n";
		Sleep(200);
		cout << "\t\t\t\t\t        Receipt Code : " << guest.authenticationCode;
		Sleep(200);
		cout << "\n\t\t\t========================**********************========================\n\n\n";
		Sleep(200);
    	
    	cin.ignore();
    	cin.get();
    	cin.get();
    	cin.get();
    	
	
	}
	if (choice == 'N')
	{
		CheckIn();
	}
	else 
	{
		main();
	}
	
	
}





void ViewRecord(){
	
	
	struct guestInformation guest;
	int code;
	
	system ("cls");
	cin >> code;
	
	ifstream infile;
    infile.open("chunk.txt",ios::app|ios::binary);
    if (infile.fail()){
		cout<<"THE FILE COULD NOT BE OPENED...";
        cin.ignore();
        cin.get();
	}
	
    while( infile.read (reinterpret_cast<char*>(&guest),sizeof(guestInformation)))
	{
		
		
		
    	if (code == guest.authenticationCode)
		{
    		
    		
    		cin.ignore();
    		if (guest.roomtayp == 1)
    		
			{
    				cout << "\n\t\t\t*********************"
							"\n\n\n\t\t\tPresidential Suite\n\t\t\t"
							"\n\t\t\t***************************************************************"
							"\n\t\t\tThe most expensive room offered by the hotel. As a general rule,"
							"\n\t\t\tthe hotel has only one president suite accessible. Presidential"
				            "\n\t\t\tsuites, like other suites, always have one or more bedrooms and "
							"\n\t\t\tliving areas, with a focus on luxurious interior design, "
							"\n\t\t\tfirst-class amenities and accessories, and customized services "
							"\n\t\t\tsuch as personal butlers during your stay."
							"\n\n\t\t\tFEATURES"
							"\n\t\t\t-Large living room\t\t-Luxury Etro amenities"
							"\n\t\t\t-Fully equipped kitchen\t\t-Nightly Turndown Service"
							"\n\t\t\t-Working and Dining Area\t-24 Hours Housekeeping Service"
							"\n\t\t\t-Two LCD TVs\t\t\t-24 Hours Room Service"
							"\n\t\t\t-Climate Control\t\t-Complimentary Wi-Fi throughout the hotel"
							"\n\t\t\t-One Bedroom & Living room\t-Complimentary Bottled Mineral Water, Refreshed Daily"
							"\n\t\t\t-Guest bathroom\t";
					cout << "\n\n\t\t\t***********************************************************************\n"
							"\n\t\t\t24 hour rate : 9,500 Php\t";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\t\t\tName					:"				<< guest.name;
					cout << "\n\t\t\tAge					:"				<< guest.age;
					cout << "\n\t\t\tBirthday				:"				<< guest.birthday;
					cout << "\n\t\t\tPhone Number				:"			<< guest.phoneNumber;
					cout << "\n\t\t\tNationality				:"			<< guest.nationality;
					cout << "\n\t\t\tAddress					:"			<< guest.address;
					cout << "\n\t\t\tPerson in case of Emergency		:"	<< guest.personIncaseofEmergency;
					cout << "\n\t\t\tPhone number of PCE			:"		<< guest.numberofpersonICE;
					cin.get();
					cin.get();
					main();

			}
			
			if (guest.roomtayp==2)
			{
				
					cout << "\n\t\t\t*********************"
							"\n\n\n\t\t\tSuite\n\t\t\t"
							"\n\t\t\t***************************************************************"
							"\n\t\t\tA living room or salon that is attached to one or more bedrooms. "
							"\n\t\t\t(A space containing a separate, living area and one or more bedrooms.)"
							"\n\n\t\t\tFEATURES"
							"\n\t\t\t-Air conditioned\t\t-Dining Setting"
							"\n\t\t\t-Mini Bar\t\t\t-Lounge Area"
							"\n\t\t\t-Views\t\t\t\t-Hairdryer"
							"\n\t\t\t-Room Safe\t\t\t-Room Service"
							"\n\t\t\t-Television\t\t\t-Desk"
							"\n\t\t\t-Cable/Satellite TV\t\t-King Bed"
							"\n\t\t\t-Telephone\t\t\t-Sofa Bed"
							"\n\t\t\t-Daily Room Service\t\t-Broadband Internet Access"
							"\n\t\t\t-Linen Provided\t\t\t-Linen and Towels Provided"
							"\n\t\t\t-Wireless Internet\t\t-Mini Fridge"
							"\n\t\t\t-Bath\tNon-Smoking";
					cout << "\n\n\t\t\t***********************************************************************\n"
							"\n\t\t\t24 hour rate : 7,500 Php\t";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\t\t\tName					:"				<< guest.name;
					cout << "\n\t\t\tAge					:"				<< guest.age;
					cout << "\n\t\t\tBirthday				:"				<< guest.birthday;
					cout << "\n\t\t\tPhone Number				:"			<< guest.phoneNumber;
					cout << "\n\t\t\tNationality				:"			<< guest.nationality;
					cout << "\n\t\t\tAddress					:"			<< guest.address;
					cout << "\n\t\t\tPerson in case of Emergency		:"	<< guest.personIncaseofEmergency;
					cout << "\n\t\t\tPhone number of PCE			:"		<< guest.numberofpersonICE;
					cin.get();
					cin.get();
					main();
				
			}
			
			if (guest.roomtayp==3)
			{
				
					cout << "\n\t\t\t*********************"
							"\n\n\n\t\t\tKing\n\t\t\t"
							"\n\t\t\t***************************************************************"
							"\n\t\t\tA king bed is in the king room. 6 feet by 6 feet is the size of "
							"\n\t\t\tthe bed. The guest may request and pay for the addition of "
							"\n\t\t\tadditional beds in this accommodation "
							"\n\n\t\t\tFEATURES"
							"\n\t\t\t-Air conditioned\t\t-Private bathroom"
							"\n\t\t\t-Free WiFi\t\t\t-Free Breakfast"
							"\n\t\t\t-Views\t\t\t\t-Hairdryer"
							"\n\t\t\t-Hot/Cold Shower\t\t-Writing Desk & Chair"
							"\n\t\t\t-Bottled Mineral Water\t\t-Free Mini Bar"
							"\n\t\t\t-32 inch LED TV\t\t\t-King Bed"
							"\n\t\t\t-Telephone\t\t\t-Hair Dryer"
							"\n\t\t\t-Cable/satellite TV channels";
					cout << "\n\n\t\t\t***********************************************************************\n"
							"\n\t\t\t24 hour rate : 6,000 Php\t";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\t\t\tName					:"				<< guest.name;
					cout << "\n\t\t\tAge					:"				<< guest.age;
					cout << "\n\t\t\tBirthday				:"				<< guest.birthday;
					cout << "\n\t\t\tPhone Number				:"			<< guest.phoneNumber;
					cout << "\n\t\t\tNationality				:"			<< guest.nationality;
					cout << "\n\t\t\tAddress					:"			<< guest.address;
					cout << "\n\t\t\tPerson in case of Emergency		:"	<< guest.personIncaseofEmergency;
					cout << "\n\t\t\tPhone number of PCE			:"		<< guest.numberofpersonICE;
					cin.get();
					cin.get();
					main();
				
			}
			
			if (guest.roomtayp==4)
			{
				
					cout << "\n\t\t\t*********************"
							"\n\n\n\t\t\tQueen\n\t\t\t"
							"\n\t\t\t***************************************************************"
							"\n\t\t\tA queen-sized bed is in the queen room. 5 feet by 6 feet bed "
							"\n\t\t\tmeasures. The guest may request and pay for the addition of "
							"\n\t\t\tadditional beds in this accommodation"
							"\n\n\t\t\tFEATURES"
							"\n\t\t\t-Air conditioned\t\t-Private bathroom"
							"\n\t\t\t-Free WiFi\t\t\t-Free Breakfast"
							"\n\t\t\t-Views\t\t\t\t-Hairdryer"
							"\n\t\t\t-Hot/Cold Shower\t\t-Writing Desk & Chair"
							"\n\t\t\t-Bottled Mineral Water\t\t-Free Mini Bar"
							"\n\t\t\t-32 inch LED TV\t\t\t-King Bed"
							"\n\t\t\t-Telephone\t\t\t-Hair Dryer"
							"\n\t\t\t-Cable/satellite TV channels\t-Safety Deposit Box";
					cout << "\n\n\t\t\t***********************************************************************\n"
							"\n\t\t\t24 hour rate : 6,000 Php\t";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\t\t\tName					:"				<< guest.name;
					cout << "\n\t\t\tAge					:"				<< guest.age;
					cout << "\n\t\t\tBirthday				:"				<< guest.birthday;
					cout << "\n\t\t\tPhone Number				:"			<< guest.phoneNumber;
					cout << "\n\t\t\tNationality				:"			<< guest.nationality;
					cout << "\n\t\t\tAddress					:"			<< guest.address;
					cout << "\n\t\t\tPerson in case of Emergency		:"	<< guest.personIncaseofEmergency;
					cout << "\n\t\t\tPhone number of PCE			:"		<< guest.numberofpersonICE;
					cin.get();
					cin.get();
					main();
					
			}
			
			if (guest.roomtayp==5)
			{
					cout << "\n\t\t\t*********************"
							"\n\n\n\t\t\tTwin\n\t\t\t"
							"\n\t\t\t***************************************************************"
							"\n\t\t\tFor two individuals, the twin rooms offer two single beds. The "
							"\n\t\t\tguest may request and pay for the addition of additional beds "
							"\n\t\t\tin this accommodation. The typical bed size in this area is 3 "
							"\n\t\t\tfeet by 6 feet. These spaces are suited for housing shared "
							"\n\t\t\trepresentative meetings between groups."
							"\n\n\t\t\tFEATURES"
							"\n\t\t\t-Two single beds (90cm)\t\t-Free WiFi"
							"\n\t\t\t-Hair dryer\t\t\t-Refrigerator / Minibar"
							"\n\t\t\t-Flat screen LCD TV\t\t-Safe"
							"\n\t\t\t-Views\t\t\t\t-Telephone"
							"\n\t\t\t-Linen and Towels Provided\t-Desk"
							"\n\t\t\t-Laundry Facilities\t\t-Room Service"
							"\n\t\t\t-Wireless Internet"
							"\n\t\t\t-Individual room temperature control"
							"\n\t\t\t-Direct-line telephone in the room";
					cout << "\n\n\t\t\t***********************************************************************\n"
							"\n\t\t\t24 hour rate : 4,000 Php\t";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\t\t\tName					:"				<< guest.name;
					cout << "\n\t\t\tAge					:"				<< guest.age;
					cout << "\n\t\t\tBirthday				:"				<< guest.birthday;
					cout << "\n\t\t\tPhone Number				:"			<< guest.phoneNumber;
					cout << "\n\t\t\tNationality				:"			<< guest.nationality;
					cout << "\n\t\t\tAddress					:"			<< guest.address;
					cout << "\n\t\t\tPerson in case of Emergency		:"	<< guest.personIncaseofEmergency;
					cout << "\n\t\t\tPhone number of PCE			:"		<< guest.numberofpersonICE;	
					cin.get();
					cin.get();
					main();
					
			}
			
			if (guest.roomtayp==6)
			{
				
					cout << "\n\t\t\t*********************"
							"\n\n\n\t\t\tDouble Bedroom\n\t\t\t"
							"\n\t\t\t***************************************************************"
							"\n\t\t\tA double bed for two persons is in the double room. The guest "
							"\n\t\t\tmay request and pay for the addition of additional beds in this  "
							"\n\t\t\taccommodation. Typically, double beds measure 4.5 feet by 6 feet.  "
							"\n\n\t\t\tFEATURES"
							"\n\t\t\t-Air conditioned\t\t\t-Cable/Satellite TV"
							"\n\t\t\t-Mini Fridge\t\t\t\t-Telephone"
							"\n\t\t\t-Views\t\t\t\t\t-Hairdryer"
							"\n\t\t\t-Balcony\t\t\t\t-Heating"
							"\n\t\t\t-Non-Smoking\t\t\t\t-Television"
							"\n\t\t\t-Linen and Towels Provided\t\t-Desk"
							"\n\t\t\t-Laundry Facilities\t\t\t-Room Service"
							"\n\t\t\t-Wireless Internet\t\t\t-King / 2 single beds"
							"\n\t\t\t-Room Safe\t\t\t\t-Disabled Room";
					cout << "\n\n\t\t\t***********************************************************************\n"
							"\n\t\t\t24 hour rate : 4,500 Php\t";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\t\t\tName					:"				<< guest.name;
					cout << "\n\t\t\tAge					:"				<< guest.age;
					cout << "\n\t\t\tBirthday				:"				<< guest.birthday;
					cout << "\n\t\t\tPhone Number				:"			<< guest.phoneNumber;
					cout << "\n\t\t\tNationality				:"			<< guest.nationality;
					cout << "\n\t\t\tAddress					:"			<< guest.address;
					cout << "\n\t\t\tPerson in case of Emergency		:"	<< guest.personIncaseofEmergency;
					cout << "\n\t\t\tPhone number of PCE			:"		<< guest.numberofpersonICE;
					cin.get();
					cin.get();
					main();
					
			}
			
			if (guest.roomtayp==7)
			{
					cout << "\n\t\t\t*********************"
							"\n\n\n\t\t\tSingle Bedroom\n\t\t\t"
							"\n\t\t\t***************************************************************"
							"\n\t\t\tThere is a temporary single bed in the single room. At the guest's "
							"\n\t\t\trequest, more beds(so-called extra beds) may be added; a surcharge "
							"\n\t\t\twill apply. "
							"\n\n\t\t\tFEATURES"
							"\n\t\t\t-Single Bed\t\t\t-Cots Available"
							"\n\t\t\t-Hair dryer\t\t\t-Shower over bath"
							"\n\t\t\t-Room Safe\t\t\t-Telephone"
							"\n\t\t\t-Wireless Internet\t\t-Mini Fridge"
							"\n\t\t\t-Laundry Facilities\t\t-Linen and Towels Provided";
					cout << "\n\n\t\t\t***********************************************************************\n"
							"\n\t\t\t24 hour rate : 3,000 Php\t";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cout << "\n\n\t\t\t***********************************************************************\n";
					cin.ignore();
					cin.ignore();
					cin.ignore();
					cin.ignore();
					cout << "\n\t\t\tName					:"				<< guest.name;
					cout << "\n\t\t\tAge					:"				<< guest.age;
					cout << "\n\t\t\tBirthday				:"				<< guest.birthday;
					cout << "\n\t\t\tPhone Number				:"			<< guest.phoneNumber;
					cout << "\n\t\t\tNationality				:"			<< guest.nationality;
					cout << "\n\t\t\tAddress					:"			<< guest.address;
					cout << "\n\t\t\tPerson in case of Emergency		:"	<< guest.personIncaseofEmergency;
					cout << "\n\t\t\tPhone number of PCE			:"		<< guest.numberofpersonICE;
					cin.get();
					cin.get();
					main();
					
			}

			
			//end
		}
    	
    	
    	
	}

  
  
    infile.close(); // Closes the text file.
	cin.get();
	cin.get();

	main();

}



void EditRecord(){
	struct guestInformation guest;
	int codex;
	cout << "\n\t\t\t========================**********************========================\n";
	cout << "\t\t\t\t\t      WELCOME TO HOTEL Edit record\n";
	cout << "\t\t\t========================**********************========================\n";
	cout << "\t\t\t================================================\n";
	cout << "\t\t\tEnter Guest Code : ";
	cin >> codex;
	if (codex == guest.authenticationCode)
	{
		ifstream input;
		input.open("test.txt", ios :: in | ios :: binary );
		while(input.read(reinterpret_cast<char *>(&guest),sizeof(guestInformation)))
    	{
			cout << "\n\t\t\tName					:"				<< guest.name;
			cout << "\n\t\t\tAge					:"				<< guest.age;
			cout << "\n\t\t\tBirthday				:"				<< guest.birthday;
			cout << "\n\t\t\tPhone Number				:"			<< guest.phoneNumber;
			cout << "\n\t\t\tNationality				:"			<< guest.nationality;
			cout << "\n\t\t\tAddress					:"			<< guest.address;
			cout << "\n\t\t\tPerson in case of Emergency		:"	<< guest.personIncaseofEmergency;
			cout << "\n\t\t\tPhone number of PCE			:"		<< guest.numberofpersonICE;
    	
    		cin.get();
		}
		input.close();
		
	}
	
}





void DeleteRecord(){
	struct guestInformation guest;
	int codex;
	cout << "\n\t\t\t========================**********************========================\n";
	cout << "\t\t\t\t\t     WELCOME TO HOTEL DELETE RECORD\n";
	cout << "\t\t\t========================**********************========================\n";
	cout << "\t\t\t================================================\n";
	cout << "\t\t\tEnter Guest Code : ";
	cin >> codex;
	/*
	ifstream delta;
	delta.open("chunk.txt", ios :: app | ios :: Binary);
	while(delta.read(reinterpret_cast< char *>(&guest),sizeof(guestInformation)))
	{
		
		if (codex == guest.authenticationCode)
		{
		
		}
		
		
		
		
	}
	*/
}






void AdministrativeCheckReservation(){
	struct guestInformation guest;
	int password;
	system("cls");
	cout << "\n\t\t\t========================**********************========================\n";
	cout << "\t\t\t\t\tWELCOME TO HOTEL ADMINISTRATIVE CHECK RECORD\n";
	cout << "\t\t\t========================**********************========================\n";
	cout << "\t\t\t================================================\n";
	cout << "\t\t\tEnter Administrative Password : ";
	cin >> password;
	if (password == 1234567890)
	{
		ifstream input;
		input.open("chunk.txt", ios :: in | ios :: binary );
		while(input.read(reinterpret_cast<char *>(&guest),sizeof(guestInformation)))
    	{
			cout <<  "\n\t\t\t***************************************************\n";
			Sleep(100);
    		cout << "\t\t\t" <<guest.name << " | " << guest.authenticationCode << " | "<<guest.phoneNumber<<endl;
    		Sleep(100);
    		cout <<  "\n\t\t\t***************************************************\n";
    		Sleep(100);
    	
    		cin.get();
		}
		input.close();
			cin.get();
			cin.get();
			cin.ignore();
		
		
		
		system("cls");
		
	}
	
}
void roomFlush(){
	
	
	ofstream d1;
	d1.open("PresidentialSuite.txt");
	
	
	
	
	
	
		fstream myfile ("PresidentialSuite.txt");
		  if (myfile.is_open())
		  {
		    for(int count = 0; count < 3; count ++){	
				myfile << 0 << " " ;
		    }
		    myfile.close();
		  }

		

			 const int sw = 5;
		fstream myfile2 ("Suite.txt");
		  if (myfile2.is_open())
		  {
		    for(int count = 0; count < 5; count ++){
		        myfile2 << 0 << " " ;
		    }
		    myfile2.close();
		  }

		
	
		  const int ki = 7;
		fstream myfile3 ("king.txt");
		  if (myfile3.is_open())
		  {
		    for(int count = 0; count < 7; count ++){
		        myfile3 << 0<< " " ;
		    }
		    myfile3.close();
		  }

		
			  const int qu = 7;
		fstream myfile4 ("queen.txt");
		  if (myfile4.is_open())
		  {
		    for(int count = 0; count < 7; count ++){
		        myfile4 << 0 << " " ;
		    }
		    myfile4.close();
		}

		
		

				  
		  const int tw = 10;
		fstream myfile5 ("twin.txt");
		  if (myfile5.is_open())
		  {
		    for(int count = 0; count < tw; count ++){
		        myfile5 << 0 << " " ;
		    }
		    myfile5.close();
		  }

		
		

			 const int db = 10;
		fstream myfile6 ("double.txt");
		  if (myfile6.is_open())
		  {
		    for(int count = 0; count < db; count ++){
		    	
		        myfile6 << 0<< " " ;
		    }
		    
		    myfile6.close();
		  }

		
		

				  const int si = 10;
		fstream myfile7 ("single.txt");
		  if (myfile7.is_open())
		  {
		    for(int count = 0; count < si; count ++){
		    	
		        myfile7 << 0 << " " ;
		    }
		    myfile7.close();
		  }

}






void Exit()
{
	int weep;
	system ("cls");
	cout << "Exit!";
	cin >> weep;
	system("cls");
}
