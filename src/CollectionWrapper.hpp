#ifndef COLLECTIONWRAPPER_HPP
#define COLLECTIONWRAPPER_HPP

#include "luabind/luabind.hpp"
#include <luabind/iterator_policy.hpp>
#include <utility>
#include <ostream>

template <class T>
class CollectionWrapper
{
public:
    T collection;

    CollectionWrapper(T collection) : collection(collection)
    {
        std::cout << "COPY CONSTRUCTOR" << std::endl;
    }

    static luabind::scope bind()
    {
        return luabind::class_<CollectionWrapper<T > >("CollectionWrapper")
                .def(luabind::constructor<T >())
                .def_readwrite("data", &CollectionWrapper<T >::collection, luabind::return_stl_iterator);
    }
};

#endif // COLLECTIONWRAPPER_HPP
