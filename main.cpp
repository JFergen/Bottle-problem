#include <iostream>
using namespace std;

int getTotalDrunk(int e, int f, int c); // Gets the total amount of bottles drunk that day

int main()
{
    int emptyBottles; // Bottles at start of day
    int foundBottles; // Bottles found during the day
    int newSoda; // Number of bottles required to get a new soda
    
    // Getting the number of bottles at start of day
    cout << "Enter number of empty soda bottles (non-negative number and < 1000):";
    cin >> emptyBottles;
    
    // Making sure it is non-negative and < 1000
    while(emptyBottles < 0 || emptyBottles >= 1000)
    {
        cout << "Error. Please enter a non-negative number and < 1000:";
        cin >> emptyBottles;
    }
    
    // Getting the number of bottles found during the day
    cout << "Enter number of empty soda bottles found during the day (non-negative number and < 1000):";
    cin >> foundBottles;
    
    // Making sure it is non-negative and < 1000
    while(foundBottles < 0 || foundBottles >= 1000)
    {
        cout << "Error. Please enter a non-negative number and < 1000:";
        cin >> foundBottles;
    }
    
    // Getting the required amount of bottles to buy a new soda
    cout << "Enter how many empty bottles is required to buy a new soda (1-2000, exclusive)):";
    cin >> newSoda;
    
    // Making sure it is (1-2000)
    while(newSoda <= 1 || newSoda >= 2000)
    {
        cout << "Error. Please enter a number that is (1-2000, exclusive):";
        cin >> newSoda;
    }
    
    cout << endl << "Total number of bottles drunk: " << getTotalDrunk(emptyBottles, foundBottles, newSoda) << endl;
    return 0;
}

int getTotalDrunk(int e, int f, int c)
{
    int totalDrunk = 0; // The total amount of sodas drunk
    int currentBottles = e + f; // Current amount of bottles. Starting with the amount to begin with + amount found
    
    while(currentBottles >= c)
    {
        totalDrunk += currentBottles / c;
        currentBottles = (currentBottles / c) + (currentBottles % c);
    }
    
    return totalDrunk;
}