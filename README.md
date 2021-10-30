# CPP Brainfuck

This project is a simple brainfuck interpreter written in C++

### Installation
Requirements
 * C++98
 * Gnu Make
 * GCC

Building
`make build`

Running
`./brainfuck -h` - Display Help
`./brainfuck -f hello.bf` - Run a brainfuck file

### Brainfuck Commands

 * `>` - Increment memory pointer
 * `<` - Decrement memory pointer
 * `+` - Add 1 to current cell
 * `-` - Subtract 1 from current cell
 * `.` - Print character in current cell (ASCII)
 * `,` - Read one byte into current cell (ASCII)
 * `[` - Start loop (LOOP ENDS WHEN CURRENT CELL IS 0)
 * `]` - End loop (Jump back to start of loop if current cell is not 0)