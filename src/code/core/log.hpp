#pragma once

#include <iostream>

#if LOG

    enum class LOG_TYPE
    {
        INFO,
        WARNING,
        ERROR
    };

    void LogFunc(const char *log, LOG_TYPE type, int line, const char *file)
    {
        switch (type)
        {
            case LOG_TYPE::INFO:
                std::cout << "[INFO] : Line " << line << " File " << file << " Log: "<< log << '\n';
                break;

            case LOG_TYPE::WARNING:
                std::cout << "[WARNING] : Line " << line << " File " << file << " Log: "<< log << '\n';
                break;

                case LOG_TYPE::ERROR:
                std::cout << "[ERROR] : Line " << line << " File " << file << " Log: "<< log << '\n';                
                break;
        }
    }

    #define Log(log, type) LogFunc(log, type, __LINE__, __FILE__)

#else

    #define Log(log, type) ((void)0)

#endif