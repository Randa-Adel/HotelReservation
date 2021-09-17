#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>
#include<stdlib.h>
using namespace std;
#define Text_File_Path "data/data.txt"
// Some Global Variable**

vector<string> ReadFromTextFile(string FilePath);
vector<string> fileLines = ReadFromTextFile(Text_File_Path);
int NumberOfFloor = 0;
int* NumberOfRoomsInEachFloor = new int[NumberOfFloor] {0};
// بتعد كا الاستاندرد روم في الاوتيل كله
int NumberOfStandardRooms = 0;
// بتعد كا سويت روم في الاوتيل كله
int NumberOfSweetdRooms = 0;
// بتعد كا كونفرينس روم في الاوتيل كله
int NumberOfConferenceRooms = 0;
int** DetailsOfStandardRooms = new int* [NumberOfStandardRooms];
int** DetailsOfConferenceRooms = new int* [NumberOfConferenceRooms];
int** DetailsOfSweetRooms = new int* [NumberOfSweetdRooms];
/**/
void Manipulation(vector<string>& fileLines);
vector<string> ReadFromTextFile(string FilePath);
/* Start Of Classes **/
class Room
{
protected:

	bool is_reversed;
	int room_number;
public:
	Room()
	{
		is_reversed = false;
		room_number = 0;
	}
	virtual void setIs_reversed(bool _is_reversed)
	{
		is_reversed = _is_reversed;
	}
	virtual bool getIs_reversed()
	{
		return is_reversed;
	}
	virtual void setRoom_number(int _room_number)
	{
	}
	virtual  int getRoom_number()
	{
		return 0;
	}
	virtual void setDaysOfReservation(int _daysOfReservation)
	{

	}
	virtual int getDaysOfReservation()
	{
		return 0;
	}
	virtual void setNumber_of_beds(int _number_of_beds)
	{

	}
	virtual int getNumber_of_beds() {
		return 0;
	}
	virtual void setBed_Price(double _Bed_Price)
	{

	}
	virtual double getBed_Price()
	{
		return 0;
	}
	virtual void setPrice_per_night(double _price_per_night)
	{

	}
	virtual double getPrice_per_night()
	{
		return 0;
	}
	virtual void setNumber_of_seats(int _number_of_seats)
	{

	}
	virtual int getNumber_of_seats() {
		return 0;
	}
	virtual void setSeatPrice(double _seatPrice)
	{

	}
	virtual double getSeatPrice() {
		return 0;
	}
	virtual bool Is_Reserve()
	{
		return 0;
	}
	virtual double Total_Profits_Of_Reservation()
	{
		return 0;
	}
	virtual void Reserve()
	{
		is_reversed = true;
	}
	virtual void To_String()
	{
		cout << endl;
	}

};

class Standard_Room :public Room
{
private:
	int daysOfReservation;
	int number_of_beds;
	double Bed_Price;

public:
	Standard_Room()
	{
		daysOfReservation = 0;
		number_of_beds = 0;
		Bed_Price = 0;

	}
	Standard_Room(int number_of_beds, double Bed_Price, int daysOfReservation, int room)
	{
		this->daysOfReservation = daysOfReservation;
		this->number_of_beds = number_of_beds;
		this->Bed_Price = Bed_Price;

	}
	void setRoom_number(int _room_number)
	{
		room_number = _room_number;
	}
	int getRoom_number()
	{
		return room_number;
	}
	void setIs_reversed(bool _is_reversed)
	{
		is_reversed = _is_reversed;
	}
	void setDaysOfReservation(int _daysOfReservation)
	{
		daysOfReservation = _daysOfReservation;
	}
	int getDaysOfReservation() {
		return daysOfReservation;
	}
	void setNumber_of_beds(int _number_of_beds)
	{
		number_of_beds = _number_of_beds;
	}
	int getNumber_of_beds() {
		return number_of_beds;
	}
	void setBed_Price(double _Bed_Price)
	{
		Bed_Price = _Bed_Price;
	}
	double getBed_Price() {
		return Bed_Price;
	}
	double Total_Profits_Of_Reservation()
	{
		double total = Bed_Price * number_of_beds;
		return (daysOfReservation * total);

	}
	void To_String()
	{
		cout << "\t*Available Standard Room Has* " << endl;
		cout << "\n\t The Number Of Room -> " << getRoom_number();
		cout << "\n\t The Number Of Beds -> " << getNumber_of_beds();
		cout << "\n\t The Price Per Bed  -> " << getBed_Price() << " $";
		cout << "\n\t Total Profits Of Room -> " << getNumber_of_beds() * getBed_Price() << endl;
	}
	void Reserve()
	{
		is_reversed = true;
	}
	bool Is_Reserve()
	{
		return is_reversed;
	}
};
class Sweet_Room :public Room
{
private:
	int daysOfReservation;
	double price_per_night;

public:
	Sweet_Room()
	{
		daysOfReservation = 0;
		price_per_night = 0;

	}
	Sweet_Room(double price, int day)
	{
		daysOfReservation = day;
		price_per_night = price;

	}
	void setRoom_number(int _room_number)
	{
		room_number = _room_number;
	}
	int getRoom_number()
	{
		return room_number;
	}
	void setIs_reversed(bool _is_reversed)
	{
		is_reversed = _is_reversed;
	}
	void setDaysOfReservation(int _daysOfReservation)
	{
		daysOfReservation = _daysOfReservation;
	}
	int getDaysOfReservation()
	{
		return daysOfReservation;
	}
	void setPrice_per_night(double _price_per_night)
	{
		price_per_night = _price_per_night;
	}
	double getPrice_per_night()
	{
		return price_per_night;
	}
	void To_String()
	{
		cout << "\t*Available Sweet Room Has* " << endl;
		cout << "\n\t The Number Of Room -> " << getRoom_number();
		cout << "\n\t The Price Per Nigth  -> " << getPrice_per_night() << " $";
		cout << "\n\t Total Profits Of Room -> " << getPrice_per_night() << endl;
	}
	double Total_Profits_Of_Reservation()
	{
		return price_per_night * daysOfReservation;
	}
	void Reserve()
	{
		is_reversed = true;
	}
	bool Is_Reserve()
	{
		return is_reversed;
	}
};
class Conference_Room :public Room
{
private:
	int daysOfReservation;
	int number_of_seats;
	double seatPrice;

public:
	Conference_Room()
	{
		seatPrice = 0;
		number_of_seats = 0;
		daysOfReservation = 0;

	}
	Conference_Room(int number_of_seats, double seatPrice, int daysOfReservation)
	{
		this->daysOfReservation = daysOfReservation;
		this->number_of_seats = number_of_seats;
		this->seatPrice = seatPrice;

	}
	void setRoom_number(int _room_number)
	{
		room_number = _room_number;
	}
	int getRoom_number()
	{
		return room_number;
	}
	void setIs_reversed(bool _is_reversed)
	{
		is_reversed = _is_reversed;
	}
	void setNumber_of_seats(int _number_of_seats)
	{
		number_of_seats = _number_of_seats;
	}
	int getNumber_of_seats() {
		return number_of_seats;
	}
	void setSeatPrice(double _seatPrice)
	{
		seatPrice = _seatPrice;
	}
	double getSeatPrice() {
		return seatPrice;
	}
	void setDaysOfReservation(int _daysOfReservation)
	{
		daysOfReservation = _daysOfReservation;
	}
	int getDaysOfReservation()
	{
		return daysOfReservation;
	}
	void To_String()
	{
		cout << "\t*Available Conference Room Has* " << endl;
		cout << "\n\t The Number Of Room -> " << getRoom_number();
		cout << "\n\t The Number Of Seats -> " << getNumber_of_seats();
		cout << "\n\t The Price Per Seat  -> " << getSeatPrice() << " $";
		cout << "\n\t Total Profits Of Room -> " << getNumber_of_seats() * getSeatPrice() << endl;
	}
	double Total_Profits_Of_Reservation()
	{
		double total = seatPrice * number_of_seats;
		return (daysOfReservation * total);
	}
	void Reserve()
	{
		is_reversed = true;
	}
	bool Is_Reserve()
	{
		return is_reversed;
	}
};

