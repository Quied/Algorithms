#pragma once

#include "boost/asio.hpp"
#include "boost/chrono.hpp"
#include "boost/coroutine/all.hpp"
#include "boost/bind/bind.hpp"
#include "boost/thread.hpp"

// std::string Address = "127.0.0.1"; 
// std::string port    = "5432";

namespace quied {
	namespace wless {







        /*
        void error(const boost::system::error_code& er, boost::asio::steady_timer *t, int *count) {
            if (*count < 6) {
                std::cout << (*count) << std::endl;
                ++(*count);
                t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
                t->async_wait(boost::bind(error, boost::asio::placeholders::error, t, count));
            }
        }
        

        auto lm = [](std::string ar, char at, uint32_t ay, std::string au) {
            std::cout << ar << std::endl;
            while (ay-- > 0) std::cout << at << std::endl;
            std::cout << au << std::endl;
        };

         // std::function<void(std::string, char, uint32_t, std::string)> Fo =
           // std::bind(&decltype(lm)::operator(), std::placeholders::_1, &lm);

        
        std::string getStockPage(const std::string site, std::string const& ticker) {
            boost::asio::ip::tcp::iostream stream;
            !!
            stream.connect(site, "http");
            stream << "GET /search?q=" << ticker << " HTTP/1.1\r\n";
            stream << "Host: " + site + "\r\n";
            stream << "Cache-Control: no-cache\r\n";
            // stream << "Content-Type: application/x-www-form-urlencoded\r\n\r\n";
            stream << "Connection: close\r\n\r\n" << std::flush;

            std::ostringstream os;
            os << stream.rdbuf();
        return os.str();
        }*/




	} // namespace wless
} // namespace Quied