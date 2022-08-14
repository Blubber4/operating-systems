Time: 1
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=1, 
   Ready Queue:
      EMPTY
   Blocked Queue:
      EMPTY

Time: 2
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=2, 
   Ready Queue:
      EMPTY
   Blocked Queue:
      EMPTY

Time: 3
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=3, 
   Ready Queue:
      EMPTY
   Blocked Queue:
      EMPTY

Time: 4
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=4, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=0, 
      pid=3, state=READY,   start=4, slice=0, 
      pid=4, state=READY,   start=4, slice=0, 
   Blocked Queue:
      EMPTY

Time: 5
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=5, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=0, 
      pid=3, state=READY,   start=4, slice=0, 
      pid=4, state=READY,   start=4, slice=0, 
   Blocked Queue:
      EMPTY

Time: 6
   CPU (currently running):
      pid=2, state=RUNNING, start=4, slice=1, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=0, 
      pid=4, state=READY,   start=4, slice=0, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      EMPTY

Time: 7
   CPU (currently running):
      pid=2, state=RUNNING, start=4, slice=2, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=0, 
      pid=4, state=READY,   start=4, slice=0, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      EMPTY

Time: 8
   CPU (currently running):
      pid=3, state=RUNNING, start=4, slice=1, 
   Ready Queue:
      pid=4, state=READY,   start=4, slice=0, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=2, event=1

Time: 9
   CPU (currently running):
      pid=4, state=RUNNING, start=4, slice=1, 
   Ready Queue:
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=2, event=1
      pid=3, state=BLOCKED, start=4, slice=1, event=1

Time: 10
   CPU (currently running):
      pid=4, state=RUNNING, start=4, slice=2, 
   Ready Queue:
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=2, event=1
      pid=3, state=BLOCKED, start=4, slice=1, event=1

Time: 11
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=1, 
   Ready Queue:
      EMPTY
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=2, event=1
      pid=3, state=BLOCKED, start=4, slice=1, event=1
      pid=4, state=BLOCKED, start=4, slice=2, event=1

Time: 12
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=2, 
   Ready Queue:
      pid=5, state=READY,   start=12, slice=0, 
      pid=6, state=READY,   start=12, slice=0, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=2, event=1
      pid=3, state=BLOCKED, start=4, slice=1, event=1
      pid=4, state=BLOCKED, start=4, slice=2, event=1

Time: 13
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=3, 
   Ready Queue:
      pid=5, state=READY,   start=12, slice=0, 
      pid=6, state=READY,   start=12, slice=0, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=2, event=1
      pid=3, state=BLOCKED, start=4, slice=1, event=1
      pid=4, state=BLOCKED, start=4, slice=2, event=1

Time: 14
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=4, 
   Ready Queue:
      pid=5, state=READY,   start=12, slice=0, 
      pid=6, state=READY,   start=12, slice=0, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=2, event=1
      pid=3, state=BLOCKED, start=4, slice=1, event=1
      pid=4, state=BLOCKED, start=4, slice=2, event=1

Time: 15
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=5, 
   Ready Queue:
      pid=5, state=READY,   start=12, slice=0, 
      pid=6, state=READY,   start=12, slice=0, 
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
   Blocked Queue:
      EMPTY

Time: 16
   CPU (currently running):
      pid=5, state=RUNNING, start=12, slice=1, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=0, 
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      EMPTY

Time: 17
   CPU (currently running):
      pid=5, state=RUNNING, start=12, slice=2, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=0, 
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      EMPTY

Time: 18
   CPU (currently running):
      pid=5, state=RUNNING, start=12, slice=3, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=0, 
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      EMPTY

Time: 19
   CPU (currently running):
      pid=5, state=RUNNING, start=12, slice=4, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=0, 
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      EMPTY

Time: 20
   CPU (currently running):
      pid=5, state=RUNNING, start=12, slice=5, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=0, 
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      EMPTY

Time: 21
   CPU (currently running):
      pid=6, state=RUNNING, start=12, slice=1, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
   Blocked Queue:
      EMPTY

Time: 22
   CPU (currently running):
      pid=6, state=RUNNING, start=12, slice=2, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
   Blocked Queue:
      EMPTY

