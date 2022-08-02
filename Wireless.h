#pragma once

#include "boost/asio.hpp"

namespace quied {
	namespace wless {

        std::string getStockPage(const std::string site, std::string const& ticker) {
            boost::asio::ip::tcp::iostream stream;
                            
            stream.connect(site, "http");
            stream << "GET /search?q=" << ticker << " HTTP/1.1\r\n";
            stream << "Host: www.google.com\r\n";
            stream << "Cache-Control: no-cache\r\n";
            // stream << "Content-Type: application/x-www-form-urlencoded\r\n\r\n";
            stream << "Connection: close\r\n\r\n" << std::flush;

            std::ostringstream os;
            os << stream.rdbuf();
            return os.str();
        }

	}
}