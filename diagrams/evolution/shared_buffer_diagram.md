# Shared Buffer Architecture

## Circular Buffer Structure

```text
Buffer Size = 5

+-----+-----+-----+-----+-----+
|  0  |  1  |  2  |  3  |  4  |
+-----+-----+-----+-----+-----+
    ^
    |
  head

                tail
                 |
                 v
+-----+-----+-----+-----+-----+
| F1  | F2  | F3  |    |    |
+-----+-----+-----+-----+-----+

count = 3
```

## Buffer Components

```text
head  -> Next frame removal position
tail  -> Next frame insertion position
count -> Current number of frames
```

## Circular Movement

```text
tail = (tail + 1) % BUFFER_SIZE

0 -> 1 -> 2 -> 3 -> 4 -> 0
```

```text
head = (head + 1) % BUFFER_SIZE

0 -> 1 -> 2 -> 3 -> 4 -> 0
```

This allows continuous insertion and removal without shifting elements.
