#pragma once

// Example from docs

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