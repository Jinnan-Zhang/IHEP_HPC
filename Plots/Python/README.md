# Python matplotlib style usage

* See Explot.py

* How to edit the file Style/Paper.mplstyle and create your own style:
    * See https://github.com/matplotlib/matplotlib/blob/v3.1.2/matplotlibrc.template

* Basically: 
```python
import matplotlib.pyplot as plt

plt.style.use("Style/Paper.mplstyle")

```

# Install matplotlib and numpy ... without root access
* Take IHEP lxslc7.ihep.ac.cn as a example, after login:
```shell
$ mkdir /workfs/juno/YourUserName/.local
$ ln -s /workfs/juno/YourUserName/.local ~/.local
$ cd ~/.local
$ mkdir src
$ wget https://bootstrap.pypa.io/get-pip.py
$ python get-pip.py --user
$ pip install --user matplotlib numpy scipy
$ export PATH=~./local/bin:$PATH
```
* The reason you need to use the commod  ```ln -s``` is afs has limited 500 MB space, it's better to put the data somewhere else.