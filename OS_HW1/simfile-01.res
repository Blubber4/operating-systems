Processing stack/queue simulation file: simfile-01.sim

Enque  : 5
Stack  :
Queue  : 5

Enque  : 7
Stack  :
Queue  : 5 7

Push   : blooper
Stack  : blooper
Queue  : 5 7

Push   : rookie
Stack  : rookie blooper
Queue  : 5 7

Dequeue: 5
Stack  : rookie blooper
Queue  : 7

Push   : demerits
Stack  : demerits rookie blooper
Queue  : 7

Popped : demerits
Stack  : rookie blooper
Queue  : 7

Enque  : 3
Stack  : rookie blooper
Queue  : 7 3

Enque  : 8
Stack  : rookie blooper
Queue  : 7 3 8

Push   : showplace
Stack  : showplace rookie blooper
Queue  : 7 3 8

Enque  : 9
Stack  : showplace rookie blooper
Queue  : 7 3 8 9

Dequeue: 7
Stack  : showplace rookie blooper
Queue  : 3 8 9

Popped : showplace
Stack  : rookie blooper
Queue  : 3 8 9

Dequeue: 3
Stack  : rookie blooper
Queue  : 8 9

Push   : palmetto
Stack  : palmetto rookie blooper
Queue  : 8 9

Push   : zebra
Stack  : zebra palmetto rookie blooper
Queue  : 8 9

Popped : zebra
Stack  : palmetto rookie blooper
Queue  : 8 9

Push   : collapse
Stack  : collapse palmetto rookie blooper
Queue  : 8 9

Dequeue: 8
Stack  : collapse palmetto rookie blooper
Queue  : 9

Dequeue: 9
Stack  : collapse palmetto rookie blooper
Queue  :

Dequeue request from empty queue
Stack  : collapse palmetto rookie blooper
Queue  :

Popped : collapse
Stack  : palmetto rookie blooper
Queue  :

Popped : palmetto
Stack  : rookie blooper
Queue  :

Popped : rookie
Stack  : blooper
Queue  :

Popped : blooper
Stack  :
Queue  :

Pop request from empty stack
Stack  :
Queue  :

Enque  : 2
Stack  :
Queue  : 2

Enque  : 4
Stack  :
Queue  : 2 4

Push   : penguins
Stack  : penguins
Queue  : 2 4

Push   : sleeping
Stack  : sleeping penguins
Queue  : 2 4

Simulation ends
