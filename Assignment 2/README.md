# ASSIGNMENT 2

-> getOwnerBalance(), viewDues() functions are view functions because they require to read the state variables but not alter them. To give only read access of the state variables to these functions, view has been used.

-> nulDiv(), getCompoundInterest() functions are pure functions because no read or update request to any of the state variables is required to execute it. And to prevent both of these by any chance, pure has been used.

-> reqLoan(), settleDues() functions have none of the above keywords because both updating the state variables is to be done inside them and thus they cannot be pure or view.


