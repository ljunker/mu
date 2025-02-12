TARGET := mu

BUILD_DIR := ./build
SRC_DIR := ./src
CFLAGS := -Wall -Werror

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean war love it_so
clean:
	-rm -r $(BUILD_DIR)

war: clean $(BUILD_DIR)/$(TARGET)

love: $(BUILD_DIR)/$(TARGET)
	$(BUILD_DIR)/$(TARGET) $(SRC_DIR)/terminal.c

it_so: war love