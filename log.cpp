//
// Created by Joseph Yan on 2022/7/17.
//
#include "log.h"
namespace sylar{
    Logger::Logger(const std::string &name):m_name(name) {

    }
    void Logger::addAppender(LogAppender::ptr appender) {
        m_appenders.push_back(appender);
    }
    void Logger::delAppender(LogAppender::ptr appender) {
        for (auto it = m_appenders.begin(); it !=m_appenders.end() ; ++it) {
            if(*it==appender){
                m_appenders.erase(it);
                break;
            }
        }
    }

    void Logger::log(LogLevel::Level level, const LogEvent::ptr event) {
        if(level>=m_level){
            for ( auto &i: m_appenders){
                i->log(level,event);
            }
        }
    }
    void Logger::debug(LogEvent::ptr event) {
        debug(LogLevel::DEBUG,event);
    }
    void Logger::info(LogEvent::ptr event) {
        info(LogLevel::INFO,event);
    }
    void Logger::warn(LogEvent::ptr event) {
        warn(LogLevel::WARN,event);
    }
    void Logger::error(LogEvent::ptr event) {
        error(LogLevel::ERROR,event);
    }
    void Logger::fatal(LogEvent::ptr event) {
        fatal(LogLevel::FATAL,event);
    }

}