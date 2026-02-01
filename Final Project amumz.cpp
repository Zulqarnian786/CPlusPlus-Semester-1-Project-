#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;

string user_id;
string password;
string name[30];
float avg[30];
string department[30];
string status[30];
int studentCount = 0;

//-----------Clear Screen Function ------------
void clearScreen() {
    // Check if the system is Windows 
    #ifdef _WIN32 
        system("cls"); // Command for Windows systems
    // Otherwise, assume Unix-like (Linux, macOS, etc.)
    #else
        system("clear"); // Command for Unix-like systems
    #endif
}

// ---------SET LOGIN FUNCTION ---------------

void set_login(){
    cout<<"Set User ID: ";
    getline(cin,user_id);
    cout<<endl;
    cout<<"Set Your Password: ";
    getline(cin,password);
}

// ------------------Entering Login Details ---------

void enter_login(string user_id,string password){
    string userId_check, password_check;

    do
    {
        cout<<"\nEnter Your User ID you Set: ";
        getline(cin,userId_check);
        cout<< "Enter Your Password: ";
        getline(cin, password_check);

        if ((userId_check != user_id) || (password_check != password)) {
            cout << "Incorrect credentials. Please try again.\n";
        }

    } while ((userId_check != user_id) || (password_check != password));
    
    cout<<"Login Successful";
}

// ---------- Apply for Admission Function ----------

void applyforAdmission(){
    float obtained_marks,total_marks,test_marks;
    int age,program_choice;
    float hssc_avg;
    string qualification;

    if (studentCount >= 30) {
        cout << "\n? Maximum student limit (30) reached. Cannot add new student.\n";
        return;
    }
    cout<<"\n------- Enter Data for Student " <<studentCount + 1;

    cout<<"\n\nEnter your Name: "; // Entering Name 
    getline(cin,name[studentCount]);
    cout<<"\nEnter your Age: "; // Entering Age 
    cin>>age;
    if(age<16){
        do{
            cout<<"\nInvalid !, Age should be greater than or equal to 16";
            cout<<"\nEnter your Age: "; // Entering Age 
            cin>>age;
        }while(age<16);
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\nEnter Highest Qualification: ";
    getline(cin, qualification);
    cout<<"\nEnter " <<qualification <<" Obtained Marks: ";
    cin>>obtained_marks;
    cout<<"\nEnter " <<qualification <<" Total Marks: ";
    cin>>total_marks;
    cout<<"\nEnter Test Obtained Marks( Out of 100 ): ";
    cin>>test_marks;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    clearScreen();
    
    cout<<"\n---------------- Averages ----------------";
    
    hssc_avg = (obtained_marks / total_marks) * 100;
    cout<<"\n\n Based on your Marks, Your HSSC Average is: " <<hssc_avg <<"%";
    
    avg[studentCount] = (hssc_avg + test_marks) / 2;
    cout<<"\n\nYour Aggregate Average is: "<<avg[studentCount] <<"%";

    cout<<"\n\nChoose Your Program Below : ";
    cout<<"\n\n1. Computer Science" <<"\n2. Business Administration" <<"\n3. Engineering" <<"\n4. Accounting and Finance";
    cout<<"\n\nEnter Your Choice: ";
    cin>>program_choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool is_eligible = false; // Flag to check eligibility

    if (program_choice == 1) {
        department[studentCount] = "Computer Science";
        if (avg[studentCount] >= 70) {
            is_eligible = true;
        }
    } else if (program_choice == 2) {
        department[studentCount] = "Business Administration";
        if (avg[studentCount] >= 60) {
            is_eligible = true;
        }
    } else if (program_choice == 3) {
        department[studentCount] = "Engineering";
        if (avg[studentCount] >= 65) {
            is_eligible = true;
        }
    } else if (program_choice == 4) {
        department[studentCount] = "Accounting and Finance";
        if (avg[studentCount] >= 70) {
            is_eligible = true;
        }
    } else {
        // Handle invalid choice 
        department[studentCount] = "N/A - Invalid Choice";
    }

    // Assign final status based on the check
    if (is_eligible) {
        status[studentCount] = "Eligible";
        cout << "\n\nCONGRATULATIONS! You are Eligible for admission to " << department[studentCount] << ".\n";
    } else {
        status[studentCount] = "Not Eligible";
        cout << "\n\nWe regret to inform you that your aggregate average of " << avg[studentCount] << "% does not meet the minimum requirement for " << department[studentCount] << ".\n";
    }

    studentCount++;
}

void viewResults (){
    if (studentCount == 0) {
        cout << "\n\nNo student data has been entered yet.\n";
        return;
    }
    
    cout << "\n----------- View Results ----------\n";

    // Loop correction: The index should be 'i', not 'studentCount'
    for(int i = 0; i < studentCount; i++){ 

        cout << "------------------------------------------\n";
        cout << "Student #" << i + 1 << ":\n";
        
        // Use index 'i' to display the data for the current student
        cout << "Name:       " << name[i] << "\n";
        cout << "Avg:        " << avg[i] << "%\n";
        cout << "Department: " << department[i] << "\n";
        cout << "Status:     " << status[i] << "\n";
    }
    cout << "------------------------------------------\n";
}

//-------View Departments Function ---------

void viewDepartments(){
    cout<<"----- Following are the Departments available --------" <<endl <<endl;
    cout<<"1. Computer Science\n";
    cout<<"The Minimum Eligibility criteria for the Computer Science Program is 70%" <<endl <<endl;

    cout<<"2. Business Administration\n"; 
    cout<<"The Minimum Eligibility criteria for the Business Administration Program is 60%" <<endl <<endl;

    cout<<"3. Engineering\n";
    cout<<"The Minimum Eligibility criteria for the Engineering Program is 65%" <<endl <<endl;

    cout<<"4. Accounting and Finance\n";
    cout<<"The Minimum Eligibility criteria for the Accounting and Finance Program is 70%";
}


int main() {

    cout << "-------- University Admission Management System ----------\n";

    // 1. SET LOGIN (user enters new ID + password)
    set_login();
    clearScreen();
    enter_login(user_id, password);

    // -------------------- MAIN MENU --------------------
    int choice;

    do {
        cout << "\n\n=========== MAIN MENU ===========";
        cout << "\n1. Apply for Admission";
        cout << "\n2. View Results";
        cout << "\n3. View Departments";
        cout << "\n4. Exit";
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        clearScreen();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        switch(choice)
        {
            case 1:
                applyforAdmission();
                break;

            case 2:
                viewResults();
                break;

            case 3:
                viewDepartments();
                break;

            case 4:
                cout << "\nExiting the System. Goodbye!";
                break;

            default:
                cout << "\n? Invalid Choice. Try Again.";
        }
    } while (choice != 4);

    return 0;
}
