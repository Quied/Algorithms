#pragma once

#include <iostream>

#include "boost/asio.hpp"
#include "boost/chrono.hpp"
#include "boost/coroutine/all.hpp"
#include "boost/bind/bind.hpp"
#include "boost/thread.hpp"
#include "boost/process.hpp"

#include "boost/beast/core.hpp"
#include "boost/beast/http.hpp"
#include "boost/beast/version.hpp"

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


namespace quied::wless {

	class Wls {
		boost::asio::strand<boost::asio::io_context::executor_type> _strand;
		boost::asio::steady_timer _timer;
		boost::asio::steady_timer _timer2;
		int _count;

	public:

		Wls(boost::asio::io_context& context)
			: _strand(boost::asio::make_strand(context)),
			_timer(context, boost::asio::chrono::seconds(1)),
			_timer2(context, boost::asio::chrono::seconds(1)),
			_count(0) {

			_timer.async_wait(boost::asio::bind_executor(_strand,
				boost::bind(&Wls::print, this)));

			_timer2.async_wait(boost::asio::bind_executor(_strand,
				boost::bind(&Wls::print2, this)));
		}


		void print() {
			if (_count < 5) {
				std::cout << _count << std::endl;
				++_count;
				_timer.expires_at(_timer.expiry() + boost::asio::chrono::seconds(1));
				_timer.async_wait(boost::asio::bind_executor(_strand,
					boost::bind(&Wls::print, this)));

			}
		}

		void print2() {
			if (_count < 10) {
				++_count;

				_timer2.expires_at(_timer2.expiry() + boost::asio::chrono::seconds(1));
				_timer2.async_wait(boost::asio::bind_executor(_strand,
					boost::bind(&Wls::print2, this)));
			}
		}




	};

}