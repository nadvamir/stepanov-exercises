# Quicksort -> Intrasort

The goal of this exercise was to build a generic quicksort algorithm 
that is comparable to std::sort in speed. I first built a simple quicksort,
and then proceeded to optimise it for best results. The outcome (speeds in *std* 
and *my* columns are in ns per element):

```
        size       std      my   ratio
           8       126     102    0.80
          16       133     118    0.88
          32       158     138    0.88
          64       183     179    0.98
         128       233     225    0.97
         256       295     245    0.83
         512       325     267    0.82
        1024       354     234    0.66
        2048       365     310    0.85
        4096       413     333    0.81
        8192       443     353    0.80
       16384       472     342    0.72
       32768       458     396    0.87
       65536       531     418    0.79
      131072       561     439    0.78
      262144       592     462    0.78
      524288       622     484    0.78
     1048576       652     506    0.78
     2097152       601     527    0.88
     4194304       596     530    0.89
     8388608       738     571    0.77
    16777216       770     594    0.77
```

