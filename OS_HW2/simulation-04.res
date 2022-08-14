Time: 1
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=1, 
   Ready Queue:
      pid=2, state=READY,   start=1, slice=0, 
   Blocked Queue:
      EMPTY

Time: 2
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=2, 
   Ready Queue:
      pid=2, state=READY,   start=1, slice=0, 
   Blocked Queue:
      EMPTY

Time: 3
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=3, 
   Ready Queue:
      pid=2, state=READY,   start=1, slice=0, 
   Blocked Queue:
      EMPTY

Time: 4
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=4, 
   Ready Queue:
      pid=2, state=READY,   start=1, slice=0, 
   Blocked Queue:
      EMPTY

Time: 5
   CPU (currently running):
      pid=2, state=RUNNING, start=1, slice=1, 
   Ready Queue:
      pid=3, state=READY,   start=5, slice=0, 
   Blocked Queue:
      EMPTY

Time: 6
   CPU (currently running):
      pid=2, state=RUNNING, start=1, slice=2, 
   Ready Queue:
      pid=3, state=READY,   start=5, slice=0, 
   Blocked Queue:
      EMPTY

Time: 7
   CPU (currently running):
      pid=2, state=RUNNING, start=1, slice=3, 
   Ready Queue:
      pid=3, state=READY,   start=5, slice=0, 
   Blocked Queue:
      EMPTY

Time: 8
   CPU (currently running):
      pid=2, state=RUNNING, start=1, slice=4, 
   Ready Queue:
      pid=3, state=READY,   start=5, slice=0, 
   Blocked Queue:
      EMPTY

Time: 9
   CPU (currently running):
      pid=3, state=RUNNING, start=5, slice=1, 
   Ready Queue:
      EMPTY
   Blocked Queue:
      pid=2, state=BLOCKED, start=1, slice=4, event=1

Time: 10
   CPU (currently running):
      IDLE
   Ready Queue:
      EMPTY
   Blocked Queue:
      pid=2, state=BLOCKED, start=1, slice=4, event=1

Time: 11
   CPU (currently running):
      IDLE
   Ready Queue:
      EMPTY
   Blocked Queue:
      pid=2, state=BLOCKED, start=1, slice=4, event=1

Time: 12
   CPU (currently running):
      IDLE
   Ready Queue:
      EMPTY
   Blocked Queue:
      pid=2, state=BLOCKED, start=1, slice=4, event=1

Time: 13
   CPU (currently running):
      pid=4, state=RUNNING, start=13, slice=1, 
   Ready Queue:
      pid=5, state=READY,   start=13, slice=0, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=1, slice=4, event=1

Time: 14
   CPU (currently running):
      pid=4, state=RUNNING, start=13, slice=2, 
   Ready Queue:
      pid=5, state=READY,   start=13, slice=0, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=1, slice=4, event=1

Time: 15
   CPU (currently running):
      pid=5, state=RUNNING, start=13, slice=1, 
   Ready Queue:
      pid=2, state=READY,   start=1, slice=4, 
   Blocked Queue:
      EMPTY

Time: 16
   CPU (currently running):
      pid=5, state=RUNNING, start=13, slice=2, 
   Ready Queue:
      pid=2, state=READY,   start=1, slice=4, 
   Blocked Queue:
      EMPTY

Time: 17
   CPU (currently running):
      pid=5, state=RUNNING, start=13, slice=3, 
   Ready Queue:
      pid=2, state=READY,   start=1, slice=4, 
   Blocked Queue:
      EMPTY

Time: 18
   CPU (currently running):
      pid=5, state=RUNNING, start=13, slice=4, 
   Ready Queue:
      pid=2, state=READY,   start=1, slice=4, 
   Blocked Queue:
      EMPTY

Time: 19
   CPU (currently running):
      pid=2, state=RUNNING, start=1, slice=1, 
   Ready Queue:
      EMPTY
   Blocked Queue:
      EMPTY

Time: 20
   CPU (currently running):
      pid=2, state=RUNNING, start=1, slice=2, 
   Ready Queue:
      EMPTY
   Blocked Queue:
      EMPTY

Time: 21
   CPU (currently running):
      IDLE
   Ready Queue:
      EMPTY
   Blocked Queue:
      EMPTY

Time: 22
   CPU (currently running):
      IDLE
   Ready Queue:
      EMPTY
   Blocked Queue:
      EMPTY

Time: 23
   CPU (currently running):
      pid=6, state=RUNNING, start=23, slice=1, 
   Ready Queue:
      pid=7, state=READY,   start=23, slice=0, 
   Blocked Queue:
      EMPTY

Time: 24
   CPU (currently running):
      pid=6, state=RUNNING, start=23, slice=2, 
   Ready Queue:
      pid=7, state=READY,   start=23, slice=0, 
   Blocked Queue:
      EMPTY

Time: 25
   CPU (currently running):
      pid=7, state=RUNNING, start=23, slice=1, 
   Ready Queue:
      EMPTY
   Blocked Queue:
      pid=6, state=BLOCKED, start=23, slice=2, event=3

