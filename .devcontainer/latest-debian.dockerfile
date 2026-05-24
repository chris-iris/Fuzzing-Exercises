FROM --platform=linux/x86-64 mcr.microsoft.com/devcontainers/cpp
ENV TZ=IT \
    DEBIAN_FRONTEND=noninteractive

RUN apt-get -y update && \
    apt install -y \
    build-essential \
    openssl \
    clang \
    graphviz-dev \
    libcap-dev \
    git file afl++

RUN bash -c "$(curl -fsSL https://gef.blah.cat/sh)"

RUN echo 'deb http://download.opensuse.org/repositories/home:/RizinOrg/Debian_13/ /' | sudo tee /etc/apt/sources.list.d/home:RizinOrg.list && \
    curl -fsSL https://download.opensuse.org/repositories/home:RizinOrg/Debian_13/Release.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/home_RizinOrg.gpg > /dev/null && \ 
    sudo apt update -y && sudo apt install rizin -y
    