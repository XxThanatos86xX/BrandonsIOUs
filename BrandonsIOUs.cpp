#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

int length = 15;
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

    length -= 1;

    ofstream file;
    file.open ("saveFile.txt");
    file << length << "\n";

    for ( int i = 0; i < length; i++ ) {
        file << iouList[i].title << "\n"
             << iouList[i].redeemed << "\n";
    }
    file.close();
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
        getline (file, line);
        length = stoi(line);        // get length

        for ( int i = 0; i < length; i++ ) {
            getline (file, line);
            availableIOUs[i].title = line;
            // cout << line << '\n';

            getline (file, line);
            // cout << line << '\n';
            availableIOUs[i].redeemed = stoi(line);
            count++;
        } 
        file.close();
    } 
    else {
        cout << "Unable to open file";
    }

    length = count;

    cout << "\n\n\nWelcome to Brandon's IOU Coupons! This program is meant to help you keep track of which coupons have been redeemed!" << endl;

    while(1) {
        cout << "\n\n\nEnter a number and press enter:"
             << "\n\t1: Available IOUs\n\t2: I would like to redeem a coupon."
             << "\n\t3: Redeemed IOUs\n\t9: Quit" << endl;
        int choice = -1;
        cin >> choice;

        if (choice != 1 || choice != 2 || choice != 9) {
            cout << "\n\n\nI didn't recognize that command. Please try again.\n";
            break;
        }
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
        
            case 9:
                cout << "\n\n\nQuitting program..." << endl;
                break;

            default:
                cout << "\n\n\n\tI didn't recognize that command. Please try again.\n";
                break;
        }
        if (choice == 9) {
            break;
        }
    }

    cout << "Updating IOU list:" << endl;

    system("git add .");
    system("git commit -m \"updated IOU list\"");
    system("git push");

}
