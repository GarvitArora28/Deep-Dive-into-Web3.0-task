# ASSIGNMENT 2

### View, Pure or None
* getOwnerBalance(), viewDues() functions are view functions because they require to read the state variables but not alter them. To give only read access of the state variables to these functions, view has been used.

* nulDiv(), getCompoundInterest() functions are pure functions because no read or update request to any of the state variables is required to execute it. And to prevent both of these by any chance, pure has been used.

* reqLoan(), settleDues() functions have none of the above keywords because both updating the state variables is to be done inside them and thus they cannot be pure or view.

### getCompoundInterest() function:
 * In order to implement this function, and to prevent overflows as much as possible while maintaining good precision, mulDiv() function has been used. Also the parameters have been type-casted to uint256.
 * In each iteration of a for loop which runs numberOfYears times, we add the interest to the principal after each year and compute the interest again for the next year using that updated principal to get the final loan amount to be paid after "time" numberOfYears.
 * This is a pure function and visibility is public, so, it can be called from anywhere both inside and outside this contract.

### reqLoan() function:
* We first calculate the amount to be paid to the creditor using the getCompoundInterest() function.
* We check if the amount found is more than or equal to the principal and that rate is indeed an integer. If not, we return false.
* Else we add the creditor with the loan amount to be paid to him in the loans mapping and emit the Request with appropriate parameters and then return true.
* This is neither a pure nor view function.

### getOwnerBalance() function:
* We get the balance of the owner using the getBalance() function from the MetaCoin contract. We could have also used super keyword to do so but because there was no ambiguity, MetaCoin was directly used.
* This is a view function.

### viewDues() function:
* This function returns the due amount of loan to be paid to a creditor. We simply access the value through mapping and return it.
* isOwner modifier has been used to restrict the access of this function to the owner.
* This is a view function.

### settleDues() function:
* We call the sendCoin() function of the MetaCoin contact directly (no ambiguity) to send the dueAmount of creditor (accessed using the loans mapping) from owner to creditor to settle the loan.
* If there is no error and sendCoin() function returns true, we return the same boolean, setting the due loan amount for that creditor in the loans mapping to zero.

### Testing:
* To test the code just compile it in remix and deploy it. The current address would be owner.
* Change the address to act like a creditor and call all the function with appropriate parameters, they would work.

#### Thank you!
