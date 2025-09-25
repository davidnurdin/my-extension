sudo rm -rf $(go env GOPATH)/pkg/mod/cache/ ~/.xcaddy
sudo rm -rf $(go env GOPATH)/pkg/mod/github.com/ ~/.xcaddy
sudo rm -rf ./build

go clean -modcache
go mod tidy
