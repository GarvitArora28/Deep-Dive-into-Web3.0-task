///////////////////  LOANING SYSTEM  //////////////////////

#include <bits/stdc++.h>
using namespace std;

class LoaningSystem{    // Class for LoaningSystem

    protected:      // Client Specific Information is kept protected
                    // Can be accessed only by this class and derived classes
    int aadharNumber;
    int startingMonth;
    int startingYear;
    int time;           // in months
    double principal;   // For borrower, principal is the amount of loan
                        // For lender, it is the initial funds that she has
    double* transactions;   // Array to store the amount paid back for borrower
                            // and Amount lended by lender
    int numberOfTransactions; // Number of transactions


    public:             // Other info related to the Loan
    double interest;    // Simple interest in percentage
    int borrowerID;
    int lenderID;
    int loanID;

    LoaningSystem(){}   // default constructor

    // Constructor for a borrower (in general)
    LoaningSystem(int aadharNumber, int startingMonth, \
    int startingYear, int time, double principal,\
    double interest, int borrowerID, int lenderID, int loanID){
        this->aadharNumber = aadharNumber;      // "this" is self-pointer used to avoid ambiguity
        this->startingMonth = startingMonth;
        this->startingYear = startingYear;
        this->time = time;
        this->principal = principal;
        this->transactions = new double[120];   // Max loan time = 10 years
        this->numberOfTransactions = 0;
        this->interest = interest;
        this->borrowerID = borrowerID;
        this->lenderID = lenderID;
        this->loanID = loanID;
    }

    // Constructor for a lender (in general)
    LoaningSystem(int aadharNumber, int principal, double interest, int lenderID){
        this->aadharNumber = aadharNumber;
        this->principal = principal;
        this->interest = interest;
        this->lenderID = lenderID;
        this->transactions = new double[1000];
        this->numberOfTransactions = 0;
    }

    // Operator overloading to check which lender has more money
    // or which borrower has borrowed more money
    bool operator > (const LoaningSystem& other){
        if(principal >= other.principal){
            return true;
        }else{
            return false;
        }
    }
    bool operator < (const LoaningSystem& other){
        if(principal <= other.principal){
            return true;
        }else{
            return false;
        }
    }
    bool operator == (const LoaningSystem& other){
        if(principal == other.principal){
            return true;
        }else{
            return false;
        }
    }

    // Amount of each installment to be paid by borrower
    double installments(){
        return (principal)*(1+interest*time/1200)/time;
    }

    // Time left for the loan to be repaid
    void timeRemaining(int currentMonth, int currentYear){
        int timePassed = 12*(currentYear-startingYear) + (currentMonth-startingMonth);
        if(timePassed<0) cout<<"Invalid\n";
        else if(timePassed>time) cout<<"Completed\n";
        else cout<<"Time remaining: "<<(time-timePassed)<<" months"<<endl;        
    }

    // Amount to be paid by borrower and funds left with lender
    int remainingAmount(){
        int paid = 0;
        for(int i=0; i<numberOfTransactions; i++){
            paid += transactions[i];
        }
        return principal - paid;
    }

    // Only for borrower
    virtual void loanDetails(){     // Used because a function with same name present in derived class
        cout<<"LoanID is: "<<(loanID)<<endl;
        cout<<"BorrowerID is: "<<(borrowerID)<<endl;
        cout<<"LenderID is: "<<(lenderID)<<endl;
        cout<<"Principal is: "<<(principal)<<endl;
        cout<<"Installment amount is: "<<this->installments()<<endl;
        cout<<"Amount left to be paid: "<<remainingAmount()<<endl;
    }

    virtual void loanDetails(int currentMonth, int currentYear){     // Used because a function with same name present in derived class
        cout<<"LoanID is: "<<(loanID)<<endl;
        cout<<"BorrowerID is: "<<(borrowerID)<<endl;
        cout<<"LenderID is: "<<(lenderID)<<endl;
        cout<<"Principal is: "<<(principal)<<endl;
        cout<<"Installment amount is: "<<this->installments()<<endl;
        cout<<"Amount left to be paid: "<<remainingAmount()<<endl;
        timeRemaining(currentMonth, currentYear);
    }

    // Lender Details
    void lenderDetails(){
        cout<<"LenderID is: "<<(lenderID)<<endl;
        cout<<"Rate of interest is: "<<interest<<endl;
        cout<<"Original Amount was: "<<(principal)<<endl;
        cout<<"Amount left with lender: "<<remainingAmount()<<endl;
    }


    // To show the clients their transactions
    void showTransactionDetails(){
        for(int i=0; i<numberOfTransactions; i++){
            cout<<"Transaction "<<i+1<<"amount is: "<<transactions[i]<<endl;
        }
    }

    // To add transactions for clients
    void addTransaction(int amount){
        numberOfTransactions++;
        transactions[numberOfTransactions-1] = amount;
    }

    ~LoaningSystem(){
        delete[] transactions;
    }

};


// Specific Class for Borrowers of Home Loan and Lenders Dealing in home loans
class HomeLoan: public LoaningSystem{

    private:   // private is used instead of protected because no derived classes
    string address;             //property address
    string documentProof;       //property document proof
    string name;

    public:
    // Constructor for a borrower (for Home Loan)
    HomeLoan(string name, string address, string document, int aadharNumber, int startingMonth, \
    int startingYear, int time, double principal,\
    double interest, int borrowerID, int lenderID, int loanID){
        this->name = name;
        this->address = address;
        this->documentProof = document;
        this->aadharNumber = aadharNumber;
        this->startingMonth = startingMonth;
        this->startingYear = startingYear;
        this->time = time;
        this->principal = principal;
        this->transactions = new double[120];   // Max loan time = 10 years
        this->numberOfTransactions = 0;
        this->interest = interest;
        this->borrowerID = borrowerID;
        this->lenderID = lenderID;
        this->loanID = loanID;
    }

