# Example Information

Main tool used hex editor, to modify .text values of our application, by replacing the correct bytes with random bytes. Sadly the x86 lib struggles for support with certain functions within auth.cpp to my own knowledge, feel free to correct me if I'm wrong. 

There for certain Xor strings were removed during the curl initialization to prevent errors, as well as the integrity check. 

The library x86 lib within this example has a modified version of the ic which will help add an extra layer of protection.
