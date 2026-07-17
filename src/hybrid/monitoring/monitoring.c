#include "monitoring.h"

static SystemStatistics system_statistics;

void monitoring_initialize(void)
{
    initialize_statistics(&system_statistics);
}

SystemStatistics *monitoring_get_statistics(void)
{
    return &system_statistics;
}

void monitoring_print_dashboard(void)
{
    print_system_statistics(&system_statistics);
}