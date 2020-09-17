#ifndef _VECTOR_H_
#define _VECTOR_H_

using namespace std;

#include <cassert>

#define DEFAULT_CAPACITY	(1)

template <typename Object>
class Vector {
  private:
  	int theSize;
	int theCapacity;
	Object *objects;

  public:
	Vector() {
  		theSize = 0;
  		theCapacity = DEFAULT_CAPACITY;
  		objects = new Object[theCapacity + 1];
  	}

	Vector(int capacity) {
		assert(capacity >= 0);
		theSize = 0;
		theCapacity = capacity;
		objects = new Object[theCapacity + 1];
	}

	~Vector( ) { delete [] objects; }

	Object &operator[](int index) {
		assert(index > 0 && index < theSize);
		return objects[index];
	}

	bool empty() { return size( ) == 0; }
	int size() { return theSize; }
	int capacity() { return theCapacity; }
	void push_back(const Object& x);
	void pop_back();
	const Object &back();
	void resize(int newSize);
	void reserve(int capacity);

	typedef Object* iterator;

	iterator begin() { return &objects[0]; }
	iterator end() { return &objects[size()]; }
};

#include "vector.tpp"

#endif
