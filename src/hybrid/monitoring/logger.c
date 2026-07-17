#include "logger.h"

#include <stdio.h>
#include <stdarg.h>

static const char *level_strings[] =
{
    "INFO",
    "WARNING",
    "ERROR"
};

void log_message(LogLevel level, const char *format, ...)
{
    va_list args;

    printf("[%s] ", level_strings[level]);

    va_start(args, format);

    vprintf(format, args);

    va_end(args);

    printf("\n");
}

void log_info(const char *format, ...)
{
    va_list args;

    printf("[INFO] ");

    va_start(args, format);

    vprintf(format, args);

    va_end(args);

    printf("\n");
}

void log_warning(const char *format, ...)
{
    va_list args;

    printf("[WARNING] ");

    va_start(args, format);

    vprintf(format, args);

    va_end(args);

    printf("\n");
}

void log_error(const char *format, ...)
{
    va_list args;

    printf("[ERROR] ");

    va_start(args, format);

    vprintf(format, args);

    va_end(args);

    printf("\n");
}