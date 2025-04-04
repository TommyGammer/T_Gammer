#include <iostream>
using namespace std;

struct Matrix{
  double m11;
  double m12;
  double m21;
  double m22;
  string name;
  //double scalar;
} Matrix1, Matrix2, mSum, mDiff, kMatrix, mProd, mInverse;

/******************************************************************
* The function getMatrix(Matrix, int) takes a matrix var and      *
* an int var and asks the user to enter the members of the Matrix *
* of index number int.                                            *
******************************************************************/

void getMatrix(Matrix &enteredMatrix, int MatrixNum) {
  cout << "Please enter a 1 word name for the matrix " << MatrixNum << ": ";
  cin >> enteredMatrix.name;
  cout << "Please enter a number m11 for " << enteredMatrix.name << ": ";
  cin >> enteredMatrix.m11;
  cout << "Please enter a number m12 for " << enteredMatrix.name << ": ";
  cin >> enteredMatrix.m12;
  cout << "Please enter a number m21 for " << enteredMatrix.name << ": ";
  cin >> enteredMatrix.m21;
  cout << "Please enter a number m22 for " << enteredMatrix.name << ": ";
  cin >> enteredMatrix.m22;
}

/******************************************************************
* The void function printMatrix(Matrix) takes a matrix var        *
* and prints its members in an appropriate format.                *
******************************************************************/

void printMatrix(Matrix enteredMatrix) {
  cout << endl << enteredMatrix.name << ": " << endl << endl;
  cout << "| ";
  cout << enteredMatrix.m11 << " ";
  cout << enteredMatrix.m12 << " |" << endl;
  cout << "| " << enteredMatrix.m21 << " ";
  cout << enteredMatrix.m22 << " |" << endl;
}

/******************************************************************
* The void function matrixAddition() sets the members of matrix   *
* mSum equal to the sum of the appropriate members of matrices    *
* matrix1 and matrix2.                                            *
******************************************************************/

void matrixAddition() {
  mSum.m11 = Matrix1.m11 + Matrix2.m11;
  mSum.m12 = Matrix1.m12 + Matrix2.m12;
  mSum.m21 = Matrix1.m21 + Matrix2.m21;
  mSum.m22 = Matrix1.m22 + Matrix2.m22;
  mSum.name = "Sum";
  
}

/******************************************************************
* The void function matrixDiff() sets the members of matrix mDiff *
* equal to the difference of the appropriate members of matrices  *
* matrix 1 and matrix2                                            *
******************************************************************/

void matrixDiff() {
  mDiff.m11 = Matrix2.m11 - Matrix1.m11;
  mDiff.m12 = Matrix2.m12 - Matrix1.m12;
  mDiff.m21 = Matrix2.m21 - Matrix1.m21;
  mDiff.m22 = Matrix2.m22 - Matrix1.m22;
  mDiff.name = "Difference";
}

/******************************************************************
* The int function getChoice(string) takes a string var and prints*
* a message to the user requesting for the matrix operation of the*
* name equal to the string var and asks which number matrix it    *
* should be performed on and returns the index number of the      *
* chosen matrix.                                                  *
******************************************************************/

int getChoice(string calcType) {
  int choice = 0;
  cout << "Would you like to " << calcType << " matrix 1 (" << Matrix1.name << ") or matrix 2 (" << Matrix2.name << ")? (type 1 or 2): ";
  cin >> choice;
  return choice;
}

/******************************************************************
* The void function scalarMult() asks the user for an integer and *
* and the index number of the matrix that is to be scales by the  *
* integer and scales the chosen matrix by the entered integer.    *
******************************************************************/

void scalarMult() {
  int k = 0;
  int choice = getChoice("scale");
  cout << "\nPlease enter a scalar to multiply by: ";
  cin >> k;
  if (choice == 1){
    kMatrix.m11 = Matrix1.m11 * k;
    kMatrix.m12 = Matrix1.m12 * k;
    kMatrix.m21 = Matrix1.m21 * k;
    kMatrix.m22 = Matrix1.m22 * k;
  } else if (choice == 2){
    kMatrix.m11 = Matrix2.m11 * k;
    kMatrix.m12 = Matrix2.m12 * k;
    kMatrix.m21 = Matrix2.m21 * k;
    kMatrix.m22 = Matrix2.m22 * k;
  }
  kMatrix.name = "Scaled";
}

