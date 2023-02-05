# KeyAuth-CPP-Example x86

KeyAuth C++ example for the https://keyauth.cc authentication system.

The source code of the static library for KeyAuth is here https://github.com/KeyAuth/keyauth-cpp-library

# Bugs

If the default example not added to your software isn't functioning how it should, please join the Discord server https://discord.gg/keyauth and submit the issue in the #bugs channel.

However, we do NOT provide support for adding KeyAuth to your project. If you can't figure this out you should use Google or YouTube to learn more about the programming language you want to sell a program in.

# Security practices

* Utilize obfuscation provided by companies such as VMProtect or Themida (utilize their SDKs too for greater protection)
* Preform frequent integrity checks to ensure the memory of the program has not been modified
* Don't write the bytes of a file you've downloaded to disk if you don't want that file to be retrieved by the user. Rather, execute * * the file in memory and erase it from memory the moment execution finishes

KeyAuth is provided in Source Code Form. The burden of client-side protection is on you the software developer, as it would be with any authentication system.

# Copyright License

KeyAuth is licensed under Elastic License 2.0

* You may not provide the software to third parties as a hosted or managed service, where the service provides users with access to any substantial set of the features or functionality of the software.

* You may not move, change, disable, or circumvent the license key functionality in the software, and you may not remove or obscure any functionality in the software that is protected by the license key.

* You may not alter, remove, or obscure any licensing, copyright, or other notices of the licensor in the software. Any use of the licensor’s trademarks is subject to applicable law.

Thank you for your compliance, we work hard on the development of KeyAuth and do not appreciate our copyright being infringed.

# What is KeyAuth?

KeyAuth is an Open source authentication system with cloud hosting plans as well. Client SDKs available for C#, C++, Python, Java, JavaScript, VB.NET, PHP, Rust, Go, Lua, Ruby, and Perl. KeyAuth has several unique features such as memory streaming, webhook function where you can send requests to API without leaking the API, discord webhook notifications, ban the user securely through the application at your discretion. Feel free to join https://discord.gg/keyauth if you have questions or suggestions.

# KeyAuthApp instance definition

Visit https://keyauth.cc/app/ and select your application, then click on the C++ tab

It'll provide you with the code which you should replace with in the [main.h](https://github.com/ash05051995/example-x86-/blob/main/example%20x86/main.h) file

```
std::string name = "example"; // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = "JjPMBVlIOd"; // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = "db40d586f4b189e04e5c18c3c94b7e72221be3f6551995adc05236948d1762bc"; // app secret, the blurred text on licenses tab and other tabs
std::string version = "1.0"; // leave alone unless you've changed version on website
std::string url = "https://keyauth.win/api/1.2/"; // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);
```

# Initialize application

You must call this function prior to using any other KeyAuth function. Otherwise the other KeyAuth function won't work.

```
KeyAuthApp.init();
if (!KeyAuthApp.data.success)
{
	std::cout << skCrypt("\n Status: ") << KeyAuthApp.data.message;
	Sleep(1500);
	exit(0);
}
```
