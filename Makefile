# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Target executable name
TARGET = poker

# Source files
SOURCES = main.cpp Card.cpp Player.cpp Community.cpp Deck.cpp

# Object files (automatically generated from source files)
OBJECTS = $(SOURCES:.cpp=.o)

# Header files (for dependency tracking)
HEADERS = Card.hpp Player.hpp Community.hpp Deck.hpp

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything from scratch
rebuild: clean all

# Install target (optional - copies to /usr/local/bin)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

# Uninstall target (optional)
uninstall:
	rm -f /usr/local/bin/$(TARGET)

# Debug build with debugging symbols and no optimization
debug: CXXFLAGS = -std=c++17 -Wall -Wextra -g -O0 -DDEBUG
debug: $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Check if all required files exist
check:
	@echo "Checking for required files..."
	@for file in $(SOURCES) $(HEADERS); do \
		if [ ! -f $$file ]; then \
			echo "Missing: $$file"; \
		else \
			echo "Found: $$file"; \
		fi \
	done

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  clean    - Remove object files and executable"
	@echo "  rebuild  - Clean and build from scratch"
	@echo "  debug    - Build with debug symbols"
	@echo "  run      - Build and run the program"
	@echo "  check    - Check if all required files exist"
	@echo "  install  - Install to /usr/local/bin"
	@echo "  uninstall- Remove from /usr/local/bin"
	@echo "  help     - Show this help message"

# Declare phony targets (targets that don't create files)
.PHONY: all clean rebuild debug run check help install uninstall