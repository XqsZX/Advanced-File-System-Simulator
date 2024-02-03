# Studio 19
1. Xin Zhao(xin.zhao1@wustl.edu), Yifan Chen(chenyifan@wustl.edu)

2. File Creation and Initial Read Test, File Modification Test, File Verification Test, Cleanup Test

3. The client calls the accept method on the AbstractFile object, passing in the Visitor. 
   The AbstractFile object, knowing its own concrete type, calls the corresponding visit_<file_type> method on the Visitor, 
   passing this as the argument. The Visitor now has a concrete instance of AbstractFile, and it performs the appropriate action on it.

4. delegation refers to an object handing over its responsibilities to another, helper object. The visitor pattern uses delegation by having the file 
   (the element) delegate the display operation to the display visitor (the visitor). When a file object's accept method is called, it delegates the responsibility 
   of the display operation by invoking the visitor's visit method, which then has the logic to handle the display.

5. Each visitor class would need a new method to handle the new file type, which increases maintenance overhead, especially if there are many visitors.
   The visitor pattern might be a bad idea when there Are Many Different Visitors.
