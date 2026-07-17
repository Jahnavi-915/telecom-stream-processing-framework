#ifndef MONITORING_H
#define MONITORING_H

#include "statistics.h"

/*
 * Initialize monitoring subsystem.
 */
void monitoring_initialize(void);

/*
 * Get pointer to global statistics.
 */
SystemStatistics *monitoring_get_statistics(void);

/*
 * Print monitoring dashboard.
 */
void monitoring_print_dashboard(void);

#endif