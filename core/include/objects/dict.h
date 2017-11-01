#pragma once
#include <iostream>
#include <cstdint>
#include <sstream>
#include <memory>
#include <map>

namespace dux {

	struct DictStore {
		std::uintptr_t memory_address;
		int size;
	};

	class Dict {

		std::map<std::string, std::uintptr_t> __keys_ref;
		long __size;

	public:
		Dict();
		~Dict();
		
		template<typename T>
		bool add(const std::string& _key, const T& _value) {
			try {
				T obj(_value);
				this->__keys_ref[_key] = reinterpret_cast<std::uintptr_t>(&obj);
				this->__size += 1;
				return true;
			} catch (...) {
				return false;

			}
		}

		template<typename T>
		T get(const std::string& _key) {
			try {
				return *reinterpret_cast<T*>(this->__keys_ref[_key]);
			} catch (...) {
				return T();
			}
		}
		
	};

}
