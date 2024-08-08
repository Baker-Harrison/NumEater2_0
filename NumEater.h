//
// Created by thehe on 8/8/2024.
//

#ifndef NUMEATER2_0_NUMEATER_H
#define NUMEATER2_0_NUMEATER_H

#include <iostream>
#include <type_traits>
#include <unistd.h>


using namespace std;


const long long int REALLY_LARGE_NUMBER = 2147483647;

template<class T>
class NumEater {
private:
    string name;



public:


    void cortisolOverload() {
        cout << "STRESS! STRESS! STRESS!" << endl;
    }

    void endorphinSurge() {
        cout << "bliss..." << endl;
        sleep(1);
    }

    static T FeedMe() {
        T num;
        bool isFailed = false;

        cout << "ME WANTS FOOD NOW : ";

        cin >> num;

        if (cin.fail()) {
            isFailed = true;
            std::cin.clear();
            std::cin.ignore(REALLY_LARGE_NUMBER, '\n'); // Ignore the invalid input
        }



        try {
            if (!isFailed) {
                return num;
            } else {
                string exceptionString = "Bad food! me want better food!";
                throw exceptionString;
            }
        }
        catch (string exceptionString) {
            cout << "error: " << exceptionString << endl;

            return FeedMe();
        }

    }

    T diejest(T num = FeedMe()) {

        if (num < 0) {
            cortisolOverload();
            return num;
        }


        if (num >= 2) {
            endorphinSurge();


            return diejest(num - 2);


        } else {
            cout << "ME FULL!" << endl;
            return num;
        }
    }
};


#endif //NUMEATER2_0_NUMEATER_H