/******************************************************************
* The void function multiplyMatrix() multiplies matrices matrix1  *
* and matrix2 and sets matrix mProd to the resulting matrix.       *
******************************************************************/

void multiplyMatrix() {
  mProd.m11 = Matrix1.m11 * Matrix2.m11 + Matrix1.m12 * Matrix2.m21;
  mProd.m12 = Matrix1.m11 * Matrix2.m12 + Matrix1.m12 * Matrix2.m22;
  mProd.m21 = Matrix1.m21 * Matrix2.m11 + Matrix1.m22 * Matrix2.m21;
  mProd.m22 = Matrix1.m21 * Matrix2.m12 + Matrix1.m22 * Matrix2.m22;
  mProd.name = "Product";
}

/******************************************************************
* The void function findInverse() asks the user to choose Matrix1 *
* or Matrix2 and finds the inverse of the chosen matrix and sets  *
* the matrix mInv to the resulting matrix.                        *
******************************************************************/

void findInverse() {
  int choice = getChoice("inverse");
  if (choice == 1) {
    double det = Matrix1.m11 * Matrix1.m22 - Matrix1.m21 * Matrix1.m12;
    mInverse.m11 = Matrix1.m22 / det;
    mInverse.m12 = -Matrix1.m12 / det;
    mInverse.m21 = -Matrix1.m21 / det;
    mInverse.m22 = Matrix1.m11 / det;
  } else if (choice == 2) {
      double det = Matrix2.m11 * Matrix2.m22 - Matrix2.m21 * Matrix2.m12;
      mInverse.m11 = Matrix2.m22 / det;
      mInverse.m12 = -Matrix2.m12 / det;
      mInverse.m21 = -Matrix2.m21 / det;
      mInverse.m22 = Matrix2.m11 / det;
  }
  mInverse.name = "Inverse";
}

/********************************************************************
* The int main function main() serves as the main menu and prompts  *
* the user to make a selection as to which function that they want  *
* invoked. The switch expression has cases corresponding to each    *
* function, i.e. inputting the elements of the matrices, printing   *
* the matrices, and perform varying mathematic operations on the    *
* matrices. The default case is used for error catching any invalid *
* input from the user.                                              *
********************************************************************/

int main() {
  int selection = 0;
  bool quit = false;
  do {
    cout << "\n========= Main Menu =========\n" << endl;
    cout << "\t1. Create matrices\n" << endl;
    cout << "\t2. Print matrices\n" << endl;
    cout << "\t3. Add matrices\n" << endl;
    cout << "\t4. Subtract matrices\n" << endl;
    cout << "\t5. Multiply matrices\n" << endl;
    cout << "\t6. Scalar multiply matrix\n" << endl;
    cout << "\t7. Invert matrix\n" << endl;
    cout << "\t8. Quit\n" << endl;
    cout << "=============================\n" << endl;
    cout << "Please enter your selection: ";
    cin >> selection;
    switch (selection) {
      case 1:
        getMatrix(Matrix1, 1);
        getMatrix(Matrix2, 2);
        break;
      case 2:
        printMatrix(Matrix1);
        printMatrix(Matrix2);
        printMatrix(mSum);
        printMatrix(mDiff);
        printMatrix(kMatrix);
        printMatrix(mProd);
        printMatrix(mInverse);
        break;
      case 3:
        matrixAddition();
        printMatrix(mSum);
        break;
      case 4:
        matrixDiff();
        printMatrix(mDiff);
        break;
      case 5:
        multiplyMatrix();
        printMatrix(mProd);
        break;
      case 6:
        scalarMult();
        printMatrix(kMatrix);
        break;
      case 7:
        findInverse();
        printMatrix(mInverse);
        break;
      case 8:
        cout << "\nGoodbye!" << endl;
        quit = true;
        break;
      default:
        cout << "Error: Invalid selection. Please try again." << endl;
    }
  } while(!quit);
  return 0;
}