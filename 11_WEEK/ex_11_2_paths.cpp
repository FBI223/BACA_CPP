

#include <iostream>
#include <filesystem>
#include <regex>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

/**
* Prints content of directory given by path
* Format
* [X] file_name file_size
* where X equals D for directories, F for regular files, L for symlinks and space otherwise.
* @param path directory path
*/


void printDirectory(std::string_view path) {
    for (const auto &entry: fs::directory_iterator(path)) {
        char type = ' ';
        if (entry.is_directory()) type = 'D';
        else if (entry.is_regular_file()) type = 'F';
        else if (entry.is_symlink()) type = 'L';

        uintmax_t size = 0;
        if (entry.is_regular_file()) {
            size = fs::file_size(entry.path());
        }

        cout << "[" << type << "] "
                << entry.path().filename().string() << " "
                << size << " bytes" << endl;
    }
}

/*
 *
entry.path()        = "testdir/file1.txt"
parent_path()       = "testdir"
stem()              = "file1"
newExtension        = ".bak"

newPath = "testdir" / "file1" + ".bak" = "testdir/file1.bak"
 *
 */


/**
* Makes copies of all files matching fileNames regular expression in directory given by path
* to files in the same directory but with changes extension to newExtension
* @param path directory path
* @param fileNames regular expression
* @param newExtension new extension
*/

void changeExtension(const fs::path &path, const std::string &fileNames, std::string_view newExtension) {
    std::regex pattern(fileNames);
    for (const auto &entry: fs::directory_iterator(path)) {
        if (!entry.is_regular_file()) continue;
        const std::string name = entry.path().filename().string();
        if (std::regex_match(name, pattern)) {
            fs::path newPath = entry.path().parent_path() / entry.path().stem();
            newPath += newExtension;
            fs::copy_file(entry.path(), newPath, fs::copy_options::overwrite_existing);
        }
    }
}


int main() {
    fs::remove_all("testdir"); // usuń stary test jeśli istnieje
    fs::create_directory("testdir");
    fs::create_directory("testdir/subdir");

    // Pliki w głównym katalogu
    ofstream("testdir/file1.txt") << "File 1 in root";
    ofstream("testdir/file2.log") << "Log file";
    ofstream("testdir/readme.md") << "# Readme";

    // Pliki w podfolderze
    ofstream("testdir/subdir/data1.txt") << "Data in subdir";
    ofstream("testdir/subdir/info.txt") << "More data";

    cout << "=== GŁÓWNY KATALOG (testdir/) ===\n";
    printDirectory("testdir");

    cout << "\n=== PODKATALOG (testdir/subdir/) ===\n";
    printDirectory("testdir/subdir");

    // Zmieniamy rozszerzenia tylko w testdir/ (nie działa rekurencyjnie!)
    cout << "\n=== ZMIANA ROZSZERZENIA *.txt → *.bak w testdir/ ===\n";
    changeExtension("testdir", R"(.*\.txt)", ".bak");

    cout << "\n=== testdir/ po zmianie rozszerzeń ===\n";
    printDirectory("testdir");

    cout << "\n=== testdir/subdir/ pozostaje bez zmian ===\n";
    printDirectory("testdir/subdir");

    return 0;
}
