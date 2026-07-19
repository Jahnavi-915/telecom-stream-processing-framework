# ============================================================================
# Hybrid Telecom Stream Processing Framework
# Communication Prototype Build System
# ============================================================================

# Compiler
CC = mpicc

# Directories
INCLUDE_DIR = include
MPI_DIR = mpi
PROCESSING_DIR = processing
DATABASE_DIR = storage
GRAPH_DIR = graph
MONITORING_DIR = monitoring

# Compiler Flags
CFLAGS = -D_DEFAULT_SOURCE -D_XOPEN_SOURCE=700 -Wall -Wextra -std=c11 -pthread -I$(INCLUDE_DIR)
# Target Executable
TARGET = hybrid

# Source Files
SOURCES = \
hybrid_main.c \
$(MPI_DIR)/mpi_client.c \
$(MPI_DIR)/mpi_server.c \
$(MPI_DIR)/telecom_packet.c \
$(MPI_DIR)/traffic_generator.c \
$(MPI_DIR)/serialization.c \
$(MPI_DIR)/queue_interface.c \
$(PROCESSING_DIR)/shared_buffer.c \
$(PROCESSING_DIR)/packet_processor.c \
$(PROCESSING_DIR)/worker_pool.c \
$(DATABASE_DIR)/berkeley_db.c \
$(GRAPH_DIR)/graph.c \
$(MONITORING_DIR)/logger.c \
$(MONITORING_DIR)/statistics.c \
$(MONITORING_DIR)/monitoring.c \
$(MPI_DIR)/config.c

# Object Files
OBJECTS = $(SOURCES:.c=.o)

# ============================================================================
# Build
# ============================================================================

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -pthread -ldb -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ============================================================================
# Run
# ============================================================================

run:
	mpirun -np 2 ./$(TARGET)

# ============================================================================
# Clean
# ============================================================================

clean:
	rm -f $(OBJECTS) $(TARGET)

# ============================================================================
# Rebuild
# ============================================================================

rebuild: clean all

.PHONY: all run clean rebuild