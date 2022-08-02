#pragma once

#include <type_traits>
#include <iterator>
#include <utility>
#include <chrono>

#include "Header.h"
#include "Wireless.h"


#ifdef _MSC_VER
#ifndef __clang__
#define CONSTEVAL consteval
#else
#define CONSTEVAL constexpr
#endif
#else
#define CONSTEVAL constexpr
#endif

#define TMPS template <typename, typename> typename

// container may consist only int or double, we give * on begin/end
template<typename T>	
concept Type = sizeof(T*) == 4 || sizeof(T*) == 8;

// __has_cpp_attribute(nodiscard)
#ifdef __has_cpp_attribute(nodiscard)
	#define QUIED_NODISCARD [[nodiscard("discard")]]
#endif  

#ifdef __has_cpp_attribute(noreturn)
	#define QUIED_NORETURN [[noreturn]]
#endif


namespace quied {
	namespace decl {
		class Same {
		public:
			/*
			template <TMPS Con, typename Type>
			bool operator()(const Con<> &h, Type const& s) const {
				const std::iterator iter = h.begin();
				for(iter; iter != h.end(); iter++){
					return (h == s) ? true : false;
				}
			}*/

			/*
			template <typename ... Args, TMPS H>
			auto Experience(Args ... Values) -> decltype(auto) {
				std::cout << "In: " << sizeof(Values);

			}*/

			template<Type ForwardIterator> // if we don't have Value in container
			static constexpr inline bool none_of(ForwardIterator First, ForwardIterator Last, int&& Value) {
				for (; First != Last; ++First) {
					bool have = (*First == Value) ? true : false;
					if (have) return false;
				}
				return true;
			}


			template <typename ForwardIterator, typename UnaryFunction>
			static constexpr UnaryFunction set_as(ForwardIterator First, ForwardIterator Last, UnaryFunction Value) {
				for (; First != Last; ++First) {
					//	std::cout << (*First) << std::endl;
					Value(*First);
				}
				return Value;
			}


			template <typename ForwardIterator, Type A>
			static void hsy(ForwardIterator First, ForwardIterator Last, A& Value) {
				for (; First != Last; ++First) {
					std::cout << (*First) << std::endl;
				}
			}


		private:

			template <typename F>
			void inside_cont(F& a) {}

		};

	} // namespace decl
} // namespace quied

namespace quied {
	namespace fs {
		// Find file at directory
		bool QUIED_NODISCARD dir_has_file(const std::string& dir_str, const std::string &file_str) {
			bool has = false; // if file has in directory
			[&has, dir_str, file_str] {
				for (const auto& entry : std::filesystem::recursive_directory_iterator(dir_str)) {
					std::cout << entry.path().filename() << std::endl;
					if (file_str == entry.path().filename()) {
						has = true; return;
					}
				}
				}();
			return has;
		}

		// Find files with extension at directory
		QUIED_NORETURN void dir_files_extension(const std::string &dir_path, const std::string &extn) {
			try {
				for (const auto& file : std::filesystem::recursive_directory_iterator(dir_path)) {
					if (file.path().extension() == extn) std::cout << file.path().filename() << std::endl;
				}
			} catch (const std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
		}



	} // fs namesapce
} // quied namespace