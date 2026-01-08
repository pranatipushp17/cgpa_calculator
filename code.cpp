#include <bits/stdc++.h>
using namespace std;

// Convert letter grade to grade point
int gradeToPoint(string grade) {
   for (char &c : grade) {
        c = toupper(c);
    }

    unordered_map<string, int> gradeMap = {
        {"O", 10}, {"A", 9}, {"B", 8},
        {"C", 7}, {"D", 6}, {"E", 5},
        {"F", 0} // Fail
    };

    if(gradeMap.find(grade) != gradeMap.end()) {
        return gradeMap[grade];
    } else {
        cout << "Invalid grade! Assuming 0.\n";
        return 0;
    }
}

int main() {
    int n;
    cout << "Enter number of subjects in current semester: ";
    cin >> n;

    double totalWeightedCurrent = 0;
    double totalCreditsCurrent = 0;

    for(int i = 0; i < n; i++) {
        string grade;
        double credits;

        cout << "Enter grade (O, A, B, C, D, E, F) for subject " << i+1 << ": ";
        cin >> grade;
        if(grade=="F"){
            cout<<"You failed this course"<<",give the supplementary exam to get you cgpa";
            return 0;
        }
        cout << "Enter credits for subject " << i+1 << ": ";
        cin >> credits;
        if(credits<0){
            cout<<"INVALID DETAILS";
        }
        int gradePoint = gradeToPoint(grade);
        totalWeightedCurrent += gradePoint * credits;
        totalCreditsCurrent += credits;
    }

    double currentCGPA = totalWeightedCurrent / totalCreditsCurrent;
    cout << "\nSemester SGPA: " << currentCGPA <<setprecision(2)<< endl;

    // Previous semester input
    double prevCGPA, prevCredits;
    cout << "\nEnter previous semester CGPA: ";
    cin >> prevCGPA;

    cout << "Enter total credits of previous semester: ";
    cin >> prevCredits;

    // Cumulative CGPA
    double cumulativeCGPA = (prevCGPA * prevCredits + currentCGPA * totalCreditsCurrent) 
                            / (prevCredits + totalCreditsCurrent);

    cout << "Cumulative CGPA: " << cumulativeCGPA <<setprecision(2)<< endl;

    return 0;
}

