
````
➜  pulpino git:(master) ls
ci  create-archive.py  doc  fpga  generate-scripts.py  ips  ips_list.yml  ipstools  LICENSE  README.md  rtl  sw  tb  update-ips.py  vsim
```

```
➜  pulpino git:(master) virtualenv --python=python3 venv
```

```
➜  pulpino git:(master) source venv/bin/activate
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

