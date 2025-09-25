#!/bin/bash


# ./clean.sh
./create.sh
git add . && git commit -m 'update' && git push
#sudo rm -rf $(go env GOPATH)/pkg/mod/cache/ ~/.xcaddy
#sudo rm -rf $(go env GOPATH)/pkg/mod/github.com/ ~/.xcaddy
#go get -u github.com/davidnurdin/my-extension/build
rm ./myfranken

LAST=$(git rev-parse --short HEAD)


CGO_ENABLED=1 \
XCADDY_GO_BUILD_FLAGS="-ldflags='-w -s' -tags=nobadger,nomysql,nopgx" \
CGO_CFLAGS=$(php-config --includes) \
CGO_LDFLAGS="$(php-config --ldflags) $(php-config --libs)" \
xcaddy build \
  --output /home/david/poc/my_extension/my_extension/myfranken \
  --with github.com/dunglas/frankenphp/caddy \
  --with github.com/dunglas/mercure/caddy \
  --with github.com/dunglas/vulcain/caddy \
  --with github.com/davidnurdin/my-extension/build/@$LAST

