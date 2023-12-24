#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

int length = 10;
struct IOU {
    string title;
    int redeemed;


    IOU() {}
    IOU(string name) {
        title = name;
    }
};

void PrintIOUs(IOU iouList[]) {
    for( int i = 0; i < length; i++ ) {                                
        cout << i + 1;                                             
        cout << ": " + iouList[i].title << endl;
    }
}

void DeleteIOU(int index, IOU iouList[]) {
    int iouIndex = index - 1;
    string temp = iouList[iouIndex].title;
    iouList[iouIndex].title = iouList[length - 1].title;
    iouList[length - 1].title = temp;
    iouList[length - 1].redeemed = 1;
}



int main() {
    cout << "Downloading any recent changes made to the IOU list:" << endl;
    system("git pull");

    IOU iou0;
    IOU iou1;
    IOU iou2;
    IOU iou3;
    IOU iou4;
    IOU iou5;
    IOU iou6;
    IOU iou7;
    IOU iou8;
    IOU iou9;

    IOU availableIOUs[10] = { iou0, iou1, iou2, iou3, iou4, iou5, iou6, iou7, iou8, iou9 };


    string line;
    ifstream file ("saveFile.txt");
    int count = 0;
    if (file.is_open()) {
        for ( int i = 0; i < 10; i++ ) {
            getline (file, line);
            cin >> availableIOUs[i].title 
                >> availableIOUs[i].title 
                >> availableIOUs[i].title 
                >> availableIOUs[i].title;
            getline (file, line);
            cin >> availableIOUs[i].redeemed;
            // cout << line << '\n';
            count++;
        } 
        file.close();
    } else {
        cout << "Unable to open file";
    }

    length = count;

    cout << "\n\n\nWelcome to Brandon's IOU Coupons! This program is meant to help you keep track of which coupons have been redeemed!" << endl;


    // IOU availableIOUs[10] = { drink1, drink2, drink3, mongo, car1, car2, car3,
    //                             doubleDate, hangout, online };

    // IOU availableIOUs[10] = {};

    // while (1) {
    //     for (int i = 0; i < 10; i++) {
    //         if (availableIOUs[i].redeemed == 1) {
    //             numRedeemed++;
    //         }
    //     }
    //     length = length - numRedeemed;

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
                cout << "\n\nEnter the IOU number you would like to redeem:";
                int iouNum;
                cin >> iouNum;
                if (iouNum > 0 && iouNum <= length) {
                    DeleteIOU(iouNum, availableIOUs);
                } else {
                    cout << "Not a valid option. Please start over." << endl;
                }
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

    cout << "Updating IOU list:" << endl;

    system("git add .");
    system("git commit -m \"updated IOU list\"");
    system("git push");

}
