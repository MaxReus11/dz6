#define _CRT_SECURE_NO_WARNINGS
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include<string>
#include<chrono>
using namespace std::chrono_literals;
template <typename TP>
std::time_t to_time_t(TP tp)
{
    using namespace std::chrono;
    auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
        + system_clock::now());
    return system_clock::to_time_t(sctp);
}
void view_directory(const std::filesystem::path& path)
{
  
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path))
    {
        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            auto file_name = entry.path().filename().string();
            auto ftime = std::filesystem::last_write_time(entry.path());
            std::time_t cftime = to_time_t(ftime);
            std::cout << file_name << " " << std::asctime(std::localtime(&cftime)) << std::endl;
        }
    }
}
int mdz6-task4ain() {
    using namespace std;
    string path;
    cout << "Enter the path of directory you want to see" << endl;
    getline(cin, path);
    cout << "Your directory:\n";
    view_directory(path);
    return 0;
}
