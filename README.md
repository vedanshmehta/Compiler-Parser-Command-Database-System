# Compiler-Parser-Command-Database-System
The parser receives a series of commands as input, involving the creation, deletion, modification, and display of shapes on the screen. Each command comprises an operation keyword and associated arguments, separated by one or more spaces. The program reads input from standard input, parses and verifies its correctness, prints a corresponding response or error message, and proceeds to create, delete, or modify Shape objects based on the specified commands. The command parser continuously processes input as long as it is available. The program serves as a basic "database" for objects, storing created shapes. This involves utilizing a Shape class to manage shape properties and dynamically allocating an array of pointers to Shape objects for tracking created and deleted shapes.  
The program aims to demonstrate:    
(1) Utilization of C++ I/O streams with error handling,    
(2) Implementation of a class with constructors, accessors, and mutators, and    
(3) Dynamic allocation and de-allocation of one-dimensional arrays.  
The number and type of arguments accepted depend on the command. The arguments and their permissible types/ranges are shown in the following table.  
![image](https://github.com/vedanshmehta/Compiler-Parser-Command-Database-System/assets/155503900/132237d2-6660-427f-8d18-1910da6b6835)  
The valid commands, their arguments, and their output (if the command and its arguments are all legal) are as follows:  
![image](https://github.com/vedanshmehta/Compiler-Parser-Command-Database-System/assets/155503900/6dc36e86-5bfd-42a0-a59e-7bf5cd2c0527)  
The software validates the input and detect and inform the user about specific input errors, prioritizing them based on a predefined order. In case multiple errors occur in a single input line, only the first encountered error is reported, progressing from left to right. If a single argument in the line could trigger multiple errors, only the first error listed in the table is reported. The sequence of errors to be reported, following priority order, includes:  
![image](https://github.com/vedanshmehta/Compiler-Parser-Command-Database-System/assets/155503900/03e217c7-d555-4a34-8877-7e17aafa69d7)  

>[!NOTE]
>The program is written in C++, and was given as a lab task under the course ECE244H1:Programming Fundamentals at University of Toronto. I hereby claim no authority over the credit of the header files created to mark the lab. The code is written completely by me and is protected under a liscence accordingly. The base code consists of a make file and .h file(s) which could not be edited, thus a property of University of Toronto. The images of the table given above are properties of University of Toronto as well.
