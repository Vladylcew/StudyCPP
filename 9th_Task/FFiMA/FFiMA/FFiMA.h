#include <deque>
#include <vector>
#include <string>
#include <iostream>

template <class T, class Container_T = std::deque <T>>
	class FIFO {
	public:
		FIFO() = default;

		bool empty() { return !container.size(); }
		void push(const T& el) {
			container.push_back(el);
		}
		T get() {
			if (!empty())
			{
				T tmp = container.front();
				container.pop_front();
				return tmp;
			}
			return NULL;
		}
	private:
		Container_T container;
};


/////////////////VECTOR////////////////////
template <class T>
	class FIFO<T,std::vector<T>> {
	public:
		FIFO() = default;

		bool empty() { return !container.size(); }
		void push(const T& el) {
			container.push_back(el);
		}

		T get() {
			T tmp = container[0];
			for (int i = 0; i < container.size()-1; i++) {
				container[i] = container[i + 1];
			}
			container.resize(container.size() - 1);
			return tmp;
		}

	private:
		std::vector<T> container;
};

/////////////////STRING////////////////////
template <>
class FIFO<char, std::string> {
public:
	FIFO() = default;

	bool empty() { return !container.size(); }
	void push(const char el) {
		container += el;
	//std::cout << container;
	}
	char get() {
		if (!empty())
		{
			char tmp = container[0];
			container = container.substr(1, container.size() - 1);
			return tmp;
		}
		return NULL;
	}

private:
	std::string container;
};