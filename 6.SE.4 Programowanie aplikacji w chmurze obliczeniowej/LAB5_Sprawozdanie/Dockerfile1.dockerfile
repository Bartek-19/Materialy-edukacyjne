ARG VERSION=3.21.3
FROM alpine:${VERSION}
WORKDIR /bin/bash

ARG VERSION
ENV ENV_VERSION=v.${VERSION}

RUN echo $ENV_VERSION > alpine_version
CMD ["sh", "-c", "echo Zadanie 1 && cat alpine_version && ip -4 a | grep inet && hostname"]
 