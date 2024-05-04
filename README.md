# MountModule

MountModule is a custom module for [AzerothCore] that allows players to mount under specific shapeshift forms.

## Features

- Allows mounting under specified shapeshift forms.
- Configuration file support for specifying allowed forms.

## Installation

1. Clone or download this repository.
2. Copy the `MountModule` folder into your server's source code directory.
3. Compile your server.

## Usage

1. Configure the allowed shapeshift forms in `mnt_config.conf` under the `[Mounting]` section.
2. Initialize the `MountModule` in your server startup code.
3. Players can now mount under the specified shapeshift forms.

## Configuration

The configuration file `mnt_config.conf` allows you to specify the allowed shapeshift forms for mounting. Example:

```conf
[Mounting]
AllowedForms = 16591, // Noggenfogger Skeleton
```

## Support

If you find any issues or have suggestions for improvement, please open an issue or submit a pull request, as none of my scripts are tested unless you test it yourself and give feedback!
