//
// Created by kurlyana on 23.04.2020.
//

#include "iterate_over_dir.h"
#include <boost/filesystem.hpp>
#include "../src/my_concurrent_queue.h"
#include <string>
#include <sstream>
#include "iostream"
#include "unpack.h"
#include "read_by_words.h"

using namespace boost::system;
namespace fs = boost::filesystem;
#ifndef USING_BOOST
#define USING_BOOST
#endif

#define ARCHIVE ".zip"
#define TEXT_FILE ".txt"
#define MAX_TEXT_FILE_SIZE 10000000

void iterate_over_dir(const boost::filesystem::path &dir, ConcurrentQueue<std::string> &substr_queue, size_t max_words) {
    try {
        if (fs::exists(dir) && fs::is_directory(dir))
        {
            fs::recursive_directory_iterator iter(dir), end;
            while (iter != end)
            {
                std::cout <<  iter->path().string() << std::endl;

                std::ifstream raw_file((const char *) iter->path().c_str(), std::ios::binary);
                auto buffer = dynamic_cast<std::ostringstream&>(std::ostringstream{} << raw_file.rdbuf()).str();

                if (iter->path().extension() == ARCHIVE) {
                    std::cout << "ARCHIVE" << iter->path().string() << std::endl;
//                    read_archive(reinterpret_cast<const char *>(&buffer), substr_queue);
                }

                else if (iter->path().extension() == TEXT_FILE && fs::file_size(iter->path()) < MAX_TEXT_FILE_SIZE)
                {
                    std::cout << "TEXT_FILE" << iter->path().string() << std::endl;
//                    read_by_words((std::string &) iter->path(), substr_queue, max_words);
                }

                error_code ec;
                iter.increment(ec);

                if (ec) {
                    std::cerr << "Error While Accessing : " << iter->path().string() << " :: " << ec.message() << '\n';
                }
            }
        }
    }
    catch (std::system_error & e)
    {
        std::cerr << "Exception :: " << e.what();
    }
}


