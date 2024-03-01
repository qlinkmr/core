FROM phusion/baseimage:focal-1.0.0
LABEL maintainer="Qlink Developers <dev@qlink.org>"
LABEL description="Dockerised Qlink, built from Travis"

ARG USER_ID
ARG GROUP_ID

ENV HOME /home/qlink

# add user with specified (or default) user/group ids
ENV USER_ID ${USER_ID:-1000}
ENV GROUP_ID ${GROUP_ID:-1000}
RUN groupadd -g ${GROUP_ID} qlink && \
    useradd -u ${USER_ID} -g qlink -s /bin/bash -m -d /home/qlink qlink && \
    mkdir /home/qlink/.qlink && \
    chown ${USER_ID}:${GROUP_ID} -R /home/qlink

COPY bin/* /usr/local/bin/

RUN chmod a+x /usr/local/bin/*

USER qlink

VOLUME ["/home/qlink"]

EXPOSE 16357 9999 26357 26358

WORKDIR /home/qlink
