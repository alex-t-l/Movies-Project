# Self-Evaluation

## Name(s): Alex Lai

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes/No

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 0

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: 0

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: -2
No memory leaks detected using G++. 


- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0
Alex: The code not ran is just edge cases. Please mind these chunks of code, all methods are tested in storetest.cpp.

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: Store.cpp processTransactions line 344

invalid movie type: Store.cpp fillInventory line 54, processTransactions line 209, line 339

invalid customer ID: Store.cpp fillStoreWithCustomers line 79
 
invalid movie: Store.cpp fillInventory line 54, processTransactions line 338

factory classes: n/a

hashtable: HashTable.h is used to store customer ID as the key and customer Object as value.

container used for comedy movies: Inventory.h line 74 : three vectors, one for each genre.

function for sorting comedy movies:  Inventory.cpp sortComedy (line 176) returns boolean, used with std::sort, functions overloaded inside of Comedy.h.

function where comedy movies are sorted: Inventory.cpp line 184,  calls std::sort for all shelves of movies.

functions called when retrieving a comedy movie based on title and year: You first get the index of the comedy movie in vector, calling indexOfComedy(title, year) (line 116), this returns an int. You then call getComedyMovie(index) (line 160) and pass in your index which you retrieved from indexOfComedy here.

functions called for retrieving and printing customer history: Customer.cpp line 20 is outputHistory.

container used for customer history: Customer.h line 41: container used is vector of Transaction* objects.

functions called when borrowing a movie: Inventory.cpp line 59 borrowMovie function is called. Calls movies' setter functions to get new stock amount and detects if stock is zero just in case they try to borrow a movie that is not in stock.  Returns a boolean depending on whether or not the borrow was successful.

explain borrowing a movie that does not exist: Store.h processTransactions line 125, 158, 187

explain borrowing a movie that has 0 stock: Inventory.cpp borrowMovie line 62, 73, 84.

explain returning a movie that customer has not checked out: Store.cpp processTransactions line 258, 296, 329.

any static_cast or dynamic_cast used: Classic.h, equals method line 45, lessThan method line 56, greaterThan method line 75.


Q: Total points: 23 (max 25)
