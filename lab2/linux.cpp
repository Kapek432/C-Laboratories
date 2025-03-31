#include <iostream>
using namespace std;

#include "user.h"
#include "linux.h"



std::size_t Linux::open_source_sympathizers_ = 0;

Linux::Linux()
{
    open_source_sympathizers_++;
    std::cout << "+" << distribution_ << '\n';

}
Linux::Linux(const std::string &dist)
{
    distribution_ = dist;
    open_source_sympathizers_++;
    std::cout << "+" << distribution_ << '\n';

}
Linux::~Linux()
{
    open_source_sympathizers_--;
    std::cout << "~" << distribution_ << '\n';
}

std::string Linux::distribution() const
{
    return distribution_;
}
std::size_t Linux::open_source_sympathizers()
{
    return open_source_sympathizers_;
}
std::size_t Linux::add_user(const std::string& user_name, const std::string& password, bool admin)
{
    users_.emplace_back(user_name, password, admin);
    return users_.size() - 1;
}
const User& Linux::user(std::size_t id) const
{
    return users_[id];
}
std::string Linux::user_home_directory(std::size_t id) const
{
    return "/home/" + user(id).user_name_ + "/";
}

std::optional<std::string> Linux::graphic_environment() const
{
    return graphic_environment_;
}
void Linux::set_graphic_environment(const std::string& env)
{
    graphic_environment_ = env;
}

//dodatkowe
std::string Linux::default_text_file_encoding()
{
    return "UTF-8";
}
std::string Linux::end_of_line()
{
    return "\n";
}
constexpr bool Linux::is_path_case_sensitive()
{
    return true;
}
constexpr char Linux::path_separator()
{
    return '/';
}
std::string Linux::shortcut_to_send_end_of_file_to_program()
{
    return "Ctrl+D";
}
std::pair<std::string, std::string> Linux::user_login_information()
{
    return {"/etc/passwd", "/etc/shadow"};
}
std::string Linux::users_directory()
{
    return "/home/";
}
