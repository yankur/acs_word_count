//
// Created by kurlyana on 23.04.2020.
//

#include "iterate_over_dir.h"
#include <boost/filesystem.hpp>
#include "my_concurrent_queue.h"
#include <string>
#include "unpack.h"
#include "read_by_words.h"

using namespace boost::system;
namespace fs = boost::filesystem;
#ifndef USING_BOOST
#define USING_BOOST
#endif

#define ARCHIVE ".zip"
#define TEXTFILE ".txt"

void iterate_over_dir(const boost::filesystem::path &dir, ConcurrentQueue<std::string> &substr_queue, size_t max_words) {
    try {
        if (fs::exists(dir) && fs::is_directory(dir))
        {
            fs::recursive_directory_iterator iter(dir), end;
            while (iter != end)
            {
                if (iter->path().extension() == ARCHIVE) {
                    read_archive((const char *) iter->path().c_str());
                }
                else if (iter->path().extension() == TEXTFILE)
                {
                    read_by_words((std::string &) iter->path(), substr_queue, max_words);
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

