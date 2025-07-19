#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Function to calculate CGPA
float calculateCGPA(const vector<float>& grades, const vector<int>& credits) {
    float totalWeightedGrades = 0.0;
    int totalCredits = 0;

    for (size_t i = 0; i < grades.size(); ++i) {
        totalWeightedGrades += grades[i] * credits[i];
        totalCredits += credits[i];
    }

    if (totalCredits == 0)
        return 0.0;

    return totalWeightedGrades / totalCredits;
}

int main() {
    int numSubjects;
    cout << "Enter number of subjects: ";
    cin >> numSubjects;

    vector<float> grades(numSubjects);
    vector<int> credits(numSubjects);

    for (int i = 0; i < numSubjects; ++i) {
        cout << "\nSubject " << i + 1 << ":" << endl;
        cout << "Enter grade point (e.g. 9.0): ";
        cin >> grades[i];
        cout << "Enter credit for this subject: ";
        cin >> credits[i];
    }

    float cgpa = calculateCGPA(grades, credits);
    cout << fixed << setprecision(2);
    cout << "\n? Your CGPA is: " << cgpa << endl;

    // Optional: Convert CGPA to percentage (rough estimate)
    cout << "?? Approximate Percentage: " << cgpa * 9.5 << "%" << endl;

    return 0;
}
