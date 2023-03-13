//
// Created by gpinto03 on 13-03-2023.
//

#include "main.h"
#include <iostream>
#include "read_files.h"

int main() {
    vector<Network> networks;
    read_files::read_network(networks);
    //read_files::print_networks(networks);
    return 0;
}