class Floor
{
public:
	Room** standard = new Room * [NumberOfStandardRooms];
	Room** sweet = new Room * [NumberOfSweetdRooms];
	Room** conference = new Room * [NumberOfConferenceRooms];
private:
	int floor_number;
	int number_of_room;
	double total = 0;
public:

	Standard_Room* st = new Standard_Room[NumberOfStandardRooms];
	Sweet_Room* sw = new Sweet_Room[NumberOfSweetdRooms];
	Conference_Room* con = new Conference_Room[NumberOfConferenceRooms];
	Floor()
	{
		floor_number = 0;
		number_of_room = 0;
		total = 0;
		for (size_t i = 0; i < NumberOfStandardRooms; i++)
		{
			standard[i] = &st[i];
		}
		for (size_t i = 0; i < NumberOfSweetdRooms; i++)
		{
			sweet[i] = &sw[i];
		}
		for (size_t i = 0; i < NumberOfConferenceRooms; i++)
		{
			conference[i] = &con[i];
		}
	}
	void setFloor_number(int _floor_number)
	{
		floor_number = _floor_number;
	}
	int getFloor_number()
	{
		return floor_number;
	}
	void setNumber_of_room(int _number_of_room)
	{
		number_of_room = _number_of_room;
	}
	int getNumber_of_room() {
		return number_of_room;
	}

	void Display_Available_Rooms(int number_of_Floor)
	{
		for (size_t i = 0; i < NumberOfStandardRooms; i++)
		{
			if (DetailsOfStandardRooms[i][0] == number_of_Floor)
			{
				//cout << " DetailsOfStandardRooms " << i << endl;
				if (!standard[i]->Is_Reserve())
				{
					standard[i]->To_String();
					cout << endl;
				}
			}
		}
		for (size_t i = 0; i < NumberOfSweetdRooms; i++)
		{
			//cout << " DetailsOfSweetRooms " << i << endl;
			if (DetailsOfSweetRooms[i][0] == number_of_Floor)
			{
				if (!sweet[i]->Is_Reserve())
				{
					sweet[i]->To_String();
					cout << endl;
				}
			}
		}
		for (size_t i = 0; i < NumberOfConferenceRooms; i++)
		{
			//cout << " DetailsOfConferenceRooms " << i << endl;
			if (DetailsOfConferenceRooms[i][0] == number_of_Floor)
			{
				if (!conference[i]->Is_Reserve())
				{
					conference[i]->To_String();
					cout << endl;
				}
			}
		}
	}
	double Profit_Of_Rooms_In_Each_Floor(int number_of_Floor)
	{
		total = 0;

		for (size_t i = 0; i < NumberOfStandardRooms; i++)
		{
			if (DetailsOfStandardRooms[i][0] == number_of_Floor)
			{

				if (standard[i]->Is_Reserve())
				{
					total += standard[i]->Total_Profits_Of_Reservation();
				}
			}
		}
		for (size_t i = 0; i < NumberOfSweetdRooms; i++)
		{

			if (DetailsOfSweetRooms[i][0] == number_of_Floor)
			{
				if (sweet[i]->Is_Reserve())
				{
					total += sweet[i]->Total_Profits_Of_Reservation();

				}
			}
		}
		for (size_t i = 0; i < NumberOfConferenceRooms; i++)
		{
			if (DetailsOfConferenceRooms[i][0] == number_of_Floor)
			{
				if (conference[i]->Is_Reserve())
				{
					total += conference[i]->Total_Profits_Of_Reservation();
				}
			}
		}
		return total;
	}

};
// End Of Classes /

