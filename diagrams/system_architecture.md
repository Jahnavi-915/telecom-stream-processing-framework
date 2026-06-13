# System Architecture

+-------------------+
|  Producer Thread  |
+---------+---------+
          |
          | Generate Frame
          v
+-------------------+
|   Shared Buffer   |
|  (Circular Queue) |
+---------+---------+
          ^
          | Consume Frame
          |
+---------+---------+
|  Consumer Thread  |
+-------------------+