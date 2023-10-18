#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


///// TAKES TWO INTS positive up to 32 bits, CONVERTS TO BINARY, ADDS IN BINARY, CONVERTS BACK TO INT AND PRINTS poop

// Old version - olny works for some numbers
vector<int> OLDAddBinary(vector<int> binaryVector1, vector<int> binaryVector2) {
    vector<int> binarySumVector;
    int carry = 0;


    for (int i = 0; i < binaryVector1.size(); i++) {
        if (binaryVector1.at(i) + binaryVector2.at(i) == 2) {
            if (carry == 0) {
                binarySumVector.push_back(0);
                carry = 1;
            }
            else if (carry == 1) {
                binarySumVector.push_back(1);
            }
        }
        else if (binaryVector1.at(i) + binaryVector2.at(i) == 1) {
            if (carry == 1) {
                binarySumVector.push_back(0);
                carry = 0;
            }
            else if (carry == 0) {
                binarySumVector.push_back(1);
            }
        }
        else if (binaryVector1.at(i) + binaryVector2.at(i) == 0) {
            if (carry == 1) {
                binarySumVector.push_back(1);
                carry = 0;
            }
            else if (carry == 0) {
                binarySumVector.push_back(0);
            }
        }
    }
    if (carry == 1) {
        binarySumVector.push_back(1);
        carry = 0;
    }


    return binarySumVector;
}

// new version - seems to work 100%
vector<int> AddBinary(vector<int> vect1, vector<int> vect2) {
    vector<int> binarySumVector;
    int carry = 0;
    

    for (int i = 0; i < vect1.size(); i++) {
        if ((vect1.at(i) + vect2.at(i) + carry) == 3) {
            binarySumVector.push_back(1);
        }
        else if ((vect1.at(i) + vect2.at(i) + carry) == 2) {
            binarySumVector.push_back(0);
            carry = 1;
        }
        else if ((vect1.at(i) + vect2.at(i) + carry) == 1) {
            binarySumVector.push_back(1);
            carry = 0;
        }
        else if ((vect1.at(i) + vect2.at(i) + carry) == 0) {
            binarySumVector.push_back(0);
        }
    }
    if (carry == 1) {
        binarySumVector.push_back(1);
    }


    return binarySumVector;
}

int main() {
    int inputNum1;
    int inputNum2;
    int sum = 0;
    vector<int> binaryVector1;
    vector<int> binaryVector2;
    vector<int> binarySumVector;
    

    cin >> inputNum1 >> inputNum2;
    

// convert to binary
    if (inputNum1 == 0) {
        binaryVector1.push_back(0);
    }
    if (inputNum2 == 0) {
        binaryVector2.push_back(0);
    }
    while (inputNum1 >= 1) {
        binaryVector1.push_back(inputNum1 % 2);
        inputNum1 = inputNum1 / 2;
    }
    while (inputNum2 >= 1) {
        binaryVector2.push_back(inputNum2 % 2);
        inputNum2 = inputNum2 / 2;
    }
    

//make vector length equal. adds to back because order is reversed  
    int binaryVector1Size = binaryVector1.size();
    int binaryVector2Size = binaryVector2.size();
    if (binaryVector1Size > binaryVector2Size) {
        for (int i = 0; i < (binaryVector1Size - binaryVector2Size); i++) {
            binaryVector2.push_back(0);
        }
    }
    else if (binaryVector2Size > binaryVector1Size) {
        for (int i = 0; i < (binaryVector2Size - binaryVector1Size); i++) {
            binaryVector1.push_back(0);
        }
    }


// binary addition
binarySumVector = AddBinary(binaryVector1, binaryVector2);


// back to int and print
    for (int i = 0; i < binarySumVector.size(); i++) {
        if (binarySumVector.at(i) == 1) {
            sum += pow(2, i);
        }
    }


    cout << sum << endl;


    return 0;
}
