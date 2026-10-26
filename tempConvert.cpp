#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

int celsiusToKelvin (double myTemp) {
    return myTemp + 273.15;
}

int celsiusToFar (double myTemp) {
    return ((9.0 / 5.0) * myTemp) + 32;
}

int farToCelsius (double myTemp) {
    return (5.0 / 9.0) * (myTemp - 32);
}

int farToKelvin (double myTemp) {
    return farToCelsius(myTemp) + 273.15;
}

int kelvinToCelsius (double myTemp) {
    return myTemp - 273.15;
}

int kelvinToFar (double myTemp) {
    return ((9.0 / 5.0) * (myTemp-273.15)) + 32;
}

int readDouble(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        std::getline(cin, input);

        try {
            size_t pos;
            double value = std::stod(input, &pos);
            if (pos != input.size()) {
                cout << "Invalid Input! Please Try a Number.\n";
                continue;
            }
            return value;
        } catch(std::invalid_argument&) {
            cout << "Invalid Input! Please Try a Number.\n";
        } catch(std::out_of_range&) {
            cout << "Number is Too Large! Try Again.\n";
        }
    }
}

int readUnit(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        std::getline(cin, input);

        try {
            size_t pos;
            int value = std::stoi(input, &pos);
            if (pos == input.size() && value >= 1 && value <= 3) {
                return value;
            }
        }
        catch(...) {
        }
        cout << "Please Choose 1, 2, or 3.\n";
    }
    
}

bool belowAbsoluteZero(double temp, int unit) {
    if (unit == 1) {
        return temp < -273.15;
    }
    if (unit == 2) {
        return temp = 0;
    }
    return temp < -459.67;
}

int main() {
    string answer;

    do {
        double number = readDouble("Enter a Temperature: ");
        int unit = readUnit("Choose Temp Unit (C[1], K[2], F[3]): ");

        if (belowAbsoluteZero(number, unit)) {
            cout << "It is impossible to have something below absolute zero!\n";
        } else {
            switch (unit) {
                case 1:
                    cout << number << " Celsius = " << celsiusToFar(number) << " Fahrenheit = " << celsiusToKelvin(number) << " Kelvin";
                    cout << "\n";
                    break;

                case 2:
                    cout << number << " Kelvin = " << kelvinToCelsius(number) << " Celsius = " << kelvinToFar(number) << " Fahrenheit";
                    cout << "\n";
                    break;

                case 3:
                    cout << number << " Fahrenheit = " << farToCelsius(number) << " Celsius = " << farToKelvin(number) << " Kelvin";
                    cout << endl;
                    break;
    
                default:
                    cout << "Please Choose 1, 2, or 3.\n";
                    break;
            }
        }

        cout << "\nDo Another Conversion? (Y/N): ";
        std::getline(cin, answer);
        cout << endl;

    } while (!answer.empty() && answer[0] == 'y' || answer[0] == 'Y');

    cout << "Goodbye!\n";

    return 0;
}