//Prototype Of Functions/
int* Room_Number = new int[NumberOfStandardRooms + NumberOfConferenceRooms + NumberOfSweetdRooms]{ 0 };
int c = 0;
void Intro();
void Check(Floor& actual_floor, int option);
int Menu();
int Ending(Floor& actual_floor);
void Status_hotel(Floor& actual_floor);
int SmallMenu();
void Make_Reservation(Floor& actual_floor);
void Cancel_Reservation(Floor& actual_floor);
void Check_Out(Floor& actual_floor);
void Available_Rooms(Floor& actual_floor);
void Total_Profit(Floor& actual_floor);
/**/

int main()
{

	Manipulation(fileLines);
	Floor actual_floor;
	Intro();
	Check(actual_floor, Menu());


	return 0;
	system("pause");
}
void Intro() {
	cout << "\n\t\t*********";
	cout << "\n\t\tHOTEL RESERVATION SYSTEM";
	cout << "\n\t\t*********";
	cout << "\n\n\t\t MADE BY: RANDA & REHAM\n";
	cin.get();
	system("cls");
}
void Check(Floor& actual_floor, int option)
{
	switch (option)
	{
	case 1:Status_hotel(actual_floor);
		break;
	case 2:Make_Reservation(actual_floor);
		break;
	case 3:Cancel_Reservation(actual_floor);
		break;
	case 4:Check_Out(actual_floor);
		break;
	case 5:Available_Rooms(actual_floor);
		break;
	case 6:Total_Profit(actual_floor);
		break;
	case 7:Ending(actual_floor);
		return;
		break;
	default:
		break;
	}
}
int Menu() {
	int option;
	cout << "\n\n\t **   WELCOME TO OUR HOTEL  **\n";
	cout << "\n\t01.View Status Of Hotel";
	cout << "\n\t02.Make Reservation";
	cout << "\n\t03.Cancel Reservation";
	cout << "\n\t04.Check Out";
	cout << "\n\t05.Available Rooms";
	cout << "\n\t06.Total Profit";
	cout << "\n\t07.End The Program";
	cout << "\n\tPlease Select Your Option (1-7) : ";
	cin >> option;
	system("cls");
	if (option >= 1 && option <= 7)
	{
		return option;
	}
	else
	{
		system("cls");
		cout << "\tWrong number\a" << endl;
		cin.get();
		cin.get();
		system("cls");
		Menu();
	}
	return 0;
}
int Ending(Floor& actual_floor)
{
	system("cls");
	Check(actual_floor, 7);
	return 0;
	system("cls");

}
void Status_hotel(Floor& actual_floor) {
	cout << "                                                      THE STATUS OF THE HOTEL                                                    \n\n";
	cout << "=============================================================================================================================================\n";
	cout << "| Floor Number  |  Room Number  |    Type Of Room    |  Number Of Beds/Seats  |  Bed/Seat/Night Price  |  Room status  |  Total Cost Of Room|\n";
	cout << "=============================================================================================================================================\n";
	int fnum = 1;
	for (size_t i = 0; i < NumberOfFloor; i++)
	{
		for (size_t j = 0; j < NumberOfStandardRooms; j++)
		{
			if (DetailsOfStandardRooms[j][0] == i + 1)
			{
				if (actual_floor.standard[j]->Is_Reserve())
				{
					cout << setw(6) << fnum << setw(20);
					cout << actual_floor.standard[j]->getRoom_number() << setw(23) << "Standard Room" << setw(18) << actual_floor.standard[j]->getNumber_of_beds() << setw(25) << actual_floor.standard[j]->getBed_Price() << setw(22) << "RESERVED" << setw(19) << actual_floor.standard[j]->Total_Profits_Of_Reservation() << " $" << endl;
				}
				else if (!actual_floor.standard[j]->Is_Reserve())
				{
					cout << setw(6) << fnum << setw(20) << DetailsOfStandardRooms[j][1] << setw(23) << "Standard Room" << setw(18) << DetailsOfStandardRooms[j][2] << setw(25) << DetailsOfStandardRooms[j][3] << setw(25) << "NOTRESERVED" << setw(15) << "0" << " $" << endl;
				}
			}
		}
		for (size_t j = 0; j < NumberOfSweetdRooms; j++)
		{
			if (DetailsOfSweetRooms[j][0] == i + 1)
			{
				if (actual_floor.sweet[j]->Is_Reserve())
				{
					cout << setw(6) << fnum << setw(20);
					cout << actual_floor.sweet[j]->getRoom_number() << setw(20) << "Sweet Room" << setw(23) << "#####" << setw(24) << actual_floor.sweet[j]->getPrice_per_night() << setw(21) << "RESERVED" << setw(19) << actual_floor.sweet[j]->Total_Profits_Of_Reservation() << " $" << endl;
				}
				else if (!actual_floor.sweet[j]->Is_Reserve()) {
					cout << setw(6) << fnum << setw(20) << DetailsOfSweetRooms[j][1] << setw(20) << "Sweet Room" << setw(23) << "#####" << setw(24) << DetailsOfSweetRooms[j][2] << setw(24) << "NOTRESERVED" << setw(15) << "0" << " $" << endl;
				}
			}
		}
		for (size_t j = 0; j < NumberOfConferenceRooms; j++)
		{
			if (DetailsOfConferenceRooms[j][0] == i + 1)
			{
				if (actual_floor.conference[j]->Is_Reserve())
				{
					cout << setw(6) << fnum << setw(20);
					cout << actual_floor.conference[j]->getRoom_number() << setw(25) << "Conference Room" << setw(17) << actual_floor.conference[j]->getNumber_of_seats() << setw(23) << actual_floor.conference[j]->getSeatPrice() << setw(23) << "RESERVED" << setw(19) << actual_floor.conference[j]->Total_Profits_Of_Reservation() << " $" << endl;
				}
				else if (!actual_floor.conference[j]->Is_Reserve())
				{
					cout << setw(6) << fnum << setw(20) << DetailsOfConferenceRooms[j][1] << setw(25) << "Conference Room" << setw(17) << DetailsOfConferenceRooms[j][2] << setw(23) << DetailsOfConferenceRooms[j][3] << setw(26) << "NOTRESERVED" << setw(15) << "0" << " $" << endl;
				}
			}
		}
		fnum++;
	}
	cin.get();
	cin.get();
	system("cls");
	Check(actual_floor, Menu());
}
int SmallMenu()
{
	int option;
	cout << "\n\n\tType Of Rooms In Hotel";
	cout << "\n\t01.Standard Room";
	cout << "\n\t02.Sweet Room";
	cout << "\n\t03.Conference Room";
	cout << "\n\tPlease Select Your Option (1-3) : ";
	cin >> option;
	if (option >= 1 && option <= 3)
	{
		return option;
	}
	else
	{
		system("cls");
		cout << "\tWrong number\a" << endl;
		cin.get();
		cin.get();
		system("cls");
		SmallMenu();
	}
	return 0;
}
void Make_Reservation(Floor& actual_floor)
{
	int RN = 0;
	int st = 0;
	int sw = 0;
	int co = 0;
	int day;
	switch (SmallMenu())
	{
	case 1:
		system("cls");
		for (size_t i = 0; i < NumberOfStandardRooms; i++)
		{
			if (actual_floor.standard[i]->Is_Reserve())
			{
				st++;
			}
		}
		if (st == NumberOfStandardRooms)
		{
			cout << "All Standard Rooms Are Reserved " << endl;
			cin.get();
			cin.get();
			system("cls");
			Check(actual_floor, Menu());
			return;
		}
		cout << "\n\t*Available Standard Room*";
		for (size_t i = 0; i < NumberOfFloor; i++)
		{
			cout << "\n\nThe Floor Number " << i + 1 << endl;
			for (size_t j = 0; j < NumberOfStandardRooms; j++)
			{
				if (DetailsOfStandardRooms[j][0] == i + 1)
				{
					if (!actual_floor.standard[j]->Is_Reserve())
					{
						cout << "\n The Number Of Standard Room : ";
						cout << DetailsOfStandardRooms[j][1] << endl;
						actual_floor.standard[j]->setRoom_number(DetailsOfStandardRooms[j][1]);
						cout << " The Number Of Beds In This Room : ";
						cout << DetailsOfStandardRooms[j][2] << endl;
						actual_floor.standard[j]->setNumber_of_beds(DetailsOfStandardRooms[j][2]);
						cout << " The Total Cost Of Reserve The Room : ";
						cout << DetailsOfStandardRooms[j][2] * DetailsOfStandardRooms[j][3] << endl;
						actual_floor.standard[j]->setBed_Price(DetailsOfStandardRooms[j][3]);
					}
				}
			}
		}
		cout << "\n\t Please Enter The Room Number You Want To Reserve : ";
		cin >> RN;
		for (size_t k = 0; k < NumberOfStandardRooms; k++)
		{
			if (!actual_floor.standard[k]->Is_Reserve() && (actual_floor.standard[k]->getRoom_number() == RN))
			{
				for (size_t i = 0; i < NumberOfStandardRooms; i++)
				{
					if (RN == DetailsOfStandardRooms[i][1])
					{
						Room_Number[c] = RN;
						c++;
						cout << "\n\t Please Enter The Number Of Reservation Days : ";
						cin >> day;
						actual_floor.standard[k]->setDaysOfReservation(day);
						actual_floor.standard[k]->setIs_reversed(true);
						actual_floor.standard[k]->Reserve();
						cout << "\n\t You Reserve This Room Correctly !" << endl;

						cin.get();
						cin.get();
						system("cls");
						Check(actual_floor, Menu());
					}
				}
				cout << "\n\t You Entered Wrong Number ! \a" << endl;
				cin.get();
				cin.get();
				system("cls");
				Check(actual_floor, Menu());
				return;
			}

		}
		cout << "\n\t You Entered Wrong Number !\a" << endl;
		cin.get();
		cin.get();
		system("cls");
		Check(actual_floor, Menu());
		return;

		break;
	case 2:
		system("cls");
		for (size_t i = 0; i < NumberOfSweetdRooms; i++)
		{
			if (actual_floor.sweet[i]->Is_Reserve())
			{
				sw++;
			}
		}
		if (sw == NumberOfSweetdRooms)
		{
			cout << "All Sweet Rooms Are Reserved " << endl;
			cin.get();
			cin.get();
			system("cls");
			Check(actual_floor, Menu());
			return;
		}
		cout << "\n\n\t*Available Sweet Room*";
		for (size_t i = 0; i < NumberOfFloor; i++)
		{
			cout << "\n\nThe Floor Number " << i + 1 << endl;
			for (size_t j = 0; j < NumberOfSweetdRooms; j++)
			{
				if (DetailsOfSweetRooms[j][0] == i + 1)
				{
					if (!actual_floor.sweet[j]->Is_Reserve())
					{
						cout << " The Number Of Sweet Room : ";
						cout << DetailsOfSweetRooms[j][1] << endl;
						actual_floor.sweet[j]->setRoom_number(DetailsOfSweetRooms[j][1]);
						cout << " The Total Cost Of Reserve The Room : ";
						cout << DetailsOfSweetRooms[j][2] << endl;
						actual_floor.sweet[j]->setPrice_per_night(DetailsOfSweetRooms[j][2]);
					}
				}
			}
		}
		cout << "\n\t Please Enter The Room Number You Want To Reserve : ";
		cin >> RN;
		for (size_t k = 0; k < NumberOfSweetdRooms; k++)
		{
			if (!actual_floor.sweet[k]->Is_Reserve() && (actual_floor.sweet[k]->getRoom_number() == RN))
			{
				for (size_t i = 0; i < NumberOfSweetdRooms; i++)
				{
					if (RN == DetailsOfSweetRooms[i][1])
					{
						Room_Number[c] = RN;
						c++;
						cout << "\n\t Please Enter The Number Of Reservation Days : ";
						cin >> day;
						actual_floor.sweet[sw]->setDaysOfReservation(day);
						actual_floor.sweet[sw]->setIs_reversed(true);
						actual_floor.sweet[sw]->Reserve();
						cout << "\n\t You Reserve This Room Correctly !" << endl;
						sw++;
						cin.get();
						cin.get();
						system("cls");
						Check(actual_floor, Menu());
					}

				}
				cout << "\n\t You Entered Wrong Number !\a" << endl;
				cin.get();
				cin.get();
				system("cls");
				Check(actual_floor, Menu());
				return;

			}
		}
		cout << "\n\t You Entered Wrong Number !\a" << endl;
		cin.get();
		cin.get();
		system("cls");
		Check(actual_floor, Menu());
		return;

		break;
	case 3:
		system("cls");
		for (size_t i = 0; i < NumberOfConferenceRooms; i++)
		{
			if (actual_floor.conference[i]->Is_Reserve())
			{
				co++;
			}
		}
		if (co == NumberOfConferenceRooms)
		{
			cout << "All Conference Rooms Are Reserved " << endl;
			cin.get();
			cin.get();
			system("cls");
			Check(actual_floor, Menu());
			return;
		}
		cout << "\n\n\t*Available Conference Room*";
		for (size_t i = 0; i < NumberOfFloor; i++)

		{
			cout << "\n\nThe Floor Number " << i + 1 << endl;
			for (size_t j = 0; j < NumberOfConferenceRooms; j++)
			{
				if (DetailsOfConferenceRooms[j][0] == i + 1)
				{
					if (!actual_floor.conference[j]->Is_Reserve())
					{
						cout << " The Number Of Conference Room : ";
						cout << DetailsOfConferenceRooms[j][1] << endl;
						actual_floor.conference[j]->setRoom_number(DetailsOfConferenceRooms[j][1]);
						cout << " The Number Of Seats In This Room : ";
						cout << DetailsOfConferenceRooms[j][2] << endl;
						actual_floor.conference[j]->setNumber_of_seats(DetailsOfConferenceRooms[j][2]);
						cout << " The Total Cost Of Reserve The Room : ";
						cout << DetailsOfConferenceRooms[j][2] * DetailsOfConferenceRooms[j][3] << endl;
						actual_floor.conference[j]->setSeatPrice(DetailsOfConferenceRooms[j][3]);
					}
				}
			}
		}
		cout << "\n\t Please Enter The Room Number You Want To Reserve : ";
		cin >> RN;
		for (size_t k = 0; k < NumberOfConferenceRooms; k++)
		{
			if (!actual_floor.conference[k]->Is_Reserve() && (actual_floor.conference[k]->getRoom_number() == RN))
			{
				for (size_t i = 0; i < NumberOfConferenceRooms; i++)
				{
					if (RN == DetailsOfConferenceRooms[i][1])
					{
						Room_Number[c] = RN;
						c++;
						cout << "\n\t Please Enter The Number Of Reservation Days : ";
						cin >> day;
						actual_floor.conference[co]->setDaysOfReservation(day);
						actual_floor.conference[co]->setIs_reversed(true);
						actual_floor.conference[co]->Reserve();
						cout << "\n\t You Reserve This Room Correctly !" << endl;
						co++;
						cin.get();
						cin.get();
						system("cls");
						Check(actual_floor, Menu());
						return;
					}

				}
				cout << "\n\t You Entered Wrong Number !\a" << endl;
				cin.get();
				cin.get();
				system("cls");
				Check(actual_floor, Menu());
				return;


			}

		}
		cout << "\n\t You Entered Wrong Number !\a" << endl;
		cin.get();
		cin.get();
		system("cls");
		Check(actual_floor, Menu());
		return;
		break;
	default:
		break;
	}
	cin.get();
	cin.get();
	system("cls");
	Check(actual_floor, Menu());

}
void Cancel_Reservation(Floor& actual_floor)
{
	int Rn;
	cout << "Please Enter The Room Number : ";
	cin >> Rn;
	for (size_t i = 0; i < NumberOfStandardRooms + NumberOfConferenceRooms + NumberOfSweetdRooms; i++)
	{
		if (Room_Number[i] == Rn)
		{
			Room_Number[i] = 0;
		}
	}
	for (size_t j = 0; j < NumberOfStandardRooms; j++)
	{
		if (actual_floor.standard[j]->Is_Reserve() && actual_floor.standard[j]->getRoom_number() == Rn)
		{
			actual_floor.standard[j]->setIs_reversed(false);
			cout << "You Successfully Cancel The Reservation !" << endl;
			cin.get();
			cin.get();
			system("cls");
			Check(actual_floor, Menu());
		}
	}
	for (size_t j = 0; j < NumberOfSweetdRooms; j++)
	{
		if (actual_floor.sweet[j]->Is_Reserve() && actual_floor.sweet[j]->getRoom_number() == Rn)
		{
			actual_floor.sweet[j]->setIs_reversed(false);
			cout << "You Successfully Cancel The Reservation !" << endl;
			cin.get();
			cin.get();
			system("cls");
			Check(actual_floor, Menu());
		}
	}
	for (size_t j = 0; j < NumberOfConferenceRooms; j++)
	{
		if (actual_floor.conference[j]->Is_Reserve() && actual_floor.conference[j]->getRoom_number() == Rn)
		{
			actual_floor.conference[j]->setIs_reversed(false);
			cout << "You Successfully Cancel The Reservation !" << endl;
			cin.get();
			cin.get();
			system("cls");
			Check(actual_floor, Menu());
		}
	}
	cout << " You Entered Wrong Number !!" << endl;
	cin.get();
	cin.get();
	system("cls");

	Check(actual_floor, Menu());
}
void Check_Out(Floor& actual_floor) {
	int RN;
	int st = 0;
	int sw = 0;
	int co = 0;
	cout << "\n\tPlease Enter The Room Number : ";
	cin >> RN;
	for (size_t i = 0; i < NumberOfStandardRooms; i++)
	{
		if (RN == DetailsOfStandardRooms[i][1])
		{
			st++;
			break;
		}
	}
	for (size_t i = 0; i < NumberOfSweetdRooms; i++)
	{
		if (RN == DetailsOfSweetRooms[i][1])
		{
			sw++;
			break;
		}
	}
	for (size_t i = 0; i < NumberOfConferenceRooms; i++)
	{
		if (RN == DetailsOfConferenceRooms[i][1])
		{
			co++;
			break;
		}
	}
	if (st == 1 || co == 1 || sw == 1) {
		for (size_t i = 0; i < NumberOfStandardRooms + NumberOfConferenceRooms + NumberOfSweetdRooms; i++)
		{
			if (Room_Number[i] == RN)
			{
				Room_Number[i] = 0;
			}
		}
		for (size_t i = 0; i < NumberOfStandardRooms; i++)
		{
			if (actual_floor.standard[i]->Is_Reserve())
			{
				if (actual_floor.standard[i]->getRoom_number() == RN)
				{
					cout << "\n\n\tThe Number Of Beds In This Room : ";
					cout << actual_floor.standard[i]->getNumber_of_beds();
					cout << "\n\n\tThe Price per bed in Room : ";
					cout << actual_floor.standard[i]->getBed_Price();
					cout << "\n\n\tThe Number Of Reservation Days : ";
					cout << actual_floor.standard[i]->getDaysOfReservation();
					cout << "\n\n\tThe Total Cost Of Reserve The Room : ";
					cout << actual_floor.standard[i]->Total_Profits_Of_Reservation();
					actual_floor.standard[i]->setIs_reversed(false);
					cin.get();
					cin.get();
					system("cls");
					Check(actual_floor, Menu());
				}
			}
		}
		for (size_t i = 0; i < NumberOfSweetdRooms; i++)
		{

			if (actual_floor.sweet[i]->Is_Reserve())
			{
				if (actual_floor.sweet[i]->getRoom_number() == RN)
				{
					cout << "\n\n\tThe Price Night in Room : ";
					cout << actual_floor.sweet[i]->getPrice_per_night();
					cout << "\n\n\tThe Number Of Reservation Days : ";
					cout << actual_floor.sweet[i]->getDaysOfReservation();
					cout << "\n\n\tThe Total Cost Of Reserve The Room : ";
					cout << actual_floor.sweet[i]->Total_Profits_Of_Reservation();
					actual_floor.sweet[i]->setIs_reversed(false);
					cin.get();
					cin.get();
					system("cls");
					Check(actual_floor, Menu());
				}
			}
		}
		for (size_t i = 0; i < NumberOfConferenceRooms; i++)
		{

			if (actual_floor.conference[i]->Is_Reserve())
			{
				if (actual_floor.conference[i]->getRoom_number() == RN)
				{
					cout << "\n\n\tThe Number Of Seats In This Room : ";
					cout << actual_floor.conference[i]->getNumber_of_seats();
					cout << "\n\n\tThe Price per Seat in Room : ";
					cout << actual_floor.conference[i]->getSeatPrice();
					cout << "\n\n\tThe Number Of Reservation Days : ";
					cout << actual_floor.conference[i]->getDaysOfReservation();
					cout << "\n\n\tThe Total Cost Of Reserve The Room : ";
					cout << actual_floor.conference[i]->Total_Profits_Of_Reservation();
					actual_floor.conference[i]->setIs_reversed(false);
					cin.get();
					cin.get();
					system("cls");
					Check(actual_floor, Menu());
				}
			}
		}

		cin.get();
		cin.get();
		system("cls");
		Check(actual_floor, Menu());
	}
	else {
		cout << " You Entered Wrong Number !!" << endl;
		cin.get();
		cin.get();
		system("cls");
		Check(actual_floor, Menu());
	}
}
void Available_Rooms(Floor& actual_floor) {
	int fnum = 1;
	int st = 0;
	int sw = 0;
	int co = 0;
	for (size_t i = 0; i < NumberOfStandardRooms; i++)
	{
		if (actual_floor.standard[i]->Is_Reserve())
		{
			st++;
		}
	}
	for (size_t i = 0; i < NumberOfSweetdRooms; i++)
	{
		if (actual_floor.sweet[i]->Is_Reserve())
		{
			sw++;
		}
	}
	for (size_t i = 0; i < NumberOfConferenceRooms; i++)
	{
		if (actual_floor.conference[i]->Is_Reserve())
		{
			co++;
		}
	}
	if (st == NumberOfStandardRooms && sw == NumberOfSweetdRooms && co == NumberOfConferenceRooms)
	{
		cout << "No Available Rooms In Hotel !" << endl;
		cin.get();
		cin.get();
		system("cls");
		Check(actual_floor, Menu());
		return;
	}
	for (size_t i = 0; i < NumberOfFloor; i++)
	{
		cout << "\nThe Floor Number " << fnum << endl;
		for (size_t j = 0; j < NumberOfStandardRooms; j++)
		{
			if (DetailsOfStandardRooms[j][0] == i + 1)
			{
				if (!actual_floor.standard[j]->Is_Reserve())
				{
					actual_floor.standard[j]->setRoom_number(DetailsOfStandardRooms[j][1]);
					actual_floor.standard[j]->setNumber_of_beds(DetailsOfStandardRooms[j][2]);
					actual_floor.standard[j]->setBed_Price(DetailsOfStandardRooms[j][3]);
				}
			}
		}
		for (size_t j = 0; j < NumberOfSweetdRooms; j++)
		{
			if (DetailsOfSweetRooms[j][0] == i + 1)
			{
				if (!actual_floor.sweet[j]->Is_Reserve())
				{
					actual_floor.sweet[j]->setRoom_number(DetailsOfSweetRooms[j][1]);
					actual_floor.sweet[j]->setPrice_per_night(DetailsOfSweetRooms[j][2]);
				}
			}
		}
		for (size_t j = 0; j < NumberOfConferenceRooms; j++)
		{
			if (DetailsOfConferenceRooms[j][0] == i + 1)
			{
				if (!actual_floor.conference[j]->Is_Reserve())
				{
					actual_floor.conference[j]->setRoom_number(DetailsOfConferenceRooms[j][1]);
					actual_floor.conference[j]->setNumber_of_seats(DetailsOfConferenceRooms[j][2]);
					actual_floor.conference[j]->setSeatPrice(DetailsOfConferenceRooms[j][3]);
				}
			}
		}
		actual_floor.Display_Available_Rooms(fnum);
		fnum++;

	}
	cin.get();
	cin.get();
	system("cls");
	Check(actual_floor, Menu());
}
void Total_Profit(Floor& actual_floor) {
	double d = 0;
	cout << "=====================================================\n";
	cout << "| Floor Number    Room Number    Total Cost Of Room | \n";
	cout << "=====================================================\n";
	int fnum = 1;
	for (size_t i = 0; i < NumberOfFloor; i++)
	{
		for (size_t j = 0; j < NumberOfStandardRooms; j++)
		{
			if (DetailsOfStandardRooms[j][0] == i + 1)
			{

				if (actual_floor.standard[j]->Is_Reserve())
				{
					cout << setw(6) << fnum << setw(20);
					cout << actual_floor.standard[j]->getRoom_number() << setw(20) << actual_floor.standard[j]->Total_Profits_Of_Reservation() << " $" << endl;
				}
			}
		}
		for (size_t j = 0; j < NumberOfSweetdRooms; j++)
		{
			if (DetailsOfSweetRooms[j][0] == i + 1)
			{
				if (actual_floor.sweet[j]->Is_Reserve())
				{
					cout << setw(6) << fnum << setw(20);
					cout << actual_floor.sweet[j]->getRoom_number() << setw(20) << actual_floor.sweet[j]->Total_Profits_Of_Reservation() << " $" << endl;
				}
			}
		}
		for (size_t j = 0; j < NumberOfConferenceRooms; j++)
		{
			if (DetailsOfConferenceRooms[j][0] == i + 1)
			{
				if (actual_floor.conference[j]->Is_Reserve())
				{
					cout << setw(6) << fnum << setw(20);
					cout << actual_floor.conference[j]->getRoom_number() << setw(20) << actual_floor.conference[j]->Total_Profits_Of_Reservation() << " $" << endl;
				}
			}
		}
		fnum++;
	}
	cout << "=====================================================\n";
	cout << "|               Total Hotel Profit                  |\n";
	cout << "=====================================================\n";
	for (size_t j = 0; j < NumberOfFloor; j++)
	{
		d += actual_floor.Profit_Of_Rooms_In_Each_Floor(j + 1);
	}
	cout << setw(27) << d << " $" << endl;
	cin.get();
	cin.get();
	system("cls");
	Check(actual_floor, Menu());
}
vector<string> ReadFromTextFile(string FilePath)
{
	vector<string> fileLines;
	string line;
	ifstream MyFile(FilePath);
	if (MyFile.is_open())
	{
		while (getline(MyFile, line))
		{
			fileLines.push_back(line);
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}

	return fileLines;
}
void Manipulation(vector<string>& fileLines)
{
	//الفانكشن دي بتقرأ اول سطر وبتعرف منه عدد الادوار الموجوده في الاوتيل
	for (size_t i = 0; i < fileLines[0].size(); i++)
	{

		if (fileLines[0][i] == '1' || fileLines[0][i] == '2' || fileLines[0][i] == '3' || fileLines[0][i] == '4' || fileLines[0][i] == '5' || fileLines[0][i] == '6' || fileLines[0][i] == '7' || fileLines[0][i] == '8' || fileLines[0][i] == '9')
		{
			NumberOfFloor = (fileLines[0][i] - '0');
		}
	}

	//cout << NumberOfFloor + 5 << endl;
	//بتمثل السطور اللي بعرف فيها عدد الاوض زي السطر الثاني والسطر السادس والسطر التاسع
	int number_Room_Line = 1;

	for (int i = 0; i < NumberOfFloor; i++)
	{
		for (int j = 0; j < fileLines[number_Room_Line].size() + 1; j++)
		{

			if (fileLines[number_Room_Line][j] == ' ')
			{

				NumberOfRoomsInEachFloor[i] = fileLines[number_Room_Line][j + 1] - '0';
				/*cout << "NumberOfRoomsInEachFloor :  "<< NumberOfRoomsInEachFloor[i] << endl;
				cout << fileLines[number_Room_Line] << endl;*/
				number_Room_Line += NumberOfRoomsInEachFloor[i] + 1;

				//cout << number_Room_Line << endl;
				break;
			}
		}
	}
	for (size_t i = 0; i < fileLines.size(); i++)
	{
		if (fileLines[i][0] == 'S' && fileLines[i][1] == 't' && fileLines[i][2] == 'a' && fileLines[i][3] == 'n' && fileLines[i][4] == 'd' && fileLines[i][5] == 'a' && fileLines[i][6] == 'r' && fileLines[i][7] == 'd')
		{
			NumberOfStandardRooms++;
		}
		else if (fileLines[i][0] == 'S' && fileLines[i][1] == 'w' && fileLines[i][2] == 'e' && fileLines[i][3] == 'e' && fileLines[i][4] == 't')
		{
			NumberOfSweetdRooms++;
		}
		else if (fileLines[i][0] == 'C' && fileLines[i][1] == 'o' && fileLines[i][2] == 'n' && fileLines[i][3] == 'f' && fileLines[i][4] == 'e' && fileLines[i][5] == 'r' && fileLines[i][6] == 'e' && fileLines[i][7] == 'n' && fileLines[i][8] == 'c' && fileLines[i][9] == 'e')
		{
			NumberOfConferenceRooms++;
		}
	}
	//cout << NumberOfStandardRooms << "       " << NumberOfSweetdRooms << "          " << NumberOfConferenceRooms << endl;
	// الفكرة اللي بعملها هنا اني بحاول اعمل اراي ثنائي الابعاد بمقاسات متغيرة مع تثبيت عدد الاعمده لاني عرافاه لكل نوع عشان اخزن رقم الاوضه وسعرها وعدد سرايرها او كراسيها
	for (int i = 0; i < NumberOfStandardRooms; i++)
	{
		DetailsOfStandardRooms[i] = new int[4];
	}
	for (int i = 0; i < NumberOfConferenceRooms; i++)
	{
		DetailsOfConferenceRooms[i] = new int[4];
	}
	for (int i = 0; i < NumberOfSweetdRooms; i++)
	{
		DetailsOfSweetRooms[i] = new int[3];
	}
	// من اللوب دي هبدأ اقرا بيانات كل سطر من سطور الاوض
	int st = 0, sw = 0, co = 0;
	int first, end;
	for (int i = 0; i < fileLines.size(); i++)
	{
		if (fileLines[i][0] == 'S' && fileLines[i][1] == 't' && fileLines[i][2] == 'a' && fileLines[i][3] == 'n' && fileLines[i][4] == 'd' && fileLines[i][5] == 'a' && fileLines[i][6] == 'r' && fileLines[i][7] == 'd')
		{
			DetailsOfStandardRooms[st][1] = stoi(fileLines[i].substr(fileLines[i].find_first_of(" "), fileLines[i].find_first_of(",", fileLines[i].find_first_of(" "))));
			DetailsOfStandardRooms[st][2] = stoi(fileLines[i].substr(fileLines[i].find_first_of(",", fileLines[i].find_first_of(" ")) + 1, fileLines[i].find_last_of(",")));
			DetailsOfStandardRooms[st][3] = stoi(fileLines[i].substr(fileLines[i].find_last_of(" "), fileLines[i].find(".")));
			st++;
		}
		else if (fileLines[i][0] == 'S' && fileLines[i][1] == 'w' && fileLines[i][2] == 'e' && fileLines[i][3] == 'e' && fileLines[i][4] == 't')
		{
			DetailsOfSweetRooms[sw][1] = stoi(fileLines[i].substr(fileLines[i].find_first_of(" "), fileLines[i].find_last_of(",")));
			DetailsOfSweetRooms[sw][2] = stoi(fileLines[i].substr(fileLines[i].find_last_of(" "), fileLines[i].find_last_of("  ")));
			sw++;
		}
		else if (fileLines[i][0] == 'C' && fileLines[i][1] == 'o' && fileLines[i][2] == 'n' && fileLines[i][3] == 'f' && fileLines[i][4] == 'e' && fileLines[i][5] == 'r' && fileLines[i][6] == 'e' && fileLines[i][7] == 'n' && fileLines[i][8] == 'c' && fileLines[i][9] == 'e')
		{
			DetailsOfConferenceRooms[co][1] = stoi(fileLines[i].substr(fileLines[i].find_first_of(" "), fileLines[i].find_first_of(",", fileLines[i].find_first_of(" "))));
			DetailsOfConferenceRooms[co][2] = stoi(fileLines[i].substr(fileLines[i].find_first_of(",", fileLines[i].find_first_of(" ")) + 1, fileLines[i].find_last_of(",")));
			DetailsOfConferenceRooms[co][3] = stoi(fileLines[i].substr(fileLines[i].find_last_of(" "), fileLines[i].find(".")));
		}

	}
	int* stand = new int[NumberOfFloor] {0};
	int* swe = new int[NumberOfFloor] {0};
	int* conf = new int[NumberOfFloor] {0};
	int k = 2;
	for (int j = 0; j < NumberOfFloor; j++)
	{
		for (int i = 0; i < NumberOfRoomsInEachFloor[j]; i++)
		{
			if (fileLines[k][0] == 'S' && fileLines[k][1] == 't' && fileLines[k][2] == 'a' && fileLines[k][3] == 'n' && fileLines[k][4] == 'd' && fileLines[k][5] == 'a' && fileLines[k][6] == 'r' && fileLines[k][7] == 'd')
			{
				stand[j] ++;
			}
			else if (fileLines[k][0] == 'S' && fileLines[k][1] == 'w' && fileLines[k][2] == 'e' && fileLines[k][3] == 'e' && fileLines[k][4] == 't')
			{
				swe[j] ++;
			}
			else if (fileLines[k][0] == 'C' && fileLines[k][1] == 'o' && fileLines[k][2] == 'n' && fileLines[k][3] == 'f' && fileLines[k][4] == 'e' && fileLines[k][5] == 'r' && fileLines[k][6] == 'e' && fileLines[k][7] == 'n' && fileLines[k][8] == 'c' && fileLines[k][9] == 'e')
			{
				conf[j]++;
			}
			k++;
		}
		k += 1;
	}
	/**/
	int x = 0;
	for (size_t i = 0; i < NumberOfFloor; i++)
	{
		for (size_t j = 0; j < stand[i]; j++)
		{
			DetailsOfStandardRooms[x++][0] = i + 1;
		}
	}
	x = 0;
	for (size_t i = 0; i < NumberOfFloor; i++)
	{
		for (size_t j = 0; j < swe[i]; j++)
		{
			DetailsOfSweetRooms[x++][0] = i + 1;
		}
	}
	x = 0;
	for (size_t i = 0; i < NumberOfFloor; i++)
	{
		for (size_t j = 0; j < conf[i]; j++)
		{
			DetailsOfConferenceRooms[x][0] = i + 1;
		}
	}
	/**/
	// لطباعة محتويات الفانكشن 
	/*for (size_t i = 0; i < 4; i++)
	{
		cout << "Standard Room " << i + 1 << endl;
		for (size_t j = 0; j < 4; j++)
		{
			cout << DetailsOfStandardRooms[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl; cout << endl;
	for (size_t i = 0; i < 2; i++)
	{
		cout << "Sweet Room " << i + 1 << endl;
		for (size_t j = 0; j < 3; j++)
		{
			cout << DetailsOfSweetRooms[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl; cout << endl;
	for (size_t i = 0; i < 1; i++)
	{
		cout << "conference Room " << i + 1 << endl;
		for (size_t j = 0; j < 4; j++)
		{
			cout << DetailsOfConferenceRooms[i][j] << "   ";
		}
		cout << endl;
	}*/
}

