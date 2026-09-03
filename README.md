*This project has been created as part of the 42 curriculum by saydilek, fguloglu.*

# Push_swap

## Description

Push_swap is a sorting project based on two stacks, `a` and `b`, and a limited set of allowed stack operations.

The goal of the project is to sort a list of unique signed integers in ascending order while generating an efficient sequence of Push_swap instructions.

At the beginning:

- stack `a` contains all input integers
- stack `b` is empty

Instead of printing the sorted numbers directly, the program prints the operations required to transform the initial stacks into a state where stack `a` is sorted and stack `b` is empty.

The project implements four sorting strategies:

- Simple: O(n^2)
- Medium: O(n sqrt(n))
- Complex: O(n log(n))
- Adaptive: selects a strategy according to the disorder of the input

The program also implements the optional `--bench` mode required by the subject. Sorting instructions remain on standard output while benchmark information is written to standard error.

## Contributions

### saydilek

- implemented and developed the sorting strategies
- worked on simple, medium, radix, and adaptive sorting
- implemented strategy selection and program integration
- worked on stack utility functions
- optimized operation counts and performance
- contributed to testing, debugging, Norminette cleanup, and final project integration

### fguloglu

- worked on the core Push_swap operations
- implemented input parsing and validation
- worked on split and memory-management utilities
- implemented the benchmark and operation-counter systems
- contributed to header integration, testing, debugging, and Norminette cleanup

### Shared Work

Both learners participated in code review, edge-case testing, performance validation, documentation, and final project review.

Both learners understand the complete project and are expected to be able to explain and defend every part of the code during the evaluation.

## Instructions

### Compilation

Compile the project with:

```sh
make
```

This creates the `push_swap` executable.

Remove object files with:

```sh
make clean
```

Remove object files and the executable with:

```sh
make fclean
```

Rebuild the complete project with:

```sh
make re
```

### Basic Usage

```sh
./push_swap 4 67 3 87 23
```

The output is a sequence of valid Push_swap operations.

Example:

```text
pb
ra
pa
```

If the input is already sorted, the program prints nothing.

If no arguments are provided, the program also prints nothing.

### Strategy Selection

A sorting strategy can be selected manually:

```sh
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

If no strategy selector is provided, the program uses adaptive mode by default.

### Benchmark Mode

Benchmark mode can be enabled with:

```sh
./push_swap --bench 4 67 3 87 23
```

It can also be combined with a strategy:

```sh
./push_swap --bench --complex 4 67 3 87 23
```

Push_swap operations remain on standard output.

Benchmark information is written to standard error and includes:

- initial disorder percentage
- selected strategy
- theoretical complexity
- total number of generated operations
- count of every Push_swap operation

## Push_swap Operations

The project uses the following operations.

### Swap

`sa`

Swap the first two elements of stack `a`.

`sb`

Swap the first two elements of stack `b`.

`ss`

Perform `sa` and `sb` at the same time.

### Push

`pa`

Take the first element of stack `b` and put it on top of stack `a`.

`pb`

Take the first element of stack `a` and put it on top of stack `b`.

### Rotate

`ra`

Move the first element of stack `a` to the bottom.

`rb`

Move the first element of stack `b` to the bottom.

`rr`

Perform `ra` and `rb` at the same time.

### Reverse Rotate

`rra`

Move the last element of stack `a` to the top.

`rrb`

Move the last element of stack `b` to the top.

`rrr`

Perform `rra` and `rrb` at the same time.

## Stack Representation

The stacks are implemented as linked lists.

Each node stores:

```c
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;
```

`value` contains the original integer.

`index` contains the normalized sorted position of the integer.

`next` points to the next node in the stack.

## Index Normalization

The sorting strategies use normalized indexes instead of operating only on the original integer values.

Example:

```text
original values:
42 -5 100 7

