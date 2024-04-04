

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
origin	git@github.com:L30nardoSV/pulpino.git (fetch)
origin	git@github.com:L30nardoSV/pulpino.git (push)
```

```
(venv) ➜  pulpino git:(lsv-zed) git remote rename origin leo
Renaming remote references: 100% (4/4), done.
```

```
(venv) ➜  pulpino git:(lsv-zed) git remote -v
leo	git@github.com:L30nardoSV/pulpino.git (fetch)
leo	git@github.com:L30nardoSV/pulpino.git (push)
```

```
(venv) ➜  pulpino git:(lsv-zed) git remote add origin https://github.com/pulp-platform/pulpino.git
(venv) ➜  pulpino git:(lsv-zed) git remote -v
leo	git@github.com:L30nardoSV/pulpino.git (fetch)
leo	git@github.com:L30nardoSV/pulpino.git (push)
origin	https://github.com/pulp-platform/pulpino.git (fetch)
origin	https://github.com/pulp-platform/pulpino.git (push)
```


```
source /opt/cad/xilinx/vivado/Vivado/2019.1/settings64.sh
```


Manually fix a printf in generated Python script:

```
(venv) ➜  pulpino git:(lsv-zed) ./update-ips.py 
Using remote git server https://github.com, remote is https://github.com/pulp-platform
Cloning into 'ipstools'...
remote: Enumerating objects: 974, done.
remote: Counting objects: 100% (29/29), done.
remote: Compressing objects: 100% (15/15), done.
remote: Total 974 (delta 14), reused 21 (delta 13), pack-reused 945
Receiving objects: 100% (974/974), 192.96 KiB | 5.36 MiB/s, done.
Resolving deltas: 100% (675/675), done.
Traceback (most recent call last):
  File "/home/wimi/lvs/Zedboard/UTEC/pulpino/./update-ips.py", line 95, in <module>
    import ipstools
  File "/home/wimi/lvs/Zedboard/UTEC/pulpino/ipstools/__init__.py", line 13, in <module>
    from .SubIPConfig import *
  File "/home/wimi/lvs/Zedboard/UTEC/pulpino/ipstools/SubIPConfig.py", line 116
    print "Skipping %s.%s as it is not supported by the TCSH-based build flow." % (self.ip_name, self.sub_ip_name)
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
```


```
pip install pyyaml
```


