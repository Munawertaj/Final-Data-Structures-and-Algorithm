#include<iostream>
using namespace std;

void triangle(int row, int col)
{
    if(row == 0)
        return;
    
    if(col < row)
    {
        cout << "*";
        triangle(row, col + 1);
    }
    else
    {
        cout << endl;
        triangle(row - 1, 0);
    }
}

int main()
{
    int numberOfRows = 5;
    
    triangle(numberOfRows, 0);

}