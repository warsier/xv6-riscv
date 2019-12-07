### Tick interval algorithm:
We implement our dynamic tick algorithm in `proc.c`.

First, when the scheduler goes over all processes once in a round-robin fashion and does not find a runnable process, we directly set the tick to MAX_TICK = 10000000.

Second, we keep a `tick` number for each process which is the tick number that we use when running this process. Initially we set this to BASE_TICK = 1000000. Then, each time we find a runnable process, we measure the actual time it uses. If it uses over 90% of its current tick number, we increase its (next) tick number by 1000000. If it uses less than 10% of its current tick number, we reduce its next tick number to 10% of current tick number. In other cases, the tick will just stay the same.

### Syscall that is affected most:
Well, `sys_uptime()` which returns how many clock tick interrupts have occurred since start will be affected most. Other process related syscalls like `sys_exec()` and `sys_wait()` will also be affected.


### Reference output of our test:
To run our test, run in the command line:
```
$ hw5test
```
This test will fork two processes, one IO-bounded program that writes multiple times to a file (proc 4 below), and one computation bounded program that does matrix multiplication (proc 5 below).

We observe that the tick interval will increase when proc 5 is doing the computation part; when both are waiting for IO, the tick interval will be very short.

Output before running `hw5test`:
```
prev tick = 1000000, time used by proc 1 = 4047, new tick = 100000.
prev tick = 100000, time used by proc 1 = 5089, new tick = 10000.
time used by proc 1 = 3883, new tick = 10000.
prev tick = 10000, time used by proc 1 = 10181, new tick = 1000000.
prev tick = 1000000, time used by proc 1 = 4297, new tick = 100000.
time used by proc 1 = 12074, new tick = 100000.
cur time = 3006917; interval = 74699.
prev tick = 100000, time used by proc 1 = 8276, new tick = 10000.
time used by proc 1 = 1304, new tick = 10000.
time used by proc 1 = 3106, new tick = 10000.
prev tick = 10000, time used by proc 1 = 28340, new tick = 1000000.
init: starting sh
prev tick = 1000000, time used by proc 1 = 18566, new tick = 100000.
prev tick = 1000000, time used by proc 2 = 14352, new tick = 100000.
prev tick = 100000, time used by proc 2 = 5774, new tick = 10000.
cur time = 3106600; interval = 99683.
time used by proc 2 = 4556, new tick = 10000.
prev tick = 10000, time used by proc 2 = 908, new tick = 1000.
cur time = 3118390; interval = 11790.
prev tick = 1000, time used by proc 2 = 6002, new tick = 1000000.
cur time = 3125605; interval = 7215.
prev tick = 1000000, time used by proc 2 = 962, new tick = 100000.
prev tick = 100000, time used by proc 2 = 2991, new tick = 10000.
time used by proc 2 = 3753, new tick = 10000.
$ prev tick = 10000, time used by proc 2 = 34723, new tick = 1000000.
cur time = 4128901; interval = 1003296.
cur time = 14136864; interval = 10007963.
cur time = 24138018; interval = 10001154.
```

