# Instructions

**Important**: _we start using the original repository to pull all required git submodules. However, thereafter, we switch to our custom repository (containing adaptations) for building the FPGA designs_.

```
git clone https://github.com/pulp-platform/pulpino.git
```

```
cd pulpino/
```

It is important to use a **Python 2**  environment (otherwise several fixes will be required):

```
virtualenv --python=python2 venv
```

```
source venv/bin/activate
```

Next instructions are executed within the Python virtual environment:

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

The following is required in a further step (building pulpino within `fpga/pulpino`) 

```
(venv) [lvs@aredhel pulpino]$ ./generate-scripts.py
```

As far as I can tell, this script generates the following (and perhaps other) files:

```
(venv) [lvs@aredhel pulpino]$ ll fpga/pulpino/tcl/
total 48
-rw-r--r--. 1 lvs wimi  1408  4. Apr 14:39 ips_add_files.tcl
-rw-r--r--. 1 lvs wimi   427  4. Apr 14:39 ips_inc_dirs.tcl
-rw-r--r--. 1 lvs wimi 10283  4. Apr 14:39 ips_src_files.tcl
-rw-r--r--. 1 lvs wimi  4250  4. Apr 14:37 run.tcl
-rw-r--r--. 1 lvs wimi   969  4. Apr 14:37 src_files.tcl
```

```
(venv) [lvs@aredhel pulpino]$ cd fpga/
```

```
(venv) [lvs@aredhel fpga]$ git remote -v
origin	https://github.com/pulp-platform/pulpino.git (fetch)
origin	https://github.com/pulp-platform/pulpino.git (push)
```

The **leo** repository in GitHub contains scripts adaptations needed to get this working:

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
(venv) [lvs@aredhel fpga]$ git checkout lsv-zed
```

```
(venv) [lvs@aredhel fpga]$ source /opt/cad/xilinx/vivado/Vivado/2019.1/settings64.sh
```

```
(venv) [lvs@aredhel fpga]$ make all
```







