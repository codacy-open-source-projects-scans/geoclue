# Building Geoclue

- The following are the dependencies needed to build Geoclue2. But If Geoclue2
  is already included in your distro/OS, you should be able to use the
  package manager's command to install all build depedndancies.

  * gio
  * gobject-introspection
  * json-glib
  * libsoup3.0
  * pkg-config

  Fedora:

  ```shell
  sudo dnf builddep geoclue2
  ```

  Debian and Ubuntu:

  ```shell
  sudo apt build-dep geoclue-2.0
  ```

- For a full-fledged build, you also want ModemManager (mm-glib),
  avahi-client and avahi-glib. You want the latter two if you want to use the
  [geoclue-share app](https://wiki.gnome.org/Apps/GeoclueShare). You also need
  libnotify if you want to build the demo agent.

  Fedora:

  ```shell
  sudo dnf install ModemManager-devel
  sudo dnf install avahi-devel
  sudo dnf install avahi-glib-devel
  sudo dnf install libnotify-devel
  ```

  Debian and Ubuntu:

  ```shell
  sudo apt install modemmanager-dev
  sudo apt install libavahi-client-dev
  sudo apt install libavahi-glib-dev
  sudo apt install libnotify-dev
  ```

- [Install meson](https://mesonbuild.com/Getting-meson.html).

- Ensure you have a `geoclue` user on your system. If it already exists, you may
  need to modify `/etc/passwd` file to make it a login user account by replacing
  `/sbin/nologin` with `/bin/bash` (or the path to your preferred shell).

- Build and install geoclue.

  ```shell
  meson --prefix=/usr --sysconfdir /etc -Ddbus-srv-user=geoclue build
  # you may need to pass --libdir=/usr/lib64 on some systems (eg. Fedora)
  ninja -C build
  sudo ninja -C build install
  ```

- Then you can run it as:

  ```shell
  sudo su geoclue # Starts a new shell as `geoclue` user
  G_MESSAGES_DEBUG=Geoclue /usr/libexec/geoclue
  ```

  If you get the following error, make sure `geoclue` process is not already
  running:

  ```
  > Failed to acquire name 'org.freedesktop.GeoClue2' on system bus or lost it
  ```

- Now you can test if Geoclue is running and working:

  ```shell
  /usr/libexec/geoclue-2.0/demos/where-am-i
  ```

  It will give your current location.

## Translating Geoclue

The demo agent, demo application (`where-am-i`) and the `--help` output of the
geoclue server contain translatable strings.

You can create a template `po/geoclue-2.0.pot` file, update the existing `.po`
translation files and build the binary translation `.mo` files by running these
commands on a configured project, respectively:

```shell
meson compile -C build geoclue-2.0-pot
meson compile -C build geoclue-2.0-update-po
meson compile -C build geoclue-2.0-gmo
```

See the documentation of meson i18n module for details.

When starting a new translation, rename the `geoclue-2.0.pot` file to the
desired language code (e.g. `en.po`) and start translating. Remember to add the
language code to `po/LINGUAS` when done.

You can test the translations after building and installing by running one of
the binaries with the `LANG` environment variable set to the full language code
of the desired language:

```shell
LANG=ka_GE.UTF8 /usr/libexec/geoclue-2.0/demos/where-am-i -h
```
