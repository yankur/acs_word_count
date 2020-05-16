//
// Created by kurlyana on 23.04.2020.
//

#include <string>
#include <sstream>
#include <iostream>

#include <archive.h>
#include <archive_entry.h>
#include <boost/filesystem.hpp>

#include "read_disk.h"
#include "my_concurrent_queue.h"


namespace fs = boost::filesystem;

#ifndef USING_BOOST
#define USING_BOOST
#endif

#define ARCHIVE_L ".zip"
#define ARCHIVE_U ".ZIP"
#define TEXT_FILE_L ".txt"
#define TEXT_FILE_U ".TXT"

#define MAX_TEXT_FILE_SIZE 10000000

void read_archive(const char *archive_file, ConcurrentQueue<std::string> &substr_queue, int max_words);
void divide_and_push(const std::string& buff, ConcurrentQueue<std::string> &strings_queue, size_t max_words);


void read_disk(const boost::filesystem::path &dir, ConcurrentQueue<std::string> &substr_queue, size_t max_words) {
    std::cout << "im here" << "\n";
    try {
        if (fs::exists(dir) && fs::is_directory(dir))
        {
            std::cout << "exists" << "\n";
            fs::recursive_directory_iterator iter(dir), end;

            while (iter != end)
            {
                std::cout << iter->path().c_str() << "\n";
                if (iter->path().extension() == ARCHIVE_L || iter->path().extension() == ARCHIVE_U) {
                    std::cout << iter->path().c_str() << "\n";
                    read_archive(iter->path().c_str(), substr_queue, max_words);
                }

                else if ((iter->path().extension() == TEXT_FILE_L || iter->path().extension() == TEXT_FILE_U) && fs::file_size(iter->path()) < MAX_TEXT_FILE_SIZE)
                {
                    std::cout << iter->path().c_str() << "\n";
                    std::ifstream raw_file(iter->path().c_str(), std::ios::binary);
                    auto buffer = dynamic_cast<std::ostringstream&>(std::ostringstream{} << raw_file.rdbuf()).str();

                    divide_and_push(buffer, substr_queue, max_words);
                }

                boost::system::error_code ec;
                iter.increment(ec);
                if (ec) {
                    std::cerr << "Error While Accessing : " << iter->path().string() << " :: " << ec.message() << '\n';
                }
            }
        }
    }
    catch (std::system_error & e) {
        std::cerr << "Exception :: " << e.what();
    }
    std::cout << "finished reading" << "\n";
}


void read_archive(const char *archive_file, ConcurrentQueue<std::string> &substr_queue, int max_words) {
    struct archive *archive_ptr;
    struct archive_entry *entry_ptr;
    int ret_signal;

    archive_ptr = archive_read_new();
    archive_read_support_filter_all(archive_ptr);
    archive_read_support_format_all(archive_ptr);

    ret_signal = archive_read_open_filename(archive_ptr, (const char *) archive_file, 10240);
    if (ret_signal != ARCHIVE_OK)
        exit(1);

    while (archive_read_next_header(archive_ptr, &entry_ptr) == ARCHIVE_OK) {
        boost::filesystem::path entry_path = boost::filesystem::path(archive_entry_pathname(entry_ptr));
        if ((entry_path.extension() == TEXT_FILE_L || entry_path.extension() == TEXT_FILE_U) && archive_entry_size(entry_ptr) <= MAX_TEXT_FILE_SIZE) {
            std::cout << "entry" << entry_path.c_str() << "\n";
            std::string text = std::string(archive_entry_size(entry_ptr), 0);
            ret_signal = archive_read_data(archive_ptr, &text[0], text.size());
            std::cout << "куе" << ret_signal;
            if (ret_signal != ARCHIVE_OK)
                continue;
            std::cout << "buffer" << text;
            divide_and_push(text, substr_queue, max_words);
        }
    }
    archive_free(archive_ptr);
}

void divide_and_push(const std::string& buff, ConcurrentQueue<std::string> &strings_queue, size_t max_words){
    size_t counter = 0;
    size_t prev = 0;
    for(size_t i = 0; i < buff.size(); ++i){
        if(std::isspace(buff[i])){
            ++counter;
        }
        if(counter == max_words){
            strings_queue.push(buff.substr(prev,i-prev));
            prev = i;
        }
    }
}


