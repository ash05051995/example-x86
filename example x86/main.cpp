#include "main.h"

/* 
   I'll update this program from time to time, but for now there's something bugging me with the code 
   and also which many people fail to understand.
   The use of  (standard) on each line is use of bad practice... You should use name spaces rather
   than using (lib) on each line....
*/

/* 
   Use namespace if using multiple scopes from the std namespace
   using namespace std;
*/

/* 
   std::count (pronounced "standard see-out") to write simple text
   std::cin (pronounced "standard see-in") to read text and numbers entered using the keyboard
   std::endl (pronounced "standard end-line) to end current line
*/

using std::cout, std::string, std::cin;

int main()
{
	string title = (string)skCrypt("Loader - Built at:  ") + compilation_date + " " + compilation_time;
	SetConsoleTitleA(title.c_str());

	cout << skCrypt("\n connecting..");
	KeyAuthApp.init();

	if (!KeyAuthApp.data.success)
	{
		cout << skCrypt("\n status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

	if (KeyAuthApp.checkblack()) {
		abort();
	}

	system("cls");

	cout << skCrypt("\n app data:");
	cout << skCrypt("\n users: ") << KeyAuthApp.data.numUsers;
	cout << skCrypt("\n online users: ") << KeyAuthApp.data.numOnlineUsers;
	cout << skCrypt("\n total keys: ") << KeyAuthApp.data.numKeys;
	cout << skCrypt("\n app version: ") << KeyAuthApp.data.version;
	cout << skCrypt("\n\n ");

	if (check_key())
	{
		read_key();

		cout << skCrypt("key found, attempting to auto login...");
		Sleep(2000);

		KeyAuthApp.license(license);
	}
	else
	{
		cout << skCrypt("input license: ");
		cin >> license;
		KeyAuthApp.license(license);
	}

	if (!KeyAuthApp.data.success)
	{
		string msg = KeyAuthApp.data.message;
		transform(msg.begin(), msg.end(), msg.begin(), [](unsigned char c) { return tolower(c); });

		cout << skCrypt("\n\n status: ") << msg;
		Sleep(1500);

		delete_key();
		exit(0);
	}
	else
	{
		save_key();
	}

	system("cls");

	cout << skCrypt("\n user data:");
	cout << skCrypt("\n username: ") << KeyAuthApp.data.username;
	cout << skCrypt("\n ip address: ") << KeyAuthApp.data.ip;
	cout << skCrypt("\n hardware id: ") << KeyAuthApp.data.hwid;
	cout << skCrypt("\n creation date: ") << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.createdate)));
	cout << skCrypt("\n last login: ") << tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.lastlogin)));
	cout << skCrypt("\n sub name(s): ");

	string subs;
	for (string value : KeyAuthApp.data.subscriptions)subs += value + " ";
	cout << subs;
	
	for (int i = 0; i < KeyAuthApp.data.subscriptions.size(); i++) 
	{
		auto sub = KeyAuthApp.data.subscriptions.at(i);
		string expiry = remove_letters(tm_to_readable_time(timet_to_tm(string_to_timet(sub.expiry))));
		cout << skCrypt("\n\n subscription expiry:") << expiry.c_str();
	}

	KeyAuthApp.check();

	string msg = KeyAuthApp.data.message;
	transform(msg.begin(), msg.end(), msg.begin(), [](unsigned char c) { return tolower(c); });

	cout << skCrypt("\n session validation: ") << msg;

    #pragma region example functions
	/*
	cout << "\n Waiting for user to login";
	KeyAuthApp.web_login();

	cout << "\n Waiting for button to be clicked";
	KeyAuthApp.button("close");
	*/

	/*
	for (string subs : KeyAuthApp.data.subscriptions)
	{
		if (subs == "default")
		{
			cout << skCrypt("\n User has subscription with name: default");
		}
	}
	*/


	/*
	// download file, change file.exe to whatever you want.
	// remember, certain paths like windows folder will require you to turn on auto run as admin https://stackoverflow.com/a/19617989

	vector<uint8_t> bytes = KeyAuthApp.download("362906");

	if (!KeyAuthApp.data.success) // check whether file downloaded correctly
	{
		cout << skCrypt("\n\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}

	ofstream file("file.dll", ios_base::out | ios_base::binary);
	file.write((char*)bytes.data(), bytes.size());
	file.close();
	*/


	// KeyAuthApp.setvar("discord", "test#0001"); // set the value of user variable 'discord' to 'test#0001'
	// string userVar = KeyAuthApp.getvar("discord");
	// if (!KeyAuthApp.data.success) // check whether user variable exists and was retrieved correctly
	// {
	// 	cout << skCrypt("\n\n Status: ") << KeyAuthApp.data.message;
	// 	Sleep(1500);
	// 	exit(0);
	// }
	// cout << "\n user variable - " + userVar; // get value of the user variable 'discord'

	/*
	// let's say you want to send request to https://keyauth.win/api/seller/?sellerkey=f43795eb89d6060b74cdfc56978155ef&type=black&ip=1.1.1.1&hwid=abc
	// but doing that from inside the loader is a bad idea as the link could get leaked.
	// Instead, you should create a webhook with the https://keyauth.win/api/seller/?sellerkey=f43795eb89d6060b74cdfc56978155ef part as the URL
	// then in your loader, put the rest of the link (the other paramaters) in your loader. And then it will send request from KeyAuth server and return response in string resp

	// example to send normal request with no POST data
	string resp = KeyAuthApp.webhook("5iZMT1f1XW", "?mak=best&debug=1");

	// example to send form data
	resp = KeyAuthApp.webhook("5iZMT1f1XW", "", "type=init&ver=1.0&name=test&ownerid=j9Gj0FTemM", "application/x-www-form-urlencoded");

	// example to send JSON
	resp = KeyAuthApp.webhook("5iZMT1f1XW", "", "{\"content\": \"webhook message here\",\"embeds\": null}", "application/json");
	if (!KeyAuthApp.data.success) // check whether webhook request sent correctly
	{
		cout << skCrypt("\n\n Status: ") << KeyAuthApp.data.message;
		Sleep(1500);
		exit(0);
	}
	cout << "\n Response recieved from webhook request: " + resp;
	*/

	// get data from global variable with name 'status'
	// cout << "\n status - " + KeyAuthApp.var("status");

	// KeyAuthApp.log("user logged in"); // send event to logs. if you set discord webhook in app settings, it will send there instead of dashboard
	// KeyAuthApp.ban(); // ban the current user, must be logged in
	// KeyAuthApp.ban("Don't try to crack my loader, cunt."); // ban the current user (with a reason), must be logged in

	/*
	// allow users to communicate amongst each other with through KeyAuth. Thank you Nuss31#1102 for this C++ implementation
	// send chat messages
	cout << skCrypt("\n Type Chat message: ");
	string message;
	//getline is important cause cin alone stops captureing after a space
	getline(cin, message);
	if (!KeyAuthApp.chatsend("test", message))
	{
		cout << KeyAuthApp.data.message << endl;
	}
	// get chat messages
	KeyAuthApp.chatget("test");
	for (int i = 0; i < KeyAuthApp.data.channeldata.size(); i++)
	{
		cout << "\n Author:" + KeyAuthApp.data.channeldata[i].author + " | Message:" + KeyAuthApp.data.channeldata[i].message + " | Send Time:" + tm_to_readable_time(timet_to_tm(string_to_timet(KeyAuthApp.data.channeldata[i].timestamp)));
	}
	*/
    #pragma endregion Example on how to use KeyAuth functions

    cout << skCrypt("\n\n closing in five seconds...");
    Sleep(5000);
    exit(0);
}

string tm_to_readable_time(tm ctx) {
	char buffer[80];

	strftime(buffer, sizeof(buffer), "%a %m/%d/%y %H:%M:%S %Z", &ctx);

	return string(buffer);
}

static time_t string_to_timet(string timestamp) {
	auto cv = strtol(timestamp.c_str(), NULL, 10); // long

	return (time_t)cv;
}

static tm timet_to_tm(time_t timestamp) {
	tm context;

	localtime_s(&context, &timestamp);

	return context;
}
