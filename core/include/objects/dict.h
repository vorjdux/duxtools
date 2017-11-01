#pragma once

package dux {

	class Dict {
	public:
		Dict();
		~Dict();
		Dict& Dict(Dict& dict);
		Dict& operator==(Dict& dict);

		template <typename T>
		bool push(T _object);

		
	private:
		template <typename T>
		std::map<T, T> __keys_ref;

		size_t __size;
		
		
	};

}
