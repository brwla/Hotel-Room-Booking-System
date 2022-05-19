#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
static int k = 0;

struct Hotel {
    int day1,month1,year1, day2,month2=0,year2=0, people, roomtype, roomno;
    int days, daytotal, daytoday, total;
    string name, address, cNum;
} guest[30];

void menu() {
    system("cls");
    cout << "=========================================" << '\n';
    cout << "========= WELCOME TO OUR HOTEL! =========" << '\n';
    cout << "=========================================" << '\n' << '\n';
    cout << "1. Admin" << '\n';
    cout << "2. Hotel Room Prices" << '\n';
    cout << "3. Book a room" << '\n';
    cout << "4. Search for receipt of booked room" << '\n';
    cout << "5. Exit" << '\n' << '\n';
    cout << "-----Press the number of the option-----" << '\n';
    cout << "--> ";
}

void adminMenu() {
    system("cls");
    cout << "=========================================" << '\n';
    cout << "=============== ADMIN PAGE ==============" << '\n';
    cout << "=========================================" << '\n' << '\n';
    cout << "1. Check all booked rooms" << '\n';
    cout << "2. Customer records" << '\n';
    cout << "3. Go back to main menu" << '\n';
}

void list() {
    system("cls");
    cout << "These are the type of rooms." << '\n' << '\n';
    cout << "------Hotel rooms------" << '\n';
    cout << "Regular - 1500 pesos per day" << '\n';
    cout << "Deluxe - 2400 pesos per day" << '\n' << '\n';
}

