#ifndef COLLECTIONWRAPPER_HPP
#define COLLECTIONWRAPPER_HPP

#include "luabind/luabind.hpp"
#include <luabind/iterator_policy.hpp>
#include <utility>
#include <ostream>

//class CollectionWrapper
//{
//public:
//    std::vector<int> collection;

//    CollectionWrapper(std::vector<int> collection) : collection(collection)
//    {
//    }

//    static luabind::scope bind()
//    {
//        return luabind::class_<CollectionWrapper>("CollectionWrapper")
//                .def(luabind::constructor<std::vector<int> >())
//                .def_readwrite("data", &CollectionWrapper::collection, luabind::return_stl_iterator);
//    }
//};


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
