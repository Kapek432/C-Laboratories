#include <iostream>
using namespace std;

#include "user.h"
#include "windows.h"

#warning "Funkcje sa do zaimplementowania. Instrukcja w pliku naglowkowym" // po zaimplementowaniu sugeruje usuniecie tej linijki - nie chcemy warningow


std::size_t Windows::activated_systems_=0;

std::string Windows::version() const
{
    return version_;
}
std::size_t Windows::activated_systems()
{
    return activated_systems_;
}
Windows::Windows()
{
    activated_systems_++;
    std::cout << "Windows " << version_ << '\n';
}
Windows::Windows(std::string version)
{
    version_ = version;
    activated_systems_++;
    std::cout << "Windows " << version_ << '\n';
}

std::size_t Windows::add_user(const std::string& user_name, const std::string& password, bool admin)
{
    users_.emplace_back(user_name,password,admin);
    return users_.size()-1;
}

const User& Windows::user(std::size_t id) const
{
    return users_[id];
}
std::string Windows::user_home_directory(std::size_t id) const
{
    return "C:\\Users\\" + user(id).user_name_;
}
//dodatkowe
std::string Windows::default_text_file_encoding()
{
    return "Windows-1252";
}
std::string Windows::end_of_line()
{
    return "\r\n";
}
constexpr bool Windows::is_path_case_sensitive()
{
    return false;
}
constexpr char Windows::path_separator()
{
    return '\\';
}
std::string Windows::shortcut_to_send_end_of_file_to_program()
{
    return "Ctrl+Z";
}
std::pair<std::string, std::string> Windows::user_login_information()
{
    return {"C:\\Windows\\System32\\config\\SAM", "C:\\Windows\\System32\\config\\SYSTEM"};
}
std::string Windows::users_directory()
{
    return "C:\\Users";
}


