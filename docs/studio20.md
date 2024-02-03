# Studio 20
1. Xin Zhao(xin.zhao1@wustl.edu), Yifan Chen(chenyifan@wustl.edu)

2. Resource allocation should be tied to object lifetime. 
   Since PasswordProxy acquires the resource (the AbstractFile), it should release it when its own lifetime ends.

4. Test 1: Attempt to read the file through the proxy (without correct password)
   Result: Read test (without password) passed: Access denied

   Test 2: Attempt to write to the file through the proxy (with correct password)
   Result: return 0, indicating that the write operation was successful.

   Test 3: Display the file through the proxy (with correct password)
   Result: The file's content displayed when the password entered is correct.

