#pragma once
#include <iostream>
#include <algorithm>
#include <cstddef>

namespace utils {
	/*
	using uint = unsigned int;

	template <class T> class shared_ptr {

		class Ref_counter {

			uint _Count{ 0 };

		public:

			Ref_counter() : _Count(1) {}
            virtual ~Ref_counter() { dispose(); }
			Ref_counter(const Ref_counter&) = delete;
			Ref_counter& operator =(const Ref_counter&) = delete;

			void reset() { _Count = 0; }
			uint get() const { return _Count; }

			void dec() {
				if (!_Count) throw std::logic_error("Zero");
				_Count--;
			}

            virtual void dispose() = 0;



			void operator++() { _Count++; }
			void operator++(int) { _Count++; }
			void operator--(int) { _Count--; }

			friend std::ostream& operator<<(std::ostream& out,
				const Ref_counter& Counter) {
				out << "Value: " << Counter._Count << std::endl;
				return out;
			}

			template <class E, class ... Args>
				friend shared_ptr<E> make_shared(Args& ... args);

             // Block 
			template<typename Y> struct Obj_Block {

				Y *_ptr;
				explicit Obj_Block(Y *p) : _ptr(p) {}
                virtual void dispose() { delete _ptr; }
			};
            // =====

			T* ptr;
			Ref_counter* Ref;

			void checkDelete() {
				if (!ptr) return;
				Ref->dec();

				if (Ref->get == 0) {
					Ref->delete_ptr();
				}

				ptr = nullptr;
				Ref = nullptr;
			}

		}; // Ref_counter

	//	shared_ptr() : ptr(nullptr), Ref(nullptr) { }

	}; // shared_ptr


	template <typename D, typename ... Args>
	shared_ptr<D> make_shared(Args&& ... args) {

		shared_ptr<D> ptr;
		// auto tmp = new shared_ptr<D

	}
	*/
} // namepsace utils

namespace utils {


	class Control_Block {

		int* pn;

	public:
		Control_Block() : pn(NULL){}
		Control_Block(const Control_Block &Count) : pn(Count.pn) {}


		void swap(Control_Block &Count) noexcept {
			std::swap(pn, Count.pn);
		}

		int use(void) const noexcept {
			int Count = 0;
			if (pn != NULL)
				Count = *(pn);
			return Count;
		}

		template <typename D>
		void accquire(D* ptr) {
			if (ptr != NULL) {
				if (pn != NULL) {
					try {
						pn = new int(1); // May throw bad alloc

					} catch (const std::bad_alloc&) {
						delete ptr;
						throw; // rethrow std::bad_alloc
					}
				}
			}
			else {	++(*pn);  }
		}
		
		template <typename TY>
		void release(TY* ptr) noexcept {
			if (pn != NULL) {
				--(*pn);
				if (*pn) {
					delete ptr;
					delete pn;
				}
				pn = NULL;
			}
		}
	}; // CB class

	class shared_ptr_base {
	protected:

		Control_Block pn; // reference counter

		shared_ptr_base(void) : pn(){}
		shared_ptr_base(const shared_ptr_base& copy) : pn(copy.pn) {}

	};

	template <class T>
	class shared_ptr : public shared_ptr_base {
	
		using Elem_Type = T; // The type of the managed object
		Elem_Type* pn;

		// Default constructor
		shared_ptr(void) noexcept : shared_ptr(), pn(NULL) { }



	};



}