# ASSIGNMENT 1

-> We have to find the value of nonce such that which when appended to a string, the resultant hash of the string is lesser than 0x00000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF

-> 3 Libraries are required, i.e., crypto-js, readline, and perf-hooks.

-> crypto-js library is required to calculate sha256 hash of a string.

-> readline library is used to take string as the input from the terminal.

-> perf-hooks library is used to calculate the time taken to find the nonce value.

### Procedure:

  &emsp; ---> First we require all the libraries to be used in our code.
  
  &emsp; ---> We then create the interface for readline function and using its question method, we take a string as an input from the terminal.
  
  &emsp; ---> We initialize the value of nonce to 0.
  
  &emsp; ---> A loop is run until we find the required string, i.e., string with the nonce appended to the input string whose hash value starts with 5 &emsp;&emsp;&emsp;&emsp;zeros, incrementing the 
      value of nonce by 1 in each iteration.
      
  &emsp; ---> We use performance.now() method from the perf-hooks library to find the starting time before the loop and the ending time after &emsp;&emsp;&emsp;&emsp; the loop, and subtracting them gives us the time it takes to find the nonce value in milisecond. Then, we console-log our results.
  
  ### Example: 
  
  &emsp;&emsp;&emsp;&emsp; If we input the string IITK, then we get the following results:
  
  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; The required nonce is 438251.
  
  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; The final string is IITK438251.
  
  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; The hash of the string + nonce is 00000ea354286b4e6f46212409f5c32a44c6e741b5d66984632be36a4abafc9c.
  
  &emsp;&emsp;&emsp;&emsp;&emsp;&emsp; Total time: 3580.1078000068665 in miliseconds.
