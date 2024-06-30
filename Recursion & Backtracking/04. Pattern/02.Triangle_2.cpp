#include<iostream>
using namespace std;

void triangle(int row, int col)
{
    if(row == 0)
        return;
    
    if(col < row)
    {
        triangle(row, col + 1);
        cout << "*";
    }
    else
    {
        triangle(row - 1, 0);
        cout << endl;
    }
}

int main()
{
    int numberOfRows = 5;
    
    triangle(numberOfRows, 0);

}