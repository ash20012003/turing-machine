#include <iostream>
#include <sstream>  

using namespace std;

void decimal_to_binary(string input, string& output) {
    int state = 0, i = 1;
    bool flag = false;
    output = "0";
    while (i < input.length() && i >= 0) {
        if (!isdigit(input[i]) && input[i] != '#') {
            flag = true;
            break;
        }
        if (state == 0 && input[i] != '#') {
            i++;
        }
        else if (state == 0 && input[i] == '#') {
            state = 1;
            i--;
        }
        else if (state == 1) {
            if (input[i] == '0') {
                input[i] = '9';
                i--;
            }
            else if (input[i] == '#') {
                state = 2;
                break;
            }
            else {
                state = 0;
                input[i]--;
                i++;
                // increment binary output
                int j;
                for (j = output.length() - 1; j >= 0; j--) {
                    if (output[j] == '0') {
                        output[j] = '1';
                        break;
                    }
                    else if (output[j] == '1') {
                        output[j] = '0';
                    }
                }
                if (j < 0) {
                    output = "1" + output;
                }
            }
        }
        else if (state == 2) {
            break;
        }
    }
    if (flag) {
        cout << "ERROR: Invalid Input Detected \n";
    }
    else if (state != 2) {
        cout << "ERROR: Sorry Problem on our part\n";
    }
    else {
        cout << "\nBINARY : " << output << "\n";
    }
}

//

void binary_to_decimal(string &input, string &output){
    int state = 0;
    int i = 2;
    while(i<input.length() && i>=0){
        if(input[i]=='#' && state==0){
            i+=1;
            state = 1;
        }
        else if((input[i]=='0' || input[i]=='1') && state == 1){
            i+=1;
        }
        else if(input[i]=='#' && state==1){
            i-=1;
            state = 2;
        }
        if(state==2){
            if(input[input.length()-1]=='1'){
                input[input.length()-1] = '0';
                if(output.length()==0){
                    output+='1';
                }
                else{
                    int j = 0;
                    if(output[output.length()-1]!='9') output[output.length()-1] += 1;
                    else{
                        for(j = output.length()-1; j>=0; j--){
                            if(output[j]=='9') output[j]=='0';
                            else{
                                output[j]+=1;
                                break;
                            }
                        }
                        if(j<=0) output = '1'+output;
                    }
                }
            }
            else if(input[input.length()-1]=='0'){
                int j = input.length()-1;
                while(input[j]!='1'){
                    input[j]='1';
                    j--;
                }
                input[j]='0';
                 if(output.length()==0){
                    output+='1';
                }
                else{
                    int j = 0;
                    if(output[output.length()-1]!='9') output[output.length()-1] += 1;
                    else{
                        for(j = output.length()-1; j>=0; j--){
                            if(output[j]=='9') output[j]=='0';
                            else{
                                output[j]+=1;
                                break;
                            }
                        }
                        if(j<=0) output = '1'+output;
                    }
                }
            }
            else{
                state = 3;
                break;
            }
        }
    }
    cout<<output<<endl;
}