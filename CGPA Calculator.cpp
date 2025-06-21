#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<double> grades(n), credits(n);
    double totalCredits = 0, totalGradePoints = 0;

    for (int i = 0; i < n; ++i) {
        cout << "Enter grade (point) for course " << i + 1 << ": ";
        cin >> grades[i];
        cout << "Enter credit hours for course " << i + 1 << ": ";
        cin >> credits[i];

        totalGradePoints += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    double cgpa = totalGradePoints / totalCredits;
    cout << "\nFinal CGPA: " << cgpa << endl;
    return 0;
}
