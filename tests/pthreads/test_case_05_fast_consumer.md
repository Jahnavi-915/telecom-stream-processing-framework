# TC-05 Fast Consumer Test

## Objective

Evaluate synchronization behavior when the consumer operates faster than the producer.

## Configuration

Buffer Size: 5

Frames Generated: 20

Producer Delay: 100 ms

Consumer Delay: 50 ms

## Results

Frames Produced: 20

Frames Consumed: 20

Buffer Full Events: 0

Buffer Empty Events: 20

Execution Time: 2.0031 seconds

Throughput: 9.98 frames/sec

Average Buffer Occupancy: 0.50

Buffer Utilization: 10.00%

## Observations

* All generated frames were successfully consumed.
* No frame loss or duplication was observed.
* Consumer frequently encountered an empty buffer and entered the waiting state.
* Buffer Empty Events increased significantly compared to the balanced baseline.
* No buffer overflow conditions occurred.
* Average buffer occupancy remained low throughout execution.
* Throughput remained similar to the baseline because overall completion time was limited by producer generation speed.

## Conclusion

PASS

The implementation correctly handled consumer-heavy workloads. Synchronization mechanisms successfully prevented buffer underflow while maintaining stable execution and data integrity.
