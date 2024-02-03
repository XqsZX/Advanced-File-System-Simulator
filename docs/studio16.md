# Studio 16
1. Xin Zhao(xin.zhao1@wustl.edu), Yifan Chen(chenyifan@wustl.edu)

2. a. The AbstractFile class will be declared as an abstract base class, 
   which contains pure virtual functions that define the interface for file operations.

3. a. It is an example of "interface inheritance".
   b. The member variables in the TextFile class should be private.This can ensures encapsulation.

4. I create a textfile and write a vector<char>(Hello World!) into it, and print it out:
   Write operation successful.
   Reading from the file:
   Hello World!

5. Create a pointer of type AbstractFile and assign it to point to the TextFile instance:
   AbstractFile* filePtr = &myTextFile;

