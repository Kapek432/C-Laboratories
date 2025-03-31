#ifndef LINUX_H
#define LINUX_H

#include <string>
#include <vector>
#include <optional> // std::optional
#include <cstdint> // uint32_t
#include <utility> // std::pair

struct User;  // declaration instead of include

class Linux
{
    std::string distribution_="Ubuntu";
    static std::size_t open_source_sympathizers_;
    std::vector<User> users_;
    std::optional<std::string> graphic_environment_;
    //char character_type;
public:
    using character_type = char;
    Linux();
    Linux(const std::string& dist);
    ~Linux();

    std::string distribution() const;
    static std::size_t open_source_sympathizers();

    std::size_t add_user(const std::string& user_name, const std::string& password, bool admin=false);
    const User& user(std::size_t id) const;
    std::string user_home_directory(std::size_t id) const;

    std::optional<std::string> graphic_environment() const;
    void set_graphic_environment(const std::string& env);

    //dodatkowe
    static std::string default_text_file_encoding();
    static std::string end_of_line();
    constexpr static bool is_path_case_sensitive();
    constexpr static char path_separator();
    static std::string shortcut_to_send_end_of_file_to_program();
    static std::pair<std::string, std::string> user_login_information();
    static std::string users_directory();


};



#endif // LINUX_H

/*Państwa zadaniem jest napisanie klasy Linux, która ma zawierać następujące składowe (typy do uzupełnienia):
1. `distribution_` - nie istnieje system Linux, systemami są jego dystrybucje.
    Jak nie wiadomo jaka dystrybucja to `Ubuntu`, więc wartość domyślna, ustawiana w klasie, to `"Ubuntu"`.
    1. Proszę do niej utworzyć metodę do odczytu `distribution()`.
2. `std::size_t open_source_sympathizers_` - jest to ilość użytkowników Linuxa, wspólna dla wszystkich klas.
    W konstruktorze powinna być zwiększana, w destruktorze zmniejszana.
    1. Proszę do niej utworzyć statyczną metodę do odczytu `open_source_sympathizers()`
3. `users_` - są to użytkownicy systemu, typ dowolny, polecam jednak `std::vector`.
    Struktura na użytkowników jest w pliku `user.h`
4. `character_type` - jest to przezwisko typu `char`
Oraz następujące metody (poza powyższymi getterami):
1. Konstruktor bezargumentowy, powinien on wypisywać: `"+" << distribution_ << '\n'`, oraz inkrementować `open_source_sympathizers_`
   - Jakbyśmy nie zdefiniowali konstruktora domyślnego to co by się stało?
*. 2Konstruktor przyjmujący dystrybucje, powinien robić co powyższy jw.
   - O czym jeszcze powinienem paniętać aby `open_source_sympathizers_` faktycznie przy każdej konstrukcji się zwiększało?
*3. Destruktor, który będzie dekrementował `open_source_sympathizers_`, oraz wyświetlał `"~" << distribution_ << '\n'`
   - jakbyśmy nie zdefiniowali destruktora to co by się stało?
*4. Metodę `add_user` zwracającą id kolejnego użytkownika (czyli ilość elementów `users_` - 1), przyjmującą `user_name` i `password`.
   Nowy użytkownik powinien być dodany do `users_`.
 *5. Metodę `user`, która przyjmując `user_id` zwróci konkretnego użytkownika
 *6. Metodę `user_home_directory`, która przyjmując `user_id` zwróci ścieżkę do katalogu użytkownika, czyli `/home/username/`
7. Środowisko graficzne dla dystrybucji, nie każdy ją ma. Dlatego proszę o dodanie:
   1. Dodanie pola w klasie: `std::optional<std::string> graphic_environment_;`
   2. Dodanie metod dostępowych: `graphic_environment() const` i `set_graphic_environment`
*/
