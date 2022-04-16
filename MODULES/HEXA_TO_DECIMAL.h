#include <iostream>
#include <sstream>  

using namespace std;

void hexa_to_decimal(string input, string& output) {
    int state = 0, i = 1;
    output = "0";
    while(i < input.length() && i >= 0){
        if(state == 0){
            if(input[i] == '#'){
                state = 1;
                i--;
            } else {
                i++;
            }
        } else if(state == 1) {
            if(input[i] == '0'){
                input[i] = 'F';
                i--;
            } else if(input[i] == '#'){
                state = 2;
                break;
            } else {
                state = 0;
                if(input[i] == 'A') {
                    input[i] = '9';
                } else {
                    input[i]--;
                }
                i++;
                // increment decimal output
                int j;
                for (j = output.length() - 1; j >= 0; j--) {
                    if(output[j] == '9'){
                        output[j] = '0';
                    } else {
                        output[j]++;
                        break;
                    }
                }    
                if (j < 0) {
                    output = "1" + output;
                }
            }
        }
    }
    if (state != 2) {
        cout << "ERROR: Sorry Problem on our part\n";
    }
    else {
        cout << "\nDECIMAL : " << output << "\n";
    }
}


void decimal_to_hexa(string input, string &output){
    int i = 1;
    int state = 0;
    output = "0";
    while(i<input.length() && i>=0){
        if(state == 0){
            if(input[i] == '#'){
                state = 1;
                i--;
            } else {
                i++;
            }
        }
        else if(state==1){
            if(input[i] == '0'){
                input[i] = '9';
                i--;
            } else if(input[i] == '#'){
                state = 2;
                break;
            } else {
                state = 0;
                input[i]--;
                i++;
                // increment decimal output
                int j;
                for (j = output.length() - 1; j >= 0; j--) {
                    if(output[j] == '9'){
                        output[j] = 'A';
                        break;
                    }
                    else if(output[j]=='F') {
                        output[j] = '0';
                    } 
                    else {
                        output[j]++;
                        break;
                    }
                }    
                if (j < 0 && output[j+1]=='0') {
                    output = "1" + output;
                }
            }
        }
    }
     if (state != 2) {
        cout << "ERROR: Sorry Problem on our part\n";
    }
    else {
        cout << "\nHEXA : " << output << "\n";
    }
}