Time: 23
   CPU (currently running):
      pid=6, state=RUNNING, start=12, slice=3, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
   Blocked Queue:
      EMPTY

Time: 24
   CPU (currently running):
      pid=6, state=RUNNING, start=12, slice=4, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
   Blocked Queue:
      EMPTY

Time: 25
   CPU (currently running):
      pid=6, state=RUNNING, start=12, slice=5, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=2, 
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
   Blocked Queue:
      EMPTY

Time: 26
   CPU (currently running):
      pid=2, state=RUNNING, start=4, slice=1, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      EMPTY

Time: 27
   CPU (currently running):
      pid=2, state=RUNNING, start=4, slice=2, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      EMPTY

Time: 28
   CPU (currently running):
      pid=2, state=RUNNING, start=4, slice=3, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      EMPTY

Time: 29
   CPU (currently running):
      pid=2, state=RUNNING, start=4, slice=4, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=1, 
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      EMPTY

Time: 30
   CPU (currently running):
      pid=3, state=RUNNING, start=4, slice=1, 
   Ready Queue:
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1

Time: 31
   CPU (currently running):
      pid=3, state=RUNNING, start=4, slice=2, 
   Ready Queue:
      pid=4, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1

Time: 32
   CPU (currently running):
      pid=4, state=RUNNING, start=4, slice=1, 
   Ready Queue:
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=3, state=BLOCKED, start=4, slice=2, event=2

Time: 33
   CPU (currently running):
      pid=4, state=RUNNING, start=4, slice=2, 
   Ready Queue:
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=3, state=BLOCKED, start=4, slice=2, event=2

Time: 34
   CPU (currently running):
      pid=4, state=RUNNING, start=4, slice=3, 
   Ready Queue:
      pid=1, state=READY,   start=1, slice=5, 
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=3, state=BLOCKED, start=4, slice=2, event=2

Time: 35
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=1, 
   Ready Queue:
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=3, state=BLOCKED, start=4, slice=2, event=2
      pid=4, state=BLOCKED, start=4, slice=3, event=3

Time: 36
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=2, 
   Ready Queue:
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=3, state=BLOCKED, start=4, slice=2, event=2
      pid=4, state=BLOCKED, start=4, slice=3, event=3

Time: 37
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=3, 
   Ready Queue:
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=4, state=BLOCKED, start=4, slice=3, event=3

Time: 38
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=4, 
   Ready Queue:
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=4, state=BLOCKED, start=4, slice=3, event=3

Time: 39
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=5, 
   Ready Queue:
      pid=5, state=READY,   start=12, slice=5, 
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=4, state=BLOCKED, start=4, slice=3, event=3

Time: 40
   CPU (currently running):
      pid=5, state=RUNNING, start=12, slice=1, 
   Ready Queue:
      pid=7, state=READY,   start=22, slice=0, 
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=4, state=BLOCKED, start=4, slice=3, event=3

