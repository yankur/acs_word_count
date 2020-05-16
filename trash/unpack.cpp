//
// Created by kurlyana on 4/5/20.
//

#include <archive.h>
#include <archive_entry.h>
#include <string>
#include <iostream>
#include "unpack.h"
#include "boost/filesystem.hpp"
#include "../src/my_concurrent_queue.h"

std::string read_archive(const std::string& buffer , ConcurrentQueue<std::string> &substr_queue){
    la_int64_t r;
    off_t size;

    std::cout << "reading archiveeeee" << std::endl;

    struct archive *a = archive_read_new();
    struct archive_entry *ae;
    archive_read_support_format_all(a);
    archive_read_support_format_raw(a);

    std::cout << buffer.c_str() << "buffer" << std::endl;

    r = archive_read_open_memory(a, buffer.c_str(), buffer.size());
    std::cout << "done1" << std::endl;
    if (r != ARCHIVE_OK) {
        std::cerr << "Error While Accessing : " << buffer << std::endl;
        exit(1);
    }

    r = archive_read_next_header(a, &ae);
    std::cout << "done2" << std::endl;
    if (r != ARCHIVE_OK) {
        std::cerr << "Error While Accessing : " << buffer << std::endl;
        exit(1);
    }
    for (;;) {
//        std::cout << boost::filesystem::path(archive_entry_pathname(ae)) << std::endl;

        if (boost::filesystem::path(archive_entry_pathname(ae)).extension() == ".txt") {
            std::cout << "done3" << std::endl;
            size = archive_entry_size(ae);
            std::string substr(size, char{});
            r = archive_read_data(a, &substr[0], substr.size());
            std::cout << substr << std::endl;
            substr_queue.push(substr);
        }

        if (r != ARCHIVE_OK) {
            std::cerr << "Error While Accessing : " << buffer << std::endl;
            exit(1);
        }
    }
    archive_read_close(a);
}
