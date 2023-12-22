#include <iostream>
#include <string>//for using string function
#include <vector>//for using vector function
#include <fstream>//for using file handling
using namespace std;

// Define a struct to represent a Doctor's information
struct Doctor {
    string speciality;
    string name;
};

// Define a class to represent Patient's information and actions
class Patient {
public:
    string name;
    Doctor doc;
    string time;
    int date, month, year;

    // Function to input patient's details
    void setter();

    // Function to display patient's and doctor's information
    void getter();
};

// Implementation of setter function
void Patient::setter() {
    cin.ignore(); // Clear the newline character from the buffer
    cout << "Patient's name: ";
    getline(cin, name);
    cout << "Time [use 24 hours system]: ";
    cin >> time;
    cout << "Appointment Date [dd mm yyyy]: ";
    cin >> date >> month >> year;
}

// Function to display available specialities
void showSpecialities(const vector<Doctor>& specialities) {
    cout << "Available Categories:" << endl;
    for (const Doctor& speciality : specialities) {
        cout << speciality.speciality << endl;
    }
}

// Function to choose a speciality and return the selected index
int choiceSpecialities(const vector<Doctor>& specialities) {
    int n;
    while (true) {
        cout << "[press 1] Emergency"<<endl;
        cout << "[press 2] Osteopaths "<<endl;
        cout << "[press 3] Pathologists"<<endl;
        cout << "[press 4] Cardiologists"<<endl;
        cout << "[press 5] Dermatologists"<<endl;
        cout << "[press 6] Kid Specialist"<<endl;
        cin >> n;
        if (n >= 1 && n <= specialities.size()) {
            break;
        } else {
            cout << "Invalid choice. Please select a valid speciality." << endl;
        }
    }
    return n;
}

// Function to display available doctors for a given speciality
void ableavailDoctor(const vector<Doctor>& doctors, const string& selectedSpeciality) {
    cout << "Available Doctors for " << selectedSpeciality << ":" << endl;
    for (int i = 0; i < doctors.size(); ++i) {
        if (doctors[i].speciality == selectedSpeciality) {
            cout << " " << i + 1 << ". " << doctors[i].name << endl;
        }
    }
}

// Function to choose a doctor and return the selected index
int choiceDoctor(const vector<Doctor>& doctors) {
    int n;
    while (true) {
        cout << "Press by given number: ";
        cin >> n;
        if (n >= 1 && n <= doctors.size()) {
            break;
        } else {
            cout << "Invalid choice. Please select a valid doctor." << endl;
        }
    }
    return n;
}

// Implementation of getter function in Patient class
void Patient::getter() {
    cout <<endl<< "------Displaying All Information-------" << endl;
    cout << "Congratulation!" << endl;
    cout << "Doctor Name: " << doc.name << endl;
    cout << "Department: " << doc.speciality << endl;
    cout << "Patient's name: " << name << endl;
    cout << "Time: " << time << endl;
    cout << "Appointment Date: " << date << " " << month << " " << year << endl;
}

// Function to save appointment to a file
void saveAppointment(const Patient& patient) {
    ofstream outFile("appointments.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Doctor: " << patient.doc.name << endl;
        outFile << "Speciality: " << patient.doc.speciality << endl;
        outFile << "Patient: " << patient.name << endl;
        outFile << "Time: " << patient.time << endl;
        outFile << "Date: " << patient.date << " " << patient.month << " " << patient.year << endl;
        outFile << "-------------------------" << endl;
        outFile.close();
        cout << "Appointment saved successfully!" << endl;
    } else {
        cout << "Error opening file." << endl;
    }
}

// Main function
int main() {
    while (true) {
        Patient patient;
        vector<Doctor> specialities;
        // Initialize available specialities
        specialities.push_back({"Emergency Medicine Specialists"});
        specialities.push_back({"Osteopaths"});
        specialities.push_back({"Pathologists"});
        specialities.push_back({"Cardiologists"});
        specialities.push_back({"Dermatologists"});
        specialities.push_back({"Kid Specialist"});

        showSpecialities(specialities); // Display available specialities
        int chosenSpeciality = choiceSpecialities(specialities); // Choose a speciality

        string selectedSpeciality = specialities[chosenSpeciality - 1].speciality;

        vector<Doctor> doctors;
        // Initialize available doctors
        doctors.push_back({"Emergency Medicine Specialists","Dr. Israt Jahan"});
        doctors.push_back({"Emergency Medicine Specialists","Dr. Saidul Bhuyan"});
        doctors.push_back({"Emergency Medicine Specialists","Dr. Moni Chowdary"});
        doctors.push_back({"Osteopaths","Dr. Naeemul Islam"});
        doctors.push_back({"Osteopaths","Dr. Shamima Akter Saki"});
        doctors.push_back({"Osteopaths","Dr. Tanvir Ahamed"});
        doctors.push_back({"Pathologists","Dr. Maruf Ahamed"});
        doctors.push_back({"Pathologists","Dr. Israt Jahan Kyra"});
        doctors.push_back({"Pathologists","Dr. Rimi Israt Ara"});
        doctors.push_back({"Cardiologists","Dr. Hafizur Rahaman"});
        doctors.push_back({"Cardiologists","Dr. Sahidul Alam"});
        doctors.push_back({"Cardiologists","Dr. Iqbal Kabir"});
        doctors.push_back({"Dermatologists","Dr. Israq Faruki"});
        doctors.push_back({"Dermatologists","Dr. Abdul Kadir Molla"});
        doctors.push_back({"Dermatologists","Dr. Ariyan Khan"});
        doctors.push_back({"Kid Specialist","Dr. Enayet Chowdhary"});
        doctors.push_back({"Kid Specialist","Dr. Abdullah Al Mamun"});
        doctors.push_back({"Kid Specialist","Dr. Musafir"});

        ableavailDoctor(doctors, selectedSpeciality); // Display available doctors
        int chosenDoctor = choiceDoctor(doctors); // Choose a doctor

        if (chosenDoctor != -1) {
            cout << "You chose: " << doctors[chosenDoctor - 1].name << endl;
            patient.doc = doctors[chosenDoctor - 1]; // Assign chosen doctor to patient
            patient.setter(); // Set patient's details
            patient.getter(); // Display patient's and doctor's information
            saveAppointment(patient); // Save the appointment to a file
        }

        cout << "Do you want to make another appointment? (y/n): ";
        char repeat;
        cin >> repeat;
        if (repeat != 'y' && repeat != 'Y') {
            cout << "Thank you for using our appointment system. Goodbye!" << endl;
            break;
        }
    }

    return 0;
}

