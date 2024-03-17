#include <iostream>
#include <vector>

using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> data;

public:
    // Method to add a new row to the spreadsheet
    void addRow(const vector<int>& newRow) {
        data.push_back(newRow);
    }

    // Method to delete a row from the spreadsheet
    void deleteRow(int rowIndex) {
        if (rowIndex >= 0 && rowIndex < data.size()) {
            data.erase(data.begin() + rowIndex);
        } else {
            cout << "Invalid row index" << endl;
        }
    }

    // Method to display the spreadsheet
    void display() {
        cout << "Spreadsheet Contents:" << endl;
        for (const auto& row : data) {
            for (int cell : row) {
                cout << cell << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a spreadsheet object
    Spreadsheet spreadsheet;

    // Add some rows to the spreadsheet
    spreadsheet.addRow({1, 2, 3});
    spreadsheet.addRow({4, 5, 6});
    spreadsheet.addRow({7, 8, 9});

    // Display the spreadsheet
    spreadsheet.display();

    // Delete a row from the spreadsheet
    spreadsheet.deleteRow(1);

    // Display the updated spreadsheet
    cout << "After deleting row 1:" << endl;
    spreadsheet.display();

    return 0;
}
