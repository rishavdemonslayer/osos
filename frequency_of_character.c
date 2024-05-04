#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define NUM_FILES 3

// Function to count the frequency of a character in a file sequentially
int count_char_in_file_sequential(char *file_path, char character) {
    int fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s\n", file_path);
        exit(1);
    }

    int count = 0;
    char ch;
    while (read(fd, &ch, 1) > 0) {
        if (ch == character)
            count++;
    }

    close(fd);
    return count;
}

int main() {
    char character;
    printf("Enter a character to count its frequency: ");
    scanf("%c", &character);

    char *file_paths[NUM_FILES] = {"/Users/trishau/Desktop/ccodes/file1.txt", 
    "/Users/trishau/Desktop/ccodes/file2.txt", "/Users/trishau/Desktop/ccodes/file3.txt"};

    int total_count = 0;
    for (int i = 0; i < NUM_FILES; i++) {
        int count = count_char_in_file_sequential(file_paths[i], character);
        printf("Character '%c' occurs %d times in %s.\n", character, count, file_paths[i]);
        total_count += count;
    }

    printf("Total count of character '%c' in all files: %d\n", character, total_count);

    return 0;
}