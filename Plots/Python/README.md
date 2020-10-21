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
$ export PATH=~/.local/bin:$PATH
$ pip install --user matplotlib numpy scipy
```
* The reason you need to use the commod  ```ln -s``` is afs has limited 500 MB space, it's better to put the data somewhere else.

# Manage project with pipenv (for developer!)
* pipenv can automatically creates and manages a virtualenv for your projects, as well as adds/removes packages from your Pipfile as you install/uninstall packages. [more information ...](https://pypi.org/project/pipenv/)
* install pipenv( if you don't have pipenv ) :
```shell
$ pip install pipenv --user
```
* Entry the virtual environment
```shell
$ cd your_project_path
$ pipenv shell
```
* Install all dependency libraries
```shell
$ pipenv install
```
This will install all dependency libraries which are recorded in Pipfile in your virtual environment.
* install/uninstall new dependency library
```shell
$ pipenv install/uninstall package_name
``` 
If there's no Pipfile, this command will create one and record all dependency libraries automatically.
