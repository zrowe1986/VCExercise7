// Exercise 7: Fuel efficiency comparison of 2 car models
// Gets two car models and their MPG, plus yearly miles and gas price,
// then reports yearly gas cost for each and which car saves more.

#include <iostream>   // cin, cout
#include <iomanip>    // fixed, setprecision
#include <string>     // string, getline
using namespace std;

int main()
{
    // Variables
    string model1, model2;                       // car model names
    double mpg1, mpg2;                           // miles per gallon for each car
    double milesPerYear, gasPrice;               // shared inputs

    // Get input from the user
    cout << "Enter car model 1: ";
    getline(cin, model1);                        // getline allows spaces in names
    cout << "Enter MPG of " << model1 << ": ";
    cin >> mpg1;
    cin.ignore();                                // clear leftover newline so the next getline works

    cout << "Enter car model 2: ";
    getline(cin, model2);
    cout << "Enter MPG of " << model2 << ": ";
    cin >> mpg2;

    cout << "Enter average miles driven per year: ";
    cin >> milesPerYear;
    cout << "Enter average cost of gas per gallon: $";
    cin >> gasPrice;

    // Input validation: MPG of 0 or less would cause a divide by zero
    if (mpg1 <= 0 || mpg2 <= 0)
    {
        cout << "\nMPG must be greater than zero." << endl;
        return 1;                                // exit with an error code
    }

    // Calculations: gallons used = miles / MPG, cost = gallons * price
    double cost1 = (milesPerYear / mpg1) * gasPrice;
    double cost2 = (milesPerYear / mpg2) * gasPrice;

    // Display results
    cout << fixed << setprecision(2);            // show 2 decimal places for all numbers
    cout << "\n----- Fuel Efficiency Analysis -----\n";
    cout << "Average miles driven per year: " << milesPerYear << endl;
    cout << "Average price per gallon:      $" << gasPrice << endl;
    cout << "\nModel 1: " << model1 << " (" << mpg1 << " MPG)" << endl;
    cout << "Model 2: " << model2 << " (" << mpg2 << " MPG)" << endl;
    cout << "\nYearly gas cost for " << model1 << ": $" << cost1 << endl;
    cout << "Yearly gas cost for " << model2 << ": $" << cost2 << endl;

    // Compare costs: the lower yearly cost is the more economical model
    if (cost1 < cost2)
    {
        cout << "\nMost economical: Model 1 (" << model1 << ")" << endl;
        cout << "Yearly savings:  $" << cost2 - cost1 << endl;   // savings = higher cost - lower cost
    }
    else if (cost2 < cost1)
    {
        cout << "\nMost economical: Model 2 (" << model2 << ")" << endl;
        cout << "Yearly savings:  $" << cost1 - cost2 << endl;
    }
    else
    {
        // Costs are equal, so neither model saves anything
        cout << "\nBoth models cost the same per year." << endl;
    }

    return 0;                                    // normal exit
}