*This project has been created as part of the 42 curriculum by saydilek, fguloglu.*

# Push_swap

## Description

Push_swap is a sorting project built around two stacks, `a` and `b`, and a restricted set of stack operations.

The goal is to sort a list of unique integers in ascending order while generating a valid sequence of Push_swap operations.

The project implements four sorting strategies:

- Simple: O(n^2)
- Medium: O(n sqrt(n))
- Complex: O(n log(n))
- Adaptive: automatically selects a strategy according to the disorder of the input

The program also includes an optional benchmark mode that reports the input disorder, selected strategy, theoretical complexity, total operation count, and individual operation counts.

## Instructions

### Compilation

Compile the project with:

```sh
make
```

This creates the `push_swap` executable.

To remove object files:

```sh
make clean
```

To remove object files and the executable:

```sh
make fclean
```

To rebuild everything:

```sh
make re
```

### Basic Usage

```sh
./push_swap 4 67 3 87 23
```

The program prints the sequence of Push_swap operations required to sort the input.

Already sorted input produces no operations.

### Strategy Selection

The strategy can be forced with one of the following flags:

```sh
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

If no strategy flag is provided, adaptive mode is used by default.

### Benchmark Mode

Benchmark mode can be enabled with:

```sh
./push_swap --bench 4 67 3 87 23
```

Sorting operations are written to standard output.

The benchmark report is written to standard error and contains:

- disorder percentage
- selected strategy
- theoretical complexity
- total number of operations
- count of each Push_swap operation

Benchmark mode can also be combined with a strategy:

```sh
./push_swap --bench --complex 4 67 3 87 23
```

## Push_swap Operations

The project uses the following operations:

- `sa`: swap the first two elements of stack a
- `sb`: swap the first two elements of stack b
- `ss`: perform `sa` and `sb`
- `pa`: push the first element of b onto a
- `pb`: push the first element of a onto b
- `ra`: rotate stack a
- `rb`: rotate stack b
- `rr`: perform `ra` and `rb`
- `rra`: reverse rotate stack a
- `rrb`: reverse rotate stack b
- `rrr`: perform `rra` and `rrb`

## Algorithms

### Simple Strategy - O(n^2)

The simple strategy uses the normalized index of each value.

Starting from the smallest target index, it finds the target inside stack `a` and moves it to the top using swap, rotate, or reverse rotate depending on its position.

The value is then pushed to stack `b`.

This process is repeated until the remaining stack is sorted, after which every value stored in `b` is pushed back to `a`.

Finding and moving successive target values may require traversing or rotating a significant portion of the stack for each element.

Therefore, the worst-case number of Push_swap operations belongs to the O(n^2) complexity class.

### Medium Strategy - O(n sqrt(n))

The medium strategy first assigns each value a normalized index from `0` to `n - 1`.

It then processes these indexes using bucket-style passes.

The bucket base is derived from the square root of the input size. A constant scaling factor is applied to improve the practical operation count without changing the asymptotic complexity class.

During each pass, values belonging to the currently processed bucket are moved between stacks while the remaining values are rotated.

The divisor is increased between passes so that different parts of the normalized indexes can be processed.

Because the number of buckets scales proportionally to sqrt(n), the operation upper bound remains in the O(n sqrt(n)) class.

### Complex Strategy - O(n log(n))

The complex strategy uses an LSD binary radix sort adapted to the two-stack Push_swap model.

Every input value is first assigned a normalized index.

Instead of processing the original potentially negative or very large values directly, the algorithm works with indexes in the range `0` to `n - 1`.

For each bit position:

- values whose current bit is `0` are pushed from stack `a` to stack `b`
- values whose current bit is `1` are rotated inside stack `a`
- after the current bit has been processed, all values stored in `b` are pushed back to `a`

The number of bit positions required grows logarithmically with the number of elements.

Each bit requires a linear number of Push_swap operations.

Therefore, the operation complexity is O(n log(n)).

### Adaptive Strategy

The adaptive strategy measures the disorder of the original stack before performing any sorting operations.

Disorder is calculated using inversions.

For every pair of elements `(i, j)` where `i < j`, the pair is considered inverted if the value at position `i` is greater than the value at position `j`.

The disorder value is calculated as:

```text
number of inverted pairs / total number of pairs
```

The result is a value between `0` and `1`.

The adaptive strategy uses the following thresholds:

- disorder < 0.2: Simple strategy
- 0.2 <= disorder < 0.5: Medium strategy
- disorder >= 0.5: Complex strategy

This allows the program to select an algorithm according to how far the initial input is from a sorted configuration.

## Index Normalization

The sorting algorithms use normalized indexes instead of directly operating on the original integer values.

For example:

```text
Original values:
42 -5 100 7

