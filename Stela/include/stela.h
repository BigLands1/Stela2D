#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #ifdef STELA_BUILDING
        #define STELA_API __declspec(dllexport)
    #else
        #define STELA_API __declspec(dllimport)
    #endif
#else
    #define STELA_API
#endif