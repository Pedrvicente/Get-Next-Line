Get Next Line

A custom implementation of the get_next_line function for reading a file descriptor line by line. This project follows the specifications of the 42 school curriculum.

⸻

📌 Overview

get_next_line reads from a file descriptor and returns one line per function call, including the newline character (\n) when present. It uses a static buffer to store leftover data between calls.

This project demonstrates:
	•	File handling in C
	•	Static variable usage
	•	Memory management (malloc/free)
	•	String manipulation

⸻

🧠 How It Works

The function is split into four main components:

🔹 1. read_and_stach()

Reads from the file descriptor into a buffer and appends the result to a static stash until either a newline is found or the end of the file is reached.

🔹 2. extract_line()

Extracts the next complete line from the stash.

🔹 3. update_stach()

Removes the extracted line from the stash and updates it with any remaining content.

🔹 4. get_next_line()

Coordinates the entire process and returns a single line per call.

⸻

📁 File Structure

get_next_line.c
get_next_line.h
get_next_line_utils.c


⸻

⚙️ Compilation

Use the following command to compile with your custom BUFFER_SIZE (example: 42):

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl


⸻

🚀 Usage

Example usage in a main program:

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}


⸻

🛠️ Utility Functions

These are required for the project and typically include:
	•	ft_strlen
	•	ft_strchr
	•	ft_strjoin
	•	ft_substr

Each function helps with string manipulation inside the main logic.

⸻

📘 Notes
	•	BUFFER_SIZE must be greater than 0
	•	Handles multiple calls for continuous reading
	•	Works with any valid file descriptor

⸻

🖊️ Author

Pedro Vicente (pedde-al) — 42 Lisboa
