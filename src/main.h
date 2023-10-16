//#include <format>
#include <functional>
#include <iostream>
#include <tuple>
#include "arcadyan.h"
#include "nvidia.h"

#define CATCH_ERR(val, size){                           \
    try{                                                \
        cin >> val;                                     \
        if((val < 0) || (val >= size))                  \
            throw "Invalid input";                      \
    }                                                   \
    catch(const char* msg){                             \
        cout << msg << endl;                            \
        exit(EXIT_FAILURE);                             \
    }                                                   \
}                                                       \

// TODO: Add other companies' name
vector<string> companiesList {"ARCADYAN", "COMPAL", "DELTA ", "MOXA  ", "NXP   ", "NVIDIA", 
                              "PHISON"};

typedef enum{
    COMPANY_ARCADYAN,
    COMPANY_COMPAL,
    COMPANY_DELTA,
    COMPANY_MOXA,
    COMPANY_NXP,
    COMPANY_NVIDIA,
    COMPANY_PHISON,
    COMPANY_MAX
}companyList_t;

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
