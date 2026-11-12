
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enum to track the type of data
typedef enum {
    INT, FLOAT, CHAR, STRING
} DataType;

// Union to store different types of data
typedef union {
    int int_value;
    float float_value;
    char char_value;
    char *string_value;
} Data;

// Structure to store data and its type
typedef struct {
    Data data;
    DataType type;
} Container;

// Function declarations
void init_container(Container *c);
void set_int(Container *c, int value);
void set_float(Container *c, float value);
void set_char(Container *c, char value);
int set_string(Container *c, const char *value);

int get_int(Container *c);
float get_float(Container *c);
char get_char(Container *c);
char *get_string(Container *c);

void free_container(Container *c);

// Initialize container
void init_container(Container *c) {
    c->type = INT;
    c->data.int_value = 0;
}

// Free previous string if present
void clear_container(Container *c) {
    if (c->type == STRING) {
        free(c->data.string_value);
        c->data.string_value = NULL;
    }
}

// Main function
int main() {

    Container c;
    init_container(&c);

    set_int(&c, 10);
    printf("Int: %d\n", get_int(&c));

    set_float(&c, 3.14f);
    printf("Float: %f\n", get_float(&c));

    set_char(&c, 'A');
    printf("Char: %c\n", get_char(&c));

    if (set_string(&c, "Hello, World!")) {
        printf("String: %s\n", get_string(&c));
    } else {
        printf("Memory allocation failed!\n");
    }

    // Free allocated memory
    free_container(&c);

    return 0;
}

// Set integer
void set_int(Container *c, int value) {
    clear_container(c);
    c->data.int_value = value;
    c->type = INT;
}

// Set float
void set_float(Container *c, float value) {
    clear_container(c);
    c->data.float_value = value;
    c->type = FLOAT;
}

// Set character
void set_char(Container *c, char value) {
    clear_container(c);
    c->data.char_value = value;
    c->type = CHAR;
}

// Set string
int set_string(Container *c, const char *value) {

    char *new_string = malloc(strlen(value) + 1);

    if (new_string == NULL) {
        return 0;
    }

    strcpy(new_string, value);

    clear_container(c);

    c->data.string_value = new_string;
    c->type = STRING;

    return 1;
}

// Get integer
int get_int(Container *c) {
    if (c->type != INT) {
        printf("Error: Not an integer\n");
        return 0;
    }

    return c->data.int_value;
}

// Get float
float get_float(Container *c) {
    if (c->type != FLOAT) {
        printf("Error: Not a float\n");
        return 0.0f;
    }

    return c->data.float_value;
}

// Get character
char get_char(Container *c) {
    if (c->type != CHAR) {
        printf("Error: Not a character\n");
        return '\0';
    }

    return c->data.char_value;
}

// Get string
char *get_string(Container *c) {
    if (c->type != STRING) {
        printf("Error: Not a string\n");
        return NULL;
    }

    return c->data.string_value;
}

// Free container memory
void free_container(Container *c) {
    clear_container(c);
}
