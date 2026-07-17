#ifndef LOGGER_H
#define LOGGER_H

#include <stdarg.h>

/*
 * Logging levels
 */
typedef enum
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

/*
 * Generic logger
 */
void log_message(LogLevel level, const char *format, ...);

/*
 * Convenience wrappers
 */
void log_info(const char *format, ...);

void log_warning(const char *format, ...);

void log_error(const char *format, ...);

#endif