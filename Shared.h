#pragma once
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <cassert>

using std::swap;

class TL {

public:
	void show(int a);
};


namespace utills {

	
	template <typename T> class unique_ptr {
		unique_ptr(const unique_ptr& arg) = delete;
		T* _ptr;


	public:
		explicit unique_ptr(T* ptr = nullptr) : _ptr(ptr){}
		T* Get() const {
			return _ptr;
		}

		unique_ptr(unique_ptr &&arg) : _ptr(arg.release()) {}
		
		unique_ptr(unique_ptr &copy) {
			copy.swap(*this);
			return *this;
		}

		//  Release from possession
		T* release() { 
			T* ptr = _ptr;
			_ptr = nullptr;
			return ptr;
		}

		unique_ptr& operator=(unique_ptr &arg) {
			arg.swap(*this);
			return *this;
		}
		operator bool() { return _ptr; }
		T& operator *() { return *_ptr; }
		T& operator ->() { return _ptr; }


		void swap(unique_ptr& ptr) {
			using std::swap;
			std::swap(_ptr, ptr._ptr);
		}

		~unique_ptr() { delete _ptr; }
		// static void frow(int a);

	};



}