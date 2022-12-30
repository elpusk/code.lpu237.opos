// tp_opos_msr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


#include <opos/ct_opos_mgmt.h>

int main()
{
    std::wcout << L"Hello World!\n";

    do {
        _ns_tools::ct_opos_mgmt *p_msr = _ns_tools::ct_opos_mgmt::get_manager(_ns_tools::ct_opos_mgmt::type_opos_msr);
        if (!p_msr) {
            std::wcout << L"ER : create mgmt msr.\n";
            continue;
        }
        if (!p_msr->is_ini()) {
            std::wcout << L"ER : ini create mgmt msr.\n";
            continue;
        }

        for (int i = 0; i < 1; i++) {
            std::wcout << L"R" << i+1 <<L": read.\n";
            //p_msr->wait_event();
        }

        Sleep(1000);

        
        /*
        _ns_tools::ct_opos_mgmt::type_ptr ptr_keylock = _ns_tools::ct_opos_mgmt::get_manager(_ns_tools::ct_opos_mgmt::type_opos_keylock);
        if (!ptr_keylock) {
            std::wcout << L"ER : create mgmt keylock.\n";
            continue;
        }
        if (!ptr_keylock->is_ini()) {
            std::wcout << L"ER : ini create mgmt keylock.\n";
            continue;
        }
        */

        _ns_tools::ct_opos_mgmt::get_manager(_ns_tools::ct_opos_mgmt::type_opos_all, true);
    }while(false);
}