Indexes:
2 0 3 1
```

The smallest value receives index `0`, the next smallest receives index `1`, and so on.

This is especially useful for radix sorting because all indexes are non-negative and limited to the range `0` to `n - 1`.

## Input Validation

The program validates every argument before sorting.

Invalid input prints:

```text
Error
```

to standard error.

Invalid cases include:

- duplicate integers
- values outside the signed 32-bit integer range
- non-numeric arguments
- malformed signs
- empty arguments
- arguments containing invalid characters
- missing integer input after a strategy flag
- missing integer input after the benchmark flag

Valid integer values must remain between:

```text
-2147483648
```

and:

```text
2147483647
```

Quoted lists are also supported.

For example:

```sh
./push_swap "3 2 1"
```

and:

```sh
./push_swap "5 4" "3 2" "1"
```

are valid inputs.

## Benchmark

The optional benchmark system records information about a sorting run without changing the normal Push_swap operation stream.

Operations continue to be printed to standard output.

Benchmark information is printed to standard error.

The report contains:

- initial disorder
- selected strategy
- theoretical complexity
- total operation count
- `sa` count
- `sb` count
- `ss` count
- `pa` count
- `pb` count
- `ra` count
- `rb` count
- `rr` count
- `rra` count
- `rrb` count
- `rrr` count

Example:

```sh
./push_swap --bench 3 51 2 55319431 53 319 5319
```

## Performance

Randomized tests were performed by generating unique integers, running Push_swap, replaying every generated operation, and verifying that:

- stack `a` is completely sorted
- stack `b` is empty
- every generated instruction is a valid Push_swap operation

### 100 Random Numbers

50 randomized tests were executed successfully.

Observed operation counts were approximately:

```text
1000 - 1080 operations
```

Average:

```text
approximately 1053 operations
```

All 50 tests reached the subject's good-performance threshold.

### 500 Random Numbers

50 randomized tests were executed successfully.

Observed operation counts were approximately:

```text
6730 - 7150 operations
```

Average:

```text
approximately 6993 operations
```

All 50 tests reached the subject's good-performance threshold.

### 1000 Random Numbers

20 additional stress tests were executed successfully.

Observed operation counts were approximately:

```text
14990 - 18150 operations
```

The subject does not define an official performance threshold for 1000 elements. These tests were used only for additional correctness and stability validation.

### Subject Performance Thresholds

| Input Size | Pass | Good | Excellent |
|---|---:|---:|---:|
| 100 | < 2000 | < 1500 | < 700 |
| 500 | < 12000 | < 8000 | < 5500 |

## Testing

The project was tested for:

- no arguments
- already sorted input
- reverse-sorted input
- single integer input
- signed values
- `INT_MIN`
- `INT_MAX`
- positive overflow
- negative overflow
- extremely large numeric strings
- duplicate values
- alphabetic input
- malformed numeric input
- empty strings
- whitespace-only strings
- quoted arguments
- multiple quoted arguments
- all strategy selectors
- benchmark mode
- random 100-element inputs
- random 500-element inputs
- random 1000-element inputs

The project was also compiled with:

```sh
-Wall -Wextra -Werror
```

and checked with Norminette.

Final Linux-specific testing, including the official checker, Makefile behavior, and memory checking, is intended to be performed in the 42 environment.

## Project Structure

```text
push_swap.c
push_swap.h

operations_push.c
operations_swap.c
operations_rotate.c
operations_reverse.c

sort_simple.c
sort_medium.c
sort_radix.c
sort_adaptive.c

stack_utils.c
strategy.c
parse.c
split.c
free.c

benchmark.c
benchmark_counter.c

Makefile
README.md
```

## Resources

Resources used while working on the project include:

- the official 42 Push_swap subject
- C manual pages for `write`, `malloc`, `free`, and `exit`
- linked-list and stack data structure references
- radix sort references
- material about inversion counting and disorder measurements
- 42 Norm documentation

### AI Usage

AI tools were used during development to assist with:

- repetitive code refactoring
- Norminette-oriented code review
- debugging
- edge-case analysis
- generating stress-test cases
- reviewing input-validation behavior
- checking algorithmic complexity arguments
- documentation
- explanations of C concepts, pointers, linked lists, stacks, and sorting algorithms

AI-generated suggestions were reviewed, adapted, compiled, and tested by the project members before being included in the project.