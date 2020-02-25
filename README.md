# Password-Manager 
# (Project period : 2018-04-15 ~ 2018-05-15)
Password Manager(Create a new password encryption technique)

contributors :
최재현,
고창훈,
서성관,
이소영,
곽근진 from sejong university



# 1. Overview
- Password Manager uses a file "password"to store the password

- However, the file may not yet exist the first time the program is executed.

- So when your main function starts, it should first try to input an encrypted password from the file “password”.

- If the file exists and contains a string, the program should set the encrypted password in the password manager.

- Otherwise it should set the password in the password manager to “sejong_security_2017!”.

- The menu should be processed in a loop, so the user may continue testing the password operations.
```lua
SejongPassword Manager:

A. Change Password
B. Validate Password
C. Quit

Enter your choice:

```


# 2. Menu Description
## 2.1 Change Password Menu
- The Change Password option should ask the user to enter a new password, and explain the criteria for a valid password.
- This menu should verify and change the password.
    * It should output a message indicating whether or not the password was changed.
    * If it was not changed, it should NOT repeat and ask the user to try again.
- To verify the password, you should make a function
    * It takes a string (a password) and returns true if it meets the following criteria:
      + it is at least 8 characters long
      + it contains at least one letter
      + it contains at least one digit
      + it contains at least one of these four characters: <, >, _, ?, !
    * Otherwise it returns false.

## 2.2 Validate Password Menu
- The Validate Password menu should ask the user to input the password. Then it validates the password, and then it should output whether or not the password was valid (matching the one stored by the password manager) or not. If it was not valid, it should NOT repeat and ask the user to try again.

## 2.3 Quit Menu
- When the user selects C to quit, the program should save the encrypted password in the file “password”(overwriting anything that was previously in the file).

# 3. Implementation Rule
## 3.1 Compile the code to run on Windows XP without dependency on .dll
- Reference for setting compile options
  * https://stackoverflow.com/questions/35664861/how-to-target-windows-xp-in-microsoft-visual-studio-c
  * https://stackoverflow.com/questions/35805113/visual-studio-2015-run-time-dependencies-or-how-to-get-rid-of-universal-crt
## 3.2 Do not apply anti-debugging techniques to your code
## 3.3 Do not apply obfuscation techniques to your code
## 3.4 The content of “password”should be encoded using ASC code as a string format.
- Do not use “hash” function
- Do not use “encryption” function from external libraries
