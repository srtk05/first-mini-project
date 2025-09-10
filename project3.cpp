#include <iostream>
#include <fstream>   // for file handling
using namespace std;

// Base class
class Patient {
public:
    int patientID;
    string name;
    int age;
    string gender;

    void getPatientDetails() {
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Gender: ";
        cin >> gender;
    }

    void showPatientDetails() {
        cout << "\nPatient ID: " << patientID;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nGender: " << gender << endl;
    }

    // Save common details to file
    void saveBasicDetails(ofstream &file) {
        file << "Patient ID: " << patientID << endl;
        file << "Name: " << name << endl;
        file << "Age: " << age << endl;
        file << "Gender: " << gender << endl;
    }
};

// Child class for patients visiting a Cardiologist
class CardiologyPatient : public Patient {
public:
    string doctorName = "Dr. Sharma (Cardiologist)";
    string heartProblem;
    float fee = 800;

    void getDetails() {
        getPatientDetails();
        cin.ignore();
        cout << "Enter Heart Problem Description: ";
        getline(cin,heartProblem);
    }

    void showDetails() {
        showPatientDetails();
        cout << "Doctor: " << doctorName;
        cout << "\nHeart Problem: " << heartProblem;
        cout << "\nConsultation Fee: " << fee << endl;
    }

    void saveToFile() {
        ofstream file("patients.txt", ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        saveBasicDetails(file);
        file << "Doctor: " << doctorName << endl;
        file << "Heart Problem: " << heartProblem << endl;
        file << "Consultation Fee: " << fee << endl;
        file << "----------------------------" << endl;
        file.close();
        cout << "Details saved to file successfully!\n";
    }
};

// Child class for patients visiting a Neurologist
class NeurologyPatient : public Patient {
public:
    string doctorName = "Dr. Mehta (Neurologist)";
    string neuroProblem;
    float fee = 1000;

    void getDetails() {
        getPatientDetails();
        cin.ignore();
        cout << "Enter Neurological Problem Description: ";
        getline(cin,neuroProblem);
    }

    void showDetails() {
        showPatientDetails();
        cout << "Doctor: " << doctorName;
        cout << "\nNeurological Problem: " << neuroProblem;
        cout << "\nConsultation Fee: " << fee << endl;
    }

    void saveToFile() {
        ofstream file("patients.txt", ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        saveBasicDetails(file);
        file << "Doctor: " << doctorName << endl;
        file << "Neurological Problem: " << neuroProblem << endl;
        file << "Consultation Fee: " << fee << endl;
        file << "----------------------------" << endl;
        file.close();
        cout << "Details saved to file successfully!\n";
    }
};

// Child class for patients visiting a Dentist
class DentalPatient : public Patient {
public:
    string doctorName = "Dr. Gupta (Dentist)";
    string dentalIssue;
    float fee = 500;

    void getDetails() {
        getPatientDetails();
        cin.ignore();
        cout << "Enter Dental Issue: ";
        getline(cin, dentalIssue);
    }

    void showDetails() {
        showPatientDetails();
        cout << "Doctor: " << doctorName;
        cout << "\nDental Issue: " << dentalIssue;
        cout << "\nConsultation Fee: " << fee << endl;
    }

    void saveToFile() {
        ofstream file("patients.txt", ios::app);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        saveBasicDetails(file);
        file << "Doctor: " << doctorName << endl;
        file << "Dental Issue: " << dentalIssue << endl;
        file << "Consultation Fee: " << fee << endl;
        file << "----------------------------" << endl;
        file.close();
        cout << "Details saved to file successfully!\n";
    }
};

// Main function
int main() {
    int choice;
    cout << "\nHospital Patient Management with File Handling";
    cout << "\n1. Cardiology Patient";
    cout << "\n2. Neurology Patient";
    cout << "\n3. Dental Patient";
    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1) {
        CardiologyPatient cp;
        cp.getDetails();
        cout << "\n--- Cardiology Patient Details ---\n";
        cp.showDetails();
        cp.saveToFile();
    }
    else if (choice == 2) {
        NeurologyPatient np;
        np.getDetails();
        cout << "\n--- Neurology Patient Details ---\n";
        np.showDetails();
        np.saveToFile();
    }
    else if (choice == 3) {
        DentalPatient dp;
        dp.getDetails();
        cout << "\n--- Dental Patient Details ---\n";
        dp.showDetails();
        dp.saveToFile();
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
