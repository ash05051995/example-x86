# Example Information

Main tool used hex editor, to modify .text values of our application, by replacing the correct bytes with random bytes. Sadly the x86 lib struggles for support with certain functions within auth.cpp to my own knowledge, feel free to correct me if I'm wrong. 

There for certain Xor strings were removed during the curl initialization to prevent errors, as well as the integrity check. 

The library x86 lib within this example has a modified version of the ic which will help add an extra layer of protection.

![image](https://raw.githubusercontent.com/ash05051995/example-x86/main/view.gif)

# Debugging And Thoughts

So The code only checks the integrity of a specific section of the module, specified by the section_name parameter (.text). This means that if the tampering occurred in a different section, the code will not detect it. The code only checks the integrity of the module when it is first loaded into memory. If the tampering occurs after the module is loaded, the code will not detect it, unless used within a thread or loop.

To debug the program to verify it works I used the code below to preform the check

```int main()
{
    if (check_section_integrity(".text", false))
    {
        MessageBox(NULL, "Do not tamper with this application!", "Error", MB_OK | MB_ICONERROR);
        return 0;
    }
    // Your application code here
    return 0;
}```

![image](https://raw.githubusercontent.com/ash05051995/example-x86/main/debug.gif)

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

* Open x86 Native Tools Command Prompt for VS 2022 and then open the curl folder you need to use command "cd " then add the (winbuild) folder example here: ```cd C:\Users\Ash\Desktop\curl-7.87.0\winbuild```

* Use the below command to build curl for x86 machine code, static. ```nmake /f Makefile.vc mode=static VC=15 debug=no machine=x86```

* Once curl has been built go to the (builds) folder then the (libcurl-vc15-x86-release-static-ipv6-sspi-schannel) here you will find the (include) folder and the (lib) folder. You need need to replace the x64 lib curl header files as well as the curl lib for this to work so just drag and drop and rename the lib file to (libcurl) most likly the new lib you compiled will have the name of (libcurl_a). This will save you from eiditing any properties.

* In the (auth.cpp) file in the library example make sure you remove the xor strings from the following https://github.com/KeyAuth/keyauth-cpp-library/blob/aef1fa7e0ff6e756d43f4b21f659e1264afdcc1a/auth.cpp#L1036 and https://github.com/KeyAuth/keyauth-cpp-library/blob/aef1fa7e0ff6e756d43f4b21f659e1264afdcc1a/auth.cpp#L1045 this will help prevent errors.

* Remove the integrity check to also prevent errors found here https://github.com/KeyAuth/keyauth-cpp-library/blob/aef1fa7e0ff6e756d43f4b21f659e1264afdcc1a/auth.cpp#L1219 and here https://github.com/KeyAuth/keyauth-cpp-library/blob/aef1fa7e0ff6e756d43f4b21f659e1264afdcc1a/auth.cpp#L1223

If the above steps are followed correctly you will now be able to run your example using the x86 lib of course you must replace the (library_x64.lib) with your new lib (library_x86).
