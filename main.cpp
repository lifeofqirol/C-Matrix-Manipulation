//ER11

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

void display (const int, int[][4]);
void addition (const int, int[][4], int[][4]);
void scalarMult (const int, int[][4], int);
void diagonal (int[][4]);
void transpose (const int, int[][4]);
void multiply (const int, int[][4], int[][4]);

int main(int argc, const char * argv[])
{
    const int MAX = 9;
    const int MIN = -9;
    const int SIZE = 4;
    int matrixA[SIZE][SIZE];
    int matrixB[SIZE][SIZE];
    
    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrixA[i][j] = rand()%(MAX-MIN+1)+MIN;
            matrixB[i][j] = rand()%(MAX-MIN+1)+MIN;
        }
    }
    
    int choice = 7;
    do
    {
        if (choice != 7)
            cout<<"||||||||||||||||||||||||||||||||||||||||||||||||"<<endl<<endl;
        cout<<"   MATRICES COMMANDS"<<endl;
        cout<<"========================"<<endl;
        cout<<"1. Display"<<endl;
        cout<<"2. Addition"<<endl;
        cout<<"3. Scalar Multiplication"<<endl;
        cout<<"4. Diagonal Summation"<<endl;
        cout<<"5. Tranpose"<<endl;
        cout<<"6. Multiply"<<endl;
        cout<<"7. Exit Menu"<<endl<<endl;
        cout<<"Choice: ";
        cin>>choice; cin.ignore(); cout<<endl;
        
        switch (choice)
        {
            case 1:
            {
                char displayChoice;
                cout<<"Matrix A or B? ";
                cin>>displayChoice; cin.ignore(); cout<<endl;
                displayChoice = toupper(displayChoice);
                
                if (displayChoice == 'A')
                    display(SIZE, matrixA);
                else if (displayChoice == 'B')
                    display(SIZE, matrixB);
                else
                    cout<<"Invalid entry."<<endl<<endl;
                break;
            }
            case 2:
            {
                addition(SIZE, matrixA, matrixB);
                break;
            }
            case 3:
            {
                char scalarChoice;
                cout<<"Matrix A or B? ";
                cin>>scalarChoice; cin.ignore(); cout<<endl;
                scalarChoice = toupper(scalarChoice);
                
                int scale;
                cout<<"Integer Scalar Factor: ";
                cin>>scale; cin.ignore(); cout<<endl;
                
                if (scalarChoice == 'A')
                    scalarMult(SIZE, matrixA, scale);
                else if (scalarChoice == 'B')
                    scalarMult(SIZE, matrixB, scale);
                else
                    cout<<"Invalid entry."<<endl<<endl;
                break;
            }
            case 4:
            {
                char diagonalChoice;
                cout<<"Matrix A or B? ";
                cin>>diagonalChoice; cin.ignore(); cout<<endl;
                diagonalChoice = toupper(diagonalChoice);
                
                if (diagonalChoice == 'A')
                    diagonal(matrixA);
                else if (diagonalChoice == 'B')
                    diagonal(matrixB);
                else
                    cout<<"Invalid entry."<<endl<<endl;
                break;
            }
            case 5:
            {
                char transposeChoice;
                cout<<"Matrix A or B? ";
                cin>>transposeChoice; cin.ignore(); cout<<endl;
                transposeChoice = toupper(transposeChoice);
                
                if (transposeChoice == 'A')
                    transpose(SIZE, matrixA);
                else if (transposeChoice == 'B')
                    transpose(SIZE, matrixB);
                else
                    cout<<"Invalid entry."<<endl<<endl;
                break;
            }
            case 6:
            {
                multiply(SIZE, matrixA, matrixB);
                break;
            }
            case 7:
            {
                cout<<"Menu closed.";
                break;
            }
            default:
            {
                cout<<"ENTRY INVALID."<<endl<<endl;
                break;
            }
        }
    } while (choice != 7);
    
    cin.get();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////1
void display (const int S, int X[][4])
{
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            cout<<X[i][j];
            if (X[i][j] >= 0)
                cout<<"  ";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////2
void addition (const int S, int A[][4], int B[][4])
{
    int sum[S][S];
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////3
void scalarMult (const int S, int X[][4], int multiple)
{
    int scaled[S][S];
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            scaled[i][j] = (X[i][j] * multiple);
            cout<<scaled[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////4
void diagonal (int X[][4])
{
    int topLeft, topRight;
    topLeft = X[0][0] + X[1][1] + X[2][2] +X[3][3];
    topRight = X[0][3] + X[1][2] + X[2][1] +X[3][0];
    cout<<"TL->BR (\\) Diagonal Sum: "<<topLeft<<endl;
    cout<<"TP->BL (/) Diagonal Sum: "<<topRight<<endl<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////5
void transpose (const int S, int X[][4])
{
    int T[S][S];
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            T[i][j] = X[i][j];
        }
    }
    
    X[1][0] = T[0][1]; X[0][1] = T[1][0];
    X[2][0] = T[0][2]; X[0][2] = T[2][0];
    X[3][0] = T[0][3]; X[0][3] = T[3][0];
    X[2][1] = T[1][2]; X[1][2] = T[2][1];
    X[3][1] = T[1][3]; X[1][3] = T[3][1];
    X[3][2] = T[2][3]; X[2][3] = T[3][2];
    
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            cout<<X[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////6
void multiply (const int S, int A[][4], int B[][4])
{
    int X[S][S];
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            X[i][j] = 0;
        }
    }
    
    for (int i = 0; i < S; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            for (int k = 0; k < S; ++k)
            {
                X[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    
    for (int i = 0; i < S; ++i)
    {
        for (int j = 0; j < S; ++j)
        {
            cout<<" "<<X[i][j];
            if (j == S-1)
                cout<<endl;
        }
}
    cout<<endl;
}
