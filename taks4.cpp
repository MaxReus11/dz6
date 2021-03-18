#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include<string>
#include<chrono>
#include "json.hpp"
using nlohmann::json;
struct Man {
    double height_;
    std::string first_name;
    std::string second_name;
    int age_;
    double weight_;
public:
    Man() :first_name("NON"), second_name("NON"), age_(0), weight_(0), height_(0) {}
    Man(std::string name, std::string surname) :first_name(name), second_name(surname) {}
    Man(std::string name, std::string surname, int age) :first_name(name), second_name(surname), age_(age) {}
    Man(std::string name, std::string surname, int age, double weight) :
        first_name(name), second_name(surname), age_(age), weight_(weight) {}
    Man(std::string name, std::string surname, int age, double weight, double height) :
        first_name(name), second_name(surname), age_(age), weight_(weight), height_(height) {}
    friend std::istream& operator>> (std::istream& in, Man& man);
};
std::istream& operator>>(std::istream& in, Man & man) {
    in >> man.first_name;
    in >> man.second_name;
    in >> man.age_;
    in >> man.weight_;
    in >> man.height_;
    return in;
}
int main() {
    auto path1 = std::filesystem::current_path();
    std::filesystem::create_directory(path1 / "json_directory");
    using namespace std;
    system("chcp 65001");
    filesystem::path path_output = path1 / "json_directory" / "output.txt";
    json j;
    Man man[3];
    std::fstream fout(path_output.string(), std::ios::app);
    for (auto& i : man) {
        cout << "Enter name, surname, age, weight and height of person" << endl;
        cin >> i;
        j["fist_Name"] = i.first_name;
        j["second_Name"] = i.second_name;
        j["Age"] =i.age_;
        j["Weight"] = i.weight_;
        j["Height"] = i.height_;
        fout << std::setw(4) << j;
    }
    return 0;
}
