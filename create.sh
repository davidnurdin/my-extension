sudo rm -rf $(go env GOPATH)/pkg/mod/cache/ ~/.xcaddy
sudo rm -rf $(go env GOPATH)/pkg/mod/github.com/ ~/.xcaddy
sudo rm -rf ./build
#GEN_STUB_FILE=/home/linuxbrew/.linuxbrew/Cellar/php-zts/8.4.12/lib/php/build/gen_stub.php frankenphp extension-init my_extension.go 
GEN_STUB_SCRIPT=/home/david/poc/my_extension/php-8.4.11/build/gen_stub.php GEN_STUB_FILE=/home/david/poc/my_extension/php-8.4.11/build/gen_stub.php frankenphp extension-init my_extension.go 
