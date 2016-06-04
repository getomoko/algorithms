### Character recognition
#### Description
character recognition is the conversion of images into text. For now we consider each character in the picture is a N`*`M matrix with only zeros ans ones, and we need to recognize K characters. You are to write a program to find minimal number of pixels so that we can recognize each character. For example, we have only two characters 'T' and 'L', and the matrix size is 3`*`3 , we can think 'T' and 'L'  are 111 100 010, 100 010 111 so we can recognize the charater with only bottom-left pixel, the answer is 1.

#### Input
The first line of input if three intergers N,M,K(1<=N,M<=10, 2<=K<=6). Which represents the size of matrix and number of characters. There is following K blocks, which represents the matrix. Notice that each block starts with a blank line.

#### ouput
You should ouput the minimum number of pixels, which is the answer.

### Sample test
#### input
    2 3 2

    111
    010
    
    100
    100

#### output
    1
