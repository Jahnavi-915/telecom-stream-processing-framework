# ============================================================================
# Hybrid Telecom Stream Processing Framework
# Communication Prototype Build System
# ============================================================================

# Compiler
CC = mpicc

# Directories
INCLUDE_DIR = include
MPI_DIR = mpi

# Compiler Flags
CFLAGS = -Wall -Wextra -std=c11 -I$(INCLUDE_DIR)

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
$(MPI_DIR)/config.c

# Object Files
OBJECTS = $(SOURCES:.c=.o)

# ============================================================================
# Build
# ============================================================================

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

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