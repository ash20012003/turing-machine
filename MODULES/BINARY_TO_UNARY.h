#include<iostream>
using namespace std;

void binary_to_unary(string input, string& output) {
    int state = 0, i = 0;
    bool flag = false, flag2 = false;
    while (i < input.length() && i >= 0) {
        // for checking invalid characters
        if (input[i] != '0' && input[i] != '1' && input[i] != '#') {
            flag = true;
            break;
        }
        // transitions
        if (state == 0 && input[i] == '#') {
            state = 1;
            i++;
        }
        else if (state == 1) {
            if (input[i] == '0') {
                state = 1;
                i++;
            }
            else if (input[i] == '1') {
                state = 1;
                i++;
            }
            else if (input[i] == '#') {
                state = 2;
                i--;
            }
        }
        else if (state == 2) {
            if (input[i] == '0') {
                state = 2;
                input[i] = '1';
                i--;
            }
            else if (input[i] == '1') {
                state = 1;
                input[i] = '0';
                i++;
                // generating output
                output += "0";
            }
            else if (input[i] == '#') {
                //final state
                state = 3;
                break;
            }
        }
    }
    if (flag) {
        cout << "ERROR: Invalid Input Detected \n";
    }
    else if (state != 3) {
        cout << state;
        cout << "ERROR: Sorry Problem on our part\n";
    }
    else {
        cout << "\nUNARY : " << output << "\n";
    }
}

void unary_to_binary(string input, string& output) {
    int i = 0;
    int state = 0, flag = 0;
    while (i < input.length() && i >= 0) {
        if (input[i] == '#' && state == 0) {
            i += 1;
            state = 1;
        }
        else if (input[i] == '#' && state == 1) {
            flag = 1;
            break;
        }
        else if (input[i] == '0' && state == 1) {
            if (output.length() == 0) output += '1';
            else if (output[output.length() - 1] == '0') output[output.length() - 1] = '1';
            else if (output[output.length() - 1] == '1') {
                int j = output.length() - 1;
                for (j = output.length() - 1; j >= 0;j--) {
                    if (output[j] == '0') {
                        output[j] = '1';
                        break;
                    }
                    else {
                        output[j] = '0';
                    }
                }
                if (j <= 0) {
                    output = "1" + output;
                }
            }
            i += 1;
        }
    }
    cout <<"BINARY : "<<output<< endl;
}