# Data-Structures-and-Algorithms
The code for the most commonly used data structures and algorithms is added here. 
To make the data structures, more reusable, I have a template class in c++ for each data structure and added the code there so you can use them in way you want.

# How to use the code?
For accessing a particular code in the folder, you just need to use the <b> include "folder_name/includer.hpp" </b> and use the code in that folder.  
Suppose, I want to use the code for all the data structures, just take out that folder of Data structures and place it in the code and when you want to including, just type, <b> include "Address_to_the_code/Data-Structures/includer.hpp"</b> and it includes the code for all the data structures. 
Suppose I want to use a specific structure or algorithm, so take that folder include the code same method.

# How to find the exact needed code?
The directory structure is simple. 
One .md file to explain and document the code. 
The includer.hpp file containing the reference to the library to be used. 
The code goes in src folder in .hpp files so we can include and use it. 
The test code go in the tests folder inside the data structure or algorithm. 
So, the over all folder for the a particular code folder have includer.hpp file, src folder, tests folder and an md file for explaination realted to it. 
Go on to the links in the Index and get to the place. 

# Some notes to consider:
* Compiler used: GNU/G++ for Linux, MinGW/G++ for Windows.
* Tested on OS: Linux(64 bit), Windows 10(64 bit)
* The Preprocessor macros are used in the includer.hpp files has Windows uses different format for paths. 
* The relatives paths are used. So, directory from where you are running things can matter. 

# Index:
<b> Data-Structures:</b>
* [Stack](https://github.com/HetDaftary/Data-Structures-and-Algorithms/tree/main/Data-Structures/Stack) 
* [Queue](https://github.com/HetDaftary/Data-Structures-and-Algorithms/tree/main/Data-Structures/Queue)
* [Linked-Lists](https://github.com/HetDaftary/Data-Structures-and-Algorithms/tree/main/Data-Structures/Linked-Lists)
