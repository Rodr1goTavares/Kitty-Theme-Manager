# Kitty-Theme-Manager (🚧: In progress)

<br>

## How it works ? 

The application will manage kitty's .conf files, using a
a theme folder in ``` $HOME/.config/kitty/ktheme ```

When saving the current theme using the ``` ktm -s ``` command, its ```.conf ``` file will be copied to the ktheme folder with the name of your choice. 

Saved themes can be applied at any time using the ```ktm --select``` command.

You can also save themes to different locations using the ```shell ktm -s <custom/path> ``` command.


<br>

## Exemples:

#### Save actual config as a theme ✔️: 
  (default location: $HOME/.config/kitty/kthemes)
``` shell
  ktm -s my-new-theme
  ktm -s my-new-theme $HOME/path/to/custom/directory
```


#### Select theme 💱:

``` shell
  ktm --select <.conf file name located in your $HOME/.config/kitty/kthemes>

  # exemple
  ktm --select gruvbox
```

## Instalation
```shell
wget -qO- https://raw.githubusercontent.com/Rodr1goTavares/Kitty-Theme-Manager/main/scripts/install.sh | bash
```

## Uninstall
```shell
wget -qO- https://raw.githubusercontent.com/Rodr1goTavares/Kitty-Theme-Manager/main/scripts/uninstall.sh | bash
```




