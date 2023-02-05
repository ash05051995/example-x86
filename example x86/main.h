#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <filesystem>

#include "auth/auth.h"
#include "auth/skstr.h"

std::string tm_to_readable_time(tm ctx);
static std::time_t string_to_timet(std::string timestamp);
static std::tm timet_to_tm(time_t timestamp);

const std::string compilation_date = (std::string)skCrypt(__DATE__);
const std::string compilation_time = (std::string)skCrypt(__TIME__);

using namespace KeyAuth;

std::string name = (std::string)skCrypt(""); // application name. right above the blurred text aka the secret on the licenses tab among other tabs
std::string ownerid = (std::string)skCrypt(""); // ownerid, found in account settings. click your profile picture on top right of dashboard and then account settings.
std::string secret = (std::string)skCrypt(""); // app secret, the blurred text on licenses tab and other tabs
std::string version = (std::string)skCrypt("1.0"); // leave alone unless you've changed version on website
std::string url = (std::string)skCrypt("https://keyauth.win/api/1.2/"); // change if you're self-hosting

api KeyAuthApp(name, ownerid, secret, version, url);

std::string license;

std::string remove_letters(std::string s) {
    std::string result;
    for (char c : s) {
        if (isdigit(c) || ispunct(c) || isspace(c)) {
            result += c;
        }
    }
    return result;
}

std::string path = "C:\\ProgramData\\key.txt";

bool check_key()
{
    if (std::filesystem::exists(path))
        return true;
    else
        return false;
}

void read_key()
{
    std::ifstream file(path);

    if (file.is_open())
    {
        std::getline(file, license, '\n');
        file.close();
    }
}

void save_key()
{
    std::ofstream file(path);
    file << license;
    file.close();
}

void delete_key()
{
    if (check_key())
    {
        std::remove(path.c_str());
    }
}