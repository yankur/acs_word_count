//
// Created by kurlyana on 4/5/20.
//

#include <archive.h>
#include <archive_entry.h>
#include <string>
#include <iostream>
#include "unpack.h"

//struct archive *a;
//struct archive_entry *entry;

std::string read_archive( const char *filename ){
    std::cout << "im here" << std::endl;

    struct archive *a;
    struct archive_entry *entry;

    a = archive_read_new();
    archive_read_support_filter_all(a);
    std::string content;

    archive_read_support_format_all(a);
    archive_read_open_filename(a, filename, 10240);

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {

        auto size = archive_entry_size(entry);
        content = std::string(size, 0);

        archive_read_data(a, &content[0], content.size());
        archive_read_data_skip(a);
    }
    archive_read_free(a);

    return content;
}