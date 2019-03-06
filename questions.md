# Questions

## What's `stdint.h`?

`stdint.h` is a header file, which contains info that'll be used when running the program, like function definitions. 

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Data types indicate to the compiler how a particular value will be used, and also how much storage space needs to be allocated for the value. 

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

Data Type|Bytes
---|:---:
BYTE|1
DWORD|4
LONG|4
WORD|2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes must be "0x42 0x4D" ("66 77" in decimal, "BM" in ASCII) to indicate that the file is indeed a bitmap.  

## What's the difference between `bfSize` and `biSize`?

`bfSize` specifies the size of a bitmap file in bytes--including the file header as will as the image. 'biSize' specifies the size of the bitmap image itself in bytes. 

## What does it mean if `biHeight` is negative?

A negative `biHeight` indicates that the bitmap is organized top-down, starting from the upper left corner. 

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount` specifies the bits per pixel. 

## Why might `fopen` return `NULL` in `copy.c`?

`fopen` will return `NULL` when the filename supplied as an arguement does not exist in the directory where the program is saved. 

## Why is the third argument to `fread` always `1` in our code?

The third argument specifies the number of times to read in a block of the size provided as the second argument. It's used in three places in `copy.c`: to read in the two headers, and lastly in a loop, where, in each iteration, a single RGBTRIPLE is read in. In each of these cases, a single chunk is dealt with at a time--hence the `1`. 
## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

If `bi.biwidth` is `3`, `3` is assigned to `padding`.
## What does `fseek` do?

`fseek` moves the position of the file pointer--in copy.c, for example, it's used to move past any padding in the input file. 

## What is `SEEK_CUR`?

`SEEK_CUR` is a constant within the function `fseek` which indicates that the pointer should be moved the total specified amount with respect to its current position, rather than the beginning or end of the file. 
