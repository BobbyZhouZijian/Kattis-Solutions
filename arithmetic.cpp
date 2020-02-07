#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string octal;
    cin >> octal;

    string bin = "";

    for (char i : octal) {
        if (i == '0')
            bin += "000";
        if (i == '1')
            bin += "001";
        if (i == '2')
            bin += "010";
        if (i == '3')
            bin += "011";
        if (i == '4')
            bin += "100";
        if (i == '5')
            bin += "101";
        if (i == '6')
            bin += "110";
        if (i == '7')
            bin += "111";
    }

    string hex = "";
    int rest = bin.length() % 4;
    while (rest % 4) {
        rest++;
        bin = "0" + bin;
    }

    for (int i = 0; i + 4 <= bin.length(); i += 4) {
        string curr = bin.substr(i, 4);

        if (curr == "0000")
            hex += "0";
        if (curr == "0001")
            hex += "1";
        if (curr == "0010")
            hex += "2";
        if (curr == "0011")
            hex += "3";
        if (curr == "0100")
            hex += "4";
        if (curr == "0101")
            hex += "5";
        if (curr == "0110")
            hex += "6";
        if (curr == "0111")
            hex += "7";
        if (curr == "1000")
            hex += "8";
        if (curr == "1001")
            hex += "9";
        if (curr == "1010")
            hex += "A";
        if (curr == "1011")
            hex += "B";
        if (curr == "1100")
            hex += "C";
        if (curr == "1101")
            hex += "D";
        if (curr == "1110")
            hex += "E";
        if (curr == "1111")
            hex += "F";
    }

    while (hex[0] == '0') {
        hex = hex.substr(1);

        if (hex == "") {
            hex = "0";
            break;
        }
    }

    cout << hex;
}