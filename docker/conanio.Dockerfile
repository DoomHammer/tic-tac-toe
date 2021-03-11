FROM conanio/gcc10

RUN sudo apt-get update && sudo apt-get install ccache && sudo rm -rf /var/lib/apt/lists/*
