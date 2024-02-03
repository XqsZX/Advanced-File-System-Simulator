# Lab 5
Name: Xin Zhao(xin.zhao1@wustl.edu), Yifan Chen(chenyifan@wustl.edu)

We choose the option "b. Touch + cat - create a file and edit it immediately.", users can input touchcat command to invoke it, the test cases will show below.

Warnings and Errors:
1. Error (Active) E0289 No constructor "CopyCommand::CopyCommand" matching parameter list Instance lab5.exe (src\lab5.exe) - x64-Debug C:\cygwin\home\15245\oop-work-lab5_xin_zhao_yifan_chen\src \Lab5.cpp 24
2. Error LNK2001 Unresolved external symbol "public: virtual class std::vector<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >,class std::allocator< class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > > > __cdecl TouchCatParsingStrategy::parse(class std::basic_string<char,struct std::char_traits<char> ,class std::allocator<char> >)"
3. error: Expected equality of these values:
  contentsStr
    Which is: "foo"
  userInput
    Which is: "hello world"
[  FAILED  ] catCommand.executeTextFileNAppendSaving (0 ms)
4. error: Expected equality of these values:
  contentsStr
    Which is: "helloworldmultiplelines"
  userInput
    Which is: "hello\nworld\nmultiple\nlines"
With diff:
@@ -1,1 +1,4 @@
-helloworldmultiplelines
+hello
+world
+multiple
+lines
5. C:\cygwin\home\15245\oop-work-lab5_xin_zhao_yifan_chen\tests\Lab5.cpp(1684): error: Expected: (0) != (cc->execute(executeInput)), actual: 0 vs 0
[  FAILED  ] catCommand.executeImageFileAppendSavingGoodInput (1 ms)
6. error: Expected equality of these values:
  v[i]
    Which is: 'h' (104, 0x68)
  c
    Which is: 'f' (102, 0x66)
[  FAILED  ] DSCommand.displaytext (0 ms)
7. [ RUN      ] catCommand.executeImageFileAppendSavingGoodInput
C:\cygwin\home\15245\oop-work-lab5_xin_zhao_yifan_chen\tests\Lab5.cpp(1684): error: Expected: (0) != (cc->execute(executeInput)), actual: 0 vs 0
[  FAILED  ] catCommand.executeImageFileAppendSavingGoodInput (1 ms)

Test cases:
Case1:
Input: help
Output:
cat
cp
ds
ls
rm
rn
touch
touchcat
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Case2:
Input: help cat
Output: cat concatenates a file's contents or appends data to it. Usage: cat <filename> [-a]
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Case3:
Input: help cp
Output: Copies a file. Usage: cp <file_to_copy> <new_name_with_no_extension>
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Case4:
Input: help ds
Output: 
Displays the contents of a file. Usage: ds <filename> [-d]
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Case5:
Input: help ls
Output: 
ls displays the names of all files in the system, ls -m displays names and metadata
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Case6:
Input: help rm 
Output:
Removes a file from the file system. Usage: rm <filename>
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Case7:
Input: help touch
Output:
touch creates a file, touch can be invoked with the command: touch <filename>, touch -p can encrypt file.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Case8:
Input: help touchcat
Output:
Executes a series of commands. Usage depends on the configured commands and parsing strategy.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Case9:
$ touch file.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ touch file.img -p
What is the password? 123
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ Command not found.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ help ls
ls displays the names of all files in the system, ls -m displays names and metadata
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls
file.img            file.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat file.txt
Enter data (':wq' to save and quit, ':q' to quit without saving):
hello
:wqw
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat file.txt -a
hello
:wqw
Enter data (':wq' to save and quit, ':q' to quit without saving):
world
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat file.img
Enter data (':wq' to save and quit, ':q' to quit without saving):
X X 2
:wq
Enter password: 123
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ Command not found.
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cp file.txt test
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls
file.img            file.txt
test.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ cat test.txt -a
hello
:wqwworld
Enter data (':wq' to save and quit, ':q' to quit without saving):
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ rm test.txt
Attempting to delete: 'test.txt'
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls
file.img            file.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.

Case10:
$ touchcat file.txt
Enter data (':wq' to save and quit, ':q' to quit without saving):
hello world
:wq
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls
file.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ rn file.txt test
Attempting to delete: 'file.txt'
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
$ ls
test.txt
Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command.
