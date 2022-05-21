# Deep-Dive-into-Web3.0-task

/////////////////////////////////////////////////////    LOANING SERVICE     //////////////////////////////////////////

This code is a program for a loaning service.

The main features of the code are:

-> There is a general class called "LoaningSystem", through which all different kinds of borrowers' and lenders' objects can be made. Separate constructors for both have been implemented.

-> This "LoaningSystem" class has 2 derived subclasses by the name of "HomeLoan" and "StudentLoan", which are specifically for the borrowers and lenders who want Home Loans and Student Loans respectively. (Inheritance)

-> In the "LoaningSystem" class, some of the variables which are confidential for clients have been kept as protected, so that they cannot be directly accessed but can be accessed by derived subclasses of the class. The other variables and functions which are not confidential have been kept as public. Anyone can access them.

-> Constructor overloading has been done to make separate constructors for lenders and borrowers. Moreover, default constructor is also written which is needed by derived class constructors. Copy constructor has also been implemented in "LoaningSystem".

-> Destructors have been used to free up memory after completion of the program. They were required because memory was allocated dynamically.

-> Operator overloading has been done for > , < and == operators to check:

    -> for lenders, who has more initial amount.
		
    -> for borrowers, who has borrowed more money.

-> Functional overloading has been done for the function loan details:

    -> if user enters current month and year, then remaining time to pay the loan will be shown.
		
    -> if not, then all other details except this will be shown.

-> The loanDetails function has been created as a virtual function in "LoaningSystem" class because a function by the same name has to be used in the derived 					classes. 
		So to call that function instead of the one present in "LoaningSystem", virtual function has been used.

-> The function installments calculates the amount of installments to be paid each month by the borrower.

-> The function timeRemaining calculates the remaining time in months given current month and year.

-> The function lenderDetails gives the information about the lender.

-> The function showTransactionDetails shows all the transactions of borrowers as well as lenders till date.

-> The function addTransactions add new transactions made to the array of transactions.


In HomeLoan Class:

-> We have 3 separate variables for storing information specific to Home Loans.

-> Separate constructors for lenders and borrowers.

-> The function changeAddress can be used to change the address of the borrower.

-> The function propertyDetails provide the details of the property.


Similar functions have been used in class StudentDetails also.


Some of the functions have been called from the main function to show their working.
The functionality of other functions can be easily verified by calling them similarly.





Que:  Is the loaning system that you implemented centralized or decentralized? Point out the demerit(s) of a centralized system.

Ans:  The implemented Loaning System is a centralized system because a single entity has full control over it.

   Demerits of Centralized System are:
			
      -> We have to trust the organisation that our data will not be tampered with. (third-party trust)
			
      -> If the whole data is stored in just one place and there are no replicas of it, then, there is a possibility of loss of data.
			
      -> Also it is more prone to hacks in this case.
			
      -> The activities of the organisation may not be very transparent.
