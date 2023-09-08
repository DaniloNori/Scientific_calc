#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>

using namespace std;

void displayMenu() {
    cout << "=== Scientific Calculator ===" << endl;
    cout << "1. Basic arithmetic operations" << endl;
    cout << "2. Trigonometric functions" << endl;
    cout << "3. Unit converter" << endl;
    cout << "4. Programming functions" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

double getInput(const string& prompt) {
    double value;
    cout << prompt;
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Invalid input. Please enter a valid number.");
    }
    return value;
}

vector<vector<double>> createMatrix(int rows, int cols) {
    vector<vector<double>> matrix(rows, vector<double>(cols, 0.0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = getInput("Enter element [" + to_string(i + 1) + "][" + to_string(j + 1) + "]: ");
        }
    }
    return matrix;
}

vector<vector<double>> addMatrices(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<double>> result(rows, vector<double>(cols, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

vector<vector<double>> subtractMatrices(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<double>> result(rows, vector<double>(cols, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

vector<vector<double>> multiplyMatrices(const vector<vector<double>>& A, const vector<vector<double>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();
    vector<vector<double>> result(rowsA, vector<double>(colsB, 0.0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

vector<vector<double>> transposeMatrix(const vector<vector<double>>& A) {
    int rows = A.size();
    int cols = A[0].size();
    vector<vector<double>> result(cols, vector<double>(rows, 0.0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = A[i][j];
        }
    }

    return result;
}

double dotProduct(const vector<double>& v1, const vector<double>& v2) {
    int size = v1.size();
    double result = 0.0;

    if (size != v2.size()) {
        throw invalid_argument("Vector sizes must match for dot product.");
    }

    for (int i = 0; i < size; ++i) {
        result += v1[i] * v2[i];
    }

    return result;
}

vector<double> matrixVectorMultiply(const vector<vector<double>>& A, const vector<double>& v) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int sizeV = v.size();
    vector<double> result(rowsA, 0.0);

    if (colsA != sizeV) {
        throw invalid_argument("Matrix columns must match vector size for multiplication.");
    }

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            result[i] += A[i][j] * v[j];
        }
    }

    return result;
}

int main() {
    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                // Basic arithmetic operations
                break;
            case 2:
                // Trigonometric functions
                break;
            case 3:
                // Unit converter
                break;
            case 4:
                cout << "=== Programming Functions ===" << endl;
                cout << "1. Matrix addition" << endl;
                cout << "2. Matrix subtraction" << endl;
                cout << "3. Matrix multiplication" << endl;
                cout << "4. Matrix transposition" << endl;
                cout << "5. Dot product of two vectors" << endl;
                cout << "6. Matrix-vector multiplication" << endl;
                cout << "Enter your choice: ";
                int progChoice;
                cin >> progChoice;
                switch (progChoice) {
                    case 1: {
                        cout << "Enter the first matrix:" << endl;
                        vector<vector<double>> matrixA = createMatrix(getInput("Enter the number of rows: "),
                                                                     getInput("Enter the number of columns: "));
                        cout << "Enter the second matrix:" << endl;
                        vector<vector<double>> matrixB = createMatrix(matrixA.size(), matrixA[0].size());
                        try {
                            vector<vector<double>> result = addMatrices(matrixA, matrixB);
                            cout << "Resultant Matrix:" << endl;
                            for (const vector<double>& row : result) {
                                for (double elem : row) {
                                    cout << elem << " ";
                                }
                                cout << endl;
                            }
                        } catch (const exception& e) {
                            cerr << "Error: " << e.what() << endl;
                        }
                        break;
                    }
                    case 2: {
                        // Similar code as case 1 for matrix subtraction
                        break;
                    }
                    case 3: {
                        // Similar code as case 1 for matrix multiplication
                        break;
                    }
                    case 4: {
                        // Similar code as case 1 for matrix transposition
