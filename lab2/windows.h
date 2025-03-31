#ifndef WINDOWS_H
#define WINDOWS_H

#include <string>
#include <vector>
#include <cstdint> // uint32_t
#include <utility> // std::pair

struct User;

class Windows
{
    std::string version_ = "11";
    static std::size_t activated_systems_;
    std::vector<User> users_;
    // TODO:

public:
    using character_type = wchar_t;
    // TODO:
   Windows();
   Windows(std::string version);

   std::size_t add_user(const std::string& user_name, const std::string& password, bool admin=false);

    std::string version() const;
    static std::size_t activated_systems();

   const User& user(std::size_t id) const;
   std::string user_home_directory(std::size_t id) const;

   //dodatkowe
   static std::string default_text_file_encoding();
   static std::string end_of_line();
   constexpr static bool is_path_case_sensitive();
   constexpr static char path_separator();
   static std::string shortcut_to_send_end_of_file_to_program();
   static std::pair<std::string, std::string> user_login_information();
   static std::string users_directory();
};

#endif // WINDOWS_H

/*
*Państwa zadaniem jest napisanie klasy Windows, która ma zawierać następujące składowe (typy do uzupełnienia):
1. `version_` - wersja, wartość domyślna, ustawiana w klasie, to `"11"`.
1. Proszę do niej utworzyć metodę do odczytu `version()`.
2. `std::size_t activated_systems_` - jest to ilość aktywowanych Windowsów, wspólna dla wszystkich klas.
W konstruktorze powinna być zwiększana.
1. Proszę do niej utworzyć statyczną metodę do odczytu `activated_systems()`
3. `users_` - są to użytkownicy systemu, typ dowolny, polecam jednak `std::vector`.
Struktura na użytkowników jest w pliku `user.h`
4. `character_type` - jest to przezwisko typu `wchar_t`

Oraz następujące metody (poza powyższymi getterami):
1. Konstruktor bezargumentowy, powinien on wypisywać: `"Windows " << version_ << '\n'`, oraz inkrementować `activated_systems_`
   - Jakbyśmy nie zdefiniowali konstruktora domyślnego to co by się stało?
2. Konstruktor przyjmujący wersję, powinien robić co powyższy jw.
   - O czym jeszcze powinienem paniętać aby `activated_systems_` faktycznie przy każdej konstrukcji się zwiększało?
3. Metodę `add_user` zwracającą id kolejnego użytkownika (czyli ilość elementów `users_` - 1), przyjmującą `user_name` i `password`.
   Nowy użytkownik powinien być dodany do `users_`.
4. Metodę `user`, która przyjmując `user_id` zwróci konkretnego użytkownika
5. Metodę `user_home_directory`, która przyjmując `user_id` zwróci ścieżkę do katalogu użytkownika, czyli `C:\Users\username`
*/
