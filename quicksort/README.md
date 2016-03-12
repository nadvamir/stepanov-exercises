# Quicksort -> Intrasort

The goal of this exercise was to build a generic quicksort algorithm 
that is comparable to std::sort in speed. I first built a simple quicksort,
and then proceeded to optimise it for best results. 

This was the outcome. *Time* column shows sorting time per element in nanoseconds,
and *lg2* is the constant factor (`time / log N`). *Ratio* column shows ratio
between times per element.

```
                  std sort         my sort
        size    time     lg2    time     lg2   ratio
           8     111      37     107      36    0.97
          16     126      31     120      30    0.95
          32     161      32     136      27    0.85
          64     183      31     152      25    0.83
         128     205      29     177      25    0.86
         256     235      29     193      24    0.82
         512     261      29     205      23    0.79
        1024     277      28     222      22    0.80
        2048     296      27     238      22    0.80
        4096     326      27     256      21    0.79
        8192     342      26     275      21    0.80
       16384     366      26     289      21    0.79
       32768     383      26     318      21    0.83
       65536     406      25     324      20    0.80
      131072     426      25     347      20    0.81
      262144     454      25     361      20    0.80
      524288     479      25     374      20    0.78
     1048576     499      25     396      20    0.79
     2097152     519      25     410      20    0.79
     4194304     540      25     435      20    0.81
     8388608     575      25     455      20    0.79
    16777216     595      25     461      19    0.77
```

