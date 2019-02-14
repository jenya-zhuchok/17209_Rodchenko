#include "Pair.h"

Pair::Pair(const Value& v, const Key& k) : k(k) { insert(v); }
Pair::Pair(Pair& p)
{
    elem = new Value;
    *elem = p.get_value();
    k = p.get_key();
    if(&p.get_next()) next = new Pair(p.get_next());
}

Pair::~Pair() {
    if (elem != nullptr) delete elem;
    if(next != nullptr) delete next;
}

void Pair::operator=(Pair & p)
{
	if (this == &p) return;
	if (elem != nullptr) delete elem;
	if (next != nullptr) delete next;
	elem = new Value(p.get_value());
	k = p.get_key();
    if(&(p.get_next()))  next = new Pair(p.get_next());
}

Pair& Pair::get_next() { return *next;  }
Key Pair::get_key() const { return k; }
void Pair::put_key(const Key& t) { k = t; }



void Pair::insert(const Value& v)
{
    if (elem) delete elem;
    elem = new Value(v);
}

void Pair::insert()
{
    if(elem) delete elem;
	elem = new Value;
}

Value& Pair::get_value() const { return *elem; }

void Pair::clear()
{
    Pair *tmp = next;
    *this = *next;
    delete tmp;
}

bool Pair::operator==(const Pair& p) const { return ((k == p.k) && (elem == p.elem) && (*next == *(p.next))); }