int main() {
    int room[6][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{26,27,28,29,30}};
    int rsvroom [6][5];
    int choice, choices, earned=0;
    start:
    menu();
    cin >> choice;

    switch (choice) {
        case 1: {
            passagain:
            system("cls");
            string password;
            int passchoice;
            cout << "Enter Admin Password: ";
            cin >> password;
            if (password == "admin") {
                admenu:
                adminMenu();
                choiceagain:cout << "Enter the number of the option:" << '\n';
                cout << "--> ";
                cin >> choices;
                switch (choices) {
                    case 1: {
                        system("cls");
                        int tablechoice;
                        cout << "---Reserved rooms---\n\n";
                        cout << "0 means the Room is Taken\n\n";
                        for (int i=0; i<6; i++) {
                            for (int j=0; j<5; j++) {
                                cout << room[i][j] << '\t';
                            }
                            cout << '\n';
                        }
                        cout << "\nPress 1 to go back to admin menu. 2 for main menu\n-->";
                        cin >> tablechoice;
                        if (tablechoice == 1) {
                            goto admenu;
                        } else {
                            goto start;
                        }
                        break;
                    }

                    case 2: {
                        system("cls");
                        int detchoice;
                        for (int l=0; l<30; l++) {
                            if (guest[l].day1 != 0) {
                                cout << "\n\n=============Customer Details=============\n\n";
                                cout << "Name: " << guest[l].name << '\n';
                                cout << "Address: " << guest[l].address << '\n';
                                cout << "Contact Number: " << guest[l].cNum << '\n';
                                cout << "Number of tenants: " << guest[l].people << '\n' << '\n';
                                cout << "----------------Room Details---------------\n\n";
                                cout << "Room No: " << guest[l].roomno << '\n';
                                cout << "Check In Date: " << guest[l].month1 << "/" << guest[l].day1 << "/" << guest[l].year1 << '\n';
                                cout << "Check Out Date: " << guest[l].month2 << "/" << guest[l].day2 << "/" << guest[l].year2 << '\n';
                                cout << "Estimated Days: " << guest[l].days << '\n';
                                if (guest[l].roomtype == 1) {
                                    cout << "Room Type: " << "Regular\n";
                                    cout << "Total Amount: PHP " << guest[l].total << "\n";
                                } else {
                                    cout << "Room Type: " << "Deluxe\n\n";
                                    cout << "Total Amount: PHP " << guest[l].total << "\n";
                                }
                                //calculation for total amount of earnings
                                earned += guest[l].total;
                            }
                        }
                        cout << "\nTotal Earning for today: PHP " << earned;
                        cout << "\n\nEnter '1' to go back to the admin menu. '2' for main menu\n--> ";
                        cin >> detchoice;
                        if (detchoice == 1) {
                            goto admenu;
                        } else {
                            goto start;
                        }
                    }

                    case 3: {
                        goto start;
                    }

                    default:
                        cout << "Invalid/Incorrect number" << '\n';
                        goto choiceagain;
                }
            } else if (password != "admin") {
                cout << "Enter '1' to re-enter password. '2' to go back to main" << '\n';
                cout << "--> ";
                cin >> passchoice;
                if (passchoice == 1) {
                    goto passagain;
                } else {
                    goto start;
                }
            }
        }

        case 2: {
            list();
            cout << "\n\nPress enter to continue...";
            _getch();
            goto start;
            break;
        }

        case 3: {
            system("cls");
            top:
            cout<<"Room Number: ";
            while (!(cin >> guest[k].roomno) or guest[k].roomno <= 0 || guest[k].roomno >30) {
                cout << "There are only 30 rooms available in this hotel.\nTry again.\n";
                cout << "Enter desired room number: ";
                cin.clear();
                cin.ignore();
            }
            for (int i=0; i<6; i++) {
                for (int j=0; j<5; j++) {
                    if (guest[k].roomno == rsvroom[i][j]) {
                        cout << "Room is taken. Please select again.\n";
                        goto top;
                    }
                }
            }
            for (int i=0; i<6; i++) {
                for (int j=0; j<5; j++) {
                    if (guest[k].roomno == room[i][j]) {
                        rsvroom[i][j] = room[i][j];
                        room[i][j] = 0;
                        cout << "Selected room is successfully reserved\n";
                    }
                }
            }
            cout << "Enter check in date(MM  DD  YYYY): ";
            cin >> guest[k].month1 >> guest[k].day1 >> guest[k].year1;
            cout << "Enter how many days you want to stay: ";
            cin >> guest[k].days;
            //calculation for date
            int monthday;
            if (guest[k].month1 == 1 || guest[k].month1 == 3 || guest[k].month1 == 5 || guest[k].month1 == 7 || guest[k].month1 == 8 || guest[k].month1 == 10 || guest[k].month1 == 12) {
                monthday = 31;
            } else if (guest[k].month1 == 4 || guest[k].month1 == 6 || guest[k].month1 == 9 || guest[k].month1 == 11) {
                monthday = 30;
            } else if (guest[k].month1 == 2) {
                monthday = 28;
            }
            guest[k].daytoday = guest[k].days - 1;
            guest[k].daytotal = guest[k].daytoday + guest[k].day1;
            guest[k].day2 = guest[k].daytotal % monthday;
            if (guest[k].day2 == 0) {
                guest[k].day2 += monthday;
            }
            if (guest[k].daytotal > monthday) {
                guest[k].month2 = guest[k].month1 + 1;
            } else if (guest[k].daytotal <= monthday){
                guest[k].month2 += guest[k].month1;
            }
            if (guest[k].daytotal > 365) {
                guest[k].year2 = guest[k].year1 + 1;
            } else if (guest[k].daytotal <= 365) {
                guest[k].year2 += guest[k].year1;
            }
            cin.ignore();
            cout << "Name of client: ";
            getline(cin, guest[k].name);
            cout << "Address: ";
            getline(cin, guest[k].address);
            cout << "Contact Number: ";
            cin >> guest[k].cNum;
            cout << "Number of tenants: ";
            cin >> guest[k].people;
            cout << "Type of room.\n(Press 1 for regular and 2 for deluxe): ";
            cin >> guest[k].roomtype;
            //calculation for amount
            if (guest[k].roomtype == 1) {
                guest[k].total = guest[k].days*1500;
            } else {
                guest[k].total = guest[k].days*2400;
            }
            k++;
            cout << "\n\nPress enter to continue...";
            _getch();
            goto start;
            break;
        }

        case 4: {
            system("cls");
            int room_no;
            cout << "Enter room no: ";
            cin >> room_no;
            for (int v=0; v<=30; v++){
                if (guest[v].roomno==room_no){
                    cout << "\n\n=============Room Customer Details=============\n\n";
                    cout << "Name: " << guest[v].name << '\n';
                    cout << "Address: " << guest[v].address << '\n';
                    cout << "Contact Number: " << guest[v].cNum << '\n';
                    cout << "Number of tenants: " << guest[v].people << '\n' << '\n';
                    cout << "----------------Room Details---------------\n\n";
                    cout << "Room No: " << guest[v].roomno << '\n';
                    cout << "Check In Date: " << guest[v].month1 << "/" << guest[v].day1 << "/" << guest[v].year1 << '\n';
                    cout << "Check Out Date: " << guest[v].month2 << "/" << guest[v].day2 << "/" << guest[v].year2 << '\n';
                    cout << "Estimated Days: " << guest[v].days << '\n';
                    if (guest[v].roomtype == 1) {
                        cout << "Room Type: " << "Regular\n";
                        cout << "Total Amount: PHP " << guest[v].total << "\n";
                    } else {
                        cout << "Room Type: " << "Deluxe\n\n";
                        cout << "Total Amount: PHP " << guest[v].total << "\n";
                    }
                    break;
                } else if (v==room_no && guest[v].roomno!=room_no) {
                    cout << "Room no: " << room_no << " has no entry.\n";
                    break;
                }
            }
            if (room_no <=0 || room_no > 30) {
                cout << "This Hotel has only 30 rooms.\n";
            }
            cout << "\n\nPress enter to continue...";
            _getch();
            goto start;
            break;
        }

        case 5:{
            return 0;
        }

        default:{
            cout << "Invalid/Incorrect number!" << '\n' << '\n';
            cout << "\n\nPress enter to continue...";
            _getch();
        }

    }
    goto start;
}