Time: 26
   CPU (currently running):
      pid=8, state=RUNNING, start=26, slice=1, 
   Ready Queue:
      pid=9, state=READY,   start=26, slice=0, 
      pid=10, state=READY,   start=26, slice=0, 
   Blocked Queue:
      pid=6, state=BLOCKED, start=23, slice=2, event=3

Time: 27
   CPU (currently running):
      pid=9, state=RUNNING, start=26, slice=1, 
   Ready Queue:
      pid=10, state=READY,   start=26, slice=0, 
   Blocked Queue:
      pid=6, state=BLOCKED, start=23, slice=2, event=3
      pid=8, state=BLOCKED, start=26, slice=1, event=4

Time: 28
   CPU (currently running):
      pid=9, state=RUNNING, start=26, slice=2, 
   Ready Queue:
      pid=10, state=READY,   start=26, slice=0, 
      pid=6, state=READY,   start=23, slice=2, 
   Blocked Queue:
      pid=8, state=BLOCKED, start=26, slice=1, event=4

Time: 29
   CPU (currently running):
      pid=10, state=RUNNING, start=26, slice=1, 
   Ready Queue:
      pid=6, state=READY,   start=23, slice=2, 
      pid=11, state=READY,   start=29, slice=0, 
   Blocked Queue:
      pid=8, state=BLOCKED, start=26, slice=1, event=4

Time: 30
   CPU (currently running):
      pid=10, state=RUNNING, start=26, slice=2, 
   Ready Queue:
      pid=6, state=READY,   start=23, slice=2, 
      pid=11, state=READY,   start=29, slice=0, 
   Blocked Queue:
      pid=8, state=BLOCKED, start=26, slice=1, event=4

Time: 31
   CPU (currently running):
      pid=10, state=RUNNING, start=26, slice=3, 
   Ready Queue:
      pid=6, state=READY,   start=23, slice=2, 
      pid=11, state=READY,   start=29, slice=0, 
   Blocked Queue:
      pid=8, state=BLOCKED, start=26, slice=1, event=4

Time: 32
   CPU (currently running):
      pid=10, state=RUNNING, start=26, slice=4, 
   Ready Queue:
      pid=6, state=READY,   start=23, slice=2, 
      pid=11, state=READY,   start=29, slice=0, 
      pid=8, state=READY,   start=26, slice=1, 
   Blocked Queue:
      EMPTY

Time: 33
   CPU (currently running):
      pid=10, state=RUNNING, start=26, slice=5, 
   Ready Queue:
      pid=6, state=READY,   start=23, slice=2, 
      pid=11, state=READY,   start=29, slice=0, 
      pid=8, state=READY,   start=26, slice=1, 
   Blocked Queue:
      EMPTY

Time: 34
   CPU (currently running):
      pid=6, state=RUNNING, start=23, slice=1, 
   Ready Queue:
      pid=11, state=READY,   start=29, slice=0, 
      pid=8, state=READY,   start=26, slice=1, 
      pid=10, state=READY,   start=26, slice=5, 
   Blocked Queue:
      EMPTY

Time: 35
   CPU (currently running):
      pid=11, state=RUNNING, start=29, slice=1, 
   Ready Queue:
      pid=8, state=READY,   start=26, slice=1, 
      pid=10, state=READY,   start=26, slice=5, 
   Blocked Queue:
      EMPTY

Time: 36
   CPU (currently running):
      pid=11, state=RUNNING, start=29, slice=2, 
   Ready Queue:
      pid=8, state=READY,   start=26, slice=1, 
      pid=10, state=READY,   start=26, slice=5, 
   Blocked Queue:
      EMPTY

Time: 37
   CPU (currently running):
      pid=11, state=RUNNING, start=29, slice=3, 
   Ready Queue:
      pid=8, state=READY,   start=26, slice=1, 
      pid=10, state=READY,   start=26, slice=5, 
   Blocked Queue:
      EMPTY

Time: 38
   CPU (currently running):
      pid=11, state=RUNNING, start=29, slice=4, 
   Ready Queue:
      pid=8, state=READY,   start=26, slice=1, 
      pid=10, state=READY,   start=26, slice=5, 
   Blocked Queue:
      EMPTY

Time: 39
   CPU (currently running):
      pid=11, state=RUNNING, start=29, slice=5, 
   Ready Queue:
      pid=8, state=READY,   start=26, slice=1, 
      pid=10, state=READY,   start=26, slice=5, 
   Blocked Queue:
      EMPTY

Time: 40
   CPU (currently running):
      pid=8, state=RUNNING, start=26, slice=1, 
   Ready Queue:
      pid=10, state=READY,   start=26, slice=5, 
      pid=11, state=READY,   start=29, slice=5, 
   Blocked Queue:
      EMPTY

Time: 41
   CPU (currently running):
      pid=10, state=RUNNING, start=26, slice=1, 
   Ready Queue:
      pid=11, state=READY,   start=29, slice=5, 
   Blocked Queue:
      EMPTY

Time: 42
   CPU (currently running):
      pid=10, state=RUNNING, start=26, slice=2, 
   Ready Queue:
      pid=11, state=READY,   start=29, slice=5, 
   Blocked Queue:
      EMPTY

Time: 43
   CPU (currently running):
      pid=11, state=RUNNING, start=29, slice=1, 
   Ready Queue:
      EMPTY
   Blocked Queue:
      EMPTY

