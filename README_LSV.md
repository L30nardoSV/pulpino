# Instructions

```
git clone https://github.com/pulp-platform/pulpino.git
```

```
cd pulpino/
```

```
virtualenv --python=python2 venv
```

```
source venv/bin/activate
```

```
(venv) [lvs@aredhel pulpino]$ ./update-ips.py
```

You will get `ImportError: No module named yaml`, so import it:

```
(venv) [lvs@aredhel pulpino]$ pip install pyyaml
```

```
(venv) [lvs@aredhel pulpino]$ ./update-ips.py
```

This time, the output will be better, but giving this summary:

```
[...]
Cloning ip 'adv_dbg_if'...
https://github.com/pulp-platform
Cloning into 'adv_dbg_if'...
remote: Enumerating objects: 244, done.
remote: Counting objects: 100% (22/22), done.
remote: Compressing objects: 100% (19/19), done.
remote: Total 244 (delta 8), reused 10 (delta 3), pack-reused 222
Receiving objects: 100% (244/244), 569.32 KiB | 20.33 MiB/s, done.
Resolving deltas: 100% (138/138), done.
error: pathspec 'pulpinov1' did not match any file(s) known to git
ERROR: could not checkout ip 'adv_dbg_if' at pulpinov1.

[...]

SUMMARY
    adv_dbg_if - Could not checkout commit pulpinov1
()
ERRORS during IP update!
```

```
(venv) [lvs@aredhel pulpino]$ cd fpga/
```

```
(venv) [lvs@aredhel fpga]$ git remote -v
origin	https://github.com/pulp-platform/pulpino.git (fetch)
origin	https://github.com/pulp-platform/pulpino.git (push)
```

```
(venv) [lvs@aredhel fpga]$ git remote add leo git@github.com:L30nardoSV/pulpino.git
```


```
(venv) [lvs@aredhel fpga]$ git remote -v
leo	git@github.com:L30nardoSV/pulpino.git (fetch)
leo	git@github.com:L30nardoSV/pulpino.git (push)
origin	https://github.com/pulp-platform/pulpino.git (fetch)
origin	https://github.com/pulp-platform/pulpino.git (push)
```

```
(venv) [lvs@aredhel fpga]$ git fetch leo
```

```
(venv) [lvs@aredhel fpga]$ git checkout  lsv-zed
```

```
source /opt/cad/xilinx/vivado/Vivado/2019.1/settings64.sh
```







