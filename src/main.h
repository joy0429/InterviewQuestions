//#include <format>
#include <functional>
#include <iostream>
#include <tuple>
#include <vector>
#include "nvidia.h"

#define CATCH_ERR(val){                                 \
    try{                                                \
        cin >> val;                                     \
        if((val < 0) || (val >= companiesList.size()))  \
            throw "Invalid input";                      \
    }                                                   \
    catch(const char* msg){                             \
        cout << msg << endl;                            \
        exit(EXIT_FAILURE);                             \
    }                                                   \
}                                                       \

vector<string> companiesList {"COMPAL", "DELTA ", "MOXA  ", "NXP   ", "NVIDIA", "PHISON"};

template <typename T>
struct funcList;

template <typename... args>
struct funcList<tuple<args...>>
{
    static constexpr auto size = sizeof...(args);

    template<size_t listSize>
    static constexpr auto func(){
        return func<listSize>(tuple<args...>());
    }
};
