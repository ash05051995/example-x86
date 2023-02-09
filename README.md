# Example Information

Main tool used hex editor, to modify .text values of our application, by replacing the correct bytes with random bytes. Sadly the x86 lib struggles for support with certain functions within auth.cpp to my own knowledge, feel free to correct me if I'm wrong. 

There for certain Xor strings were removed during the curl initialization to prevent errors, as well as the integrity check. 

The library x86 lib within this example has a modified version of the ic which will help add an extra layer of protection.

![image](https://raw.githubusercontent.com/ash05051995/example-x86/main/view.gif)

# About the extra layer of protection

It checks the integrity of a section of a module in memory and potentially repairs it. In auth.cpp in the standard lib the module used is (.text) see here https://github.com/KeyAuth/keyauth-cpp-library/blob/aef1fa7e0ff6e756d43f4b21f659e1264afdcc1a/auth.cpp#L1219

The section is specified by its name, in our case as above (.text). The function retrieves a handle to the module using GetModuleHandle and gets the base address of the module. It then reads the module header and verifies that it is a valid module by checking the "DOS signature" and the "NT signature".

Next, the function iterates over all sections in the module, and if the name of the current section matches section_name and it is executable, the code will compare the contents of the section in memory with the contents of the same section in the file on disk. If any difference is found, and fix is true, the code will modify the in-memory copy to match the disk copy.

The function returns false if the section is found to be intact, otherwise it returns true.

# Extra Information

Compile curl if you wish to do this your self:

* Open native tools x86 which can be found here most likely C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2022\Visual Studio Tools\VC
note Visual Studio must be installed.

* Download curl from this link here: https://curl.se/download.html

* Open x86 Native Tools Command Prompt for VS 2022 and then open the curl folder you need to use command "cd " then add the (winbuild) folder example here: 

```cd C:\Users\Ash\Desktop\curl-7.87.0\winbuild```

* Use the below command to build curl for x86 machine code, static.

```nmake /f Makefile.vc mode=static VC=15 debug=no machine=x86```
