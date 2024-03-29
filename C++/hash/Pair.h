#pragma once

#include "Header.h"
#include "Value.h"

struct Pair {
private:
	Key k;
	Value *elem = nullptr;
    Pair *next = nullptr;
public:

    Pair();
    Pair(const Key& k);
	Pair(Pair& p);
	Pair(const Value& v, const Key& k);
	~Pair();



	void operator=(Pair& p);

	Key get_key() const;
	Pair* get_next() const;
	Value& get_value() const;

    void put_key(const Key& t);
    void put_next(Pair p);


    void insert(const Value& v);
	void insert();
    void insert_back(const Value& v, const Key& k);

	void clear();

    bool is_empty() const;
	bool operator==(const Pair& p) const;
    bool operator!=(const Pair& p) const;
};