Output after running `hw5test`:
```
prev tick = 1000000, time used by proc 2 = 15065, new tick = 100000.
prev tick = 1000000, time used by proc 3 = 36225, new tick = 100000.
prev tick = 100000, time used by proc 3 = 5522, new tick = 10000.
time used by proc 3 = 3077, new tick = 10000.
cur time = 44134072; interval = 10002621.
prev tick = 10000, time used by proc 3 = 45886, new tick = 1000000.
cur time = 44139028; interval = 4956.
cur time = 44146546; interval = 7518.
prev tick = 1000000, time used by proc 3 = 7554, new tick = 100000.
prev tick = 100000, time used by proc 3 = 9095, new tick = 10000.
forking hw5testproc1
prev tick = 1000000, time used by proc 4 = 84577, new tick = 100000.
forking hw5testproc2
prev tick = 1000000, time used by proc 5 = 85584, new tick = 100000.
prev tick = 100000, time used by proc 4 = 5464, new tick = 10000.
prev tick = 100000, time used by proc 5 = 5413, new tick = 10000.
time used by proc 4 = 3006, new tick = 10000.
time used by proc 5 = 4006, new tick = 10000.
prev tick = 10000, time used by proc 4 = 42112, new tick = 1000000.
cur time = 45149272; interval = 1002726.
prev tick = 10000, time used by proc 5 = 737084, new tick = 1000000.
cur time = 45156866; interval = 7594.
prev tick = 1000000, time used by proc 4 = 5401, new tick = 100000.
cur time = 46159191; interval = 1002325.
prev tick = 1000000, time used by proc 5 = 999649, new tick = 2000000.
prev tick = 100000, time used by proc 4 = 4205, new tick = 10000.
cur time = 47158161; interval = 998970.
time used by proc 5 = 988940, new tick = 2000000.
time used by proc 4 = 2600, new tick = 10000.
cur time = 49159806; interval = 2001645.
prev tick = 2000000, time used by proc 5 = 1994781, new tick = 3000000.
time used by proc 4 = 4172, new tick = 10000.
cur time = 51159948; interval = 2000142.
time used by proc 5 = 1990609, new tick = 3000000.
time used by proc 4 = 3463, new tick = 10000.
cur time = 54161353; interval = 3001405.
prev tick = 3000000, time used by proc 5 = 2993584, new tick = 4000000.
time used by proc 4 = 4709, new tick = 10000.
cur time = 57161354; interval = 3000001.
time used by proc 5 = 2990801, new tick = 4000000.
prev tick = 10000, time used by proc 4 = 189571, new tick = 1000000.
cur time = 61161894; interval = 4000540.
prev tick = 4000000, time used by proc 5 = 3805626, new tick = 5000000.
prev tick = 1000000, time used by proc 4 = 3942, new tick = 100000.
cur time = 65162157; interval = 4000263.
time used by proc 5 = 3990905, new tick = 5000000.
prev tick = 100000, time used by proc 4 = 3304, new tick = 10000.
finished testproc2
time used by proc 5 = 1602018, new tick = 5000000.
time used by proc 4 = 4015, new tick = 10000.
prev tick = 10000, time used by proc 4 = 187605, new tick = 1000000.
prev tick = 5000000, time used by proc 5 = 50, new tick = 500000.
prev tick = 1000000, time used by proc 4 = 3805, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3052, new tick = 10000.
time used by proc 4 = 3714, new tick = 10000.
prev tick = 10000, time used by proc 4 = 187453, new tick = 1000000.
prev tick = 500000, time used by proc 5 = 46, new tick = 50000.
prev tick = 1000000, time used by proc 4 = 3729, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3059, new tick = 10000.
time used by proc 4 = 3728, new tick = 10000.
prev tick = 10000, time used by proc 4 = 188161, new tick = 1000000.
prev tick = 50000, time used by proc 5 = 48, new tick = 5000.
prev tick = 1000000, time used by proc 4 = 3724, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3058, new tick = 10000.
time used by proc 4 = 3715, new tick = 10000.
prev tick = 10000, time used by proc 4 = 189606, new tick = 1000000.
prev tick = 5000, time used by proc 5 = 50, new tick = 500.
prev tick = 1000000, time used by proc 4 = 3738, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3069, new tick = 10000.
time used by proc 4 = 4074, new tick = 10000.
prev tick = 10000, time used by proc 4 = 192172, new tick = 1000000.
prev tick = 500, time used by proc 5 = 1099, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3902, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3251, new tick = 10000.
time used by proc 4 = 3794, new tick = 10000.
prev tick = 10000, time used by proc 4 = 196066, new tick = 1000000.
prev tick = 1000000, time used by proc 5 = 48, new tick = 100000.
prev tick = 1000000, time used by proc 4 = 4099, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3216, new tick = 10000.
time used by proc 4 = 3744, new tick = 10000.
prev tick = 10000, time used by proc 4 = 210048, new tick = 1000000.
prev tick = 100000, time used by proc 5 = 49, new tick = 10000.
prev tick = 1000000, time used by proc 4 = 3958, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3039, new tick = 10000.
time used by proc 4 = 3732, new tick = 10000.
prev tick = 10000, time used by proc 4 = 226035, new tick = 1000000.
prev tick = 10000, time used by proc 5 = 48, new tick = 1000.
prev tick = 1000000, time used by proc 4 = 3756, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3202, new tick = 10000.
time used by proc 4 = 3704, new tick = 10000.
prev tick = 10000, time used by proc 4 = 265343, new tick = 1000000.
prev tick = 1000, time used by proc 5 = 49, new tick = 100.
prev tick = 1000000, time used by proc 4 = 3675, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3005, new tick = 10000.
time used by proc 4 = 3686, new tick = 10000.
prev tick = 10000, time used by proc 4 = 346279, new tick = 1000000.
prev tick = 100, time used by proc 5 = 1073, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3652, new tick = 100000.
prev tick = 100000, time used by proc 4 = 2990, new tick = 10000.
time used by proc 4 = 3667, new tick = 10000.
prev tick = 10000, time used by proc 4 = 501126, new tick = 1000000.
prev tick = 1000000, time used by proc 5 = 47, new tick = 100000.
prev tick = 1000000, time used by proc 4 = 3656, new tick = 100000.
prev tick = 100000, time used by proc 4 = 2986, new tick = 10000.
time used by proc 4 = 3654, new tick = 10000.
cur time = 70160585; interval = 4998428.
prev tick = 10000, time used by proc 4 = 387971, new tick = 1000000.
prev tick = 100000, time used by proc 5 = 2088, new tick = 10000.
cur time = 70168193; interval = 7608.
prev tick = 100000, time used by proc 1 = 140, new tick = 10000.
prev tick = 10000, time used by proc 3 = 17636, new tick = 1000000.
cur time = 70268138; interval = 99945.
prev tick = 1000000, time used by proc 4 = 78179, new tick = 100000.
prev tick = 10000, time used by proc 1 = 57, new tick = 1000.
$ prev tick = 100000, time used by proc 2 = 3386, new tick = 10000.
time used by proc 4 = 16640, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3683, new tick = 10000.
time used by proc 4 = 3000, new tick = 10000.
time used by proc 4 = 3677, new tick = 10000.
prev tick = 10000, time used by proc 4 = 190371, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3707, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3265, new tick = 10000.
time used by proc 4 = 3901, new tick = 10000.
prev tick = 10000, time used by proc 4 = 194430, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3736, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3003, new tick = 10000.
time used by proc 4 = 3695, new tick = 10000.
prev tick = 10000, time used by proc 4 = 196942, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3687, new tick = 100000.
prev tick = 100000, time used by proc 4 = 2989, new tick = 10000.
time used by proc 4 = 3684, new tick = 10000.
prev tick = 10000, time used by proc 4 = 206757, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3675, new tick = 100000.
prev tick = 100000, time used by proc 4 = 2996, new tick = 10000.
time used by proc 4 = 3686, new tick = 10000.
cur time = 71268092; interval = 999954.
prev tick = 10000, time used by proc 4 = 59568, new tick = 1000000.
cur time = 71277034; interval = 8942.
prev tick = 1000000, time used by proc 4 = 6458, new tick = 100000.
prev tick = 100000, time used by proc 4 = 249366, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3721, new tick = 100000.
prev tick = 100000, time used by proc 4 = 2978, new tick = 10000.
time used by proc 4 = 3656, new tick = 10000.
prev tick = 10000, time used by proc 4 = 497195, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3748, new tick = 100000.
prev tick = 100000, time used by proc 4 = 2971, new tick = 10000.
time used by proc 4 = 3652, new tick = 10000.
cur time = 72277633; interval = 1000599.
prev tick = 10000, time used by proc 4 = 200583, new tick = 1000000.
cur time = 72288000; interval = 10367.
prev tick = 1000000, time used by proc 4 = 11746, new tick = 100000.
prev tick = 100000, time used by proc 4 = 307277, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3700, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3040, new tick = 10000.
time used by proc 4 = 3938, new tick = 10000.
prev tick = 10000, time used by proc 4 = 188457, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3692, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3006, new tick = 10000.
time used by proc 4 = 3688, new tick = 10000.
prev tick = 10000, time used by proc 4 = 187701, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3712, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3027, new tick = 10000.
time used by proc 4 = 3712, new tick = 10000.
prev tick = 10000, time used by proc 4 = 188613, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3693, new tick = 100000.
prev tick = 100000, time used by proc 4 = 2996, new tick = 10000.
time used by proc 4 = 3672, new tick = 10000.
cur time = 73287102; interval = 999102.
prev tick = 10000, time used by proc 4 = 15028, new tick = 1000000.
cur time = 73296891; interval = 9789.
prev tick = 1000000, time used by proc 4 = 7413, new tick = 100000.
prev tick = 100000, time used by proc 4 = 180261, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 4027, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3188, new tick = 10000.
time used by proc 4 = 3937, new tick = 10000.
prev tick = 10000, time used by proc 4 = 293748, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 4141, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3223, new tick = 10000.
time used by proc 4 = 3937, new tick = 10000.
prev tick = 10000, time used by proc 4 = 229227, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3726, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3140, new tick = 10000.
time used by proc 4 = 3998, new tick = 10000.
cur time = 74298208; interval = 1001317.
prev tick = 10000, time used by proc 4 = 215998, new tick = 1000000.
cur time = 74307588; interval = 9380.
prev tick = 1000000, time used by proc 4 = 7029, new tick = 100000.
time used by proc 4 = 75818, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3673, new tick = 10000.
time used by proc 4 = 2985, new tick = 10000.
time used by proc 4 = 3967, new tick = 10000.
prev tick = 10000, time used by proc 4 = 494663, new tick = 1000000.
prev tick = 1000000, time used by proc 4 = 3690, new tick = 100000.
prev tick = 100000, time used by proc 4 = 2988, new tick = 10000.
time used by proc 4 = 3671, new tick = 10000.
cur time = 75308505; interval = 1000917.
prev tick = 10000, time used by proc 4 = 379055, new tick = 1000000.
cur time = 75316973; interval = 8468.
prev tick = 1000000, time used by proc 4 = 6365, new tick = 100000.
time used by proc 4 = 50777, new tick = 100000.
prev tick = 100000, time used by proc 4 = 3862, new tick = 10000.
time used by proc 4 = 3065, new tick = 10000.
time used by proc 4 = 3705, new tick = 10000.
finished testproc1
prev tick = 10000, time used by proc 4 = 170723, new tick = 1000000.
prev tick = 1000, time used by proc 1 = 5283, new tick = 1000000.
cur time = 76319030; interval = 1002057.
cur time = 86322864; interval = 10003834.
cur time = 96328010; interval = 10005146.
```