    // Constructor for a lender
    HomeLoan(string name, int aadharNumber, int principal, double interest, int lenderID){
        this->name = name;
        this->aadharNumber = aadharNumber;
        this->principal = principal;
        this->interest = interest;
        this->lenderID = lenderID;
        this->transactions = new double[1000];
        this->numberOfTransactions = 0;
    }

    // To change the property address of the borrower
    void changeAddress(string s){
        address = s;
    }

    // Show property Details
    void propertyDetails(){
        cout<<"Name: "<<name<<endl;
        cout<<"Property Address: "<<address<<endl;
        cout<<"Document Type: "<<documentProof<<endl;
    }

    // Loan Details
    void loanDetails(){
        cout<<"Name of the borrower is: "<<name<<endl;
        cout<<"LoanID is: "<<(loanID)<<endl;
        cout<<"BorrowerID is: "<<(borrowerID)<<endl;
        cout<<"LenderID is: "<<(lenderID)<<endl;
        cout<<"Principal is: "<<(principal)<<endl;
        cout<<"Installment amount is: "<<this->installments()<<endl;
        cout<<"Amount left to be paid: "<<remainingAmount()<<endl;
    }

    void loanDetails(int currentMonth, int currentYear){
        cout<<"Name of the borrower is: "<<name<<endl;
        cout<<"LoanID is: "<<(loanID)<<endl;
        cout<<"BorrowerID is: "<<(borrowerID)<<endl;
        cout<<"LenderID is: "<<(lenderID)<<endl;
        cout<<"Principal is: "<<(principal)<<endl;
        cout<<"Installment amount is: "<<this->installments()<<endl;
        cout<<"Amount left to be paid: "<<remainingAmount()<<endl;
        timeRemaining(currentMonth, currentYear);
    }
    
    ~HomeLoan(){
        delete[] transactions;
    }

};

class StudentLoan: public LoaningSystem{

    private:
    string name;
    int studentRollNumber;
    string educationQualification;

    public:

    // Constructor for a borrower
    StudentLoan(string name, int studentRollNumber, string educationQualification,\
    int aadharNumber, int startingMonth, \
    int startingYear, int time, double principal,\
    double interest, int borrowerID, int lenderID, int loanID){
        this->name = name;
        this->studentRollNumber = studentRollNumber;
        this->educationQualification = educationQualification;
        this->aadharNumber = aadharNumber;
        this->startingMonth = startingMonth;
        this->startingYear = startingYear;
        this->time = time;
        this->principal = principal;
        this->transactions = new double[120];   // Max loan time = 10 years
        this->numberOfTransactions = 0;
        this->interest = interest;
        this->borrowerID = borrowerID;
        this->lenderID = lenderID;
        this->loanID = loanID;
    }

    // Constructor for a lender
    StudentLoan(string name, int aadharNumber, int principal, double interest, int lenderID){
        this->name = name;
        this->aadharNumber = aadharNumber;
        this->principal = principal;
        this->interest = interest;
        this->lenderID = lenderID;
        this->transactions = new double[1000];
        this->numberOfTransactions = 0;
    }
    
    //To change the educational qualification of the borrower
    void changeEducationalQualification(string s){
        educationQualification = s;
    }

    // Function to show Student details
    void studentDetails(){
        cout<<"Student Name is: "<<name<<endl;
        cout<<"Educational Qualification is: "<<educationQualification<<endl;
        cout<<"Roll number of student is: "<<studentRollNumber<<endl;
    }

    // To show student loan details
    void loanDetails(){
        cout<<"Name of the borrower is: "<<name<<endl;
        cout<<"Roll number of the student is: "<<studentRollNumber<<endl;
        cout<<"LoanID is: "<<(loanID)<<endl;
        cout<<"BorrowerID is: "<<(borrowerID)<<endl;
        cout<<"LenderID is: "<<(lenderID)<<endl;
        cout<<"Principal is: "<<(principal)<<endl;
        cout<<"Installment amount is: "<<this->installments()<<endl;
        cout<<"Amount left to be paid: "<<remainingAmount()<<endl;
    }
    
    ~StudentLoan(){
        delete[] transactions;
    }

};

int main(){
    
    LoaningSystem lender1(12121,1000, 10, 1);
    LoaningSystem lender2(121,1200, 10, 2);

    if(lender1>lender2){
        cout<<"Lender 1 has more money than lender 2\n";
    }else{
        cout<<"Lender 2 has more money than lender 1\n";
    }

    lender1.addTransaction(100);
    lender1.lenderDetails();
    cout<<endl;

    HomeLoan h1("Rahul","Kanpur", "Pan Card", 101, 1, 2022, 12, 1000, 10, 1, 2, 1);
    HomeLoan h2("Ram","Delhi", "Voter Card", 102, 5, 2022, 24, 500, 5, 2, 1, 2);
    
    h1.loanDetails(2,2022);
    cout<<endl;
    h1.propertyDetails();
    cout<<endl;

    StudentLoan s1("Divya",48, "MBBS", 103, 2, 2022, 60, 10000, 5, 3, 1, 3);
    StudentLoan s2("Garvit",372, "B. Tech", 104, 3, 2022, 30, 10000, 7.5, 4, 3, 4);

    if(s1==s2){
        cout<<"Student 1 and 2 have taken the same amount of loan!\n";
    }
    cout<<endl;
    cout<<"Student 1 details are: \n";
    s1.loanDetails();
    cout<<endl;
    cout<<"Student 2 details are: \n";
    s2.loanDetails();
    cout<<endl;

    return 0;
}
