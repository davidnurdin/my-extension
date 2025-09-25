go get -u github.com/davidnurdin/my-extension/build

sudo rm -rf ./build
sudo rm -rf $(go env GOPATH)/pkg/mod/cache/ ~/.xcaddy
sudo rm -rf $(go env GOPATH)/pkg/mod/github.com/ ~/.xcaddy
go clean -modcache
go mod tidy