Time: 41
   CPU (currently running):
      pid=7, state=RUNNING, start=22, slice=1, 
   Ready Queue:
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=4, state=BLOCKED, start=4, slice=3, event=3
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 42
   CPU (currently running):
      pid=7, state=RUNNING, start=22, slice=2, 
   Ready Queue:
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=4, state=BLOCKED, start=4, slice=3, event=3
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 43
   CPU (currently running):
      pid=7, state=RUNNING, start=22, slice=3, 
   Ready Queue:
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      pid=2, state=BLOCKED, start=4, slice=4, event=1
      pid=4, state=BLOCKED, start=4, slice=3, event=3
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 44
   CPU (currently running):
      pid=7, state=RUNNING, start=22, slice=4, 
   Ready Queue:
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
   Blocked Queue:
      pid=4, state=BLOCKED, start=4, slice=3, event=3
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 45
   CPU (currently running):
      pid=7, state=RUNNING, start=22, slice=5, 
   Ready Queue:
      pid=8, state=READY,   start=22, slice=0, 
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
   Blocked Queue:
      pid=4, state=BLOCKED, start=4, slice=3, event=3
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 46
   CPU (currently running):
      pid=8, state=RUNNING, start=22, slice=1, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
   Blocked Queue:
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 47
   CPU (currently running):
      pid=8, state=RUNNING, start=22, slice=2, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
   Blocked Queue:
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 48
   CPU (currently running):
      pid=8, state=RUNNING, start=22, slice=3, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
   Blocked Queue:
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 49
   CPU (currently running):
      pid=8, state=RUNNING, start=22, slice=4, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
   Blocked Queue:
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 50
   CPU (currently running):
      pid=8, state=RUNNING, start=22, slice=5, 
   Ready Queue:
      pid=6, state=READY,   start=12, slice=5, 
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
   Blocked Queue:
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 51
   CPU (currently running):
      pid=6, state=RUNNING, start=12, slice=1, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
   Blocked Queue:
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 52
   CPU (currently running):
      pid=6, state=RUNNING, start=12, slice=2, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
   Blocked Queue:
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 53
   CPU (currently running):
      pid=6, state=RUNNING, start=12, slice=3, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
   Blocked Queue:
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 54
   CPU (currently running):
      pid=6, state=RUNNING, start=12, slice=4, 
   Ready Queue:
      pid=3, state=READY,   start=4, slice=2, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
   Blocked Queue:
      pid=5, state=BLOCKED, start=12, slice=1, event=2

Time: 55
   CPU (currently running):
      pid=3, state=RUNNING, start=4, slice=1, 
   Ready Queue:
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
   Blocked Queue:
      EMPTY

Time: 56
   CPU (currently running):
      pid=3, state=RUNNING, start=4, slice=2, 
   Ready Queue:
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
   Blocked Queue:
      EMPTY

Time: 57
   CPU (currently running):
      pid=3, state=RUNNING, start=4, slice=3, 
   Ready Queue:
      pid=1, state=READY,   start=1, slice=5, 
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
   Blocked Queue:
      EMPTY

Time: 58
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=1, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
   Blocked Queue:
      pid=3, state=BLOCKED, start=4, slice=3, event=1

Time: 59
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=2, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
   Blocked Queue:
      pid=3, state=BLOCKED, start=4, slice=3, event=1

Time: 60
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=3, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
   Blocked Queue:
      pid=3, state=BLOCKED, start=4, slice=3, event=1

Time: 61
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=4, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
   Blocked Queue:
      pid=3, state=BLOCKED, start=4, slice=3, event=1

Time: 62
   CPU (currently running):
      pid=1, state=RUNNING, start=1, slice=5, 
   Ready Queue:
      pid=2, state=READY,   start=4, slice=4, 
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
   Blocked Queue:
      pid=3, state=BLOCKED, start=4, slice=3, event=1

Time: 63
   CPU (currently running):
      pid=2, state=RUNNING, start=4, slice=1, 
   Ready Queue:
      pid=7, state=READY,   start=22, slice=5, 
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
      pid=1, state=READY,   start=1, slice=5, 
   Blocked Queue:
      pid=3, state=BLOCKED, start=4, slice=3, event=1

Time: 64
   CPU (currently running):
      pid=7, state=RUNNING, start=22, slice=1, 
   Ready Queue:
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=3, state=READY,   start=4, slice=3, 
   Blocked Queue:
      EMPTY

Time: 65
   CPU (currently running):
      pid=7, state=RUNNING, start=22, slice=2, 
   Ready Queue:
      pid=4, state=READY,   start=4, slice=3, 
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=3, state=READY,   start=4, slice=3, 
   Blocked Queue:
      EMPTY

Time: 66
   CPU (currently running):
      pid=4, state=RUNNING, start=4, slice=1, 
   Ready Queue:
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=3, state=READY,   start=4, slice=3, 
   Blocked Queue:
      EMPTY

Time: 67
   CPU (currently running):
      pid=4, state=RUNNING, start=4, slice=2, 
   Ready Queue:
      pid=8, state=READY,   start=22, slice=5, 
      pid=5, state=READY,   start=12, slice=1, 
      pid=1, state=READY,   start=1, slice=5, 
      pid=3, state=READY,   start=4, slice=3, 
   Blocked Queue:
      EMPTY