indexes:
2 0 3 1
```

The sorted order is:

```text
-5 -> index 0
7 -> index 1
42 -> index 2
100 -> index 3
```

The original values remain unchanged.

Index normalization is especially useful for radix sorting because every index is non-negative and belongs to the compact range:

```text
0 ... n - 1
```

## Disorder Metric

The adaptive strategy calculates the disorder of the original input before performing any sorting operation.

Disorder is calculated using inversions.

For every pair of positions `(i, j)` where:

```text
i < j
```

the pair is considered inverted when:

```text
value[i] > value[j]
```

The disorder is:

```text
number of inverted pairs / total number of pairs
```

The value is between `0` and `1`.

A disorder of:

```text
0
```

means the stack is already sorted.

A disorder of:

```text
1
```

means the stack is in the worst possible reverse order.

The adaptive strategy uses the required thresholds:

```text
disorder < 0.2
```

Simple strategy.

```text
0.2 <= disorder < 0.5
```

Medium strategy.

```text
disorder >= 0.5
```

Complex strategy.

These thresholds correspond to the low, medium, and high disorder regimes required by the subject.

## Algorithms

### Simple Strategy - O(n^2)

The simple strategy is based on repeatedly extracting the next smallest normalized index.

First, every node receives its sorted index.

The algorithm starts with target index `0`.

It searches for the target inside stack `a` and calculates its position.

Depending on that position, the target is moved to the top using:

- `sa`
- `ra`
- `rra`

When the target reaches the top, it is pushed to stack `b` using `pb`.

The algorithm then searches for the next target index.

Once the remaining part of stack `a` is sorted, all elements stored in stack `b` are pushed back to stack `a`.

This strategy is useful for low-disorder inputs because it can stop early when the remaining stack is already sorted.

#### Complexity

For each of up to `n` target elements, moving the target to the top may require O(n) Push_swap operations.

Therefore:

```text
O(n) * O(n) = O(n^2)
```

The Push_swap operation upper bound is:

```text
O(n^2)
```

### Medium Strategy - O(n sqrt(n))

The medium strategy uses a bucket-style sorting method.

After index normalization, the algorithm calculates a bucket base from approximately:

```text
sqrt(n)
```

A constant scaling factor is applied to improve the practical operation count while keeping the same asymptotic complexity class.

The algorithm processes indexes using two concepts:

```text
base
divisor
```

During a bucket pass, the current bucket of every index is calculated using:

```text
(index / divisor) % base
```

Values matching the current bucket are pushed from stack `a` to stack `b`.

Other values are rotated inside stack `a`.

After the pass, the elements in stack `b` are pushed back to stack `a`.

The divisor is multiplied by the base after every full pass:

```text
divisor *= base
```

This allows the algorithm to process different parts of the normalized index.

The approach is similar to a multi-base bucket/radix process.

#### Complexity

The base remains proportional to:

```text
sqrt(n)
```

Each bucket may require scanning a linear number of nodes.

Therefore the generated Push_swap operation upper bound is:

```text
O(n sqrt(n))
```

The medium strategy is used for inputs with intermediate disorder.

It provides better scalability than the simple strategy while avoiding the fixed binary passes of the complex strategy.

### Complex Strategy - O(n log(n))

The complex strategy uses LSD binary radix sort adapted to the Push_swap model.

The original values are first converted into normalized indexes.

Example:

```text
values:
50 -10 900 7

