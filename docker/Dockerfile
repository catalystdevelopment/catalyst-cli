FROM ubuntu:18.04

ENV TERM=xterm

RUN apt-get update

RUN apt-get install -y \
    apt-utils \
    git \
    vim \
    zsh \
    iputils-ping \
    net-tools \
    netcat

ARG LOCALE_LANG_COUNTRY="en_US"
ARG LOCALE_CODIFICATION="UTF-8"
ARG LOCALE_CODIFICATION_ENV="utf8"

RUN git clone git://github.com/robbyrussell/oh-my-zsh.git ~/.oh-my-zsh --depth 1 \
    && cp ~/.oh-my-zsh/templates/zshrc.zsh-template ~/.zshrc

RUN apt-get install -y \
    build-essential \
    python-dev \
    g++-8 \
    gcc-8 \
    cmake \
    libboost-all-dev

WORKDIR /releases
