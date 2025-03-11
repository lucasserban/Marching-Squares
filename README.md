# Marching-Squares
MARCHING SQUARES ALGORITHM:

I dynamically allocate the matrices I will need for the program. I take input from the keyboard, which is of string type, and compare it with each possible command. If the input and command are identical, it enters the sequence of the respective command. Each command has a main function. In most of the functions, I use the address of the dynamically allocated matrix.
READ: I read the input from the keyboard, and if the input is in the form MxN, then a matrix of Mx3*N will be read from the keyboard, since each pixel contains 3 values. These values are stored in the dynamically allocated matrix initially. If the values entered exceed the specified limits (also given in the input) or if fewer elements are entered than needed, the main function of the command will return a specific error number for each case.

WRITE: I print the dynamically allocated matrix to the output. This command can be used after a READ, RESIZE, or MARCH command.

RESIZE: In the main function of the RESIZE command, I dynamically allocate memory for an auxiliary matrix, which has larger dimensions by a factor of RESIZE or greater than the previous matrix (in our case, RESIZE is 4). I then take the pixel values from the original matrix, and each pixel is transformed into a RESIZExRESIZE matrix of pixels. Afterward, I reallocate memory for the original matrix and copy the auxiliary matrix into the original one, freeing the memory of the auxiliary matrix.

GRID: In the main function of the GRID command, I dynamically allocate the grid matrix with a size of VALOARE_SAMPLING times smaller + 1 (in our case, VALOARE_SAMPLING is 4). Then, I calculate the brightness of each pixel by averaging the three RGB values. After that, in a for loop, I check every 4x4 pixel block from left to right and top to bottom to see if it has neighbors, and calculate their average. Finally, I store the result in the grid matrix.

INIT_CONTUR: For the INIT_CONTUR command, I created a function for each template. Also, the main function of this command is called within the main function of the MARCH command to retrieve the template. Therefore, when the command INIT_CONTUR is called, it will print all 16 templates in the output along with their characteristics (P3, 4 4... etc.).

MARCH: In the main function of the MARCH command, I dynamically reallocate the original matrix. Then, I go through each "square" made up of 4 elements of the grid matrix. Through a mathematical calculation and a function that converts binary numbers to decimal, I find the number and the template represented by that square, call the INIT_CONTUR function to get the corresponding template, and place the template in the original matrix. If the GRID command has not been called before, calling MARCH will automatically call GRID beforehand.
