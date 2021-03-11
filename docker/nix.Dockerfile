FROM conanio/gcc10

ENV USER conan

RUN /bin/bash -c "$(curl -fsSL https://nixos.org/nix/install)"

RUN echo 'if [ -e /home/conan/.nix-profile/etc/profile.d/nix.sh ]; then . /home/conan/.nix-profile/etc/profile.d/nix.sh; fi' >> /home/conan/.bashrc

SHELL ["/bin/bash", "-c"]

RUN . /home/conan/.nix-profile/etc/profile.d/nix.sh && nix-env -i direnv gnutar gzip

RUN . /home/conan/.nix-profile/etc/profile.d/nix.sh && nix-channel --add https://github.com/NixOS/nixpkgs/archive/a439e0ef6eb2ab395048b3cf68a46224874245ef.tar.gz daily && nix-channel --update

RUN . /home/conan/.nix-profile/etc/profile.d/nix.sh && nix-env -i direnv pre-commit ccache binutils gnutar gcc git gnumake cmake python3 pkg-config

RUN . /home/conan/.nix-profile/etc/profile.d/nix.sh && direnv hook bash >> ~/.bashrc
