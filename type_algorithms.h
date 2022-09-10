#pragma once

#include <type_traits>
#include <iterator>
#include <utility>
#include <chrono>
#include <typeinfo>


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

#ifdef __has_cpp_attribute(maybe_unused)
	#define QUIED_M_U [[maybe_unused]]
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

			/*
			 template<typename ... Arg>
			auto th = [](Arg& ... sm){};
			*/

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


class M_Value {
public:
	virtual ~M_Value();
};

template <class T> class Value : public M_Value {
	T _Value;

public:

	explicit Value(const T &value) : _Value(value) {}
	T& get() const { return _Value; }

};



namespace quied::any {

	struct QAny {
		void* _ptr;
		std::type_info const& _type;

		std::type_info const& (*_getType)();
		void* (*_clone)(void* other);

		/*
		template <typename T>
		explicit QAny(T &&value) : _ptr(new T{std::forward<T>(value)}), 
			_type(typeid(T)){ }
			*/
	
		template <typename T> 
		explicit QAny(T&& value) : _ptr(new T{ std::forward<T>(value) }), _getType{ []() -> 
			std::type_info const& { return typeid(T); } }, _clone([](void* other) -> 
			void* { return new T(*static_cast<T*>(other)); }) { }
			

	//	QAny(const QAny& copy) : _ptr(copy._clone(copy._ptr), _getType(copy._getType), _clone(copy._clone) {}

		template <typename T>
		static T& any_cast(QAny& Any) {
			if (typeid(T) == Any._type)
				return *static_cast<T*>(Any._ptr);
			else {
				throw std::bad_any_cast{};
			}
		}
	};

	// Any must store pointer on object
	// this object store the type we want
	class Any {
		std::unique_ptr<M_Value> _ptr;

	public:
		template <class T>
		Any(const T &value) : _ptr(new Value<T>(value)){ }

		template <class T>
		T& get()  {
			Value<T>* val = dynamic_cast<Value<T>*>(_ptr.get());
			if (!val) { return T(); }
			return val->get();
		}
	};



}// namespace any

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
					} } }();
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
		
		QUIED_M_U std::map<std::string, std::set<std::string>> RecursiveGarb(std::string Path) {
			std::map<std::string, std::set<std::string>> st;
			std::vector<std::string> Vec; // txt 


			[=]() mutable {
				try {
					std::filesystem::recursive_directory_iterator it(Path);
					for (const auto& data : it) {
						if (data.path().extension() == ".txt") { 
							//Vec.push_back(data.path()); 
						}
					}
				} 
				catch (const std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
				
			}();

			return st;
		}

		QUIED_M_U std::map<std::string, std::set<std::string>> RecursiveGarb(std::string &Arg, std::string Dictionary) {
			std::ifstream Fin(Dictionary);

			if (Fin.is_open()) { // if we have dictionary
				std::map<std::string, std::set<std::string>> CoverData;
					std::filesystem::recursive_directory_iterator(Arg);	

				return CoverData;
			}  else {
				RecursiveGarb(Arg); 
			}
		}






	} // fs namesapce
} // quied namespace