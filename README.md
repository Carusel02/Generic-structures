# Generic structure

## Solution
- The ***main idea*** consists in the dynamic allocation of a structure,  reading some data and adding them to the `data_element` structure.
- Given a `vector *arr`, all memory (not addresses) from that one the data_element structure must be copied into the `*arr vector` bythrough the memcpy function and with the help of some functions.
-  All the implementation is based on a **"play"** with the size of a reading, respectively with bytes allocated to a read.

## Observation:
- I stored all the content of the head with `memcpy`. It contains 8 bytes, 1 byte for char type and the next 3 also for him (padding) and 4 bytes for len.
- I also used the necessary casts to be able to read and writes data into the `generic vector`.

## Functions:
1. `main`: 
- besides the main things declared in main, I have used a while (with the purpose of an infinite loop) until we read from
exit command keyboard. With `strcmp` we see what command we have to execute, then depending on the requirement we enter a personalized if.
2. `write_data`: 
- after dynamically allocating a structure in main, I have transmitted as a parameter to be able to read and store the data
in the respective structure, after the 3 types of data insertion
reading presented in the request. 
- it is worth mentioning that it must also transmitted the `**arr vector` because I called it inside this function
`add_last` (at the end I was careful to give free everything that was allocated)
- I had to use memcpy to store the data in the `generic pointer` empty
3. `add_last`:
- with the `add_last` function I copied memcpy from the structure `data_element` recently completed in the `vector *arr`. I had to save
the initial value of the pointer address so as not to lose it.
- I copied the head after I jumped by 8 bytes then I copied the entire void data field with
the size extracted from the head. (after I increased the size of the arr vector)
- in the beginning the `*arr vector` must be allocated dynamically each time fixed with
size to be added
4. `write_element`: 
- similar to `write_data`, I used one to be able to
read and insert an element at an index. 
- It has the same principle as `write_data`, only that it calls another function. ( `add_at` )
5. `add_at`: 
- the idea of this function is to first reallocate the vector ours to make room for the new element, then let's go through the vector
to the index. Then we copy bytes from the index address + size the inserted element from the index address with `memcpy`, then we copy from
index address to index address + element size element.
- then we make the `vector address *arr` the initial one to print again if we want
the vector *arr
6. `delete_at`: 
- we go through the vector until the index, this time we copy bytes from `address *arr` + size deleted element at `address *arr` and then reallocate the vector
with len - element size
7. `find`:
- the find function has the principle of traversing the vector up to the index. That let's do this, in a while we read the length of an element by moving 4 bytes (after type char (1 byte) + 3 bytes padding) and after `*arr` will be increased by 8 (the size of a head) + the length of the element and then a counter increases. We keep doing this until the counter will be equal to the index. Then we display the element
8. `print`:
- the same way of working as find only that we scroll until we reach the length len.
(the whole `vector`).
- to read the data, we first find out what type it is and then we move with x no
of bytes depending on how they are located (for example if the banknotes are of type int8_t it means they have 1 byte. the first part of `*arr` is the head (in the first 4 bytes is the type and in the following is len, we jump by 8 bytes, we reach the date where the first string is located, we jump by its length and
we reach the first banknote, we jump with one byte we reach 2 a, we jump with another byte we reach the last line)
- it is worth mentioning that when reading and writing, we must be careful in order to be able to figure it out
exactly what kind (type) of data we are reading. (I also have the expression (char *)arr + x in the code, that's what it means
that I move x bytes implicitly because *arr is now of pointer char type and, according to pointer arithmetic,
they jump with their length, if we had (int *)arr + x we jump with 4 * x because the int pointer jumps with 4
bytes).
9. `exit`: 
- when we read exit we exit, creating a variable that helps us move to the next iteration in while
to no longer comply with the while condition (it's a `flag`)
