#include <iostream>
using namespace std;
int main( )
{
int Array[2][2][4];
cout << "Please enter 16 values of your choice: \n";
for(int i = 0; i < 2; i++)
{
for (int j = 0; j < 2; j++)
{
for(int k = 0; k < 4; k++ )
{
cin >> Array[i][j][k];
}
}
}
cout<<"\n Below are the values you have stored in the array"<< endl;
for(int i = 0; i < 2; i++)
{
for (int j = 0; j < 2; j++)
{
for(int k = 0; k < 4; k++)
{
cout << "[" << i << "][" << j << "][" << k << "] =" <<
Array[i][j][k] << endl;
}
}
}
}
