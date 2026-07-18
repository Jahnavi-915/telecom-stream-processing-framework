# TC-01 Balanced Baseline

## Objective

Validate producer-consumer functionality under balanced operating conditions.

## Configuration

Buffer Size: 5

Frames Generated: 20

Producer Delay: 100 ms

Consumer Delay: 100 ms

## Results

Frames Produced: 20

Frames Consumed: 20

Buffer Full Events: 0

Buffer Empty Events: 12

Execution Time: 2.0074 seconds

Throughput: 9.96 frames/sec

Average Buffer Occupancy: 0.50

Buffer Utilization: 10.00%

## Observations

* All generated frames were successfully consumed.
* No frame loss or duplication was observed.
* No buffer overflow conditions occurred.
* Consumer frequently encountered an empty buffer because processing and production rates were equal.
* Average buffer occupancy remained low throughout execution.
* Throughput remained close to the theoretical maximum for the selected delay configuration.

## Conclusion

PASS

The implementation demonstrated correct synchronization, stable execution, and efficient operation under balanced producer-consumer conditions.
