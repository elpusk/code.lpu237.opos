// tp_opos_msr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


#include <opos/ct_opos_mgmt.h>

int main()
{
    std::wcout << L"Hello World!\n";

    

    do {
        _ns_tools::ct_opos_mgmt::type_ptr ptr_msr = _ns_tools::ct_opos_mgmt::get_manager(_ns_tools::ct_opos_mgmt::type_opos_msr);
        if (!ptr_msr) {
            std::wcout << L"ER : create mgmt msr.\n";
            continue;
        }
        if (!ptr_msr->is_ini()) {
            std::wcout << L"ER : ini create mgmt msr.\n";
            continue;
        }

        ptr_msr->wait_event();

        _ns_tools::ct_opos_mgmt::type_ptr ptr_keylock = _ns_tools::ct_opos_mgmt::get_manager(_ns_tools::ct_opos_mgmt::type_opos_keylock);
        if (!ptr_keylock) {
            std::wcout << L"ER : create mgmt keylock.\n";
            continue;
        }
        if (!ptr_keylock->is_ini()) {
            std::wcout << L"ER : ini create mgmt keylock.\n";
            continue;
        }

    }while(false);
}