indexes:
2 0 3 1
```

The algorithm then processes each binary bit of the indexes.

For each bit position:

If the current bit is `0`:

```text
pb
```

is used to move the node to stack `b`.

If the current bit is `1`:

```text
ra
```

is used to keep the node inside stack `a` while moving to the next element.

After all nodes have been inspected for the current bit:

```text
pa
```

is used until stack `b` is empty again.

The process repeats for every required bit.

For indexes between:

```text
0
```

and:

```text
n - 1
```

the number of required bits grows logarithmically with `n`.

#### Complexity

Each bit requires O(n) Push_swap operations.

The number of bits is:

```text
O(log(n))
```

Therefore:

```text
O(n) * O(log(n)) = O(n log(n))
```

The final Push_swap operation complexity is:

```text
O(n log(n))
```

The complex strategy is used for highly disordered inputs because it provides predictable scaling as the input grows.

### Adaptive Strategy

Adaptive mode is the default strategy.

It first calculates the disorder of the original stack.

No Push_swap operation is performed before this measurement.

The strategy then selects:

```text
disorder < 0.2
-> Simple
-> O(n^2)
```

```text
0.2 <= disorder < 0.5
-> Medium
-> O(n sqrt(n))
```

```text
disorder >= 0.5
-> Complex
-> O(n log(n))
```

The reason for using multiple strategies is that the same algorithm is not equally suitable for every input configuration.

A nearly sorted stack can benefit from the early termination behavior of the simple strategy.

A moderately disordered stack uses the bucket-based medium strategy.

A highly disordered stack uses radix sorting for predictable O(n log(n)) operation scaling.

## Complexity and Space Usage

The complexity classes required by the project refer primarily to the number of generated Push_swap operations.

The C-level computation required to decide which operations to generate is discussed separately where relevant.

### Simple

Push_swap operation complexity:

```text
O(n^2)
```

Auxiliary sorting space:

```text
O(1)
```

The algorithm uses the existing stack nodes and only a fixed number of local variables.

### Medium

Push_swap operation complexity:

```text
O(n sqrt(n))
```

Auxiliary sorting space:

```text
O(1)
```

The bucket algorithm works directly on stacks `a` and `b`.

It does not allocate an additional array or dynamically sized sorting structure.

### Complex

Push_swap operation complexity:

```text
O(n log(n))
```

Auxiliary sorting space:

```text
O(1)
```

Radix sorting reuses the two existing stacks and processes the stored normalized indexes directly.

### Adaptive

Adaptive mode inherits the operation complexity of the selected strategy:

```text
low disorder:
O(n^2)
```

```text
medium disorder:
O(n sqrt(n))
```

```text
high disorder:
O(n log(n))
```

The disorder calculation itself compares all possible pairs.

Therefore its C-level comparison complexity is:

```text
O(n^2)
```

However, calculating disorder generates no Push_swap operations.

The disorder calculation uses:

```text
O(1)
```

auxiliary memory.

### Input Storage

The stack itself contains one linked-list node for each input integer.

Therefore storing the input requires:

```text
O(n)
```

memory.

## Input Validation

Every input value is validated before sorting begins.

In case of an error, the program prints:

```text
Error
```

followed by a newline on standard error.

Handled invalid input includes:

- duplicate integers
- values larger than `INT_MAX`
- values smaller than `INT_MIN`
- alphabetic input
- malformed numeric input
- invalid characters
- empty arguments
- whitespace-only arguments
- malformed signs
- missing input after a strategy selector
- missing input after `--bench`

The accepted signed integer range is:

```text
-2147483648
```

to:

```text
2147483647
```

Quoted lists are supported.

Example:

```sh
./push_swap "3 2 1"
```

Multiple quoted lists are also supported:

```sh
./push_swap "5 4" "3 2" "1"
```

## Benchmark Implementation

The benchmark system records statistics without changing the normal Push_swap output stream.

Sorting operations are written to:

```text
stdout
```

Benchmark information is written to:

```text
stderr
```

The benchmark records:

- initial disorder
- selected strategy
- theoretical complexity
- total number of operations
- `sa`
- `sb`
- `ss`
- `pa`
- `pb`
- `ra`
- `rb`
- `rr`
- `rra`
- `rrb`
- `rrr`

The operation counter is only updated when an operation is actually emitted.

Example:

```sh
./push_swap --bench 3 51 2 55319431 53 319 5319
```

Example benchmark report:

```text
=== BENCHMARK REPORT ===
Disorder: 23.81%
Strategy: Adaptive
Complexity: O(n*sqrt(n))
Total Operations: 31
------------------------
sa: 0 | sb: 0 | ss: 0
pa: 10 | pb: 10
ra: 11 | rb: 0 | rr: 0
rra: 0 | rrb: 0 | rrr: 0
========================
```

## Performance

Randomized tests were performed by generating unique signed integers and running the program.

The generated instructions were replayed independently to verify that:

- stack `a` becomes sorted
- stack `b` becomes empty
- every generated instruction is valid

### 100 Random Numbers

50 randomized tests were executed.

Results:

```text
50 / 50 sorted correctly
```

Observed operation range:

```text
approximately 1000 - 1080
```

Average:

```text
approximately 1053 operations
```

All 50 tests reached the subject's good-performance threshold.

### 500 Random Numbers

50 randomized tests were executed.

Results:

```text
50 / 50 sorted correctly
```

Observed operation range:

```text
approximately 6730 - 7150
```

Average:

```text
approximately 6993 operations
```

All 50 tests reached the subject's good-performance threshold.

### 1000 Random Numbers

20 additional stress tests were executed.

Results:

```text
20 / 20 sorted correctly
```

Observed operation range:

```text
approximately 14990 - 18150
```

The subject does not define an official performance target for 1000 elements.

These tests were used only for additional correctness and stability validation.

### Subject Performance Thresholds

| Input Size | Pass | Good | Excellent |
|---|---:|---:|---:|
| 100 | < 2000 | < 1500 | < 700 |
| 500 | < 12000 | < 8000 | < 5500 |

## Testing

The project has been tested for:

- no arguments
- single values
- already sorted input
- reverse-sorted input
- signed integers
- `INT_MIN`
- `INT_MAX`
- positive integer overflow
- negative integer overflow
- extremely large numeric strings
- duplicate values
- alphabetic input
- malformed input
- empty arguments
- whitespace-only arguments
- quoted lists
- multiple quoted lists
- all four strategy selectors
- strategy selectors without input
- benchmark mode
- benchmark operation counting
- randomized 100-element inputs
- randomized 500-element inputs
- randomized 1000-element stress inputs

The code was compiled using:

```sh
-Wall -Wextra -Werror
```

The source files were also checked successfully with Norminette in the development environment.

Before the final evaluation, Linux-specific validation should also be performed in the 42 environment using:

- the project Makefile
- the official checker
- memory-leak checking
- relink checks

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
- linked-list data-structure references
- stack data-structure references
- radix-sort references
- bucket-sort references
- material about inversion counting
- material about algorithmic complexity
- 42 Norm documentation

### AI Usage

AI tools were used during development to assist with:

- repetitive refactoring tasks
- Norminette-oriented code review
- debugging
- edge-case analysis
- generation of stress-test cases
- review of input-validation behavior
- review of algorithmic complexity arguments
- performance analysis
- documentation
- explanations of C concepts
- explanations of pointers and linked lists
- explanations of stack operations
- explanations of the sorting algorithms

AI-generated suggestions were reviewed, adapted, compiled, and tested by the project members before being included in the project.