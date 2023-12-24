#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int length = 10;
struct IOU {
    string title;
    int redeemed = 0;

    IOU(string name) {
        title = name;
    }
};

void PrintIOUs(IOU iouList[]) {
     for( int i = 0; i < 10; i++ ) {                                
        cout << i + 1;                                             
        cout << ": " + iouList[i].title << endl;
     }
}



int main() {
    IOU drink1("One Drink");
    IOU drink2("One Drink");
    IOU drink3("One Drink");
    IOU mongo("One Mongo Meal");
    IOU car1("One Car Cleanin");
    IOU car2("One Car Cleanin");
    IOU car3("One Car Cleanin");
    IOU doubleDate("One Double Date");
    IOU hangout("One Hangout Session");
    IOU online("One Online Hangout Session");


    cout << "Welcome to Brandon's IOU Coupons! This program is meant to help you keep track of which coupons have been redeemed!" << endl;


    IOU availableIOUs[10] = { drink1, drink2, drink3, mongo, car1, car2, car3,
                                doubleDate, hangout, online };

    while (1) {
        cout << "\n\n\nEnter a number and press enter:"
             << "\n\t1: Available IOUs\n\t2: I would like to redeem a coupon."
             << "\n\t3: Redeemed IOUs\n\t9: Quit" << endl;
        int choice = -1;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n\n\n\tAvailable IOUs:\n";
                PrintIOUs(availableIOUs);
                break;

            case 2:
                cout << "\n\n\n\tAvailable coupons to redeem:\n";
                PrintIOUs(availableIOUs);

                break;
        
            case 3:
                cout << "\n\n\n\tRedeemed IOUs:\n";
                break;

            case 9:
                cout << "\n\n\nQuitting program..." << endl;
                break;

            default:
                cout << "\n\n\n\tI didn't recognize that command. Please try again.\n";
                break;
        }

       if (choice == 9) {
           cout << "Successfully Exited Program!" << endl;
           break;}

    }

    system("git add .");
    system("git commit -m \"updated IOU list\"");
    system("git push");
    system("git pull");

}
