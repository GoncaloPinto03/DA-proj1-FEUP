#include <iostream>
#include "main.h"
#include "read_files.h"
using namespace std;

int main() {
    vector<Network> networks;
    read_network(networks);
    print_networks(networks);
    return 0;
}